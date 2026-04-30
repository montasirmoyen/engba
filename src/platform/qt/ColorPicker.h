#pragma once

#include <QColor>
#include <QObject>

class QWidget;

namespace QGBA {

class ColorPicker : public QObject {
Q_OBJECT

public:
	ColorPicker();
	ColorPicker(QWidget* parent, const QColor& defaultColor);

	ColorPicker& operator=(const ColorPicker&);

signals:
	void colorChanged(const QColor&);

public slots:
	void setColor(const QColor&);

protected:
	bool eventFilter(QObject* obj, QEvent* event) override;

private:
	QWidget* m_parent = nullptr;
	QColor m_defaultColor;
};

}
