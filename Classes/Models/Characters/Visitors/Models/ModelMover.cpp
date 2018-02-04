#include "./ModelMover.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Models {

					ModelMover::ModelMover(float xVelocity) : CharacterVisitor(), xVelocity(xVelocity) {
					}

					ModelMover::~ModelMover() {
					}

					void ModelMover::visit(Ryunosuke &ryunosuke) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(ModelMover::visitFunction, this, ryunosuke)), nullptr));
						ryunosuke.runAction(action);
						this->action = action;
					}

					void ModelMover::visitFunction(Ryunosuke &ryunosuke) {
						ryunosuke.getCurrentState().move(xVelocity);
					}
				}
			}
		}
	}
}