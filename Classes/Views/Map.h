#ifndef NINJANOMEIYO_VIEWS_MAP_H
#define NINJANOMEIYO_VIEWS_MAP_H

#include "cocos2d.h"
#include "../Models/Maps/MapElementVisitor.h"
#include "../Models/Maps/Map.h"

namespace NinjaNoMeiyo {
	namespace Models {
				class Map;
	}
}

namespace NinjaNoMeiyo {
	namespace Views {

		class Map : virtual public Models::Maps::MapElementVisitor{
		public:
			Map(Models::Maps::Map &map, cocos2d::Layer &layer);
			virtual ~Map();

			void visit(Models::Maps::Texture & texture);
			void visit(Models::Maps::Surface & surface);
			void visit(Models::Maps::Limit & limit);
			void spawn();

		protected:
			cocos2d::Layer &layer;

			std::list<Node> elements;
		};
	}

}

#endif