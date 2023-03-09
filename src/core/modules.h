#ifndef MODULES_H
#define MODULES_H

#include "../types.h"

typedef struct ArrlApp ArrlApp;

typedef void (*ModuleOnStartFn)(void*);
typedef void (*ModuleOnUpdateFn)(void*);
typedef void (*ModuleOnEndFn)(void*);

typedef struct Module {
  u32 data_size;
  ModuleOnStartFn on_start;
  ModuleOnUpdateFn on_update;
  ModuleOnEndFn on_end;
} Module;

typedef struct ModuleManager {
  Module* modules;
} ModuleManager;

void arrl_module_register(ModuleManager* modules, const u32 size, const ModuleOnStartFn on_start, const ModuleOnUpdateFn on_update, const ModuleOnEndFn on_end);

void arrl_module_start(ModuleManager* modules);
void arrl_module_update(ModuleManager* modules);
void arrl_module_end(ModuleManager* modules);

#endif