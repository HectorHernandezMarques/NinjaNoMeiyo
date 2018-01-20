#ifndef NINJANOMEIYO_MODELS_CHARACTERS_CHARACTERVISITOR_H
#define NINJANOMEIYO_MODELS_CHARACTERS_CHARACTERVISITOR_H

#include "./Ryunosuke.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			class CharacterVisitor {
			public:
				virtual void visit(Ryunosuke &ryunosuke) = 0;

			};
		}
	}
}

#endif