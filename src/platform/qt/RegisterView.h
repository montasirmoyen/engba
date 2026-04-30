#pragma once

#include <QMap>
#include <QWidget>

#include <memory>

class QLabel;

namespace QGBA {

class CoreController;

class RegisterView : public QWidget {
Q_OBJECT

public:
	RegisterView(std::shared_ptr<CoreController> controller, QWidget* parent = nullptr);

public slots:
	void updateRegisters();

private:
	void addRegisters(const QStringList& names);
#ifdef M_CORE_GBA
	void updateRegistersARM();
#endif
#ifdef M_CORE_GB
	void updateRegistersSM83();
#endif

	QMap<QString, QLabel*> m_registers;

	std::shared_ptr<CoreController> m_controller;
};

}
