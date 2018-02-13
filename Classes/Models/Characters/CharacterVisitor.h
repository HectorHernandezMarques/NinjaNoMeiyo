#ifndef NINJANOMEIYO_MODELS_CHARACTERS_CHARACTERVISITOR_H
#define NINJANOMEIYO_MODELS_CHARACTERS_CHARACTERVISITOR_H

#include "./Ryunosuke.h"
#include "./Observers/CharacterObserver.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			class CharacterVisitor : public Observers::CharacterObserver{
			public:
				CharacterVisitor();
				virtual ~CharacterVisitor();

				virtual void visit(Ryunosuke &ryunosuke);
				virtual void unvisit(Ryunosuke &ryunosuke);
				virtual void setState(States::State &state) = 0;
				cocos2d::Action* getAction();

			};
		}
	}
}

#endif