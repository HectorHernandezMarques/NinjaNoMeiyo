#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELMOVER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELMOVER_H

#include "../../CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					class ModelMover : public CharacterVisitor {
					public:
						ModelMover(float xVelocity);
						virtual ~ModelMover();

						void visit(Ryunosuke &ryunosuke);

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