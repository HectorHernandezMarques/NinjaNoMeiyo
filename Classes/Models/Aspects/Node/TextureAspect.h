#ifndef NINJANOMEIYO_MODELS_ASPECTS_NODE_TEXTUREASPECT_H
#define NINJANOMEIYO_MODELS_ASPECTS_NODE_TEXTUREASPECT_H

#include "cocos2d.h"
#include "./Aspect.h"
#include "../../../Views/Node.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				class TextureAspect : virtual public Aspect {
				public:
					TextureAspect(std::string texture);
					virtual ~TextureAspect();

					void visit(Views::Node &node);

				protected:

				private:
					std::string texture;
				};
			}
		}
	}
}

#endif
