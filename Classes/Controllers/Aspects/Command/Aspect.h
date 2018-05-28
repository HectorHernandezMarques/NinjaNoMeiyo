#ifndef NINJANOMEIYO_CONTROLLERS_ASPECTS_COMMAND_ASPECT_H
#define NINJANOMEIYO_CONTROLLERS_ASPECTS_COMMAND_ASPECT_H

#include "cocos2d.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Character {

			class CommandDealer;
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Aspects {
			namespace Command {

				class Aspect {
				public:
					virtual void visit(Character::CommandDealer &commandDealer) = 0;

				protected:

				private:

				};
			}
		}
	}
}

#endif
