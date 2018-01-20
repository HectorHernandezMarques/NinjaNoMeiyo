#ifndef NINJANOMEIYO_MODELS_MAPS_MAPELEMENTVISITOR_H
#define NINJANOMEIYO_MODELS_MAPS_MAPELEMENTVISITOR_H

#include "./Texture.h"
#include "./Surface.h"
#include "./Limit.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			class MapElementVisitor {
			public:
				virtual void visit(Texture &texture) = 0;
				virtual void visit(Surface &surface) = 0;
				virtual void visit(Limit &limit) = 0;

			private:

			};
		}
	}
}

#endif