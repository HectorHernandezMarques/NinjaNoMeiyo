#include "./Map.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			Map::Map() : textures(), surfaces(), limits() {
			}

			Map::~Map()
			{
			}

			void Map::add(Texture *texture) {
				this->textures.push_back(texture);
				this->elements.push_back(texture);
			}

			void Map::add(Surface *surface) {
				this->surfaces.push_back(surface);
				this->elements.push_back(surface);
			}

			void Map::add(Limit *limit) {
				this->limits.push_back(limit);
				this->elements.push_back(limit);
			}

			std::list<MapElement*>::iterator Map::begin() {
				return this->elements.begin();
			}

			std::list<MapElement*>::iterator Map::end() {
				return this->elements.end();
			}
		}
	}
}