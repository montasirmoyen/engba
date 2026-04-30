#pragma once

#include <QByteArray>
#include <QFile>
#include <QObject>

class QNetworkReply;

namespace QGBA {

class AbstractUpdater : public QObject {
Q_OBJECT

public:
	AbstractUpdater(QObject* parent = nullptr);
	virtual ~AbstractUpdater() {}

public slots:
	void checkUpdate();
	void downloadUpdate();

signals:
	void updateAvailable(bool);
	void updateDone(bool);
	void updateProgress(float done);

protected:
	virtual QUrl manifestLocation() const = 0;
	virtual QUrl parseManifest(const QByteArray&) = 0;
	virtual QString destination() const = 0;

private slots:
	void progress(qint64 progress, qint64 max);

private:
	void chaseRedirects(QNetworkReply*, void (AbstractUpdater::*cb)(QNetworkReply*));
	void manifestDownloaded(QNetworkReply*);
	void updateDownloaded(QNetworkReply*);

	bool m_isUpdating = false;
	QByteArray m_manifest;
};

}
