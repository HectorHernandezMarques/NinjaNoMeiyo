#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELATTACKER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELATTACKER_H

#include "./ModelVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					class ModelAttacker : public ModelVisitor {
					public:
						ModelAttacker(Sense sense);
						virtual ~ModelAttacker();

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