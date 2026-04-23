#!/usr/bin/env python3
# pip install websockets
# Permissions (one-time):
#   sudo usermod -aG input $USER  && re-login
#   sudo chmod a+rw /dev/uinput

import asyncio, json, struct, time, os, fcntl, websockets

UI_SET_EVBIT   = 0x40045564
UI_SET_ABSBIT  = 0x40045567
UI_SET_KEYBIT  = 0x40045565
UI_DEV_CREATE  = 0x00005501
UI_DEV_DESTROY = 0x00005502
UI_DEV_SETUP   = 0x405c5503
UI_ABS_SETUP   = 0x401c5504

EV_SYN, EV_KEY, EV_ABS = 0, 1, 3
SYN_REPORT = 0
BTN_SOUTH, BTN_EAST, BTN_NORTH, BTN_WEST = 0x130, 0x131, 0x133, 0x134
ABS_X, ABS_Y, ABS_RX, ABS_RY = 0, 1, 3, 4
ABS_MAX = 32767

HOST = "0.0.0.0"
PORT = 9091
MAX_LIN = 1.0
MAX_ANG = 1.5

def open_uinput():
    fd = os.open("/dev/uinput", os.O_WRONLY | os.O_NONBLOCK)

    # Pass integer directly — NOT struct.pack buffer
    def si(req, val):
        fcntl.ioctl(fd, req, val)

    si(UI_SET_EVBIT, EV_SYN)
    si(UI_SET_EVBIT, EV_KEY)
    si(UI_SET_EVBIT, EV_ABS)

    for btn in [BTN_SOUTH, BTN_EAST, BTN_NORTH, BTN_WEST]:
        si(UI_SET_KEYBIT, btn)

    for axis in [ABS_X, ABS_Y, ABS_RX, ABS_RY]:
        si(UI_SET_ABSBIT, axis)

    # UI_ABS_SETUP: struct uinput_abs_setup
    # u16 code, 2 pad, then input_absinfo: 6x s32 (value,min,max,fuzz,flat,res)
    for axis in [ABS_X, ABS_Y, ABS_RX, ABS_RY]:
        buf = struct.pack("H2xiiiiii", axis, 0, -ABS_MAX, ABS_MAX, 16, 128, 0)
        fcntl.ioctl(fd, UI_ABS_SETUP, buf)

    # UI_DEV_SETUP: struct uinput_setup
    # input_id (4x u16) + name[80] + ff_effects_max (u32) = 92 bytes
    input_id = struct.pack("HHHH", 3, 0x045E, 0x028E, 0x0114)
    name = b"Robot Joystick\x00" + b"\x00" * 65  # 80 bytes
    buf = input_id + name + struct.pack("I", 0)
    fcntl.ioctl(fd, UI_DEV_SETUP, buf)

    fcntl.ioctl(fd, UI_DEV_CREATE)
    time.sleep(0.2)
    print("uinput device created")
    return fd

def emit(fd, etype, code, value):
    t = time.time()
    sec = int(t)
    usec = int((t - sec) * 1e6)
    os.write(fd, struct.pack("llHHi", sec, usec, etype, code, value))

def send_axes(fd, lx, ly, rx, ry):
    def to_abs(v):
        return int(max(-1.0, min(1.0, v)) * ABS_MAX)
    emit(fd, EV_ABS, ABS_X,  to_abs(lx))
    emit(fd, EV_ABS, ABS_Y,  to_abs(ly))
    emit(fd, EV_ABS, ABS_RX, to_abs(rx))
    emit(fd, EV_ABS, ABS_RY, to_abs(ry))
    emit(fd, EV_SYN, SYN_REPORT, 0)

async def handler(fd, ws):
    print(f"Client connected: {ws.remote_address}")
    async for msg in ws:
        try:
            d = json.loads(msg)
            body    = d.get("msg", d)   # rosbridge wraps in "msg", fall back to flat
            linear  = body.get("linear",  {})
            angular = body.get("angular", {})
            vx  = linear.get("x",  0.0)   # forward/back
            vy  = linear.get("y",  0.0)   # strafe
            yaw = angular.get("z", 0.0)   # rotation

            lx = -vy  / MAX_LIN   # left stick X  (strafe)
            ly = -vx  / MAX_LIN   # left stick Y  (forward, inverted for canvas Y)
            rx = -yaw / MAX_ANG   # right stick X (yaw)
            ry = 0.0

            send_axes(fd, lx, ly, rx, ry)
            print(f"\rvx={vx:+.2f} vy={vy:+.2f} yaw={yaw:+.2f}", end="", flush=True)
        except Exception as e:
            print(f"\nError: {e}")

async def main():
    fd = open_uinput()
    print(f"WebSocket server on {HOST}:{PORT}")
    try:
        async with websockets.serve(lambda ws: handler(fd, ws), HOST, PORT):
            await asyncio.Future()
    finally:
        fcntl.ioctl(fd, UI_DEV_DESTROY)
        os.close(fd)
        print("\nuinput device destroyed")

asyncio.run(main())