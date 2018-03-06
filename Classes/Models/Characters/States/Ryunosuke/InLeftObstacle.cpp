#include "./InLeftObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InLeftObstacle::InLeftObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InLeftObstacle::~InLeftObstacle() {
					}

					void InLeftObstacle::move(Controllers::Sense sense) {
						if (sense == Controllers::Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->ryunosuke.getVelocity().y));
						}
						else {
							this->ryunosuke.setVelocityLimit(RYUNOSUKE_WALL_SPEED);
							this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
					}

					cocos2d::Action* InLeftObstacle::moveAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InLeftObstacle::moveAnimationFunction, this, sense)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						this->ryunosuke.runAction(action);
						return action;
					}

					void InLeftObstacle::stop(Controllers::Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->ryunosuke.getVelocity().y));
					}

					cocos2d::Action* InLeftObstacle::stopAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InLeftObstacle::stopAnimationFunction, this, sense)), cocos2d::DelayTime::create(STOP_ANIMATION_DELAY), nullptr));
						this->ryunosuke.runAction(action);
						return action;
					}

					void InLeftObstacle::jump(Controllers::Sense sense) {
						if (sense == Controllers::Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->yVelocityJumpWall));
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->yVelocityJumpWall));
						}
					}

					cocos2d::Action* InLeftObstacle::jumpAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InLeftObstacle::jumpAnimationFunction, this, sense)), cocos2d::DelayTime::create(STOP_ANIMATION_DELAY), nullptr));
						this->ryunosuke.runAction(action);
						return action;
					}

					void InLeftObstacle::moveAnimationFunction(Controllers::Sense sense) {
						std::string textureName;
						if (sense == Controllers::Sense::RIGHT) {
							textureName.append("RyunosukeMove");
							textureName.append(this->to_string(this->animationIndex++%MOVE_TEXTURES_NUMBER));
							textureName.append("D.png");
						}
						else {
							textureName.append("RyunosukeClimb");
							textureName.append(this->to_string(this->animationIndex++%CLIMB_TEXTURES_NUMBER));
							textureName.append("I.png");
						}
						this->ryunosuke.setTexture(textureName);
					}

					void InLeftObstacle::stopAnimationFunction(Controllers::Sense sense) {
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

					void InLeftObstacle::jumpAnimationFunction(Controllers::Sense sense) {
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