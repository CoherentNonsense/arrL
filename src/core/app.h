#ifndef ARRL_APP_H
#define ARRL_APP_H

#include "modules.h"
#include "scene.h"
#include <pd_api.h>

typedef struct ArrlApp {
  PlaydateAPI* playdate;
  GameData game_data;
  SceneManager* scene_manager;
} ArrlApp;

extern ArrlApp app;

ArrlApp* arrl_app_init(PlaydateAPI* playdate);
void arrl_app_terminate(void);
void arrl_app_update(void);

#endif // ARRL_APP_H