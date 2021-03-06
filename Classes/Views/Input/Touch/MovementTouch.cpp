#include <unistd.h>
#include "./MovementTouch.h"


namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {

				MovementTouch::MovementTouch(Models::Input::Touch::Touch &touch, cocos2d::Layer &layer, Models::Characters::Sense sense, Models::Characters::Ryunosuke& ryunosuke, Controllers::Character::CommandDealer &commandDealer) :
						Touch(touch, layer), sense(sense), ryunosuke(ryunosuke), commandDealer(commandDealer) {

				}

				MovementTouch::~MovementTouch() {

				}

				void MovementTouch::press() {
					this->commandDealer.executeCommand(*new Controllers::Character::Mover(true, this->ryunosuke, this->sense));
				}
				
				void MovementTouch::unpress() {
					this->commandDealer.executeCommand(*new Controllers::Character::Stopper(true, this->ryunosuke));
				}

				bool MovementTouch::getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event) {
					auto touchPosition = touch->getLocation();
					if (this->nodeSprite.getBoundingBox().containsPoint(touchPosition)) {
						if (this->mDoubleTouch.try_lock()) {
							this->setPressed(true);
							this->initialTouchPosition = this->nodeSprite.getPosition();
							this->positionVariation = cocos2d::Vec2(touch->getLocation().x - this->initialTouchPosition.x, touch->getLocation().y - this->initialTouchPosition.y);
							return true;
						}
						else {
							return false;
						}
					}
					else {
						return false;
					}
				}

				void MovementTouch::moveTouch(cocos2d::Touch* touch, cocos2d::Event* event) {
					if (this->mForcingUntouch.try_lock()) {
						mForcingUntouch.unlock();
						auto touchPosition = touch->getLocation();
						this->nodeSprite.setPosition(cocos2d::Vec2(touchPosition.x - this->positionVariation.x, touchPosition.y - this->positionVariation.y));
						// |o|o|o|
						// | | | |
						// | | | |
						if (this->nodeSprite.getPositionY() > this->initialTouchPosition.y + this->layer.getContentSize().height / TOUCH_UPPER_JUMP){
							// | | |o|
							// | | | |
							// | | | |
							if (this->nodeSprite.getPositionX() > this->initialTouchPosition.x + this->layer.getContentSize().height / TOUCH_RIGHT_JUMP){
								this->mForcingUntouch.lock();

								this->commandDealer.executeCommand(*new Controllers::Character::Jumper(true, this->ryunosuke, Models::Characters::Sense::RIGHT));
							}
							// |o| | |
							// | | | |
							// | | | |
							else if (this->nodeSprite.getPositionX() < this->initialTouchPosition.x - this->layer.getContentSize().height / TOUCH_LEFT_JUMP){
								this->mForcingUntouch.lock();

								this->commandDealer.executeCommand(*new Controllers::Character::Jumper(true, this->ryunosuke, Models::Characters::Sense::LEFT));
							}
							// | |o| |
							// | | | |
							// | | | |
							else if (this->nodeSprite.getPositionY() > this->initialTouchPosition.y + this->layer.getContentSize().height / TOUCH_UPPER_JUMP_2){
								this->mForcingUntouch.lock();

								this->commandDealer.executeCommand(*new Controllers::Character::Jumper(true, this->ryunosuke, Models::Characters::Sense::MIDDLE));
							}
						}
                        // | | | |
                        // | | |o|
                        // | | | |
                        else if (this->nodeSprite.getPositionX() > this->initialTouchPosition.x + this->layer.getContentSize().height / TOUCH_RIGHT_ATTACK){
                            this->mForcingUntouch.lock();

                            this->commandDealer.executeCommand(*new Controllers::Character::Attacker(false, this->ryunosuke, Models::Characters::Sense::RIGHT));
                        }
                        // | | | |
                        // |o| | |
                        // | | | |
                        else if (this->nodeSprite.getPositionX() < this->initialTouchPosition.x - this->layer.getContentSize().height / TOUCH_LEFT_ATTACK) {
                            this->mForcingUntouch.lock();

                            this->commandDealer.executeCommand(*new Controllers::Character::Attacker(false, this->ryunosuke, Models::Characters::Sense::LEFT));
                        }
					}
				}

				void MovementTouch::endMovement(cocos2d::Touch* touch, cocos2d::Event* event) {
					this->setPressed(false);
					this->setPosition(this->initialPosition);
					this->mDoubleTouch.unlock();
					this->mForcingUntouch.unlock();
				}

			}
		}
	}
}