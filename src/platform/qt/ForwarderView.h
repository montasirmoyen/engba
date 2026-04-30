#pragma once

#include "ForwarderController.h"
#include "ForwarderGenerator.h"

#include <QImage>
#include <QVector>

#include "ui_ForwarderView.h"

namespace QGBA {

class ForwarderView : public QDialog {
Q_OBJECT

public:
	ForwarderView(QWidget* parent = nullptr);

private slots:
	void build();
	void validate();

private:
	void setSystem(ForwarderGenerator::System);
	void connectBrowseButton(QAbstractButton* button, QLineEdit* lineEdit, const QString& title, bool save = false, const QString& filter = {});
	void selectImage();
	void setActiveImage(int);
	void updateProgress();

	ForwarderController m_controller;
	QVector<QImage> m_images;
	int m_currentImage;
	QSize m_activeSize;

	qreal m_downloadProgress;
	ForwarderController::Download m_currentDownload;
	bool m_needsForwarderKit;

	Ui::ForwarderView m_ui;
};

}
