#include "./Limit.h"
#include "./MapElementVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			Limit::Limit(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, std::list<cocos2d::Vec2> &points) :
				Node(position, anchorPoint, texture, rotation, new Physics::PhysicPolygon(
                        static_cast<int>(Characters::CollisionHandlers::Bitmasks::FIXED_OBSTACLE), points)
				) {

				this->setDynamic(false);
			}

			Limit::~Limit()
			{
			}

			void Limit::accept(MapElementVisitor &mapElementVisitor) {
				mapElementVisitor.visit(*this);
			}
		}
	}
}