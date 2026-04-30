#pragma once

#include "ui_DebuggerConsole.h"

namespace QGBA {

class DebuggerConsoleController;

class DebuggerConsole : public QWidget {
Q_OBJECT

public:
	DebuggerConsole(DebuggerConsoleController* controller, QWidget* parent = nullptr);

private slots:
	void postLine(const QString&);
	void repeat();

private:
	Ui::DebuggerConsole m_ui;

	DebuggerConsoleController* m_consoleController;
};

}
