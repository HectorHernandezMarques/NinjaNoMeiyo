#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATE_H

#include <sstream>
#include "cocos2d.h"
#include "../Sense.h"
#include "../Animations/Animation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {

					class State {
					public:
						std::string to_string(int num) {
							std::ostringstream ss;
							ss << num;
							return ss.str();
						}

						virtual void move(Sense sense) = 0;
						virtual Animations::Animation* moveAnimation(Sense sense) = 0;
						virtual void stop(Sense sense) = 0;
						virtual Animations::Animation* stopAnimation(Sense sense) = 0;
						virtual void jump(Sense sense) = 0;
						virtual Animations::Animation* jumpAnimation(Sense sense) = 0;
						virtual void attack(Sense sense) = 0;
						virtual Animations::Animation* attackAnimation(Sense sense) = 0;

					};
			}
		}
	}
}

#endif