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
				this->textures.insert(texture);
				this->elements.insert(texture);
			}

			void Map::add(Surface *surface) {
				this->surfaces.insert(surface);
				this->elements.insert(surface);
			}

			void Map::add(Limit *limit) {
				this->limits.insert(limit);
				this->elements.insert(limit);
			}

			std::unordered_set<MapElement*>::iterator Map::begin() {
				return this->elements.begin();
			}

			std::unordered_set<MapElement*>::iterator Map::end() {
				return this->elements.end();
			}
		}
	}
}