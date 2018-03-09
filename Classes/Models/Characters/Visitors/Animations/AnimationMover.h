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
						AnimationMover(Sense sense);
						virtual ~AnimationMover();

						void visit(Ryunosuke &ryunosuke);
						void update(Aspects::Characters::Aspect &aspect);
						void setState(States::State &state, Interaction interactionType);

					protected:

					private:
						float xVelocity;
						Sense sense;

					};
				}
			}
		}
	}
}

#endif