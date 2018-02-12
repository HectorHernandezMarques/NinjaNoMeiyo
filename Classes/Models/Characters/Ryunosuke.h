#ifndef NINJANOMEIYO_MODELS_CHARACTERS_RYUNOSUKE_H
#define NINJANOMEIYO_MODELS_CHARACTERS_RYUNOSUKE_H

#define INITIAL_RYUNOSUKE_TEXTURE "RyunosukeMove0D.png"

#include "./Character.h"
#include "../Physics/PhysicBox.h"
#include "./States/Ryunosuke/State.h"
#include "./CollisionHandlers/Bitmasks.h"
#include "./CollisionHandlers/CollisionHandler.h"
#include "./CollisionHandlers/Ryunosuke/ConcreteCollisionHandlerBuilder.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			class Ryunosuke : public Character {
			public:
				Ryunosuke(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint = cocos2d::Vec2::ZERO);
				virtual ~Ryunosuke();

				void accept(CharacterVisitor &characterVisitor);
				States::State& getCurrentState();
				void setCollisionEventDispatchers();

			protected:

			private:
				CollisionHandlers::CollisionHandler &collisionHandler;

				bool onContactBegin(cocos2d::PhysicsContact &contact);
				bool onContactSeparate(cocos2d::PhysicsContact &contact);

			};
		}
	}
}

#endif