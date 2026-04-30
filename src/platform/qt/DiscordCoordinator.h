#pragma once

#include <memory>

namespace QGBA {

class CoreController;

namespace DiscordCoordinator {

void init();
void deinit();

void gameStarted(std::shared_ptr<CoreController>);
void gameStopped();

}

}