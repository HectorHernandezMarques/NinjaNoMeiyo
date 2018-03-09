#include "./ModelStopper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelStopper::ModelStopper() : ModelVisitor() {
					}

					ModelStopper::~ModelStopper() {
					}

					void ModelStopper::visit(Ryunosuke &ryunosuke) {
						CharacterVisitor::visit(ryunosuke);
						ryunosuke.getCurrentState().stop(this->character->getSense());
					}

					void ModelStopper::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void ModelStopper::setState(States::State &state, Interaction interactionType) {
						state.stop(this->character->getSense());
					}
				}
			}
		}
	}
}