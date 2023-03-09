#include <pd_api.h>

#include "entry.h"
#include "core/app.h"


  // ********************** //
 //  Playdate Entry Point  //
// ********************** //
static int onUpdate(void* _) {
  arrl_app_update();

  // TODO: Return 0 if no screen updates happened.
  return 1;
}

static void onStart(PlaydateAPI* playdate) {
  arrl_app_init(playdate);
  
  arrl_setup();

  playdate->system->setUpdateCallback(onUpdate, onUpdate);
}

static void onEnd(void) {
  arrl_app_terminate();
}


#ifdef _WINDLL
__declspec(dllexport)
#endif
int eventHandler(PlaydateAPI* playdate, PDSystemEvent event, uint32_t arg) {
  switch (event) {
    case kEventInit: onStart(playdate); break;
    case kEventTerminate: onEnd(); break;
    default: break;
  }
  
  return 0;
}