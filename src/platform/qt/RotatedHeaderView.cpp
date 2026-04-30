#include "RotatedHeaderView.h"

#include <QPainter>

using namespace QGBA;

RotatedHeaderView::RotatedHeaderView(Qt::Orientation orientation, QWidget* parent)
	: QHeaderView(orientation, parent)
{
	int margin = 2 * style()->pixelMetric(QStyle::PM_HeaderMargin, 0, this);
	setMinimumSectionSize(fontMetrics().height() + margin);
}

void RotatedHeaderView::paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const {
	painter->save();
	painter->translate(rect.x() + rect.width(), rect.y());
	painter->rotate(90);
	QHeaderView::paintSection(painter, QRect(0, 0, rect.height(), rect.width()), logicalIndex);
	painter->restore();
}

QSize RotatedHeaderView::sectionSizeFromContents(int logicalIndex) const {
	return QHeaderView::sectionSizeFromContents(logicalIndex).transposed();
}