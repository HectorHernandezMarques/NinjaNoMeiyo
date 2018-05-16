#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ASPECTS_ANIMATION_ANIMATIONFINISHEDASPECT_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ASPECTS_ANIMATION_ANIMATIONFINISHEDASPECT_H

#include "./Aspect.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {
					class AnimationVisitor;
				}
			}
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {
				namespace Aspects {
					namespace Animation {

						class AnimationFinishedAspect : virtual public Aspect {
						public:
							AnimationFinishedAspect();
							virtual ~AnimationFinishedAspect();

							void visit(Visitors::Animations::AnimationVisitor &animationVisitor);

						protected:

						private:

						};
					}
				}
			}
		}
	}
}

#endif
