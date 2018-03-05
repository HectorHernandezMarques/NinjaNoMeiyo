#include "./InOilRightObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InOilRightObstacle::InOilRightObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
						this->yVelocityJump = 950;
					}

					InOilRightObstacle::~InOilRightObstacle() {
					}

					void InOilRightObstacle::move(Controllers::Sense sense) {
						if (sense == Controllers::Sense::RIGHT) {
							ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
						else {
							ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, ryunosuke.getVelocity().y));
						}
					}

					cocos2d::Action* InOilRightObstacle::moveAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InOilRightObstacle::moveAnimationFunction, this, sense)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					cocos2d::Action* InOilRightObstacle::stopAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InOilRightObstacle::stopAnimationFunction, this, sense)), cocos2d::DelayTime::create(STOP_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					void InOilRightObstacle::stop(Controllers::Sense sense) {
						ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
					}

					void InOilRightObstacle::moveAnimationFunction(Controllers::Sense sense) {
						std::string textureName;
						if (sense == Controllers::Sense::RIGHT) {
							textureName.append("RyunosukeClimb");
							textureName.append(this->to_string(this->animationIndex++%CLIMB_TEXTURES_NUMBER));
							textureName.append("D.png");
						}
						else {
							textureName.append("RyunosukeMove");
							textureName.append(this->to_string(this->animationIndex++%MOVE_TEXTURES_NUMBER));
							textureName.append("I.png");
						}
						this->ryunosuke.setTexture(textureName);
					}

					void InOilRightObstacle::stopAnimationFunction(Controllers::Sense sense) {
						std::string textureName;
						if (sense == Controllers::Sense::RIGHT) {
							textureName.append("RyunosukeStop");
							textureName.append(this->to_string(this->animationIndex++%STOP_TEXTURES_NUMBER));
							textureName.append("D.png");
						}
						else {
							textureName.append("RyunosukeStop");
							textureName.append(this->to_string(this->animationIndex++%STOP_TEXTURES_NUMBER));
							textureName.append("I.png");
						}
						this->ryunosuke.setTexture(textureName);
					}
				}
			}
		}
	}
}