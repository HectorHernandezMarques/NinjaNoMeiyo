#include "./ModelMover.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelMover::ModelMover(float xVelocity) : CharacterVisitor(), xVelocity(xVelocity) {
					}

					ModelMover::~ModelMover() {
					}

					void ModelMover::visit(Ryunosuke &ryunosuke) {
						CharacterVisitor::visit(ryunosuke);
						ryunosuke.getCurrentState().move(this->xVelocity);
					}

					void ModelMover::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void ModelMover::setState(States::State &state) {
						state.move(this->xVelocity);
					}
				}
			}
		}
	}
}