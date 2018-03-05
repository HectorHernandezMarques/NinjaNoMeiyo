#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_STATE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_STATE_H

#include <sstream>
#include "cocos2d.h"
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
						float yVelocityJump;

						void jump(Controllers::Sense sense) {};
						cocos2d::Action* jumpAnimation(Controllers::Sense sense) {};

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