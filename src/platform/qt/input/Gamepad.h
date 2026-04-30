#pragma once

#include "GamepadHatEvent.h"
#include "input/InputSource.h"

namespace QGBA {

class InputDriver;

class Gamepad : public InputSource {
Q_OBJECT

public:
	Gamepad(InputDriver* driver, QObject* parent = nullptr);

	virtual QList<bool> currentButtons() const = 0;
	virtual QList<int16_t> currentAxes() const = 0;
	virtual QList<GamepadHatEvent::Direction> currentHats() const = 0;

	virtual QString buttonHumanName(int) const = 0;
	virtual QString axisHumanName(int) const = 0;

	virtual int buttonCount() const = 0;
	virtual int axisCount() const = 0;
	virtual int hatCount() const = 0;
};

}
