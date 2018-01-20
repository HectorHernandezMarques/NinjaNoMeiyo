#include "./CommandDealer.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			CommandDealer::CommandDealer() {
			}

			CommandDealer::~CommandDealer() {
			}

			Error CommandDealer::executeCommand(CharacterCommand &command) {
				Error result = Error::NO_ERROR;
				if (currentCommand == nullptr) {
					this->currentCommand = &command;
					this->currentCommand->execute();
				}
				else {
					if (currentCommand->isStoppable()) {
						this->currentCommand->stop();
						this->currentCommand = &command;
						this->currentCommand->execute();
					}
					else {
						result = Error::NON_STOPPABLE_COMMAND_BEING_EXECUTED;
					}
				}
				return result;
			}

			Error CommandDealer::executeCommand(CharacterCommand &command, float secondsToBeTrying) {
				//HUAHUAMECOMESTODALAPOYADORAIMON.
			}
		}
	}
}