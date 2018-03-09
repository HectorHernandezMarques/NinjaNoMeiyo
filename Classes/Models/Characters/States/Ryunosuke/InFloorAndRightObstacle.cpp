#include "./InFloorAndRightObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InFloorAndRightObstacle::InFloorAndRightObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InFloorAndRightObstacle::~InFloorAndRightObstacle() {
					}

					void InFloorAndRightObstacle::move(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->ryunosuke.getVelocity().y));
						}
					}

					cocos2d::Action* InFloorAndRightObstacle::moveAnimation(Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InFloorAndRightObstacle::moveAnimationFunction, this, sense)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						this->ryunosuke.runAction(action);
						return action;
					}

					void InFloorAndRightObstacle::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
					}

					cocos2d::Action* InFloorAndRightObstacle::stopAnimation(Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InFloorAndRightObstacle::stopAnimationFunction, this, sense)), cocos2d::DelayTime::create(STOP_ANIMATION_DELAY), nullptr));
						this->ryunosuke.runAction(action);
						return action;
					}

					void InFloorAndRightObstacle::jump(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->yVelocityJumpWall));
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->yVelocityJumpFloor));
						}
					}

					cocos2d::Action* InFloorAndRightObstacle::jumpAnimation(Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InFloorAndRightObstacle::jumpAnimationFunction, this, sense)), cocos2d::DelayTime::create(STOP_ANIMATION_DELAY), nullptr));
						this->ryunosuke.runAction(action);
						return action;
					}

					void InFloorAndRightObstacle::moveAnimationFunction(Sense sense) {
						std::string textureName;
						if (sense == Sense::RIGHT) {
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

					void InFloorAndRightObstacle::stopAnimationFunction(Sense sense) {
						std::string textureName;
						if (sense == Sense::RIGHT) {
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

					void InFloorAndRightObstacle::jumpAnimationFunction(Sense sense) {
						std::string textureName;
						if (sense == Sense::RIGHT) {
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