#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTERS_COMMANDDEALER_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTERS_COMMANDDEALER_H

#include "./CharacterCommand.h"
#include "./Error.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			class CommandDealer {
			public:
				CommandDealer();
				virtual ~CommandDealer();

				Error executeCommand(CharacterCommand &command);
				Error executeCommand(CharacterCommand &command, float secondsToBeTrying);

			private:
				CharacterCommand *currentCommand;
				CharacterCommand *nextCommand;
			};
		}
	}
}

#endif