#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INRIGHTOBSTACLE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INRIGHTOBSTACLE_H

#define RYUNOSUKE_WALL_SPEED 100

#include "./State.h"
#include "../../Ryunosuke.h"
#include "../../Animations/StoppedAnimation.h"
#include "../../Animations/MovingAnimation.h"
#include "../../Animations/JumpingAnimation.h"
#include "../../Animations/JumpingOnWallAnimation.h"
#include "../../Animations/ClimbingAnimation.h"
#include "../../Animations/ClimbingOilAnimation.h"
#include "../../Animations/AttackingAnimation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					class InRightObstacle : public State {
					public:
						InRightObstacle(Characters::Ryunosuke &ryunosuke);
						virtual ~InRightObstacle();

						void move(Sense sense);
						Animations::Animation* moveAnimation(Sense sense);
						void stop(Sense sense);
						Animations::Animation* stopAnimation(Sense sense);
						void jump(Sense sense);
						Animations::Animation* jumpAnimation(Sense sense);
						void attack(Sense sense);
						Animations::Animation* attackAnimation(Sense sense);

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