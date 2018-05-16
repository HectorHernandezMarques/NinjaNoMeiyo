#include "./AnimationVisitor.h"
#include "../../Animations/Aspects/Animation/Aspect.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationVisitor::AnimationVisitor() : CharacterVisitor(), characterMutex(), animation(nullptr) {
					}

					AnimationVisitor::~AnimationVisitor() {
					}

					void AnimationVisitor::unvisit(Ryunosuke &ryunosuke) {
						CharacterVisitor::unvisit(ryunosuke);
						this->animation->detach(*this);
						this->animation->stopAnimation();
					}

					cocos2d::Action* AnimationVisitor::getAnimationAction() {
						return this->animation->getAnimationAction();
					}

					void AnimationVisitor::update(Characters::Animations::Aspects::Animation::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationVisitor::attach(Observers::AnimationVisitorObserver *commandObserver) {
						this->animationVisitorObservers.insert(commandObserver);
					}

					void AnimationVisitor::detach(Observers::AnimationVisitorObserver *commandObserver) {
						this->animationVisitorObservers.erase(commandObserver);
					}

					void AnimationVisitor::notify(Aspects::AnimationVisitor::Aspect &aspect) {
						std::list<Observers::AnimationVisitorObserver*> auxAnimationVisitorObservers;
						for (auto it = this->animationVisitorObservers.begin(); it != this->animationVisitorObservers.end(); ++it) {
							auxAnimationVisitorObservers.push_back(*it);
						}
						for (auto it = auxAnimationVisitorObservers.begin(); it != auxAnimationVisitorObservers.end(); ++it) {
							(*it)->update(aspect);
						}
					}

					void AnimationVisitor::notifyAnimationFinished() {
						this->notify(*new Aspects::AnimationVisitor::AnimationFinishedAspect());
					}
				}
			}
		}
	}
}