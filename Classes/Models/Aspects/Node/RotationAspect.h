#ifndef NINJANOMEIYO_MODELS_ASPECTS_NODE_ROTATIONASPECT_H
#define NINJANOMEIYO_MODELS_ASPECTS_NODE_ROTATIONASPECT_H

#include "cocos2d.h"
#include "./Aspect.h"
#include "../../../Views/Node.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				class RotationAspect : virtual public Aspect {
				public:
					RotationAspect(float rotation);
					virtual ~RotationAspect();

					void visit(Views::Node &node);

				protected:

				private:
					float rotation;

				};
			}
		}
	}
}

#endif
