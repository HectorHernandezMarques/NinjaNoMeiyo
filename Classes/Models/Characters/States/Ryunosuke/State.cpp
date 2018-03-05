#include "./State.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					State::State() : animationIndex(0), xVelocityMovement(750), yVelocityJump(0) {
					}

					State::~State() {
					}

				}
			}
		}
	}
}