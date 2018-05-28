#include "./AnimationFinishedAspect.h"
#include "../../../../../../Controllers/Character/CharacterCommand.h"

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

							void AnimationFinishedAspect::visit(Controllers::Character::CharacterCommand &characterCommand) {
								characterCommand.notifyCommandFinished();
							}
						}
					}
				}
			}
		}
	}
}