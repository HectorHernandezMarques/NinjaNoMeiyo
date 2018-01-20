#ifndef NINJANOMEIYO_MODELS_ASPECTS_NODE_ASPECT_H
#define NINJANOMEIYO_MODELS_ASPECTS_NODE_ASPECT_H

#include "cocos2d.h"
#include "../../../Views/Node.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {

				class Aspect {
				public:
					virtual void visit(Views::Node &node) = 0;

				protected:

				private:

				};
			}
		}
	}
}

#endif
