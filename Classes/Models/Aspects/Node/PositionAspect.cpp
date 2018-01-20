#include "./PositionAspect.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				PositionAspect::PositionAspect(cocos2d::Vec2 &position) : position(position) {
				}

				PositionAspect::~PositionAspect() {

				}

				void PositionAspect::visit(Views::Node &node) {
					node.setPosition(this->position);
				}
			}
		}
	}
}