// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from messages:msg/CobotRawStatus.idl
// generated code does not contain a copyright notice

#include "messages/msg/detail/cobot_raw_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_messages
const rosidl_type_hash_t *
messages__msg__CobotRawStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa5, 0xa1, 0x91, 0xd1, 0x0c, 0x47, 0x60, 0x65,
      0xac, 0xaf, 0xb1, 0xf3, 0xfa, 0xee, 0x6f, 0x29,
      0xb8, 0x2a, 0xcd, 0xe9, 0x18, 0x0d, 0x7d, 0x33,
      0x69, 0x27, 0x38, 0x11, 0x73, 0xae, 0xbe, 0xde,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char messages__msg__CobotRawStatus__TYPE_NAME[] = "messages/msg/CobotRawStatus";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char messages__msg__CobotRawStatus__FIELD_NAME__header[] = "header";
static char messages__msg__CobotRawStatus__FIELD_NAME__dr[] = "dr";
static char messages__msg__CobotRawStatus__FIELD_NAME__dx[] = "dx";
static char messages__msg__CobotRawStatus__FIELD_NAME__dy[] = "dy";
static char messages__msg__CobotRawStatus__FIELD_NAME__v0[] = "v0";
static char messages__msg__CobotRawStatus__FIELD_NAME__v1[] = "v1";
static char messages__msg__CobotRawStatus__FIELD_NAME__v2[] = "v2";
static char messages__msg__CobotRawStatus__FIELD_NAME__v3[] = "v3";
static char messages__msg__CobotRawStatus__FIELD_NAME__vr[] = "vr";
static char messages__msg__CobotRawStatus__FIELD_NAME__vx[] = "vx";
static char messages__msg__CobotRawStatus__FIELD_NAME__vy[] = "vy";
static char messages__msg__CobotRawStatus__FIELD_NAME__v_batt[] = "v_batt";
static char messages__msg__CobotRawStatus__FIELD_NAME__status[] = "status";

static rosidl_runtime_c__type_description__Field messages__msg__CobotRawStatus__FIELDS[] = {
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__dr, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__dx, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__dy, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__v0, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__v1, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__v2, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__v3, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__vr, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__vx, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__vy, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__v_batt, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {messages__msg__CobotRawStatus__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription messages__msg__CobotRawStatus__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
messages__msg__CobotRawStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {messages__msg__CobotRawStatus__TYPE_NAME, 27, 27},
      {messages__msg__CobotRawStatus__FIELDS, 13, 13},
    },
    {messages__msg__CobotRawStatus__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "float32 dr\n"
  "float32 dx\n"
  "float32 dy\n"
  "float32 v0\n"
  "float32 v1\n"
  "float32 v2\n"
  "float32 v3\n"
  "float32 vr\n"
  "float32 vx\n"
  "float32 vy\n"
  "float32 v_batt\n"
  "int32 status";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
messages__msg__CobotRawStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {messages__msg__CobotRawStatus__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 160, 160},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
messages__msg__CobotRawStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *messages__msg__CobotRawStatus__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
