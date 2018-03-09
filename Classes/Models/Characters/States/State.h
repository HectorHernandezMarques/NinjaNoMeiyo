#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATE_H

#include <sstream>
#include "cocos2d.h"
#include "../Sense.h"

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
						virtual cocos2d::Action* moveAnimation(Sense sense) = 0;
						virtual void stop(Sense sense) = 0;
						virtual cocos2d::Action* stopAnimation(Sense sense) = 0;
						virtual void jump(Sense sense) = 0;
						virtual cocos2d::Action* jumpAnimation(Sense sense) = 0;

					};
			}
		}
	}
}

#endif