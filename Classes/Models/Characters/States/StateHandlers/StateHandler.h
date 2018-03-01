#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_STATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_STATEHANDLER_H

#include "cocos2d.h"
#include "./StateIndex.h"
#include "./StateResult.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {

					class StateHandler {
					public:
						StateHandler();
						StateHandler(StateHandler &next);
						virtual ~StateHandler();

						virtual bool canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) = 0;
						virtual StateResult* handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact);
						bool hasNext();

						void setNext(StateHandler &collisionHandler);

					private:
						StateHandler *next;

					};
				}
			}
		}
	}
}

#endif