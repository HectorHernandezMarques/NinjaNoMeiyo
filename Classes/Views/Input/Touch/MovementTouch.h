#ifndef NINJANOMEIYO_VIEWS_INPUT_TOUCH_MOVEMENTTOUCH_H
#define NINJANOMEIYO_VIEWS_INPUT_TOUCH_MOVEMENTTOUCH_H

#define TOUCH_UPPER_JUMP 20
#define TOUCH_UPPER_JUMP_2 10
#define TOUCH_RIGHT_JUMP 30
#define TOUCH_LEFT_JUMP 30
#define TOUCH_RIGHT_ATTACK 10
#define TOUCH_LEFT_ATTACK 10

#include "./Touch.h"
#include "../../../Models/Characters/Sense.h"
#include "../../../Controllers/Character/Stopper.h"
#include "../../../Controllers/Character/Mover.h"
#include "../../../Controllers/Character/Jumper.h"
#include "../../../Controllers/Character/Attacker.h"
#include "../../../Models/Characters/Ryunosuke.h"

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {

				class MovementTouch : public Touch {
				public:
					MovementTouch(Models::Input::Touch::Touch &touch, cocos2d::Layer &layer, Models::Characters::Sense sense, Models::Characters::Ryunosuke& ryunosuke, Controllers::Character::CommandDealer &commandDealer);
					virtual ~MovementTouch();

					void press();
					void unpress();

				protected:
					bool getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event);
					void moveTouch(cocos2d::Touch* touch, cocos2d::Event* event);
					void endMovement(cocos2d::Touch* touch, cocos2d::Event* event);

				private:
					std::mutex mDoubleTouch, mForcingUntouch, mGestureMade;
					/*we want to avoid the user touching the same touch detector twice*/
					/*we want to force the user to stop to touch the screen once he has made a gesture*/

					Models::Characters::Ryunosuke& ryunosuke;
					Controllers::Character::CommandDealer& commandDealer;
					Models::Characters::Sense sense;

				};
			}
		}
	}
}

#endif //NINJANOMEIYO_MOVEMENT_TOUCH_H
