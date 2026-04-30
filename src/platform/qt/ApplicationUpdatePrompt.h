#pragma once

#include <QDialog>

#include "ui_ApplicationUpdatePrompt.h"

namespace QGBA {

class ApplicationUpdatePrompt : public QDialog {
Q_OBJECT

public:
	ApplicationUpdatePrompt(QWidget* parent = nullptr);

private slots:
	void startUpdate();
	void promptRestart();

private:
	Ui::ApplicationUpdatePrompt m_ui;
	QMetaObject::Connection m_okDownload;
};

}
