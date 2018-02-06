#ifndef NINJANOMEIYO_MODELS_CHARACTERS_OBSERVERS_CHARACTEROBSERVER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_OBSERVERS_CHARACTEROBSERVER_H

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Aspects {
				namespace Characters {
					class Aspect;

				}
			}
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Observers {

				class CharacterObserver {
				public:
					virtual void update(Aspects::Characters::Aspect &aspect) = 0;
				};
			}
		}
	}

}

#endif