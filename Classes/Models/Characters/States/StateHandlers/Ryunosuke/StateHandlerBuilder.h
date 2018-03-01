#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_STATEHANDLERBUILDER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_STATEHANDLERBUILDER_H

#include "./InFloorStateHandler.h"
#include "./InRightObstacleStateHandler.h"
#include "./InLeftObstacleStateHandler.h"
#include "./InFloorAndRightObstacleStateHandler.h"
#include "./InFloorAndLeftObstacleStateHandler.h"
#include "./InOilRightObstacleStateHandler.h"
#include "./InOilLeftObstacleStateHandler.h"
#include "../../../Ryunosuke.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						class StateHandlerBuilder {
						public:
							StateHandlerBuilder(Characters::Ryunosuke &ryunosuke);
							virtual ~StateHandlerBuilder();

							StateHandler& getStateHandler();

						private:
							StateHandler *stateHandler;

						};
					}
				}
			}
		}
	}
}

#endif