#pragma once

#include "input/InputSource.h"

namespace QGBA {

class InputDriver;

class KeySource : public InputSource {
Q_OBJECT

public:
	KeySource(InputDriver* driver, QObject* parent = nullptr);

	virtual QSet<int> currentKeys() = 0;
};

}
