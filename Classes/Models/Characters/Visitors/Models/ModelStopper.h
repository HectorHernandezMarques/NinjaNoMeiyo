#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELSTOPPER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELSTOPPER_H

#include "./ModelVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					class ModelStopper : public ModelVisitor {
					public:
						ModelStopper();
						virtual ~ModelStopper();

						void visit(Ryunosuke &ryunosuke);
						void update(Aspects::Characters::Aspect &aspect);
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