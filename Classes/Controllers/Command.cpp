#include "./Command.h"

namespace NinjaNoMeiyo {
	namespace Controllers {

		Command::Command(bool stoppable) : stoppable(stoppable) {
		}

		Command::~Command() {
		}

		bool Command::isStoppable() {
			return this->stoppable;
		}

		void Command::attach(Observers::CommandObserver &commandObserver) {
			this->commandObservers.insert(&commandObserver);
		}

		void Command::detach(Observers::CommandObserver &commandObserver) {
			this->commandObservers.erase(&commandObserver);
		}

		void Command::notify(Aspects::Command::Aspect &aspect) {
			std::list<Observers::CommandObserver*> auxCommandObservers;
			for (auto it = this->commandObservers.begin(); it != this->commandObservers.end(); ++it) {
				auxCommandObservers.push_back(*it);
			}
			for (auto it = auxCommandObservers.begin(); it != auxCommandObservers.end(); ++it) {
				(*it)->update(aspect);
			}
		}

		void Command::notifyCommandFinished() {
			this->notify(*new Controllers::Aspects::Command::CommandFinishedAspect());
		}
	}
}