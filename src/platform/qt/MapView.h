#pragma once

#include "AssetView.h"

#include "ui_MapView.h"

#include <mgba/core/map-cache.h>

namespace QGBA {

class CoreController;

class MapView : public AssetView {
Q_OBJECT

public:
	MapView(std::shared_ptr<CoreController> controller, QWidget* parent = nullptr);

public slots:
	void exportMap();
	void copyMap();

private slots:
	void selectMap(int);
	void selectTile(int x, int y);

protected:
	bool eventFilter(QObject*, QEvent*) override;

private:
#ifdef M_CORE_GBA
	void updateTilesGBA(bool force) override;
#endif
#ifdef M_CORE_GB
	void updateTilesGB(bool force) override;
#endif

	Ui::MapView m_ui;

	std::shared_ptr<CoreController> m_controller;
	QVector<mMapCacheEntry> m_mapStatus;
	QVector<mBitmapCacheEntry> m_bitmapStatus{512 * 2}; // TODO: Correct size
	int m_map = 0;
	QImage m_rawMap;
	int m_boundary;
	int m_addressBase;
	int m_addressWidth;
};

}
