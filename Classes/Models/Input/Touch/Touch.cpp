#include "./Touch.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Input {
			namespace Touch {

				Touch::Touch(cocos2d::Vec2 position, cocos2d::Rect area, cocos2d::Vec2 anchorPoint, float rotation) : Models::Node(position, anchorPoint, "", rotation), area(area) {
				}

				Touch::~Touch() {
				}

				cocos2d::Rect Touch::getArea() {
					return this->area;
				}
			}
		}
	}
}