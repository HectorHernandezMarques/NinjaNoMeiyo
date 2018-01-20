#include "./ModelMover.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelMover::ModelMover(float xVelocity) : xVelocity(xVelocity) {
					}

					ModelMover::~ModelMover() {
					}

					void ModelMover::visit(Ryunosuke &ryunosuke) {
						ryunosuke.getCurrentState().move(xVelocity);
					}
				}
			}
		}
	}
}