#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INOILRIGHTOBSTACLE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INOILRIGHTOBSTACLE_H

#define RYUNOSUKE_WALL_SPEED 100

#include "./State.h"
#include "../../Ryunosuke.h"
#include "../../Animations/StoppedAnimation.h"
#include "../../Animations/MovingAnimation.h"
#include "../../Animations/JumpingAnimation.h"
#include "../../Animations/ClimbingAnimation.h"
#include "../../Animations/AttackingAnimation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					class InOilRightObstacle : public State {
					public:
						InOilRightObstacle(Characters::Ryunosuke &ryunosuke);
						virtual ~InOilRightObstacle();

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