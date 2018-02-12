#include "./ModelStopper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelStopper::ModelStopper(float xVelocity) : CharacterVisitor(), xVelocity(xVelocity) {
					}

					ModelStopper::~ModelStopper() {
					}

					void ModelStopper::visit(Ryunosuke &ryunosuke) {
						CharacterVisitor::visit(ryunosuke);
						ryunosuke.getCurrentState().stop(this->xVelocity);
					}

					void ModelStopper::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void ModelStopper::setState(States::State &state) {
						state.stop(this->xVelocity);
					}
				}
			}
		}
	}
}