#pragma once

#include <QList>
#include <QString>

#ifdef M_CORE_GB
#include <mgba/gb/interface.h>

namespace QGBA {

namespace GameBoy {
	QList<GBModel> modelList();
	QString modelName(GBModel);

	QList<GBMemoryBankControllerType> mbcList();
	QString mbcName(GBMemoryBankControllerType);
}

}
#endif
