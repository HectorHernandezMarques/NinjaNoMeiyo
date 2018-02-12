#include "./InRightObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InRightObstacle::InRightObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InRightObstacle::~InRightObstacle() {
					}

					void InRightObstacle::move(float xVelocity) {
						if (xVelocity > 0.0) {
							ryunosuke.setVelocityLimit(RYUNOSUKE_WALL_SPEED);
							ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
						else {
							ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							ryunosuke.setVelocity(cocos2d::Vec2(xVelocity, ryunosuke.getVelocity().y));
						}
					}

					cocos2d::Action* InRightObstacle::moveAnimation(float xVelocity) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InRightObstacle::moveAnimationFunction, this, xVelocity)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					cocos2d::Action* InRightObstacle::stopAnimation(float xVelocity) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InRightObstacle::stopAnimationFunction, this, xVelocity)), cocos2d::DelayTime::create(STOP_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					void InRightObstacle::stop(float xVelocity) {
						ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
					}

					void InRightObstacle::moveAnimationFunction(float xVelocity) {
						std::string textureName;
						if (xVelocity > 0.0) {
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

					void InRightObstacle::stopAnimationFunction(float xVelocity) {
						std::string textureName;
						if (xVelocity > 0.0) {
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