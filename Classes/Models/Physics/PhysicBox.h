#ifndef NINJANOMEIYO_MODELS_PHYSICS_PHYSICBOX_H
#define NINJANOMEIYO_MODELS_PHYSICS_PHYSICBOX_H

#include "cocos2d.h"
#include "./Physic.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Physics {

			class PhysicBox : public Physic
			{
			public:
				PhysicBox(int bitmask, cocos2d::Size size);
				virtual ~PhysicBox();

			protected:
				cocos2d::PhysicsBody& init(int bitmask, cocos2d::Size &size);

			private:
				cocos2d::Size size;

			};
		}
	}
}

#endif
