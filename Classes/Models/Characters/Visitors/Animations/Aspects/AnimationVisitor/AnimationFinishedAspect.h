#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ASPECTS_ANIMATIONVISITOR_ANIMATIONFINISHEDASPECT_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ASPECTS_ANIMATIONVISITOR_ANIMATIONFINISHEDASPECT_H

#include "./Aspect.h"


namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {
					namespace Aspects {
						namespace AnimationVisitor {

							class AnimationFinishedAspect : virtual public Aspect {
							public:
								AnimationFinishedAspect();
								virtual ~AnimationFinishedAspect();

								void visit(Controllers::Characters::CharacterCommand &characterCommand);

							protected:

							private:

							};
						}
					}
				}
			}
		}
	}
}

#endif
