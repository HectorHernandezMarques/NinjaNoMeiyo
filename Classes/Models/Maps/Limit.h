#ifndef NINJANOMEIYO_MODELS_MAPS_LIMIT_H
#define NINJANOMEIYO_MODELS_MAPS_LIMIT_H

#include "cocos2d.h"
#include "./MapElement.h"
#include "../Node.h"
#include "../Physics/PhysicPolygon.h"
#include "../Characters/CollisionHandlers/Bitmasks.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			class Limit : public Node, virtual public MapElement {
			public:
				Limit(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, std::list<cocos2d::Vec2> &points);
				virtual ~Limit();

				void accept(MapElementVisitor &mapElementVisitor);

			private:

			};
		}
	}
}

#endif