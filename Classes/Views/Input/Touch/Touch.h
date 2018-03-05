#ifndef NINJANOMEIYO_VIEWS_INPUT_TOUCH_TOUCH_H
#define NINJANOMEIYO_VIEWS_INPUT_TOUCH_TOUCH_H

#include "../../Node.h"
#include "../../../Models/Input/Touch/Touch.h"
#include "./TouchObserver.h"
#include "./Aspects/PressAspect.h"

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {

				class Touch : public Node {
				public:
					Touch(Models::Input::Touch::Touch &node, cocos2d::Layer &layer);
					virtual ~Touch();

					void setEventDispatcher();
					void attach(Views::Input::Touch::TouchObserver& nodeObserver);
					void notify(Aspects::Aspect &aspect);
					void setPressed(bool pressed);
					bool getPressed();
					virtual void press() = 0;
					virtual void unpress() = 0;

				protected:
					std::mutex mPressed;
					bool pressed;
					cocos2d::Vec2 initialPosition;
					cocos2d::Vec2 positionVariation;
					cocos2d::Vec2 initialTouchPosition;
					cocos2d::EventListenerTouchOneByOne *listener;

					virtual bool getInitialTouchValues(cocos2d::Touch *touch, cocos2d::Event *event) = 0;
					virtual void moveTouch(cocos2d::Touch *touch, cocos2d::Event *event) = 0;
					virtual void endMovement(cocos2d::Touch *touch, cocos2d::Event *event) = 0;

				private:
					std::list<Views::Input::Touch::TouchObserver*> touchObservers;

				};
			}
		}
	}
}

#endif