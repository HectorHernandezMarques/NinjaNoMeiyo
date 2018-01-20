#include "./Command.h"

namespace NinjaNoMeiyo {
	namespace Controllers {

		Command::Command(bool stoppable) : stoppable(stoppable), animationAction(nullptr) {
		}

		Command::~Command() {
		}

		bool Command::isStoppable() {
			return this->stoppable;
		}
	}
}