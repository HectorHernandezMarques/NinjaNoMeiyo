#ifndef NINJANOMEIYO_VIEWS_INPUT_TOUCH_ASPECTS_PRESSASPECT_H
#define NINJANOMEIYO_VIEWS_INPUT_TOUCH_ASPECTS_PRESSASPECT_H

#include "./Aspect.h"

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {
				namespace Aspects {

					class PressAspect : virtual public Aspect {
					public:
						PressAspect(Touch &touch, bool presssed);
						virtual ~PressAspect();

						void visit(Controller &controller);

					protected:

					private:
						bool pressed;

					};
				}
			}
		}
	}
}

#endif
