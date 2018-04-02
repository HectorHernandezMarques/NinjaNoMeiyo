#ifndef NINJANOMEIYO_MODELS_CHARACTERS_CHARACTER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_CHARACTER_H

#include "../Node.h"
#include "./Sense.h"
#include "./Aspects/Characters/StateAspect.h"
#include "./Observers/CharacterObserver.h"
#include "./States/StateHandlers/StateIndex.h"
#include "./States/StateHandlers/StateHandler.h"
#include "./CollisionHandlers/CollisionHandler.h"
#include "./Interaction.h"
#include <unordered_set>

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			class CharacterVisitor;
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			class Character : public Node {
			public:
				Character(CollisionHandlers::CollisionHandler &collisionHandler, States::StateHandlers::StateHandler &stateHandler, cocos2d::Vec2 position, 
					cocos2d::Vec2 anchorPoint = cocos2d::Vec2::ZERO, std::string texture = "", float rotation = 0.0, cocos2d::Size initialPhysicSize = cocos2d::Size::ZERO, Physics::Physic *physic = new Physics::PhysicEmpty());
				virtual ~Character();

				void attach(Observers::CharacterObserver &characterObserver);
				void detach(Observers::CharacterObserver &characterObserver);
				void notify(Aspects::Characters::Aspect &aspect);
				virtual void accept(CharacterVisitor &characterVisitor) = 0;
                virtual void reject(CharacterVisitor &characterVisitor) = 0;

                States::State& getCurrentState();
				Sense getSense();
				cocos2d::Size getInitialPhysicSize();
				void setSense(Sense sense);

			protected:
				States::StateHandlers::StateIndex currentStateIndex;
                CollisionHandlers::CollisionHandler &collisionHandler;
                std::unordered_multimap<int, cocos2d::Node*> nodesInContact;
				cocos2d::Size initialPhysicSize;

                void notifyCurrentStateIfChanged(Interaction interactionType);
				Sense sense;

			private:
				std::unordered_set<Observers::CharacterObserver*> characterObservers;
                States::StateHandlers::StateHandler &stateHandler;
			};
		}
	}
}

#endif