#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELVISITOR_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_MODELS_MODELVISITOR_H

#include "../../CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					class ModelVisitor : public CharacterVisitor {
					public:
						ModelVisitor();
						virtual ~ModelVisitor();

					protected:

					private:

					};
				}
			}
		}
	}
}

#endif