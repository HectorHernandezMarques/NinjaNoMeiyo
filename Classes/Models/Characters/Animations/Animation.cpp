#include "./Animation.h"
#include "../Character.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				Animation::Animation(Character &character, Sense sense, int texturesNumber, float animationDelay, AnimationIndex animationIndex) :
					character(character), sense(sense), texturesIndex(0), texturesNumber(texturesNumber), animationDelay(animationDelay), animationIndex(animationIndex), animationAction(nullptr) {
				}

				Animation::~Animation() {
				}

				void Animation::animate() {
					this->character.runAction(this->getAnimationAction());
				}

				void Animation::stopAnimation() {
					this->character.stopAction(this->getAnimationAction());
				}

				cocos2d::Action* Animation::animate(Animation &animation) {
					cocos2d::Action* result = nullptr;
					if (this->animationIndex != animation.animationIndex || this->sense != animation.sense) {
						result = this->getAnimationAction();
					}
					this->animate();
					return result;
				}

				void Animation::attach(Observers::AnimationObserver &animationObserver) {
					this->animationObservers.insert(&animationObserver);
				}

				void Animation::detach(Observers::AnimationObserver &animationObserver) {
					this->animationObservers.erase(&animationObserver);
				}

				void Animation::notify(Aspects::Animation::Aspect &aspect) {
					std::list<Observers::AnimationObserver*> auxAnimationObservers;
					for (auto it = this->animationObservers.begin(); it != this->animationObservers.end(); ++it) {
						auxAnimationObservers.push_back(*it);
					}
					for (auto it = auxAnimationObservers.begin(); it != auxAnimationObservers.end(); ++it) {
						(*it)->update(aspect);
					}
				}

				cocos2d::Action* Animation::getAnimationAction() {
					return this->animationAction;
				}
			}
		}
	}
}