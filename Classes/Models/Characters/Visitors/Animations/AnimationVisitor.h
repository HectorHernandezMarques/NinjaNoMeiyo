#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONVISITOR_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONVISITOR_H

#include "../../CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					class AnimationVisitor : public CharacterVisitor {
					public:
						AnimationVisitor(Controllers::Sense sense);
						virtual ~AnimationVisitor();

						virtual void unvisit(Ryunosuke &ryunosuke);
						cocos2d::Action* getAnimationAction();

					protected:
						std::mutex characterMutex;
						Character *character;
						cocos2d::Action *animationAction;
						Controllers::Sense sense;

					private:

					};
				}
			}
		}
	}
}

#endif