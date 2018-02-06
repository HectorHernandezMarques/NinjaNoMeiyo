#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELSTOPPER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELSTOPPER_H

#include "../../CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					class ModelStopper : public CharacterVisitor {
					public:
						ModelStopper(float xVelocity);
						virtual ~ModelStopper();

						void visit(Ryunosuke &ryunosuke);
						void update(Aspects::Characters::Aspect &aspect);
						void setState(States::State &state);

					protected:

					private:
						float xVelocity;
					};
				}
			}
		}
	}
}

#endif