#include "coreinit.h"
#include "coreinit_memheap.h"

CoreInit::CoreInit()
{
}

CoreInit::~CoreInit()
{
   CoreFreeDefaultHeap();
}

void
CoreInit::initialise()
{
   initialiseAlarm();
   initialiseDynLoad();
   initialiseEvent();
   initialiseGHS();
   initialiseMembase();
   initialiseMessageQueues();
   initialiseSchedulerFunctions();
   initialiseSystemInformation();
   initialiseThread();
}

void
CoreInit::RegisterFunctions()
{
   registerAlarmFunctions();
   registerCoreFunctions();
   registerCacheFunctions();
   registerDebugFunctions();
   registerDeviceFunctions();
   registerDynLoadFunctions();
   registerEventFunctions();
   registerExceptionFunctions();
   registerExpHeapFunctions();
   registerFastMutexFunctions();
   registerFileSystemFunctions();
   registerFrameHeapFunctions();
   registerGhsFunctions();
   registerMcpFunctions();
   registerMemoryFunctions();
   registerMembaseFunctions();
   registerMemlistFunctions();
   registerMessageQueueFunctions();
   registerMutexFunctions();
   registerSchedulerFunctions();
   registerSemaphoreFunctions();
   registerSharedFunctions();
   registerSpinLockFunctions();
   registerSystemInfoFunctions();
   registerThreadFunctions();
   registerTimeFunctions();
   registerUserConfigFunctions();
}
