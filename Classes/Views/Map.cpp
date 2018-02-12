#include "./Map.h"
#include "../Models/Maps/Map.h"

namespace NinjaNoMeiyo {
	namespace Views {

		Map::Map(Models::Maps::Map &map, cocos2d::Layer &layer) : layer(layer) {
			assert(&layer);
			for (auto it = map.begin(); it != map.end(); ++it) {
				(*it)->accept(*this);
			}
		}

		Map::~Map() {

		}

		void Map::spawn() {
			for (auto it = this->elements.begin(); it != this->elements.end(); ++it) {
				it->spawn();
			}
		}

		void Map::visit(Models::Maps::Texture &texture) {
			this->elements.emplace(this->elements.end(), texture, this->layer);
		}

		void Map::visit(Models::Maps::Surface &surface) {
			for (auto it = surface.begin(); it != surface.end(); ++it) {
				this->elements.emplace(this->elements.end(), *it, this->layer);
			}
		}

		void Map::visit(Models::Maps::Limit &limit) {
			this->elements.emplace(this->elements.end(), limit, this->layer);
		}

	}
}