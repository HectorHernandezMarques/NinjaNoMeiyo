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
				if (currentCommand != nullptr) {
					if (currentCommand->isStoppable()) {
						this->currentCommand->stop();
						this->currentCommand = &command;
						this->currentCommand->execute();
					}
					else {
						result = Error::NON_STOPPABLE_COMMAND_BEING_EXECUTED;
					}
				}
				else {
					this->currentCommand = &command;
					this->currentCommand->execute();
				}
				return result;
			}

			Error CommandDealer::executeCommand(CharacterCommand &command, float secondsToBeTrying) {
				//HUAHUAMECOMESTODALAPOYADORAIMON.
			}
		}
	}
}