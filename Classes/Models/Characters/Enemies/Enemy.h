#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ENEMIES_ENEMY_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ENEMIES_ENEMY_H

#define INITIAL_ENEMY_TEXTURE "EnemyPhysic.png"

#include "../Character.h"
#include "../../Physics/PhysicBox.h"
#include "../../CollisionHandlers/Bitmasks.h"
#include <map>

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Enemies {

				class Enemy : public Character {
				public:
					Enemy(cocos2d::Vec2 position);
					virtual ~Enemy();

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
}

#endif