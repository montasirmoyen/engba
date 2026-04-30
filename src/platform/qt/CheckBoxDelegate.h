#pragma once

#include <QStyledItemDelegate>

namespace QGBA {

class CheckBoxDelegate : public QStyledItemDelegate {
public:
	CheckBoxDelegate(QObject* parent = nullptr);

	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
};

}
