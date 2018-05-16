#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_OBSERVERS_ANIMATIONOBSERVER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_OBSERVERS_ANIMATIONOBSERVER_H

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {
				namespace Aspects {
					namespace Animation {

						class Aspect;
					}
				}
			}
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {
				namespace Observers {

					class AnimationObserver {
					public:
						virtual void update(Aspects::Animation::Aspect &aspect) = 0;
					};
				}
			}
		}
	}
}

#endif