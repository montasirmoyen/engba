#pragma once

#include <QWidget>

#include <memory>

#include "ui_ROMInfo.h"

namespace QGBA {

class CoreController;

class ROMInfo : public QDialog {
Q_OBJECT

public:
	ROMInfo(std::shared_ptr<CoreController> controller, QWidget* parent = nullptr);

private:
	Ui::ROMInfo m_ui;
};

}
