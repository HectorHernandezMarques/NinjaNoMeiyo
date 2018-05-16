#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ASPECTS_ANIMATION_ASPECT_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ASPECTS_ANIMATION_ASPECT_H

#include "cocos2d.h"

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

						class Aspect {
						public:
							virtual void visit(Visitors::Animations::AnimationVisitor &animationVisitor) = 0;

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
