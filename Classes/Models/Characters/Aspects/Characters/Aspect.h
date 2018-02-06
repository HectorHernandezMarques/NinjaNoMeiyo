#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ASPECTS_CHARACTERS_ASPECT_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ASPECTS_CHARACTERS_ASPECT_H

#include "cocos2d.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			class CharacterVisitor;
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
		    namespace Aspects {
                namespace Characters {

                    class Aspect {
                    public:
                        virtual void visit(CharacterVisitor &characterVisitor) = 0;

                    protected:

                    private:

                    };
                }
			}
		}
	}
}

#endif
