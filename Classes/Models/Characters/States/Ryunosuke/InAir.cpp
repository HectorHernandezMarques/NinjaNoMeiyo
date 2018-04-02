#include "./InAir.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InAir::InAir(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InAir::~InAir() {
					}

					void InAir::move(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->ryunosuke.getVelocity().y));
					}

					cocos2d::Action* InAir::moveAnimation(Sense sense) {
						Animations::MovingAnimation &animation = *new Animations::MovingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InAir::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
					}

					cocos2d::Action* InAir::stopAnimation(Sense sense) {
						Animations::JumpingAnimation &animation = *new Animations::JumpingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InAir::jump(Sense sense) {
					}

					cocos2d::Action* InAir::jumpAnimation(Sense sense) {
						Animations::JumpingAnimation &animation = *new Animations::JumpingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InAir::attack(Sense sense) {

					}

					cocos2d::Action* InAir::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}
				}
			}
		}
	}
}