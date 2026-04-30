#pragma once

#include <QDialog>
#include <QList>

#include <memory>

#include "ui_PlacementControl.h"

namespace QGBA {

class CoreController;

class PlacementControl : public QDialog {
Q_OBJECT

public:
	PlacementControl(std::shared_ptr<CoreController>, QWidget* parent = nullptr);

private:
	void adjustLayer(int layer, int32_t x, int32_t y);

	std::shared_ptr<CoreController> m_controller;
	QList<QPair<QSpinBox*, QSpinBox*>> m_layers;

	Ui::PlacementControl m_ui;
};

}
