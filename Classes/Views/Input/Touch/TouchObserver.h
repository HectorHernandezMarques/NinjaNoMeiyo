#ifndef NINJANOMEIYO_VIEWS_INPUT_TOUCH_TOUCHOBSERVER_H
#define NINJANOMEIYO_VIEWS_INPUT_TOUCH_TOUCHOBSERVER_H

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {
				namespace Aspects {

					class Aspect;
				}
			}
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Input {
			namespace Touch {

				class TouchObserver {
				public:
					virtual void update(Aspects::Aspect &aspect) = 0;
				};
			}
		}
	}

}

#endif