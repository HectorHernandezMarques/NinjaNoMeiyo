#include "./ModelJumper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelJumper::ModelJumper(Controllers::Sense sense) : ModelVisitor(sense) {
					}

					ModelJumper::~ModelJumper() {
					}

					void ModelJumper::visit(Ryunosuke &ryunosuke) {
						CharacterVisitor::visit(ryunosuke);
						ryunosuke.getCurrentState().jump(this->sense);
					}

					void ModelJumper::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void ModelJumper::setState(States::State &state) {
						state.jump(this->sense);
					}
				}
			}
		}
	}
}