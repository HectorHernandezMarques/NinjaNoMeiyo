#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INLEFTOBSTACLE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INLEFTOBSTACLE_H

#define MOVE_TEXTURES_NUMBER 3
#define MOVE_ANIMATION_DELAY 0.15

#define CLIMB_TEXTURES_NUMBER 2
#define CLIMB_ANIMATION_DELAY 0.15

#define STOP_TEXTURES_NUMBER 2
#define STOP_ANIMATION_DELAY 0.45

#define RYUNOSUKE_WALL_SPEED 100

#include "./State.h"
#include "../../Ryunosuke.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					class InLeftObstacle : public State {
					public:
						InLeftObstacle(Characters::Ryunosuke &ryunosuke);
						virtual ~InLeftObstacle();

						void move(Controllers::Sense sense);
						cocos2d::Action* moveAnimation(Controllers::Sense sense);
						void stop(Controllers::Sense sense);
						cocos2d::Action* stopAnimation(Controllers::Sense sense);

						void moveAnimationFunction(Controllers::Sense sense);
						void stopAnimationFunction(Controllers::Sense sense);

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