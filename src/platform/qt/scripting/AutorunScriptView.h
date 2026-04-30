#pragma once

#include "ui_AutorunScriptView.h"

namespace QGBA {

class AutorunScriptModel;
class ScriptingController;

class AutorunScriptView : public QDialog {
Q_OBJECT

public:
	AutorunScriptView(AutorunScriptModel* model, ScriptingController* controller, QWidget* parent = nullptr);
	void removeScript(const QModelIndex&);

private slots:
	void addScript();
	void removeScript();
	void moveUp();
	void moveDown();

private:
	Ui::AutorunScriptView m_ui;
	ScriptingController* m_controller;
};

}
