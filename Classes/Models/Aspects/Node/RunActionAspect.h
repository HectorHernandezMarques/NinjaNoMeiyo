#ifndef NINJANOMEIYO_MODELS_ASPECTS_NODE_RUNACTIONASPECT_H
#define NINJANOMEIYO_MODELS_ASPECTS_NODE_RUNACTIONASPECT_H

#include "cocos2d.h"
#include "./Aspect.h"
#include "../../../Views/Node.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				class RunActionAspect : virtual public Aspect {
				public:
					RunActionAspect(cocos2d::Action *animationAction);
					virtual ~RunActionAspect();

					void visit(Views::Node &node);

				protected:

				private:
					cocos2d::Action *animationAction;
				};
			}
		}
	}
}

#endif
