#pragma once

#include <QAbstractListModel>

#include <mgba/script/context.h>

struct mScriptTextBuffer;

namespace QGBA {

class ScriptingTextBuffer;

class ScriptingTextBufferModel : public QAbstractListModel {
Q_OBJECT

public:
	enum ItemDataRole {
		DocumentRole = Qt::UserRole + 1,
	};

	ScriptingTextBufferModel(QObject* parent = nullptr);

	void attachToContext(mScriptContext* context);

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

signals:
	void textBufferCreated(ScriptingTextBuffer*);

public slots:
	void reset();

private slots:
	void bufferNameChanged(const QString&);

private:
	static mScriptTextBuffer* createTextBuffer(void* context);

	QList<ScriptingTextBuffer*> m_buffers;
};

}
