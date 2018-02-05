#ifndef NINJANOMEIYO_MODELS_CHARACTERS_CHARACTER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_CHARACTER_H

#include "../Node.h"

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

				virtual void accept(CharacterVisitor &characterVisitor) = 0;
				virtual States::Ryunosuke::State& getCurrentState() = 0;

			protected:

			private:

			};
		}
	}
}

#endif