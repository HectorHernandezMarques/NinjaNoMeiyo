#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INAIR_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_INAIR_H

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