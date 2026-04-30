#include "GDBController.h"

#include "CoreController.h"

using namespace QGBA;

GDBController::GDBController(QObject* parent)
	: DebuggerController(&m_gdbStub.d, parent)
	, m_bindAddress({ IPV4, {0} })
{
	GDBStubCreate(&m_gdbStub);
}

ushort GDBController::port() {
	return m_port;
}

void GDBController::setPort(ushort port) {
	m_port = port;
}

void GDBController::setBindAddress(const Address& address) {
	m_bindAddress = address;
}

void GDBController::setWatchpointsBehavior(int watchpointsBehaviorId) {
	m_watchpointsBehavior = static_cast<GDBWatchpointsBehvaior>(watchpointsBehaviorId);
}

void GDBController::listen() {
	if (GDBStubListen(&m_gdbStub, m_port, &m_bindAddress, m_watchpointsBehavior)) {
		if (!isAttached()) {
			attach();
		}
		emit listening();
	} else {
		detach();
		emit listenFailed();
	}
}

void GDBController::shutdownInternal() {
	GDBStubShutdown(&m_gdbStub);
}
