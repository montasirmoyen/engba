#pragma once

#include "ui_DolphinConnector.h"

#include <memory>

namespace QGBA {

class CoreController;
class Window;

class DolphinConnector : public QDialog {
Q_OBJECT

public:
	DolphinConnector(Window* window, QWidget* parent = nullptr);

public slots:
	void attach();
	void detach();

private slots:
	void updateAttached();

private:
	Ui::DolphinConnector m_ui;

	std::shared_ptr<CoreController> m_controller;
	Window* m_window;
};

}
