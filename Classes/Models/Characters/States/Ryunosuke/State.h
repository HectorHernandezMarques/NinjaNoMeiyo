#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_STATE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_STATE_H

#include "../State.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					class State : public States::State {
					protected:
						int animationIndex;
						float xVelocityMovement;
						float yVelocityJumpFloor;
						float yVelocityJumpWall;

					public:
						State();
						virtual ~State();
					};
				}
			}
		}
	}
}

#endif