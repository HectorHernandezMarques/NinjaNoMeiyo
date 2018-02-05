#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ASPECTS_CHARACTERS_STATEASPECT_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ASPECTS_CHARACTERS_STATEASPECT_H

#include "./Aspect.h"
#include "../../CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Aspects {
				namespace Node {

					class StateAspect : virtual public Aspect {
					public:
						StateAspect(States::Ryunosuke::State &state);
						virtual ~StateAspect();

						void visit(CharacterVisitor &characterVisitor);

					protected:

					private:
						States::Ryunosuke::State &state;

					};
				}
			}
		}
	}
}

#endif
