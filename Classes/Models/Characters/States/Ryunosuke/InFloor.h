#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INFLOOR_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INFLOOR_H

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

					class InFloor : public State {
					public:
						InFloor(Characters::Ryunosuke &ryunosuke);
						virtual ~InFloor();

						void move(Controllers::Sense sense);
						cocos2d::Action* moveAnimation(Controllers::Sense sense);
						void stop(Controllers::Sense sense);
						cocos2d::Action* stopAnimation(Controllers::Sense sense);
						void jump(Controllers::Sense sense);
						cocos2d::Action* jumpAnimation(Controllers::Sense sense);

						void moveAnimationFunction(Controllers::Sense sense);
						void stopAnimationFunction(Controllers::Sense sense);
						void jumpAnimationFunction(Controllers::Sense sense);

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