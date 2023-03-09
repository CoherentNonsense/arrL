#include "app.h"

ArrlApp app;

ArrlApp* arrl_app_init(PlaydateAPI* pd) {
  app.playdate = pd;

  app.scene_manager = arrl_scene_newSceneManager();

  return &app;
}

void arrl_app_terminate(void) {
  arrl_scene_deleteSceneManager(app.scene_manager);
}

void arrl_app_update(void) {
  f32 current_time = (float)app.playdate->system->getCurrentTimeMilliseconds();
  app.game_data.delta_time = current_time - app.game_data.time;
  app.game_data.time = current_time;

  arrl_scene_updateSceneManager(app.scene_manager);

  app.game_data.tick += 1;
}