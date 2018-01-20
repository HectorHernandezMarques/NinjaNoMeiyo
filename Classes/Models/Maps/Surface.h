#ifndef NINJANOMEIYO_MODELS_MAPS_SURFACE_H
#define NINJANOMEIYO_MODELS_MAPS_SURFACE_H

#define SURFACES_NUMBER 4
#define UPPER_SURFACE_INDEX 0
#define RIGHT_SURFACE_INDEX 1
#define LEFT_SURFACE_INDEX 2
#define LOWER_SURFACE_INDEX 3

#include "cocos2d.h"
#include "./MapElement.h"
#include "../Node.h"
#include "../Physics/PhysicBox.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			class Surface : virtual public MapElement{
			public:
				Surface(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, cocos2d::Size size, std::array<int, SURFACES_NUMBER> surfaceBitmasks);
				virtual ~Surface();

				void accept(MapElementVisitor &mapElementVisitor);
				std::list<Node>::iterator begin();
				std::list<Node>::iterator end();

			private:
				std::list<Node> surfaces;
			};
		}
	}
}

#endif