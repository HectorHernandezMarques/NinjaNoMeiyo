#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELMOVER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELMOVER_H

#include "./ModelVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					class ModelMover : public ModelVisitor {
					public:
						ModelMover(Sense sense);
						virtual ~ModelMover();

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