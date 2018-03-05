#include "./Touch.h"

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {

				Touch::Touch(Models::Input::Touch::Touch &touch, cocos2d::Layer &layer) : Views::Node(touch, layer), pressed(false), initialPosition(touch.getInitialPosition()) {
					assert(&touch);
					assert(&layer);

					this->nodeSprite.setTextureRect(touch.getArea());
				}

				Touch::~Touch() {

				}

				void Touch::setEventDispatcher() {
					this->listener = cocos2d::EventListenerTouchOneByOne::create();
					this->listener->onTouchBegan = CC_CALLBACK_2(Touch::getInitialTouchValues, this);
					this->listener->onTouchMoved = CC_CALLBACK_2(Touch::moveTouch, this);
					this->listener->onTouchEnded = CC_CALLBACK_2(Touch::endMovement, this);
					this->nodeSprite.getEventDispatcher()->addEventListenerWithSceneGraphPriority(this->listener, &this->nodeSprite);
				}

				void Touch::attach(Views::Input::Touch::TouchObserver& nodeObserver) {
					this->touchObservers.push_back(&nodeObserver);
				}

				void Touch::notify(Aspects::Aspect &aspect) {
					for (auto it = this->touchObservers.begin(); it != this->touchObservers.end(); ++it) {
						(*it)->update(aspect);
					}
				}

				void Touch::setPressed(bool pressed) {
					if (pressed != this->pressed) {
						this->pressed = pressed;
						this->notify(*new Aspects::PressAspect(*this, this->pressed));
					}
				}
				bool Touch::getPressed() {
					return this->pressed;
				}
			}
		}
	}
}