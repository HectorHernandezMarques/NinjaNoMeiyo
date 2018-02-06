#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_FLOOR_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_FLOOR_H

#define MOVE_TEXTURES_NUMBER 3
#define MOVE_ANIMATION_DELAY 0.15

#define STOP_TEXTURES_NUMBER 2
#define STOP_ANIMATION_DELAY 0.45

#include "./State.h"
#include "../../Ryunosuke.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					class Floor : public State {
					public:
						Floor(Characters::Ryunosuke &ryunosuke);
						virtual ~Floor();

						void move(float xVelocity);
						cocos2d::Action* moveAnimation(float xVelocity);
						void stop(float xVelocity);
						cocos2d::Action* stopAnimation(float xVelocity);

						void moveAnimationFunction(float xVelocity);
						void stopAnimationFunction(float xVelocity);

					protected:

					private:
						Characters::Ryunosuke &ryunosuke;

					};
				}
			}
		}
	}
}

#endif