#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_STATERESULT_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_STATERESULT_H

#include "./StateIndex.h"
#include "../State.h"
#include "cocos2d.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {

					class StateResult {
					protected:
						State &state;
						StateIndex stateIndex;

					public:
						StateResult(State &state, StateIndex stateIndex);
						virtual ~StateResult();

						State& getState();
						StateIndex getStateIndex();
					};
				}
			}
		}
	}
}

#endif