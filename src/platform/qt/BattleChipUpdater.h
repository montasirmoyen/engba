#pragma once

#include "AbstractUpdater.h"

namespace QGBA {

class BattleChipUpdater : public AbstractUpdater {
public:
	BattleChipUpdater(QObject* parent = nullptr);

protected:
	virtual QUrl manifestLocation() const override;
	virtual QUrl parseManifest(const QByteArray&) override;
	virtual QString destination() const override;
};

}
