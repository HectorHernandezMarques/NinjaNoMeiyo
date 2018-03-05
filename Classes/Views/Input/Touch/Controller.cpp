#include "./Controller.h"
#include "./MovementTouch.h"

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {

				Controller::Controller(cocos2d::Layer &layer, Models::Characters::Ryunosuke& ryunosuke, cocos2d::Size visibleSize) :
					layer(layer), ryunosuke(ryunosuke), ryunosukeCommandDealer(){

					NinjaNoMeiyo::Models::Input::Touch::Touch *leftTouch = new NinjaNoMeiyo::Models::Input::Touch::Touch(cocos2d::Vec2::ZERO, cocos2d::Rect(0.0, 0.0, visibleSize.width / 2, visibleSize.height));
					NinjaNoMeiyo::Models::Input::Touch::Touch *rightTouch = new NinjaNoMeiyo::Models::Input::Touch::Touch(cocos2d::Vec2(visibleSize.width / 2, 0), cocos2d::Rect(visibleSize.width / 2, 0.0, visibleSize.width / 2, visibleSize.height));

					this->leftTouchView = new NinjaNoMeiyo::Views::Input::Touch::MovementTouch(*leftTouch, layer, NinjaNoMeiyo::Controllers::Sense::LEFT, ryunosuke, ryunosukeCommandDealer);
					this->rightTouchView = new NinjaNoMeiyo::Views::Input::Touch::MovementTouch(*rightTouch, layer, NinjaNoMeiyo::Controllers::Sense::RIGHT, ryunosuke, ryunosukeCommandDealer);

					this->leftTouchView->spawn();
					this->rightTouchView->spawn();

					this->leftTouchView->setEventDispatcher();
					this->rightTouchView->setEventDispatcher();

					this->leftTouchView->attach(*this);
					this->rightTouchView->attach(*this);

				}

				Controller::~Controller() {

				}

				void Controller::update(Aspects::Aspect &aspect) {
					aspect.visit(*this);
				}

				void Controller::dealInteraction(Touch &touch, bool pressed) {
					if (pressed) {
						touch.press();
					}
					else {
						if (&touch == this->leftTouchView) {
							if (this->rightTouchView->getPressed()) {
								this->rightTouchView->press();
							}
							else {
								touch.unpress();
							}
						}
						else if (&touch == this->rightTouchView) {
							if (this->leftTouchView->getPressed()) {
								this->leftTouchView->press();
							}
							else {
								touch.unpress();
							}
						}
						else {
							touch.unpress();
						}
					}
				}
			}
		}
	}
}