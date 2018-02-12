#include "./Surface.h"
#include "./MapElementVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			Surface::Surface(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, cocos2d::Size size, std::array<int, SURFACES_NUMBER> surfaceBitmasks) : surfaces() {

				surfaces.emplace_back(cocos2d::Vec2(position.x + size.width / 2, position.y + size.height), cocos2d::Vec2::ZERO, "", 0.0, 
													surfaceBitmasks[UPPER_SURFACE_INDEX] != 0 ? static_cast<Physics::Physic*>(new Physics::PhysicBox(surfaceBitmasks[UPPER_SURFACE_INDEX], cocos2d::Size(size.width, 1))) :
																								static_cast<Physics::Physic*>(new Physics::PhysicEmpty()
										));

				surfaces.emplace_back(cocos2d::Vec2(position.x + size.width, position.y + size.height / 2), cocos2d::Vec2::ZERO, "", 0.0,
													surfaceBitmasks[RIGHT_SURFACE_INDEX] != 0 ? static_cast<Physics::Physic*>(new Physics::PhysicBox(surfaceBitmasks[RIGHT_SURFACE_INDEX], cocos2d::Size(1, size.height))) :
																								static_cast<Physics::Physic*>(new Physics::PhysicEmpty()
										));

				surfaces.emplace_back(cocos2d::Vec2(position.x, position.y + size.height / 2), cocos2d::Vec2::ZERO, "", 0.0,
													surfaceBitmasks[LEFT_SURFACE_INDEX] != 0 ? static_cast<Physics::Physic*>(new Physics::PhysicBox(surfaceBitmasks[LEFT_SURFACE_INDEX], cocos2d::Size(1, size.height))) :
																								static_cast<Physics::Physic*>(new Physics::PhysicEmpty()
										));

				surfaces.emplace_back(cocos2d::Vec2(position.x + size.width / 2, position.y), cocos2d::Vec2::ZERO, "", 0.0,
													surfaceBitmasks[LOWER_SURFACE_INDEX] != 0 ? static_cast<Physics::Physic*>(new Physics::PhysicBox(surfaceBitmasks[LOWER_SURFACE_INDEX], cocos2d::Size(size.width, 1))) :
																								static_cast<Physics::Physic*>(new Physics::PhysicEmpty()
										));

				for (auto it = this->surfaces.begin(); it != this->surfaces.end(); ++it) {
					it->setDynamic(false);
					it->setContactTestBitmask(true);
				}
			}

			Surface::~Surface(){
			}

			void Surface::accept(MapElementVisitor &mapElementVisitor) {
				mapElementVisitor.visit(*this);
			}

			std::list<Node>::iterator Surface::begin() {
				return this->surfaces.begin();
			}

			std::list<Node>::iterator Surface::end() {
				return this->surfaces.end();
			}
		}
	}
}