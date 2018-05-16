#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONJUMPER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ANIMATIONJUMPER_H

#include "./AnimationVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					class AnimationJumper : public AnimationVisitor {
					public:
						AnimationJumper(Sense sense);
						virtual ~AnimationJumper();

						void visit(Ryunosuke &ryunosuke);
						void update(Characters::Aspects::Characters::Aspect &aspect);
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