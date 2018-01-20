#include "./PhysicAspect.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				PhysicAspect::PhysicAspect(cocos2d::PhysicsBody &physicBody) : physicBody(physicBody) {
				}

				PhysicAspect::~PhysicAspect() {

				}

				void PhysicAspect::visit(Views::Node &node) {
					node.setPhysic(this->physicBody);
				}
			}
		}
	}
}