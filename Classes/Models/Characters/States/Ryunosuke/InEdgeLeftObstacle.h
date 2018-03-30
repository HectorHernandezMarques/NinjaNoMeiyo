#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INEDGELEFTOBSTACLE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INEDGELEFTOBSTACLE_H

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

					class InEdgeLeftObstacle : public State {
					public:
						InEdgeLeftObstacle(Characters::Ryunosuke &ryunosuke);
						virtual ~InEdgeLeftObstacle();

						void move(Sense sense);
						cocos2d::Action* moveAnimation(Sense sense);
						void stop(Sense sense);
						cocos2d::Action* stopAnimation(Sense sense);
						void jump(Sense sense);
						cocos2d::Action* jumpAnimation(Sense sense);
						void attack(Sense sense);
						cocos2d::Action* attackAnimation(Sense sense);

						void moveAnimationFunction(Sense sense);
						void stopAnimationFunction(Sense sense);
						void jumpAnimationFunction(Sense sense);

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