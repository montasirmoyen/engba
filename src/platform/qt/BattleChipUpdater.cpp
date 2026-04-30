#include "BattleChipUpdater.h"

#include "ConfigController.h"
#include "GBAApp.h"

#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace QGBA;

BattleChipUpdater::BattleChipUpdater(QObject* parent)
	: AbstractUpdater(parent)
{
}

QUrl BattleChipUpdater::manifestLocation() const {
	return {"https://api.github.com/repos/mgba-emu/chip-assets/releases/latest"};
}

QUrl BattleChipUpdater::parseManifest(const QByteArray& manifest) {
	QJsonDocument manifestDoc(QJsonDocument::fromJson(manifest));
	if (manifestDoc.isNull()) {
		return QUrl();
	}
	for (const auto& assetv : manifestDoc.object()["assets"].toArray()) {
		QJsonObject asset = assetv.toObject();
		if (asset["name"].toString() == "chips.rcc") {
			return asset["browser_download_url"].toString();
		}
	}
	return QUrl();
}

QString BattleChipUpdater::destination() const {
	QFileInfo info(GBAApp::dataDir() + "/chips.rcc");
	if (info.isWritable()) {
		return info.filePath();
	}
	return ConfigController::configDir() + "/chips.rcc";
}
