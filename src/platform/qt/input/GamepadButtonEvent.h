#pragma once

#include <QEvent>

namespace QGBA {

class InputController;

class GamepadButtonEvent : public QEvent {
public:
	GamepadButtonEvent(Type pressType, int button, int type, InputController* controller = nullptr);

	int value() const { return m_button; }
	int platformKey() const { return m_key; }

	static Type Down();
	static Type Up();

private:
	static Type s_downType;
	static Type s_upType;

	int m_button;
	int m_key;
};

}
