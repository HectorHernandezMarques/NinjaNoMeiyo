

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define RYUNOSUKE_SPEED 850
#define RYUNOSUKE_WALL_SPEED 100
#define RYUNOSUKE_JUMP_ON_FLOOR 1400
#define RYUNOSUKE_JUMP_ON_WALL 950
#define RYUNOSUKE_JUMP_TIME_REMEMBER 0.15

#define RYUNOSUKE_MOVE_ANIMATION_NUMBER 3
#define RYUNOSUKE_MOVE_ANIMATION_DELAY 0.15

#define RYUNOSUKE_STOP_ANIMATION_NUMBER 2
#define RYUNOSUKE_STOP_ANIMATION_DELAY 0.5

#define RYUNOSUKE_JUMP_ANIMATION_NUMBER 2
#define RYUNOSUKE_JUMP_ANIMATION_DELAY 0.2

#define RYUNOSUKE_JUMP_WALL_ANIMATION_NUMBER 2
#define RYUNOSUKE_JUMP_WALL_ANIMATION_DELAY 0.1

#define RYUNOSUKE_FALL_ANIMATION_NUMBER 4
#define RYUNOSUKE_FALL_ANIMATION_NUMBER_SECOND 2
#define RYUNOSUKE_FALL_ANIMATION_DELAY 0.1

#define RYUNOSUKE_CLIMB_ANIMATION_NUMBER 2
#define RYUNOSUKE_CLIMB_ANIMATION_DELAY 0.1

#define MYFUCKINGWORLDGRAVITY 3600.0

#define FLOOR_BITMASK 90 //0x000000
#define RIGHT_OBSTACLE_BITMASK 1 //0x000001
#define LEFT_OBSTACLE_BITMASK 2 //0x000002
#define CEILING_BITMASK 3 //0x000003

#define EDGE_FLOOR_RIGHT_BITMASK 4 //0x000004
#define EDGE_RIGHT_OBSTACLE_BITMASK 5 //0x000005
#define EDGE_LEFT_OBSTACLE_BITMASK 6 //0x000006
#define EDGE_FLOOR_LEFT_BITMASK 7 //0x000007

#define FLOAT_FLOOR_BITMASK 8 //0x000008
#define FLOAT_RIGHT_OBSTACLE_BITMASK 9 //0x000009
#define FLOAT_LEFT_OBSTACLE_BITMASK 10 //0x000010
#define FLOAT_CEILING_BITMASK 11 //0x000011

#define FLOAT_EDGE_FLOOR_RIGHT_BITMASK 12 //0x000012
#define FLOAT_EDGE_RIGHT_OBSTACLE_BITMASK 13//0x000013
#define FLOAT_EDGE_LEFT_OBSTACLE_BITMASK 14 //0x000014
#define FLOAT_EDGE_FLOOR_LEFT_BITMASK 15 //0x000015

#define OIL_FLOOR_BITMASK 16 //0x000016
#define OIL_RIGHT_OBSTACLE_BITMASK 17 //0x00017
#define OIL_LEFT_OBSTACLE_BITMASK 18 //0x00018
#define OIL_CEILING_BITMASK 19 //0x000019

#define OIL_EDGE_FLOOR_RIGHT_BITMASK 20 //0x000020
#define OIL_EDGE_RIGHT_OBSTACLE_BITMASK 21 //0x000021
#define OIL_EDGE_LEFT_OBSTACLE_BITMASK 22 //0x000022
#define OIL_EDGE_FLOOR_LEFT_BITMASK 23 //0x000023

#define OIL_FLOAT_FLOOR_BITMASK 24 //0x000024
#define OIL_FLOAT_RIGHT_OBSTACLE_BITMASK 25 //0x000025
#define OIL_FLOAT_LEFT_OBSTACLE_BITMASK 26 //0x000026
#define OIL_FLOAT_CEILING_BITMASK 27 //0x000027

#define OIL_FLOAT_EDGE_FLOOR_RIGHT_BITMASK 28 //0x000028
#define OIL_FLOAT_EDGE_RIGHT_OBSTACLE_BITMASK 29 //0x000029
#define OIL_FLOAT_EDGE_LEFT_OBSTACLE_BITMASK 30 //0x000030
#define OIL_FLOAT_EDGE_FLOOR_LEFT_BITMASK 31 //0x000031

#define AIR_BITMASK 0 //0x000128
#define RYUNOSUKE_BITMASK 129 //0x000129

#define FIXED_OBSTACLE_BITMASK 130 //0x000130

#define UPPER_SURFACE_INDEX 0
#define RIGHT_SURFACE_INDEX 1
#define LEFT_SURFACE_INDEX 2
#define LOWER_SURFACE_INDEX 3
#define SURFACE_NUMBER 4


#define TOUCH_UPPER_JUMP 20
#define TOUCH_UPPER_JUMP_2 10
#define TOUCH_RIGHT_JUMP 30
#define TOUCH_LEFT_JUMP 30
#define TOUCH_DELAY 0.0

#endif //DEFINITIONS_H
