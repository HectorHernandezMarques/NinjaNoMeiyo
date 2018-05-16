#include "./AnimationFinishedAspect.h"
#include "../../../../../../Controllers/Characters/CharacterCommand.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {
					namespace Aspects {
						namespace AnimationVisitor {

							AnimationFinishedAspect::AnimationFinishedAspect() {
							}

							AnimationFinishedAspect::~AnimationFinishedAspect() {

							}

							void AnimationFinishedAspect::visit(Controllers::Characters::CharacterCommand &characterCommand) {
								characterCommand.notifyCommandFinished();
							}
						}
					}
				}
			}
		}
	}
}