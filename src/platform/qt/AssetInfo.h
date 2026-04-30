#pragma once

#include <QGroupBox>
#include <QHash>
#include <QLabel>
#include <QVariant>

namespace QGBA {

class CoreController;

class AssetInfo : public QGroupBox {
Q_OBJECT

public:
	AssetInfo(QWidget* parent = nullptr);
	void addCustomProperty(const QString& id, const QString& visibleName);

public slots:
	void setCustomProperty(const QString& id, const QVariant& value);

protected:
	virtual int customLocation(const QString& id = {});

private:
	QHash<QString, QLabel*> m_customProperties;
};

}
