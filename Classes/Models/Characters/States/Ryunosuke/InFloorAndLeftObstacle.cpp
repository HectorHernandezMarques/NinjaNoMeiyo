#include "./InFloorAndLeftObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InFloorAndLeftObstacle::InFloorAndLeftObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InFloorAndLeftObstacle::~InFloorAndLeftObstacle() {
					}

					void InFloorAndLeftObstacle::move(float xVelocity) {
						if (xVelocity > 0.0) {
							ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							ryunosuke.setVelocity(cocos2d::Vec2(xVelocity, ryunosuke.getVelocity().y));
						}
						else {
							ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
					}

					cocos2d::Action* InFloorAndLeftObstacle::moveAnimation(float xVelocity) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InFloorAndLeftObstacle::moveAnimationFunction, this, xVelocity)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					cocos2d::Action* InFloorAndLeftObstacle::stopAnimation(float xVelocity) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(InFloorAndLeftObstacle::stopAnimationFunction, this, xVelocity)), cocos2d::DelayTime::create(STOP_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					void InFloorAndLeftObstacle::stop(float xVelocity) {
						ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
					}

					void InFloorAndLeftObstacle::moveAnimationFunction(float xVelocity) {
						std::string textureName;
						if (xVelocity > 0.0) {
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

					void InFloorAndLeftObstacle::stopAnimationFunction(float xVelocity) {
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