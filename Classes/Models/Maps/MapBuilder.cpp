#include "./MapBuilder.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			MapBuilder* MapBuilder::instance = nullptr;

			MapBuilder& MapBuilder::getInstance() {
				if (!instance) {
					instance = new MapBuilder();
				}
				return *MapBuilder::instance;
			}

			MapBuilder::MapBuilder() : boxSize(cocos2d::Sprite::create(BOX_SIZE_IMAGE_SAMPLE)->getContentSize()) {
			}

			MapBuilder::~MapBuilder()
			{
			}

			Map MapBuilder::get(std::string path) {
				Map result;
				this->setTiledBoxSize(path);
				this->setTexturesTo(result, path);
				this->setSurfacesTo(result, path);
				this->setLimitsTo(result, path);

				return result;
			}

			void MapBuilder::setTiledBoxSize(std::string path) {
				cocos2d::TMXTiledMap *tiledMap = cocos2d::TMXTiledMap::create(path);
				cocos2d::ValueVector vectorObjects = tiledMap->getObjectGroup("Textures")->getObjects();
				cocos2d::ValueMap properties;
				this->tiledBoxSize = new cocos2d::Size(vectorObjects.begin()->asValueMap()["width"].asInt(), vectorObjects.begin()->asValueMap()["height"].asInt());
			}

			void MapBuilder::setTexturesTo(Map &map, std::string path) {
				assert(this->tiledBoxSize);

				cocos2d::TMXTiledMap *tiledMap = cocos2d::TMXTiledMap::create(path);
				cocos2d::ValueVector vectorObjects = tiledMap->getObjectGroup("Textures")->getObjects();
				cocos2d::ValueMap properties;
				Texture *texture;

				for (const auto& object : vectorObjects) {
					properties = object.asValueMap();
					texture = new Texture(this->getRelativeVec2(properties["x"].asFloat(), properties["y"].asFloat(), properties["height"].asFloat()),
						cocos2d::Vec2::ZERO,
						properties["type"].asString(),
						properties["rotation"].asFloat());
					map.add(texture);
				}
			}

			void MapBuilder::setSurfacesTo(Map &map, std::string path) {
				assert(this->tiledBoxSize);

				cocos2d::TMXTiledMap *tiledMap = cocos2d::TMXTiledMap::create(path);
				cocos2d::ValueVector vectorObjects = tiledMap->getObjectGroup("Surfaces")->getObjects();
				cocos2d::ValueMap properties;
				Surface *surface;

				for (const auto& object : vectorObjects) {
					properties = object.asValueMap();

					cocos2d::Size surfaceSize(this->getRelativeSize(properties["width"].asFloat(), properties["height"].asFloat()));
					std::array <int, SURFACES_NUMBER> surfaceBitmasks;
					surfaceBitmasks[UPPER_SURFACE_INDEX] = properties["upperSurfaceBitmask"].asInt();
					surfaceBitmasks[RIGHT_SURFACE_INDEX] = properties["rightSurfaceBitmask"].asInt();
					surfaceBitmasks[LEFT_SURFACE_INDEX] = properties["leftSurfaceBitmask"].asInt();
					surfaceBitmasks[LOWER_SURFACE_INDEX] = properties["lowerSurfaceBitmask"].asInt();
					
					surface = new Surface(this->getRelativeVec2(properties["x"].asFloat(), properties["y"].asFloat(), properties["height"].asFloat()), cocos2d::Vec2::ZERO, surfaceSize, surfaceBitmasks);
					map.add(surface);
				}
			}

			void MapBuilder::setLimitsTo(Map &map, std::string path) {
				assert(this->tiledBoxSize);

				cocos2d::TMXTiledMap *tiledMap = cocos2d::TMXTiledMap::create(path);
				cocos2d::ValueVector vectorObjects = tiledMap->getObjectGroup("Limits")->getObjects();
				cocos2d::ValueMap properties;

				int numObjects = 1000;
				for (int i = 0; i < numObjects; i++) {
					numObjects = (numObjects == 1000) ? 0 : numObjects;
					cocos2d::Vec2 position;
					std::map<int, cocos2d::Vec2> pointsMap;
					Limit *limit;
					for (const auto& object : vectorObjects) {
						properties = object.asValueMap();
						if (properties["Object"].asInt() == i) {
							pointsMap[properties["Index"].asInt()] = this->getRelativeVec2(properties["x"].asFloat(), properties["y"].asFloat(), properties["height"].asFloat()) +
																		cocos2d::Vec2(properties["XVar"].asInt(), properties["YVar"].asInt());
							if (properties["IsAnchor"].asInt()) {
								position = pointsMap[properties["Index"].asInt()];
							}
						}
						if (i == 0) {
							numObjects = (numObjects < properties["Object"].asInt() + 1) ? properties["Object"].asInt() + 1 : numObjects;
						}
					}

					std::list<cocos2d::Vec2> pointsList;
					for (auto it = pointsMap.begin(); it != pointsMap.end(); ++it) {
						pointsList.push_back(it->second - position);
					}
					limit = new Limit(position, cocos2d::Vec2::ZERO, "", 0.0, pointsList);
					map.add(limit);
				}
			}

			float MapBuilder::getRelativeX(float absoluteX) {
				return (absoluteX / this->tiledBoxSize->width) * this->boxSize.width;
			}

			float MapBuilder::getRelativeY(float absoluteY) {
				return (absoluteY / this->tiledBoxSize->height) * this->boxSize.height;
			}

			float MapBuilder::getRelativeY(float absoluteY, float absoluteHeight) {
				return (((absoluteY + absoluteHeight) / this->tiledBoxSize->height) - 1) * this->boxSize.height;
			}

			cocos2d::Vec2 MapBuilder::getRelativeVec2(float absoluteX, float absoluteY, float absoluteHeight) {
				return cocos2d::Vec2(this->getRelativeX(absoluteX), this->getRelativeY(absoluteY, absoluteHeight));
			}

			cocos2d::Size MapBuilder::getRelativeSize(float absoluteWidth, float absoluteHeight) {
				return cocos2d::Size(this->getRelativeX(absoluteWidth), this->getRelativeY(absoluteHeight));
			}
		}
	}
}