#include "./AddEventListenerWithSceneGraphPriorityAspect.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				AddEventListenerWithSceneGraphPriorityAspect::AddEventListenerWithSceneGraphPriorityAspect(cocos2d::EventListener *listener) : listener(listener) {
					assert(listener);

				}

				AddEventListenerWithSceneGraphPriorityAspect::~AddEventListenerWithSceneGraphPriorityAspect() {

				}

				void AddEventListenerWithSceneGraphPriorityAspect::visit(Views::Node &node) {
					node.addEventListenerWithSceneGraphPriority(this->listener);
				}
			}
		}
	}
}