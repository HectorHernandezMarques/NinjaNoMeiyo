#include "./ModelStopper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelStopper::ModelStopper(float xVelocity) : xVelocity(xVelocity) {
					}

					ModelStopper::~ModelStopper() {
					}

					void ModelStopper::visit(Ryunosuke &ryunosuke) {
						ryunosuke.getCurrentState().stop(xVelocity);
					}
				}
			}
		}
	}
}