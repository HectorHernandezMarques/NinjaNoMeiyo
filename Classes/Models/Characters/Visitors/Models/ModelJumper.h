#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELJUMPER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELJUMPER_H

#include "./ModelVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					class ModelJumper : public ModelVisitor {
					public:
						ModelJumper(Sense sense);
						virtual ~ModelJumper();

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