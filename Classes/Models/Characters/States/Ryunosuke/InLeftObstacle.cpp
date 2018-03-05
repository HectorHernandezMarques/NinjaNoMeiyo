#include "./InLeftObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InLeftObstacle::InLeftObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
						this->yVelocityJump = 950;
					}

					InLeftObstacle::~InLeftObstacle() {
					}

					void InLeftObstacle::move(Controllers::Sense sense) {
						if (sense == Controllers::Sense::RIGHT) {
							ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, ryunosuke.getVelocity().y));
						}
						else {
							ryunosuke.setVelocityLimit(RYUNOSUKE_WALL_SPEED);
							ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
					}

					cocos2d::Action* InLeftObstacle::moveAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InLeftObstacle::moveAnimationFunction, this, sense)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					cocos2d::Action* InLeftObstacle::stopAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InLeftObstacle::stopAnimationFunction, this, sense)), cocos2d::DelayTime::create(STOP_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					void InLeftObstacle::stop(Controllers::Sense sense) {
						ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
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
				}
			}
		}
	}
}