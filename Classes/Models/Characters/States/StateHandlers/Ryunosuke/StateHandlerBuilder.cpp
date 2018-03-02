#include "./StateHandlerBuilder.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {


						StateHandlerBuilder::StateHandlerBuilder(Characters::Ryunosuke &ryunosuke) : stateHandler(new InAirStateHandler(ryunosuke)) {
							this->stateHandler = new InOilLeftObstacleStateHandler(ryunosuke, *this->stateHandler);
							this->stateHandler = new InOilRightObstacleStateHandler(ryunosuke, *this->stateHandler);
                            this->stateHandler = new InFloorStateHandler(ryunosuke, *this->stateHandler);
							this->stateHandler = new InLeftObstacleStateHandler(ryunosuke, *this->stateHandler);
							this->stateHandler = new InRightObstacleStateHandler(ryunosuke, *this->stateHandler);
                            this->stateHandler = new InFloorAndLeftObstacleStateHandler(ryunosuke, *this->stateHandler);
                            this->stateHandler = new InFloorAndRightObstacleStateHandler(ryunosuke, *this->stateHandler);
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