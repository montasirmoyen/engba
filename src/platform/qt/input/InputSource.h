#pragma once

#include <QObject>
#include <QString>

#include "input/InputDriver.h"

namespace QGBA {

class InputSource : public QObject {
Q_OBJECT

public:
	InputSource(InputDriver* driver, QObject* parent = nullptr);
	virtual ~InputSource() = default;

	InputDriver* driver() { return m_driver; }
	uint32_t type() { return m_driver->type(); }

	virtual QString name() const = 0;
	virtual QString visibleName() const = 0;
	virtual QString serial() const = 0;

protected:
	InputDriver* const m_driver;
};

}
