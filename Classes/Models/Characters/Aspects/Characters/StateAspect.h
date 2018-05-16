#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ASPECTS_CHARACTERS_STATEASPECT_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ASPECTS_CHARACTERS_STATEASPECT_H

#include "./Aspect.h"
#include "../../Interaction.h"
#include "../../States/State.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Aspects {
				namespace Characters {

					class StateAspect : virtual public Aspect {
					public:
						StateAspect(States::State &state, Interaction interactionType);
						virtual ~StateAspect();

						void visit(CharacterVisitor &characterVisitor);

					protected:

					private:
						States::State &state;
						Interaction interactionType;

					};
				}
			}
		}
	}
}

#endif
