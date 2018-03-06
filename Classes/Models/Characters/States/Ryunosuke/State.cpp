#include "./State.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					State::State() : animationIndex(0), xVelocityMovement(750), yVelocityJumpFloor(1400), yVelocityJumpWall(950) {
					}

					State::~State() {
					}

				}
			}
		}
	}
}