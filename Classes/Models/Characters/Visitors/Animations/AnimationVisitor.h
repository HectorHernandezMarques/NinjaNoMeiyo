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
						AnimationVisitor();
						virtual ~AnimationVisitor();

						cocos2d::Action* getAnimationAction();

					protected:
						cocos2d::Action *animationAction;

					private:

					};
				}
			}
		}
	}
}

#endif