#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATE_H

#include <sstream>
#include "cocos2d.h"
#include "../../../Controllers/Sense.h"

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

						virtual void move(Controllers::Sense sense) = 0;
						virtual cocos2d::Action* moveAnimation(Controllers::Sense sense) = 0;
						virtual void stop(Controllers::Sense sense) = 0;
						virtual cocos2d::Action* stopAnimation(Controllers::Sense sense) = 0;
						virtual void jump(Controllers::Sense sense) = 0;
						virtual cocos2d::Action* jumpAnimation(Controllers::Sense sense) = 0;
					};
			}
		}
	}
}

#endif