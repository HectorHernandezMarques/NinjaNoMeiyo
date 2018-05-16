#ifndef NINJANOMEIYO_MODELS_MAPS_MAP_H
#define NINJANOMEIYO_MODELS_MAPS_MAP_H

#include <list>
#include "cocos2d.h"
#include "./Surface.h"
#include "./Limit.h"
#include "./Texture.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			class Map
			{
			public:
				Map();
				virtual ~Map();

				void add(Texture *texture);
				void add(Surface *surface);
				void add(Limit *limit);

				std::list<MapElement*>::iterator begin();
				std::list<MapElement*>::iterator end();

			private:
				std::list<Texture*> textures;
				std::list<Surface*> surfaces;
				std::list<Limit*> limits;
				std::list<MapElement*> elements;

			};
		}
	}
}

#endif