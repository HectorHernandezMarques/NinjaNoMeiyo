#include "./CommandFinishedAspect.h"
#include "../../Characters/CommandDealer.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Aspects {
			namespace Command {

				CommandFinishedAspect::CommandFinishedAspect() {
				}

				CommandFinishedAspect::~CommandFinishedAspect() {

				}

				void CommandFinishedAspect::visit(Characters::CommandDealer &commandDealer) {
					commandDealer.executeNextCommand();
				}
			}
		}
	}
}