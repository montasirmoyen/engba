#include "input/GamepadHatEvent.h"

#include "InputController.h"

using namespace QGBA;

QEvent::Type GamepadHatEvent::s_downType = QEvent::None;
QEvent::Type GamepadHatEvent::s_upType = QEvent::None;

GamepadHatEvent::GamepadHatEvent(QEvent::Type pressType, int hatId, Direction direction, int type, InputController* controller)
	: QEvent(pressType)
	, m_hatId(hatId)
	, m_direction(direction)
	, m_keys(0)
{
	ignore();
	if (controller) {
		m_keys = mInputMapHat(controller->map(), type, hatId, direction);
	}
}

QEvent::Type GamepadHatEvent::Down() {
	if (s_downType == None) {
		s_downType = static_cast<Type>(registerEventType());
	}
	return s_downType;
}

QEvent::Type GamepadHatEvent::Up() {
	if (s_upType == None) {
		s_upType = static_cast<Type>(registerEventType());
	}
	return s_upType;
}
