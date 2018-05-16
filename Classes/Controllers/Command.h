#ifndef NINJANOMEIYO_CONTROLLERS_COMMAND_H
#define NINJANOMEIYO_CONTROLLERS_COMMAND_H

#include <unordered_set>
#include "cocos2d.h"
#include "./Observers/CommandObserver.h"
#include "./Aspects/Command/CommandFinishedAspect.h"
#include "../Models/Characters/Visitors/Animations/Observers/AnimationVisitorObserver.h"

namespace NinjaNoMeiyo {
	namespace Controllers {

		class Command : virtual public Models::Characters::Visitors::Animations::Observers::AnimationVisitorObserver{
		public:
			Command(bool stoppable);
			virtual ~Command();

			virtual void execute() = 0;
			virtual void stop() = 0;
			bool isStoppable();
			void attach(Observers::CommandObserver &commandObserver);
			void detach(Observers::CommandObserver &commandObserver);
			void notify(Aspects::Command::Aspect &aspect);
			void notifyCommandFinished();

		private:
			bool stoppable;

			std::unordered_set<Observers::CommandObserver*> commandObservers;

		};
	}
}

#endif