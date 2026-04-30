#include "input/InputSource.h"

using namespace QGBA;

InputSource::InputSource(InputDriver* driver, QObject* parent)
	: QObject(parent)
	, m_driver(driver)
{
}
