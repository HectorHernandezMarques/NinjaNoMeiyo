#include "./ModelJumper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelJumper::ModelJumper(Sense sense) : ModelVisitor(), sense(sense) {
					}

					ModelJumper::~ModelJumper() {
					}

					void ModelJumper::visit(Ryunosuke &ryunosuke) {
						CharacterVisitor::visit(ryunosuke);
						if(this->sense == Sense::RIGHT || this->sense == Sense::LEFT) {
							ryunosuke.setSense(this->sense);
						}
						ryunosuke.getCurrentState().jump(this->sense);
					}

					void ModelJumper::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void ModelJumper::setState(States::State &state, Interaction interactionType) {
						if (interactionType == Interaction::COLLISION) {
							state.stop(this->sense);
						}
					}
				}
			}
		}
	}
}