#ifndef NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ASPECTS_ANIMATIONVISITOR_ASPECT_H
#define NINJANOMEIYO_MODELS_CHARACTERS_VISITORS_ANIMATIONS_ASPECTS_ANIMATIONVISITOR_ASPECT_H

#include "cocos2d.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			class CharacterCommand;
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {
					namespace Aspects {
						namespace AnimationVisitor {

							class Aspect {
							public:
								virtual void visit(Controllers::Characters::CharacterCommand &characterCommand) = 0;

							protected:

							private:

							};
						}
					}
				}
			}
		}
	}
}

#endif
