#ifndef NINJANOMEIYO_MODELS_CHARACTERS_RYUNOSUKE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_RYUNOSUKE_H

#define INITIAL_RYUNOSUKE_TEXTURE "DefaultTexture.png"

#include "./Character.h"
#include "../Physics/PhysicBox.h"
#include "./States/Ryunosuke/State.h"
#include "./CollisionHandlers/Bitmasks.h"
#include "./CollisionHandlers/Ryunosuke/ConcreteCollisionHandlerBuilder.h"
#include <map>

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			class Ryunosuke : public Character {
			public:
				Ryunosuke(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint = cocos2d::Vec2::ZERO);
				virtual ~Ryunosuke();

				void accept(CharacterVisitor &characterVisitor);
				void reject(CharacterVisitor &characterVisitor);
				void setCollisionEventDispatchers();

			protected:

			private:
				bool onContactBegin(cocos2d::PhysicsContact &contact);
				void onContactSeparate(cocos2d::PhysicsContact &contact);

			};
		}
	}
}

#endif