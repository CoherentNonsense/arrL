#include "../src/arrl.h"

// menu.c
typedef struct MenuData {
  int empty;
} MenuData;

void menu_onStart(const GameData* game_data, void* menu_data) {
  PRINT("Starting...");
  ((MenuData*)menu_data)->empty = 123;
}

void menu_onUpdate(const GameData* game_data, void* menu_data) {
  if (game_data->tick == 50) {
    sceneTransition(game_data->scenes[1]);
  }
}

void menu_onEnd(const GameData* game_data, void* menu_data) {
  PRINT("Ending... %d", ((MenuData*)menu_data)->empty);
}

// main.c
void arrl_setup() {
  registerScene(sizeof(MenuData), menu_onStart, menu_onUpdate, menu_onEnd);
  registerScene(sizeof(MenuData), menu_onStart, menu_onUpdate, menu_onEnd);
}
