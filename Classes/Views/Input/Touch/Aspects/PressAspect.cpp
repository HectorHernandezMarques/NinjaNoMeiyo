#include "./PressAspect.h"

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {
				namespace Aspects {

					PressAspect::PressAspect(Touch &touch, bool pressed) : Aspect(touch), pressed(pressed) {
					}

					PressAspect::~PressAspect() {

					}

					void PressAspect::visit(Controller &controller) {
						controller.dealInteraction(this->touch, this->pressed);
					}
				}
			}
		}
	}
}