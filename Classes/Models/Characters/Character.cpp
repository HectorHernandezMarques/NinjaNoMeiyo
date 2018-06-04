#include "./Character.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			Character::Character(CollisionHandlers::CollisionHandler &collisionHandler, States::StateHandlers::StateHandler &stateHandler, cocos2d::Vec2 position,
                                 cocos2d::Vec2 anchorPoint, std::string texture, float rotation, cocos2d::Size initialPhysicSize, Physics::Physic *physic) :
					Node(position, anchorPoint, texture, rotation, physic),
                    sense(Sense::RIGHT),
                    collisionHandler(collisionHandler),
					stateHandler(stateHandler),
					initialPhysicSize(initialPhysicSize)
				{

				assert(&position);
				assert(&anchorPoint);

				this->getPhysic().setRotationEnable(false);
			}

			Character::~Character() {
			}

			void Character::attach(Observers::CharacterObserver &characterObserver) {
				this->characterObservers.insert(&characterObserver);
			}

			void Character::detach(Observers::CharacterObserver &characterObserver) {
				this->characterObservers.erase(&characterObserver);
			}

			void Character::notify(Aspects::Characters::Aspect &aspect) {
				for (auto it = this->characterObservers.begin(); it != this->characterObservers.end(); ++it) {
					(*it)->update(aspect);
				}
			}

			States::State& Character::getCurrentState() {
				return this->stateHandler.handle(this->nodesInContact)->getState();
			}

			Sense Character::getSense() {
				return this->sense;
			}

			cocos2d::Size Character::getInitialPhysicSize() {
				return this->initialPhysicSize;
			}

			void Character::setSense(Sense sense) {
				this->sense = sense;
			}

			void Character::notifyCurrentStateIfChanged(Interaction interactionType) {
				States::StateHandlers::StateResult& stateResult = *this->stateHandler.handle(this->nodesInContact);

				if (stateResult.getStateIndex() != this->currentStateIndex) {
					this->currentStateIndex = stateResult.getStateIndex();
					this->notify(*new Aspects::Characters::StateAspect(stateResult.getState(), interactionType));
				}
			}

		}
	}
}