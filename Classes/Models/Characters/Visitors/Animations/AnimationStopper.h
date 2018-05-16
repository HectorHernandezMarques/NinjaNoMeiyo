#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONSTOPPER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONSTOPPER_H

#include "./AnimationVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					class AnimationStopper : public AnimationVisitor {
					public:
						AnimationStopper();
						virtual ~AnimationStopper();

						void visit(Ryunosuke &ryunosuke);
						void update(Characters::Aspects::Characters::Aspect &aspect);
						void setState(States::State &state, Interaction interactionType);

					protected:

					private:
					};
				}
			}
		}
	}
}

#endif