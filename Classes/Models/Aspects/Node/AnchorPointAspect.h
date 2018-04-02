#ifndef NINJANOMEIYO_MODELS_ASPECTS_NODE_ANCHORPOINTASPECT_H
#define NINJANOMEIYO_MODELS_ASPECTS_NODE_ANCHORPOINTASPECT_H

#include "cocos2d.h"
#include "./Aspect.h"
#include "../../../Views/Node.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				class AnchorPointAspect : virtual public Aspect {
				public:
					AnchorPointAspect(cocos2d::Vec2 anchorPoint);
					virtual ~AnchorPointAspect();

					void visit(Views::Node &node);

				protected:

				private:
					cocos2d::Vec2 anchorPoint;
				};
			}
		}
	}
}

#endif
