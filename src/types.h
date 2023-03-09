#ifndef ARRL_TYPES_H
#define ARRL_TYPES_H

#include <stdint.h>


  // ************ //
 //  Primitives  //
// ************ //
typedef uint8_t u8;
typedef int8_t i8;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint32_t u32;
typedef int32_t i32;
typedef float f32;

#ifndef __cplusplus
typedef uint8_t bool;
#endif

#define true (1)
#define false (0)

#define null (0)


typedef struct ArrlApp ArrlApp;

typedef u32 scene_id;

typedef struct GameData {
  float time;
  float delta_time;
  u32 tick;
  u32 scenes_length;
  scene_id scenes[15];
} GameData;

typedef void (*OnStartFn)(const GameData*, void*);
typedef void (*OnUpdateFn)(const GameData*, void*);
typedef void (*OnEndFn)(const GameData*, void*);

#endif // ARRL_TYPES_H