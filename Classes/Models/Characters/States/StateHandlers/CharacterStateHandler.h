#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_CHARACTERSTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_CHARACTERSTATEHANDLER_H

#include "./StateHandler.h"
#include "../../Character.h"
#include "../../States/Ryunosuke/UnknownState.h"

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

						virtual StateResult* handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact);

                    protected:
                        Character &character;

					};
				}
			}
		}
	}
}

#endif