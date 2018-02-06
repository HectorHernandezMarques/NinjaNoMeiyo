#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATE_H

#include <sstream>
#include "cocos2d.h"

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

						virtual void move(float xVelocity) = 0;
						virtual cocos2d::Action* moveAnimation(float xVelocity) = 0;
						virtual void stop(float xVelocity) = 0;
						virtual cocos2d::Action* stopAnimation(float xVelocity) = 0;
					};
			}
		}
	}
}

#endif