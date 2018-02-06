#ifndef NINJANOMEIYO_MODELS_CHARACTERS_CHARACTER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_CHARACTER_H

#include "../Node.h"
#include "./Aspects/Characters/StateAspect.h"
#include "./Observers/CharacterObserver.h"

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
				Character(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint = cocos2d::Vec2::ZERO, std::string texture = "", float rotation = 0.0, Physics::Physic *physic = new Physics::PhysicEmpty());
				virtual ~Character();

				void attach(Observers::CharacterObserver &characterObserver);
				//void detach(Observers::CharacterObserver &characterObserver);
				void notify(Aspects::Characters::Aspect &aspect);
				virtual void accept(CharacterVisitor &characterVisitor) = 0;
				virtual States::State& getCurrentState() = 0;

			protected:

			private:
				Observers::CharacterObserver* characterObserver;
			};
		}
	}
}

#endif