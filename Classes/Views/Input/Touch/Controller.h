#ifndef NINJANOMEIYO_VIEWS_INPUT_TOUCH_CONTROLLER_H
#define NINJANOMEIYO_VIEWS_INPUT_TOUCH_CONTROLLER_H

#include "../../../Models/Characters/Ryunosuke.h"
#include "./TouchObserver.h"
#include "../../../Controllers/Characters/CommandDealer.h"

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {

				class Touch;
				class MovementTouch;
			}
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {

				class Controller : public TouchObserver {
				public:
					Controller(cocos2d::Layer &layer, Models::Characters::Ryunosuke& ryunosuke, cocos2d::Size visibleSize);
					virtual ~Controller();

					void update(Aspects::Aspect &aspect);
					void dealInteraction(Touch &touch, bool pressed);

				private:
					Models::Characters::Ryunosuke& ryunosuke;
					cocos2d::Layer &layer;
					Controllers::Characters::CommandDealer ryunosukeCommandDealer;

					NinjaNoMeiyo::Views::Input::Touch::MovementTouch *leftTouchView;
					NinjaNoMeiyo::Views::Input::Touch::MovementTouch *rightTouchView;

				};
			}
		}
	}
}

#endif
