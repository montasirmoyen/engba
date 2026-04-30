#include "ColorPicker.h"

#include <QColorDialog>
#include <QEvent>

using namespace QGBA;

ColorPicker::ColorPicker() {
}

ColorPicker::ColorPicker(QWidget* parent, const QColor& defaultColor)
	: m_parent(parent)
{
	setColor(defaultColor);
	parent->installEventFilter(this);
}

ColorPicker& ColorPicker::operator=(const ColorPicker& other) {
	if (m_parent) {
		m_parent->removeEventFilter(this);
	}
	m_parent = other.m_parent;
	m_defaultColor = other.m_defaultColor;
	m_parent->installEventFilter(this);

	return *this;
}

void ColorPicker::setColor(const QColor& color) {
	m_defaultColor = color;
	m_parent->setStyleSheet(QString("background-color: %1;").arg(color.name()));
}

bool ColorPicker::eventFilter(QObject* obj, QEvent* event) {
	if (event->type() != QEvent::MouseButtonRelease) {
		return false;
	}
	if (obj != m_parent) {
		return false;
	}

	QColorDialog* colorPicker = new QColorDialog;
	colorPicker->setAttribute(Qt::WA_DeleteOnClose);
	colorPicker->setCurrentColor(m_defaultColor);
	colorPicker->open();
	connect(colorPicker, &QColorDialog::colorSelected, [this](const QColor& color) {
		setColor(color);
		emit colorChanged(color);
	});
	return true;
}
