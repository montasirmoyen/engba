#pragma once

#include <QAbstractButton>

namespace QGBA {

class SavestateButton : public QAbstractButton {
public:
	SavestateButton(QWidget* parent = nullptr);

protected:
	virtual void paintEvent(QPaintEvent*) override;
};

}
