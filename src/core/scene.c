#include "scene.h"

#include "../arrl.h"
#include "app.h"

typedef struct Scene {
  void* data;
  u32 data_size;
  OnStartFn on_start;
  OnUpdateFn on_update;
  OnEndFn on_end;
} Scene;

typedef struct SceneManager {
  bool running;
  Scene scenes[10];
  u32 scenes_length;
  scene_id current_scene_id;
  scene_id next_scene_id;
} SceneManager;

SceneManager* arrl_scene_newSceneManager(void) {
  SceneManager* scene_manager = ALLOC(sizeof(SceneManager));

  scene_manager->running = 0;
  
  scene_manager->scenes_length = 0;
  
  scene_manager->current_scene_id = 0;
  scene_manager->next_scene_id = 0;

  return scene_manager;
}

void arrl_scene_deleteSceneManager(SceneManager* scene_manager) {
  Scene* scene = &scene_manager->scenes[scene_manager->current_scene_id];
  if (scene_manager->running && scene->on_end != null) {
    scene->on_end(&app.game_data, scene->data);
  }

  FREE(scene_manager);
}

void arrl_scene_updateSceneManager(SceneManager* scene_manager) {
  if (scene_manager->running && scene_manager->next_scene_id == scene_manager->current_scene_id) {  
    Scene* scene = &scene_manager->scenes[scene_manager->current_scene_id];
  
    if (scene->on_update != null) {
      scene->on_update(&app.game_data, scene->data);
    }

    return;
  }

  // Scene Transition
  // End old scene
  if (scene_manager->running) {
    Scene* old_scene = &scene_manager->scenes[scene_manager->current_scene_id];
    if (old_scene->on_end != null) {
      old_scene->on_end(&app.game_data, old_scene->data);
    }
    FREE(scene_manager->scenes[scene_manager->current_scene_id].data);
  } else {
    scene_manager->running = true;
  }

  // Create new scene
  scene_manager->current_scene_id = scene_manager->next_scene_id;
  Scene* scene = &scene_manager->scenes[scene_manager->current_scene_id];
  scene->data = ALLOC(scene->data_size);
  memset(scene->data, 0, scene->data_size);
  
  if (scene->on_start != null) {
    scene->on_start(&app.game_data, scene->data);
  }
}

scene_id arrl_scene_addScene(
  SceneManager* scene_manager,
  const u32 scene_data_size,
  const OnStartFn on_start,
  const OnUpdateFn on_update,
  const OnEndFn on_end
) {
  const scene_id id = scene_manager->scenes_length;
  Scene* new_scene = &scene_manager->scenes[id];
  new_scene->data_size = scene_data_size;
  new_scene->on_start = on_start;
  new_scene->on_update = on_update;
  new_scene->on_end = on_end;
  
  scene_manager->scenes_length += 1;

  scene_manager->current_scene_id = id;

  return id;
}

void arrl_scene_transition(SceneManager* scene_manager, const scene_id scene_id) {
  scene_manager->next_scene_id = scene_id;
}
