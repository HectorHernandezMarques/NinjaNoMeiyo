#ifndef NINJANOMEIYO_MODELS_COLLISIONHANDLERS_BITMASKS
#define NINJANOMEIYO_MODELS_COLLISIONHANDLERS_BITMASKS


namespace NinjaNoMeiyo {
	namespace Models {
		namespace CollisionHandlers {

			enum class Bitmasks : int {
				FLOOR = 90,
				RIGHT_OBSTACLE = 1,
				LEFT_OBSTACLE = 2,
				CEILING = 3,

				EDGE_FLOOR_RIGHT = 4,
				EDGE_RIGHT_OBSTACLE = 5,
				EDGE_LEFT_OBSTACLE = 6,
				EDGE_FLOOR_LEFT = 7,

				FLOAT_FLOOR = 8,
				FLOAT_RIGHT_OBSTACLE = 9,
				FLOAT_LEFT_OBSTACLE = 10,
				FLOAT_CEILING = 11,

				FLOAT_EDGE_FLOOR_RIGHT = 12,
				FLOAT_EDGE_RIGHT_OBSTACLE = 13,
				FLOAT_EDGE_LEFT_OBSTACLE = 14,
				FLOAT_EDGE_FLOOR_LEFT = 15,

				OIL_FLOOR = 16,
				OIL_RIGHT_OBSTACLE = 17,
				OIL_LEFT_OBSTACLE = 18,
				OIL_CEILING = 19,

				OIL_EDGE_FLOOR_RIGHT = 20,
				OIL_EDGE_RIGHT_OBSTACLE = 21,
				OIL_EDGE_LEFT_OBSTACLE = 22,
				OIL_EDGE_FLOOR_LEFT = 23,

				OIL_FLOAT_FLOOR = 24,
				OIL_FLOAT_RIGHT_OBSTACLE = 25,
				OIL_FLOAT_LEFT_OBSTACLE = 26,
				OIL_FLOAT_CEILING = 27,

				OIL_FLOAT_EDGE_FLOOR_RIGHT = 28,
				OIL_FLOAT_EDGE_RIGHT_OBSTACLE = 29,
				OIL_FLOAT_EDGE_LEFT_OBSTACLE = 30,
				OIL_FLOAT_EDGE_FLOOR_LEFT = 31,

				DAMAGER = 32,

				AIR = 0,
				RYUNOSUKE = 131,

				FIXED_OBSTACLE = 130,
				ENEMY = 129,
				UNKNOWN_BITMASK = 88
			};
		}
	}
}

#endif