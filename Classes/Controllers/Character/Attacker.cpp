#include "./Attacker.h"
#include "../Aspects/Command/CommandFinishedAspect.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Character {

			Attacker::Attacker(bool stoppable, Models::Characters::Character &character, Models::Characters::Sense sense) : CharacterCommand(stoppable, character) {

				this->modelVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Models::ModelAttacker(sense);
				this->animationVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationAttacker(sense);
			}

			Attacker::~Attacker() {
			}

			void Attacker::execute() {
				this->animationVisitor->attach(this);
				this->damager = new Models::Environment::Damager(this->character.getPosition() + cocos2d::Vec2(this->character.getInitialPhysicSize().width / 2, 0), this->character.getInitialPhysicSize());
				this->damagerView = new Views::Node(*this->damager, this->character.getLayer());
				this->damagerView->spawn();

				CharacterCommand::execute();
			}

			void Attacker::stop() {
				this->animationVisitor->detach(this);
				this->damagerView->unspawn();

				CharacterCommand::stop();
			}
		}
	}
}