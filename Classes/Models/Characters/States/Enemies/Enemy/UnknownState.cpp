#include "./UnknownState.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Enemies {
					namespace Enemy {

						UnknownState::UnknownState(Characters::Enemies::Enemy &enemy) : State(), enemy(enemy) {
						}

						UnknownState::~UnknownState() {
						}

						void UnknownState::move(Sense sense) {
						}

						Animations::Animation* UnknownState::moveAnimation(Sense sense) {
							Animations::NoAnimation &animation = *new Animations::NoAnimation(this->enemy, sense);
							return &animation;
						}

						void UnknownState::stop(Sense sense) {
						}

						Animations::Animation* UnknownState::stopAnimation(Sense sense) {
							Animations::NoAnimation &animation = *new Animations::NoAnimation(this->enemy, sense);
							return &animation;
						}

						void UnknownState::jump(Sense sense) {
						}

						Animations::Animation* UnknownState::jumpAnimation(Sense sense) {
							Animations::NoAnimation &animation = *new Animations::NoAnimation(this->enemy, sense);
							return &animation;
						}

						void UnknownState::attack(Sense sense) {

						}

						Animations::Animation* UnknownState::attackAnimation(Sense sense) {
							Animations::NoAnimation &animation = *new Animations::NoAnimation(this->enemy, sense);
							return &animation;
						}
					}
				}
			}
		}
	}
}