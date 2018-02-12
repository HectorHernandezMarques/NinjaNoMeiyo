#include "./StateResult.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {

					StateResult::StateResult(State &state, StateIndex stateIndex) : state(state), stateIndex(stateIndex) {
					}

					StateResult::~StateResult() {
					}

					State& StateResult::getState() {
						return this->state;
					}

					StateIndex StateResult::getStateIndex() {
						return this->stateIndex;
					}
				}
			}
		}
	}
}