#include "./ModelMover.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelMover::ModelMover(Sense sense) : ModelVisitor(), sense(sense) {
					}

					ModelMover::~ModelMover() {
					}

					void ModelMover::visit(Ryunosuke &ryunosuke) {
						CharacterVisitor::visit(ryunosuke);
                        if(this->sense == Sense::RIGHT || this->sense == Sense::LEFT) {
                            ryunosuke.setSense(this->sense);
                        }
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