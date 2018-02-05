#ifndef NINJANOMEIYO_MODELS_CHARACTERS_CHARACTERVISITOR_H
#define NINJANOMEIYO_MODELS_CHARACTERS_CHARACTERVISITOR_H

#include "./Ryunosuke.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			class CharacterVisitor {
			public:
				CharacterVisitor();
				virtual ~CharacterVisitor();

				virtual void visit(Ryunosuke &ryunosuke) = 0;
				virtual void setState(States::Ryunosuke::State &state) = 0;
				cocos2d::Action* getAction();

			protected:
				cocos2d::Action *action;

				virtual void visitFunction(Ryunosuke &ryunosuke) = 0;
			};
		}
	}
}

#endif