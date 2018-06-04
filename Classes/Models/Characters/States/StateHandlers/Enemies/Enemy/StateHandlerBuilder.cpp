#include "./StateHandlerBuilder.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Enemies {
						namespace Enemy {


							StateHandlerBuilder::StateHandlerBuilder(Characters::Enemies::Enemy &enemy) : stateHandler(new EnemyStateHandler(enemy)) {
							}

							StateHandlerBuilder::~StateHandlerBuilder() {

							}

							StateHandler& StateHandlerBuilder::getStateHandler() {
								return *this->stateHandler;
							}
						}
					}
				}
			}
		}
	}
}