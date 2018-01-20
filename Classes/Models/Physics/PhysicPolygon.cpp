#include "./PhysicPolygon.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Physics {

			PhysicPolygon::PhysicPolygon(int bitmask, std::list<cocos2d::Vec2> &points) : Physic(this->init(bitmask, points)) {
			}

			PhysicPolygon::~PhysicPolygon() {
			}

			cocos2d::PhysicsBody& PhysicPolygon::init(int bitmask, std::list<cocos2d::Vec2> &points) {
				cocos2d::Vec2 pointsArray[points.size()];
				int i = 0;
				for (auto point : points) {
					pointsArray[i++] = point;
				}
				cocos2d::PhysicsBody &result = *cocos2d::PhysicsBody::createPolygon(pointsArray, points.size());
				result.setCategoryBitmask(bitmask);
				return result;
			}
		}
	}
}