#ifndef SCENE_H
#define SCENE_H

#include "../types.h"

typedef struct SceneManager SceneManager;
typedef struct Scene Scene;

SceneManager* arrl_scene_newSceneManager(void);

void arrl_scene_deleteSceneManager(SceneManager* scene_manager);

void arrl_scene_updateSceneManager(SceneManager* scene_manager);

scene_id arrl_scene_addScene(
  SceneManager* scene_manager,
  const u32 scene_data_size,
  const OnStartFn on_start,
  const OnUpdateFn on_update,
  const OnEndFn on_end
);

void arrl_scene_transition(SceneManager* scene_manager, const scene_id scene_id);

#endif // SCENE_H