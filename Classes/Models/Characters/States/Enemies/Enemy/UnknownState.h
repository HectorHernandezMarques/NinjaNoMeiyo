#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_ENEMIES_ENEMY_UNKNOWNSTATE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_ENEMIES_ENEMY_UNKNOWNSTATE_H

#include "./State.h"
#include "../../../Enemies/Enemy.h"
#include "../../../Animations/NoAnimation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Enemies {
					namespace Enemy {

						class UnknownState : public State {
						public:
							UnknownState(Characters::Enemies::Enemy &enemy);
							virtual ~UnknownState();

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
							Characters::Enemies::Enemy &enemy;

						};
					}
				}
			}
		}
	}
}

#endif