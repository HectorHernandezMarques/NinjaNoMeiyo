#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INAIR_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INAIR_H

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

					class InAir : public State {
					public:
						InAir(Characters::Ryunosuke &ryunosuke);
						virtual ~InAir();

						void move(Sense sense);
						cocos2d::Action* moveAnimation(Sense sense);
						void stop(Sense sense);
						cocos2d::Action* stopAnimation(Sense sense);
						void jump(Sense sense);
						cocos2d::Action* jumpAnimation(Sense sense);
						void attack(Sense sense);
						cocos2d::Action* attackAnimation(Sense sense);

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