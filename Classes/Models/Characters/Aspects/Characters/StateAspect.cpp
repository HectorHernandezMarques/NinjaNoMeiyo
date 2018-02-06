#include "./StateAspect.h"
#include "../../CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Aspects {
				namespace Characters {

					StateAspect::StateAspect(States::State &state) : state(state) {
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