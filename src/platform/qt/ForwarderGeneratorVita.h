#pragma once

#include "ForwarderGenerator.h"

struct VDir;
struct VFile;

namespace QGBA {

class ForwarderGeneratorVita final : public ForwarderGenerator {
Q_OBJECT

public:
	ForwarderGeneratorVita();

	QList<QPair<QString, QSize>> imageTypes() const override;
	System system() const override { return System::VITA; }
	QString extension() const override { return QLatin1String("vpk"); }

	void rebuild(const QString& source, const QString& target) override;

private:
	bool copyAssets(const QString& vpk, VDir* out);
	QString makeSerial() const;
	void writeSfo(VFile* out);
	void injectImage(VDir* out, const char* name, int index);
};

}
