#include "./ModelStopper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelStopper::ModelStopper(Controllers::Sense sense) : ModelVisitor(sense) {
					}

					ModelStopper::~ModelStopper() {
					}

					void ModelStopper::visit(Ryunosuke &ryunosuke) {
						CharacterVisitor::visit(ryunosuke);
						ryunosuke.getCurrentState().stop(this->sense);
					}

					void ModelStopper::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void ModelStopper::setState(States::State &state) {
						state.stop(this->sense);
					}
				}
			}
		}
	}
}