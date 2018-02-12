#include "./StateHandlerBuilder.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {


						StateHandlerBuilder::StateHandlerBuilder(Characters::Ryunosuke &ryunosuke) : stateHandler(new InFloorStateHandler(ryunosuke)) {
							this->stateHandler = new InRightObstacleStateHandler(ryunosuke, *this->stateHandler);
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