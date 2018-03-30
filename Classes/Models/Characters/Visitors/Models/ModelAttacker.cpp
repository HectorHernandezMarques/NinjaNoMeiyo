#include "./ModelAttacker.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelAttacker::ModelAttacker(Sense sense) : ModelVisitor(), sense(sense) {
					}

					ModelAttacker::~ModelAttacker() {
					}

					void ModelAttacker::visit(Ryunosuke &ryunosuke) {
						CharacterVisitor::visit(ryunosuke);
						ryunosuke.getCurrentState().attack(this->sense);
					}

					void ModelAttacker::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void ModelAttacker::setState(States::State &state, Interaction interactionType) {
						if (interactionType == Interaction::COLLISION) {
							state.attack(this->sense);
						}
					}
				}
			}
		}
	}
}