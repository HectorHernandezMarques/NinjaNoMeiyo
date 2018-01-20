#ifndef NINJANOMEIYO_CONTROLLERS_COMMAND_H
#define NINJANOMEIYO_CONTROLLERS_COMMAND_H

#include "cocos2d.h"

namespace NinjaNoMeiyo {
	namespace Controllers {

		class Command {
		public:
			Command(bool stoppable);
			virtual ~Command();

			virtual void execute() = 0;
			virtual void stop() = 0;
			bool isStoppable();

		protected:
			cocos2d::Action *animationAction;

		private:
			bool stoppable;

		};
	}
}

#endif