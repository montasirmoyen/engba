#include <mgba/core/lockstep.h>

#ifndef DISABLE_THREADING
#include <mgba/core/thread.h>
#endif

void mLockstepInit(struct mLockstep* lockstep) {
	lockstep->attached = 0;
	lockstep->transferActive = static_cast<enum mLockstepPhase>(0);
#ifndef NDEBUG
	lockstep->transferId = 0;
#endif
	lockstep->lock = NULL;
	lockstep->unlock = NULL;
}

void mLockstepDeinit(struct mLockstep* lockstep) {
	UNUSED(lockstep);
}

#ifndef DISABLE_THREADING
static void mLockstepThreadUserSleep(struct mLockstepUser* user) {
	struct mLockstepThreadUser* lockstep = (struct mLockstepThreadUser*) user;
	mCoreThreadWaitFromThread(lockstep->thread);
}

static void mLockstepThreadUserWake(struct mLockstepUser* user) {
	struct mLockstepThreadUser* lockstep = (struct mLockstepThreadUser*) user;
	mCoreThreadStopWaiting(lockstep->thread);
}

void mLockstepThreadUserInit(struct mLockstepThreadUser* lockstep, struct mCoreThread* thread) {
	memset(lockstep, 0, sizeof(*lockstep));
	lockstep->d.sleep = mLockstepThreadUserSleep;
	lockstep->d.wake = mLockstepThreadUserWake;
	lockstep->thread = thread;
}
#endif
