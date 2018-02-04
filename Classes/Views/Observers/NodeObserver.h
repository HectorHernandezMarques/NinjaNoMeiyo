#ifndef NINJANOMEIYO_VIEWS_OBSERVERS_NODEOBSERVER_H
#define NINJANOMEIYO_VIEWS_OBSERVERS_NODEOBSERVER_H

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Aspects {
			namespace Node {
				class Aspect;

			}
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Views {
		namespace Observers {

			class NodeObserver {
			public:
				virtual void update(Models::Aspects::Node::Aspect &aspect) = 0;
			};
		}
	}

}

#endif