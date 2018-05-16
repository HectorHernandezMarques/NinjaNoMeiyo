#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONVISITOR_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONVISITOR_H

#include "../../CharacterVisitor.h"
#include "../../Animations/Observers/AnimationObserver.h"
#include "./Observers/AnimationVisitorObserver.h"
#include "./Aspects/AnimationVisitor/AnimationFinishedAspect.h"
#include "../../Animations/Animation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					class AnimationVisitor : public CharacterVisitor, virtual public Characters::Animations::Observers::AnimationObserver {
					public:
						AnimationVisitor();
						virtual ~AnimationVisitor();

						virtual void unvisit(Ryunosuke &ryunosuke);
						cocos2d::Action* getAnimationAction();
						void update(Characters::Animations::Aspects::Animation::Aspect &aspect);
						void attach(Observers::AnimationVisitorObserver *commandObserver);
						void detach(Observers::AnimationVisitorObserver *commandObserver);
						void notify(Aspects::AnimationVisitor::Aspect &aspect);
						void notifyAnimationFinished();

					protected:
						std::mutex characterMutex;
						Characters::Animations::Animation *animation;

					private:
						std::unordered_set<Observers::AnimationVisitorObserver*> animationVisitorObservers;
					};
				}
			}
		}
	}
}

#endif