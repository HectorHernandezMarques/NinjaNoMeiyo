#include "./InOilLeftObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InOilLeftObstacle::InOilLeftObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InOilLeftObstacle::~InOilLeftObstacle() {
					}

					void InOilLeftObstacle::move(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->ryunosuke.getVelocity().y));
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
					}

					cocos2d::Action* InOilLeftObstacle::moveAnimation(Sense sense) {
						Animations::Animation *animation = nullptr;
						cocos2d::Action* result = nullptr;

						if (sense == Sense::RIGHT) {
							animation = new Animations::MovingAnimation(this->ryunosuke, sense);
							result = animation->animate();
						}
						else {
							animation = new Animations::ClimbingAnimation(this->ryunosuke, sense);
							result = animation->animate();
						}

						return result;
					}

					void InOilLeftObstacle::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->ryunosuke.getVelocity().y));
					}

					cocos2d::Action* InOilLeftObstacle::stopAnimation(Sense sense) {
						Animations::StoppedAnimation &animation = *new Animations::StoppedAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InOilLeftObstacle::jump(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->yVelocityJumpWall));
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						}
					}

					cocos2d::Action* InOilLeftObstacle::jumpAnimation(Sense sense) {
						Animations::JumpingAnimation &animation = *new Animations::JumpingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InOilLeftObstacle::attack(Sense sense) {

					}

					cocos2d::Action* InOilLeftObstacle::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

				}
			}
		}
	}
}