#ifndef NINJANOMEIYO_MODELS_PHYSICS_PHYSICEMPTY_H
#define NINJANOMEIYO_MODELS_PHYSICS_PHYSICEMPTY_H

#include "cocos2d.h"
#include "./Physic.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Physics {

			class PhysicEmpty : public Physic
			{
			public:
				PhysicEmpty();
				virtual ~PhysicEmpty();

			protected:
				cocos2d::PhysicsBody& init();

			};
		}
	}
}

#endif
