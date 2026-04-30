#pragma once

#include "ui_ArchiveInspector.h"

struct VFile;

namespace QGBA {

class ArchiveInspector : public QDialog {
Q_OBJECT

public:
	ArchiveInspector(const QString& filename, QWidget* parent = nullptr);

	VFile* selectedVFile() const;
	QPair<QString, QString> selectedPath() const;

private:
	Ui::ArchiveInspector m_ui;
};

}
