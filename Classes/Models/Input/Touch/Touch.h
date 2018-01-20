#ifndef NINJANOMEIYO_MODELS_INPUT_TOUCH_TOUCH_H
#define NINJANOMEIYO_MODELS_INPUT_TOUCH_TOUCH_H

#include <string>
#include "cocos2d.h"
#include "../../Node.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Input {
			namespace Touch {

				class Touch : public Node {
				public:
					Touch(cocos2d::Vec2 position, cocos2d::Rect area, cocos2d::Vec2 anchorPoint = cocos2d::Vec2::ZERO, float rotation = 0.0);
					virtual ~Touch();

					cocos2d::Rect getArea();

				private:
					cocos2d::Rect area;
				};
			}
		}
	}
}

#endif