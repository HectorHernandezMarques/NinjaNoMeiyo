#include "./StateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {

					StateHandler::StateHandler(Character &character) : character(character), next(nullptr) {
					}

					StateHandler::StateHandler(Character &character, StateHandler &next) : character(character), next(&next) {
					}

					StateHandler::~StateHandler() {
					}

					StateResult* StateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
						if (this->hasNext()) {
							return this->next->handle(nodesInContact);
						}
						else {
							nullptr;
						}
					}

					bool StateHandler::hasNext() {
						return this->next != nullptr;
					}

					void StateHandler::setNext(StateHandler &collisionHandler) {
						this->next = &collisionHandler;
					}
				}
			}
		}
	}
}