#ifndef NINJANOMEIYO_MODELS_MAPS_TEXTURE_H
#define NINJANOMEIYO_MODELS_MAPS_TEXTURE_H

#include "./MapElement.h"
#include "../Node.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			class Texture : public Node, virtual public MapElement {
			public:
				Texture(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation);
				virtual ~Texture();

				void accept(MapElementVisitor &mapElementVisitor);

			private:

			};
		}
	}
}

#endif