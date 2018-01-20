#ifndef NINJANOMEIYO_VIEWS_INPUT_TOUCH_ASPECTS_ASPECT_H
#define NINJANOMEIYO_VIEWS_INPUT_TOUCH_ASPECTS_ASPECT_H

#include "../Controller.h"

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {

				class Touch;
			}
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {
				namespace Aspects {

					class Aspect {
					public:
						Aspect(Touch &touch);
						virtual ~Aspect();

						virtual void visit(Controller &controller) = 0;

					protected:
						Touch& touch;

					private:

					};
				}
			}
		}
	}
}

#endif
