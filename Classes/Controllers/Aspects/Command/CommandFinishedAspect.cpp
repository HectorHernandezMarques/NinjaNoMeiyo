#include "./CommandFinishedAspect.h"
#include "../../Character/CommandDealer.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Aspects {
			namespace Command {

				CommandFinishedAspect::CommandFinishedAspect() {
				}

				CommandFinishedAspect::~CommandFinishedAspect() {

				}

				void CommandFinishedAspect::visit(Character::CommandDealer &commandDealer) {
					commandDealer.executeNextCommand();
				}
			}
		}
	}
}