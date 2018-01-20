#ifndef NINJANOMEIYO_MODELS_MAPS_MAPELEMENT_H
#define NINJANOMEIYO_MODELS_MAPS_MAPELEMENT_H

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {
			class MapElementVisitor;
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			class MapElement {
			public:
				virtual void accept(MapElementVisitor &map) = 0;

			private:

			};
		}
	}
}

#endif