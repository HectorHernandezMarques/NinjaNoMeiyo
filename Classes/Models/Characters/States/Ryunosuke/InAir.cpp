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

					void InAir::move(Controllers::Sense sense) {
						ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, ryunosuke.getVelocity().y));
					}

					cocos2d::Action* InAir::moveAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InAir::moveAnimationFunction, this, sense)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					cocos2d::Action* InAir::stopAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InAir::stopAnimationFunction, this, sense)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					void InAir::stop(Controllers::Sense sense) {
						ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
					}

					void InAir::moveAnimationFunction(Controllers::Sense sense) {
						std::string textureName;
						if (sense == Controllers::Sense::RIGHT) {
							textureName.append("RyunosukeMove");
							textureName.append(this->to_string(this->animationIndex++%MOVE_TEXTURES_NUMBER));
							textureName.append("D.png");
						}
						else {
							textureName.append("RyunosukeMove");
							textureName.append(this->to_string(this->animationIndex++%MOVE_TEXTURES_NUMBER));
							textureName.append("I.png");
						}
						this->ryunosuke.setTexture(textureName);
					}

					void InAir::stopAnimationFunction(Controllers::Sense sense) {
						std::string textureName;
						if (sense == Controllers::Sense::RIGHT) {
							textureName.append("RyunosukeMove");
							textureName.append(this->to_string(this->animationIndex++%MOVE_TEXTURES_NUMBER));
							textureName.append("D.png");
						}
						else {
							textureName.append("RyunosukeMove");
							textureName.append(this->to_string(this->animationIndex++%MOVE_TEXTURES_NUMBER));
							textureName.append("I.png");
						}
						this->ryunosuke.setTexture(textureName);
					}
				}
			}
		}
	}
}