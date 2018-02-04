#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONMOVER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONMOVER_H

#include "./AnimationVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					class AnimationMover : public AnimationVisitor {
					public:
						AnimationMover(float xVelocity);
						virtual ~AnimationMover();

						void visit(Ryunosuke &ryunosuke);

					protected:

					private:
						float xVelocity;
						void visitFunction(Ryunosuke &ryunosuke);
					};
				}
			}
		}
	}
}

#endif