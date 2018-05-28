#ifndef NINJANOMEIYO_CONTROLLERS_ASPECTS_COMMAND_COMMANDFINISHEDASPECT_H
#define NINJANOMEIYO_CONTROLLERS_ASPECTS_COMMAND_COMMANDFINISHEDASPECT_H

#include "./Aspect.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Aspects {
			namespace Command {

				class CommandFinishedAspect : virtual public Aspect {
				public:
					CommandFinishedAspect();
					virtual ~CommandFinishedAspect();

					void visit(Character::CommandDealer &commandDealer);

				protected:

				private:

				};
			}
		}
	}
}

#endif
