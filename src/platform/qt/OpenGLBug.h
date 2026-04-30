#pragma once

namespace QGBA {

enum class OpenGLBug {
	CROSS_THREAD_FLUSH,       // mgba.io/i/2761
	GLTHREAD_BLOCKS_SWAP,     // mgba.io/i/2767
	IG4ICD_CRASH,             // mgba.io/i/2136
};

bool glContextHasBug(OpenGLBug);

}
