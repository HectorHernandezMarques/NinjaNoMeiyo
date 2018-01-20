#ifndef NINJANOMEIYO_MODELS_PHYSICS_PHYSIC_H
#define NINJANOMEIYO_MODELS_PHYSICS_PHYSIC_H

#include "cocos2d.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Physics {

			class Physic
			{
			public:
				Physic(cocos2d::PhysicsBody &physic);
				virtual ~Physic();

				cocos2d::PhysicsBody& getPhysic();
				cocos2d::Vec2 getVelocity();
				void setDynamic(bool dynamic);
				void setCategoryBitmask(int bitmask);
				void setCollisionBitmask(int bitmask);
				void setContactTestBitmask(int bitmask);
				void setRotationEnable(bool enable);
				void setVelocity(cocos2d::Vec2 velocity);
				void setFriction(float friction);

			protected:
				cocos2d::PhysicsBody &physic;

			};
		}
	}
}

#endif