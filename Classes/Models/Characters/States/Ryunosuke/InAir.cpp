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

					Animations::Animation* InAir::moveAnimation(Sense sense) {
						Animations::MovingAnimation &animation = *new Animations::MovingAnimation(this->ryunosuke, sense);
						return &animation;
					}

					void InAir::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
					}

					Animations::Animation* InAir::stopAnimation(Sense sense) {
						Animations::JumpingAnimation &animation = *new Animations::JumpingAnimation(this->ryunosuke, sense);
						return &animation;
					}

					void InAir::jump(Sense sense) {
					}

					Animations::Animation* InAir::jumpAnimation(Sense sense) {
						Animations::JumpingAnimation &animation = *new Animations::JumpingAnimation(this->ryunosuke, sense);
						return &animation;
					}

					void InAir::attack(Sense sense) {
					}

					Animations::Animation* InAir::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return &animation;
					}
				}
			}
		}
	}
}