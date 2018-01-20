#ifndef NINJANOMEIYO_MODELS_MAPS_MAPBUILDER_H
#define NINJANOMEIYO_MODELS_MAPS_MAPBUILDER_H

#define BOX_SIZE_IMAGE_SAMPLE "BoxSample.png"

#include "cocos2d.h"
#include "./Map.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			class MapBuilder {
			public:
				static MapBuilder& getInstance();
				virtual ~MapBuilder();

				Map get(std::string path);

			private:
				MapBuilder();
				static MapBuilder *instance;
				
				cocos2d::Size *tiledBoxSize;
				cocos2d::Size boxSize;

				void setTiledBoxSize(std::string path);
				void setTexturesTo(Map &map, std::string path);
				void setSurfacesTo(Map &map, std::string path);
				void setLimitsTo(Map &map, std::string path);
				float getRelativeX(float absoluteX);
				float getRelativeY(float absoluteY);
				float getRelativeY(float absoluteY, float absoluteHeight);
				cocos2d::Vec2 getRelativeVec2(float absoluteX, float absoluteY, float absoluteHeight);
				cocos2d::Size getRelativeSize(float absoluteWidth, float absoluteHeight);

			};
		}
	}
}

#endif