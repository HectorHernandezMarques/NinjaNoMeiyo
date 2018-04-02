#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONATTACKER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONATTACKER_H

#include "./AnimationVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					class AnimationAttacker : public AnimationVisitor {
					public:
						AnimationAttacker(Sense sense);
						virtual ~AnimationAttacker();

						void visit(Ryunosuke &ryunosuke);
						void update(Aspects::Characters::Aspect &aspect);
						void setState(States::State &state, Interaction interactionType);

					protected:

					private:
						Sense sense;

					};
				}
			}
		}
	}
}

#endif