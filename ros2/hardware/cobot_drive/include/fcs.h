#ifndef UTILS_H
#define UTILS_H

#define INITFCS16    0xffff  /* Initial FCS value */
#define GOODFCS16    0xf0b8  /* Good final FCS value */

unsigned short fcs16(unsigned short fcs, char* cp, int len);
unsigned char checkfcs(char* dat, int len);
int addfcs(char* dat, int len);

#endif // UTILS_H
