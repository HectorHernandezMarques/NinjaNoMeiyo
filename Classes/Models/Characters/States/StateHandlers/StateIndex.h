#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_STATEINDEX
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_STATEINDEX


namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {

					enum class StateIndex : int {
						IN_FLOOR,
						IN_RIGHT_OBSTACLE,
						IN_LEFT_OBSTACLE,
						//IN_CEILING,
						IN_FLOOR_AND_RIGHT_OBSTACLE,
						IN_FLOOR_AND_LEFT_OBSTACLE,

						//IN_OIL_FLOOR,
						IN_OIL_RIGHT_OBSTACLE,
						IN_OIL_LEFT_OBSTACLE,
						//IN_OIL_CEILING,

						IN_AIR,
						UNKNOWN_STATE
					};
				}
			}
		}
	}
}

#endif