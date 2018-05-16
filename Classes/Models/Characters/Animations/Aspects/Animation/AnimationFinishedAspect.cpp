#include "./AnimationFinishedAspect.h"
#include "../../../Visitors/Animations/AnimationVisitor.h"


namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {
				namespace Aspects {
					namespace Animation {


						AnimationFinishedAspect::AnimationFinishedAspect() {
						}

						AnimationFinishedAspect::~AnimationFinishedAspect() {

						}

						void AnimationFinishedAspect::visit(Visitors::Animations::AnimationVisitor &animationVisitor) {
							animationVisitor.notifyAnimationFinished();
						}
					}
				}
			}
		}
	}
}