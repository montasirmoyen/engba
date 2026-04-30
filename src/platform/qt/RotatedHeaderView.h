#pragma once

#include <QHeaderView>

namespace QGBA {

class RotatedHeaderView : public QHeaderView {
Q_OBJECT

public:
	RotatedHeaderView(Qt::Orientation orientation, QWidget* parent = nullptr);

protected:
	void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const override;
	QSize sectionSizeFromContents(int logicalIndex) const override;
};

}
