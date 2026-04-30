#pragma once

#include <QObject>

#include <memory>

struct mDebuggerModule;

namespace QGBA {

class CoreController;

class DebuggerController : public QObject {
Q_OBJECT

public:
	DebuggerController(mDebuggerModule* debugger, QObject* parent = nullptr);

public:
	bool isAttached();
	void setController(std::shared_ptr<CoreController>);

public slots:
	virtual void attach();
	virtual void detach();
	virtual void breakInto();
	virtual void shutdown();

protected:
	virtual void attachInternal();
	virtual void shutdownInternal();

	mDebuggerModule* const m_debugger;
	std::shared_ptr<CoreController> m_gameController;

private:
	bool m_autoattach = false;
};

}
