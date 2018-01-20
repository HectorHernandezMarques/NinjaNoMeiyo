#include "./Texture.h"
#include "./MapElementVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Maps {

			Texture::Texture(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation) :
				Node(position, anchorPoint, texture, rotation, nullptr) {

			}

			Texture::~Texture()
			{

			}

			void Texture::accept(MapElementVisitor &mapElementVisitor) {
				mapElementVisitor.visit(*this);
			}
		}
	}
}