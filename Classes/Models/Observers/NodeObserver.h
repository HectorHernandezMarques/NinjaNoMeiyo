#ifndef NINJANOMEIYO_MODELS_OBSERVERS_NODEOBSERVER_H
#define NINJANOMEIYO_MODELS_OBSERVERS_NODEOBSERVER_H

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
	namespace Models {
		namespace Observers {

			class NodeObserver {
			public:
				virtual void update(Aspects::Node::Aspect &aspect) = 0;
				virtual cocos2d::Vec2 getCurrentPosition() = 0;
				virtual cocos2d::Size getContentSize() = 0;
				virtual cocos2d::Layer &getLayer() = 0;
			};
		}
	}

}

#endif