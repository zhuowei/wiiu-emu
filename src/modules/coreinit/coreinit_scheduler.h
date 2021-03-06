#pragma once
#include "systemtypes.h"
#include "coreinit_thread.h"

struct OSThread;
struct OSThreadQueue;

void
OSLockScheduler();

void
OSUnlockScheduler();

void
OSRescheduleNoLock();

int32_t
OSResumeThreadNoLock(OSThread *thread, int32_t counter);

void
OSSleepThreadNoLock(OSThreadQueue *queue);

void
OSSuspendThreadNoLock(OSThread *thread);

void
OSTestThreadCancelNoLock();

void
OSWakeupOneThreadNoLock(OSThread *thread);

void
OSWakeupThreadNoLock(OSThreadQueue *queue);

void
OSWakeupThreadWaitForSuspensionNoLock(OSThreadQueue *queue, int32_t suspendResult);

OSThread *
OSSetInterruptThread(uint32_t core, OSThread *thread);

OSThread *
OSGetInterruptThread(uint32_t coreID);

extern ThreadEntryPoint
InterruptThreadEntryPoint;
