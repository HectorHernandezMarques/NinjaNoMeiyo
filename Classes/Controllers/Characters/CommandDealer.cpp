#include "./CommandDealer.h"
#include "./CharacterCommand.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			CommandDealer::CommandDealer() : currentCommand(nullptr), nextCommand(nullptr) {
			}

			CommandDealer::~CommandDealer() {
			}

			Error CommandDealer::executeCommand(CharacterCommand &command) {
				Error result = Error::NO_ERROR;
				if (this->currentCommand != nullptr) {
					if (this->currentCommand->isStoppable()) {
						this->currentCommand->detach(*this);
						this->currentCommand->stop();
						this->currentCommand = &command;
						this->nextCommand = nullptr;
						this->currentCommand->attach(*this);
						this->currentCommand->execute();
					}
					else {
						this->nextCommand = &command;
					}
				}
				else {
					this->nextCommand = nullptr;
					this->currentCommand = &command;
					this->currentCommand->attach(*this);
					this->currentCommand->execute();
				}
				return result;
			}

			Error CommandDealer::executeCommand(CharacterCommand &command, float secondsToBeTrying) {
				//HUAHUAMECOMESTODALAPOYADORAIMON.
			}

			Error CommandDealer::executeNextCommand() {
				this->currentCommand->detach(*this);
				this->currentCommand->stop();
				this->currentCommand = this->nextCommand;
				this->nextCommand = nullptr;
				if (this->currentCommand != nullptr) {
					this->currentCommand->attach(*this);
					this->currentCommand->execute();
				}
			}

			void CommandDealer::update(Aspects::Command::Aspect &aspect) {
				aspect.visit(*this);
			}
		}
	}
}