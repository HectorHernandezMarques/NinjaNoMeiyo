#include "./RotationAspect.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				RotationAspect::RotationAspect(float rotation) : rotation(rotation){
				}

				RotationAspect::~RotationAspect() {

				}

				void RotationAspect::visit(Views::Node &node) {
					node.setRotation(this->rotation);
				}
			}
		}
	}
}