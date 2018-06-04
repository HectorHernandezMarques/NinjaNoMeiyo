LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/LevelOneScene.cpp \
                   ../../Classes/Models/Node.cpp \
                   ../../Classes/Models/Aspects/Node/AddEventListenerWithSceneGraphPriorityAspect.cpp \
                   ../../Classes/Models/Aspects/Node/PhysicAspect.cpp \
                   ../../Classes/Models/Aspects/Node/PositionAspect.cpp \
                   ../../Classes/Models/Aspects/Node/AnchorPointAspect.cpp \
                   ../../Classes/Models/Aspects/Node/RotationAspect.cpp \
                   ../../Classes/Models/Aspects/Node/TextureAspect.cpp \
                   ../../Classes/Models/Aspects/Node/RunActionAspect.cpp \
                   ../../Classes/Models/Aspects/Node/StopActionAspect.cpp \
                   ../../Classes/Models/Characters/Character.cpp \
                   ../../Classes/Models/Characters/CharacterVisitor.cpp \
                   ../../Classes/Models/Characters/Ryunosuke.cpp \
                   ../../Classes/Models/Characters/Enemies/Enemy.cpp \
                   ../../Classes/Models/Characters/Animations/Animation.cpp \
                   ../../Classes/Models/Characters/Animations/Aspects/Animation/AnimationFinishedAspect.cpp \
                   ../../Classes/Models/Characters/Animations/StoppedAnimation.cpp \
                   ../../Classes/Models/Characters/Animations/MovingAnimation.cpp \
                   ../../Classes/Models/Characters/Animations/JumpingAnimation.cpp \
                   ../../Classes/Models/Characters/Animations/JumpingOnWallAnimation.cpp \
                   ../../Classes/Models/Characters/Animations/ClimbingAnimation.cpp \
                   ../../Classes/Models/Characters/Animations/ClimbingOilAnimation.cpp \
                   ../../Classes/Models/Characters/Animations/AttackingAnimation.cpp \
                   ../../Classes/Models/Characters/Animations/NoAnimation.cpp \
                   ../../Classes/Models/Characters/Aspects/Characters/StateAspect.cpp \
                   ../../Classes/Models/CollisionHandlers/CollisionHandler.cpp \
                   ../../Classes/Models/CollisionHandlers/CollisionResult.cpp \
                   ../../Classes/Models/CollisionHandlers/ConcreteCollisionHandler.cpp \
                   ../../Classes/Models/CollisionHandlers/Characters/Ryunosuke/ConcreteCollisionHandlerBuilder.cpp \
                   ../../Classes/Models/CollisionHandlers/Characters/Enemies/Enemy/ConcreteCollisionHandlerBuilder.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/UnknownState.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/InAir.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/InFloor.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/InRightObstacle.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/InLeftObstacle.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/InEdgeRightObstacle.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/InEdgeLeftObstacle.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/InFloorAndRightObstacle.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/InFloorAndLeftObstacle.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/InOilRightObstacle.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/InOilLeftObstacle.cpp \
                   ../../Classes/Models/Characters/States/Ryunosuke/State.cpp \
                   ../../Classes/Models/Characters/States/Enemies/Enemy/State.cpp \
                   ../../Classes/Models/Characters/States/Enemies/Enemy/UnknownState.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/StateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/CharacterStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/StateResult.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/StateHandlerBuilder.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InAirStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InFloorStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InRightObstacleStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InLeftObstacleStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InEdgeObstacleStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InEdgeRightObstacleStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InEdgeLeftObstacleStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InFloorAndRightObstacleStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InFloorAndLeftObstacleStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InOilRightObstacleStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Ryunosuke/InOilLeftObstacleStateHandler.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Enemies/Enemy/StateHandlerBuilder.cpp \
                   ../../Classes/Models/Characters/States/StateHandlers/Enemies/Enemy/EnemyStateHandler.cpp \
                   ../../Classes/Models/Characters/Visitors/Animations/AnimationVisitor.cpp \
                   ../../Classes/Models/Characters/Visitors/Animations/AnimationMover.cpp \
                   ../../Classes/Models/Characters/Visitors/Animations/AnimationStopper.cpp \
                   ../../Classes/Models/Characters/Visitors/Animations/AnimationJumper.cpp \
                   ../../Classes/Models/Characters/Visitors/Animations/AnimationAttacker.cpp \
                   ../../Classes/Models/Characters/Visitors/Animations/Aspects/AnimationVisitor/AnimationFinishedAspect.cpp \
                   ../../Classes/Models/Characters/Visitors/Models/ModelVisitor.cpp \
                   ../../Classes/Models/Characters/Visitors/Models/ModelMover.cpp \
                   ../../Classes/Models/Characters/Visitors/Models/ModelStopper.cpp \
                   ../../Classes/Models/Characters/Visitors/Models/ModelJumper.cpp \
                   ../../Classes/Models/Characters/Visitors/Models/ModelAttacker.cpp \
                   ../../Classes/Models/Input/Touch/Touch.cpp \
                   ../../Classes/Models/Physics/Physic.cpp \
                   ../../Classes/Models/Physics/PhysicEmpty.cpp \
                   ../../Classes/Models/Physics/PhysicBox.cpp \
                   ../../Classes/Models/Physics/PhysicPolygon.cpp \
                   ../../Classes/Models/Maps/Map.cpp \
                   ../../Classes/Models/Maps/MapBuilder.cpp\
                   ../../Classes/Models/Maps/Texture.cpp \
                   ../../Classes/Models/Maps/Surface.cpp \
                   ../../Classes/Models/Maps/Limit.cpp \
                   ../../Classes/Models/Environment/Damager.cpp \
                   ../../Classes/Views/Node.cpp \
                   ../../Classes/Views/Map.cpp \
                   ../../Classes/Views/Input/Touch/Touch.cpp \
                   ../../Classes/Views/Input/Touch/MovementTouch.cpp \
                   ../../Classes/Views/Input/Touch/Controller.cpp \
                   ../../Classes/Views/Input/Touch/Aspects/Aspect.cpp \
                   ../../Classes/Views/Input/Touch/Aspects/PressAspect.cpp \
                   ../../Classes/Controllers/Character/CommandDealer.cpp \
                   ../../Classes/Controllers/Character/CharacterCommand.cpp \
                   ../../Classes/Controllers/Character/Stopper.cpp \
                   ../../Classes/Controllers/Character/Mover.cpp \
                   ../../Classes/Controllers/Character/Jumper.cpp \
                   ../../Classes/Controllers/Character/Attacker.cpp \
                   ../../Classes/Controllers/Command.cpp \
                   ../../Classes/Controllers/Aspects/Command/CommandFinishedAspect.cpp \
				   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END