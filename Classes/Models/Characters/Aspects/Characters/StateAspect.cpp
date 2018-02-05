#include "./StateAspect.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Aspects {
				namespace Node {

					StateAspect::StateAspect(States::Ryunosuke::State &state) : state(state) {
					}

                    StateAspect::~StateAspect() {

					}

					void StateAspect::visit(CharacterVisitor &characterVisitor) {
						characterVisitor.setState(this->state);
					}
				}
			}
		}
	}
}