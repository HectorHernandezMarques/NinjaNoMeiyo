#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_CHARACTERSTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_CHARACTERSTATEHANDLER_H

#include "./StateHandler.h"
#include "../../Character.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {

					class CharacterStateHandler : public StateHandler{
					public:
						CharacterStateHandler(Character &character);
						CharacterStateHandler(Character &character, StateHandler &next);
						virtual ~CharacterStateHandler();

                    protected:
                        Character &character;

					};
				}
			}
		}
	}
}

#endif