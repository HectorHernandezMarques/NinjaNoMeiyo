#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_UNKNOWN_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_RYUNOSUKE_UNKNOWN_H

#include "./State.h"
#include "../../Ryunosuke.h"
#include "../../Animations/NoAnimation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					class UnknownState : public State {
					public:
						UnknownState(Characters::Ryunosuke &ryunosuke);
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
						Characters::Ryunosuke &ryunosuke;

					};
				}
			}
		}
	}
}

#endif