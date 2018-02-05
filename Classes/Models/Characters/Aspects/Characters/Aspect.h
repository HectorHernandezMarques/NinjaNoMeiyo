#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ASPECTS_CHARACTERS_ASPECT_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ASPECTS_CHARACTERS_ASPECT_H

#include "cocos2d.h"
#include "../../CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
		    namespace Aspects {
                namespace Node {

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
