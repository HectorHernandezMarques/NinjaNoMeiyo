#include "./AnchorPointAspect.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				AnchorPointAspect::AnchorPointAspect(cocos2d::Vec2 anchorPoint) : anchorPoint(anchorPoint) {
				}

				AnchorPointAspect::~AnchorPointAspect() {

				}

				void AnchorPointAspect::visit(Views::Node &node) {
					node.setAnchorPoint(this->anchorPoint);
				}
			}
		}
	}
}