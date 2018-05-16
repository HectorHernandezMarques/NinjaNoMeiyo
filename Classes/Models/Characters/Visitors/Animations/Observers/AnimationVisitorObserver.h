#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_OBSERVERS_ANIMATIONVISITOROBSERVER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_OBSERVERS_ANIMATIONVISITOROBSERVER_H

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {
					namespace Aspects {
						namespace AnimationVisitor {

							class Aspect;
						}
					}
				}
			}
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {
					namespace Observers {

						class AnimationVisitorObserver {
						public:
							virtual void update(Aspects::AnimationVisitor::Aspect &aspect) = 0;
						};
					}
				}
			}
		}
	}
}

#endif