#pragma once

#include <QDialog>

#include "ui_AboutScreen.h"

namespace QGBA {

class AboutScreen : public QDialog {
Q_OBJECT

public:
	AboutScreen(QWidget* parent = nullptr);

private:
	Ui::AboutScreen m_ui;
};

}
