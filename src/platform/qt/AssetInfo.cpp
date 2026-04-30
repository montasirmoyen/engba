#include "AssetInfo.h"

#include "GBAApp.h"

#include <QHBoxLayout>

using namespace QGBA;

AssetInfo::AssetInfo(QWidget* parent)
	: QGroupBox(parent)
{
}

void AssetInfo::addCustomProperty(const QString& id, const QString& visibleName) {
	QHBoxLayout* newLayout = new QHBoxLayout;
	newLayout->addWidget(new QLabel(visibleName));
	QLabel* value = new QLabel;
	value->setFont(GBAApp::app()->monospaceFont());
	value->setAlignment(Qt::AlignRight);
	value->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
	newLayout->addWidget(value);
	m_customProperties[id] = value;
	int index = customLocation();
	static_cast<QBoxLayout*>(layout())->insertLayout(index, newLayout);
}

void AssetInfo::setCustomProperty(const QString& id, const QVariant& value) {
	QLabel* label = m_customProperties[id];
	if (!label) {
		return;
	}
	label->setText(value.toString());
}

int AssetInfo::customLocation(const QString&) {
	return layout()->count();
}
