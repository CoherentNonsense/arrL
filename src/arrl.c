#include "arrl.h"
#include "core/app.h"
#include "core/scene.h"

PlaydateAPI* getPlaydate(void) {
  return app.playdate;
}

void registerScene(u32 size, OnStartFn on_start, OnUpdateFn on_update, OnEndFn on_end) {
  SceneManager* scene_manager = app.scene_manager;
  scene_id id = arrl_scene_addScene(scene_manager, size, on_start, on_update, on_end);
  app.game_data.scenes[app.game_data.scenes_length++] = id;
}

void sceneTransition(const scene_id scene_id) {
  SceneManager* scene_manager = app.scene_manager;
  arrl_scene_transition(scene_manager, scene_id);
}
