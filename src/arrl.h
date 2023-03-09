#ifndef ARRL_H
#define ARRL_H

#include "pd_api.h"
#include "types.h"
#include "entry.h"
#include "core/scene.h"

GameData getGameData(void);
PlaydateAPI* getPlaydate(void);

#define ALLOC(size) getPlaydate()->system->realloc(NULL, size)
#define FREE(ptr) getPlaydate()->system->realloc(ptr, 0)
#define REALLOC(...) getPlaydate()->system->realloc(__VA_ARGS__)
#define PRINT(...) getPlaydate()->system->logToConsole(__VA_ARGS__)

void registerScene(u32 size, OnStartFn on_start, OnUpdateFn on_update, OnEndFn on_end);

void sceneTransition(const scene_id scene_id);

#endif // ARRL_H