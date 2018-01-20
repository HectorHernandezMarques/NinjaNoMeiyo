#ifndef NINJANOMEIYO_MODELS_MAPS_MAP_H
#define NINJANOMEIYO_MODELS_MAPS_MAP_H

#include <unordered_set>
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

				std::unordered_set<MapElement*>::iterator begin();
				std::unordered_set<MapElement*>::iterator end();

			private:
				std::unordered_set<Texture*> textures;
				std::unordered_set<Surface*> surfaces;
				std::unordered_set<Limit*> limits;
				std::unordered_set<MapElement*> elements;

			};
		}
	}
}

#endif