#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INFLOORANDRIGHTOBSTACLE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INFLOORANDRIGHTOBSTACLE_H

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

					class InFloorAndRightObstacle : public State {
					public:
						InFloorAndRightObstacle(Characters::Ryunosuke &ryunosuke);
						virtual ~InFloorAndRightObstacle();

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