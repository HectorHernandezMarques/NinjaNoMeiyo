#include "./RunActionAspect.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				RunActionAspect::RunActionAspect(cocos2d::Action *animationAction) : animationAction(animationAction) {
				}

				RunActionAspect::~RunActionAspect() {

				}

				void RunActionAspect::visit(Views::Node &node) {
					node.runAction(this->animationAction);
				}
			}
		}
	}
}