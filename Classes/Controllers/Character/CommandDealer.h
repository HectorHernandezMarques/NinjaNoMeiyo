#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTER_COMMANDDEALER_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTER_COMMANDDEALER_H

#include "../Observers/CommandObserver.h"
#include "./Error.h"
#include "./Stopper.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Character {

			class CharacterCommand;
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Character {

			class CommandDealer : virtual public Observers::CommandObserver {
			public:
				CommandDealer();
				virtual ~CommandDealer();

				Error executeCommand(CharacterCommand &command);
				Error executeCommand(CharacterCommand &command, float secondsToBeTrying);
				Error executeNextCommand();
				void update(Aspects::Command::Aspect &aspect);

			private:
				CharacterCommand *currentCommand;
				CharacterCommand *nextCommand;
			};
		}
	}
}

#endif