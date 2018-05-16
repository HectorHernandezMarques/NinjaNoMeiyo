#ifndef NINJANOMEIYO_CONTROLLERS_OBSERVERS_COMMANDOBSERVER_H
#define NINJANOMEIYO_CONTROLLERS_OBSERVERS_COMMANDOBSERVER_H

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Aspects {
			namespace Command {
				class Aspect;

			}
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Observers {

			class CommandObserver {
			public:
				virtual void update(Aspects::Command::Aspect &aspect) = 0;
			};
		}
	}
}

#endif