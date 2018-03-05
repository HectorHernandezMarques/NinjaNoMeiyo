#include "./ModelMover.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelMover::ModelMover(Controllers::Sense sense) : ModelVisitor(sense) {
					}

					ModelMover::~ModelMover() {
					}

					void ModelMover::visit(Ryunosuke &ryunosuke) {
						CharacterVisitor::visit(ryunosuke);
						ryunosuke.getCurrentState().move(this->sense);
					}

					void ModelMover::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void ModelMover::setState(States::State &state, Interaction interactionType) {
						state.move(this->sense);
					}
				}
			}
		}
	}
}