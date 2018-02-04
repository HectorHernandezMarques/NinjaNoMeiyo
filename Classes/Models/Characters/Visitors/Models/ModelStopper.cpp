#include "./ModelStopper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelStopper::ModelStopper(float xVelocity) : CharacterVisitor(), xVelocity(xVelocity) {
					}

					ModelStopper::~ModelStopper() {
					}

					void ModelStopper::visit(Ryunosuke &ryunosuke) {
						cocos2d::Action *action = cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(ModelStopper::visitFunction, this, ryunosuke)), nullptr);
						ryunosuke.runAction(action);
						this->action = action;
					}

					void ModelStopper::visitFunction(Ryunosuke &ryunosuke) {
						ryunosuke.getCurrentState().stop(xVelocity);
					}
				}
			}
		}
	}
}