#pragma once

#include <QLineEdit>

class QAbstractItemModel;
class QKeyEvent;

namespace QGBA {

class HistoryLineEdit : public QLineEdit {
Q_OBJECT

public:
	HistoryLineEdit(QWidget* parent = nullptr);
	virtual ~HistoryLineEdit() = default;

	int activeIndex() const { return m_historyOffset; }

	void setModel(QAbstractItemModel* model);
	QAbstractItemModel* model() const { return m_model; }

signals:
	void indexChanged(int);
	void linePosted(const QString&);
	void emptyLinePosted();

public slots:
	void setIndex(int);
	void appendLine(const QString& string);

protected:
	void keyPressEvent(QKeyEvent*) override;

private:
	QAbstractItemModel* m_model = nullptr;
	int m_historyOffset = 0;
};

}
