#include "./ModelVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelVisitor::ModelVisitor(Controllers::Sense sense) : CharacterVisitor(), sense(sense) {
					}

					ModelVisitor::~ModelVisitor() {
					}
				}
			}
		}
	}
}