#include "./StateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {

					StateHandler::StateHandler() : next(nullptr) {
					}

					StateHandler::StateHandler(StateHandler &next) : next(&next) {
					}

					StateHandler::~StateHandler() {
					}

					StateResult* StateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
						if (this->hasNext()) {
							return this->next->handle(nodesInContact);
						}
						else {
							return nullptr;
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