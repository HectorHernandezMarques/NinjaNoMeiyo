#include "LevelOneScene.h"
#include "SimpleAudioEngine.h"
#include ".\Ryunosuke.h"
#include ".\MovementTouch.h"
#include ".\Terrain.h"

USING_NS_CC;

Scene* LevelOneScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    // 'layer' is an autorelease object
    auto layer = LevelOneScene::create();
    layer->sceneWorld = scene->getPhysicsWorld();

	layer->sceneWorld->setGravity(Vec2(0.0, -MYFUCKINGWORLDGRAVITY));

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LevelOneScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

    /*
	auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(LevelOneScene::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	*/

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    //auto label = Label::createWithTTF(Convert(Director::getInstance()->getOpenGLView()->getFrameSize().width) + "x" + Convert(Director::getInstance()->getOpenGLView()->getFrameSize().height), "fonts/Marker Felt.ttf", 124);

    // position the label on the center of the screen
    //label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                        origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    //this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);

    NinjaM::Node *ryunosuke = new NinjaM::Ryunosuke(visibleSize, Vec2(visibleSize.width / 2 , visibleSize.height / 2), Vec2::ZERO, "Ryunosuke1D.png", 0.0);
    ryunosuke->spawn(this);
	((NinjaM::Ryunosuke*)ryunosuke)->setEventDispatcher();
	
	//top edge
    auto topEdgeBody = PhysicsBody::createBox( cocos2d::Size(visibleSize.width, 1), PHYSICSBODY_MATERIAL_DEFAULT);
	topEdgeBody->setDynamic(false);
	topEdgeBody->setCollisionBitmask(AIR_BITMASK);
	topEdgeBody->setContactTestBitmask(true);

    auto topEdgeNode = Node::create();
    topEdgeNode->setPosition( Vec2(visibleSize.width/2 + origin.x, visibleSize.height + origin.y) );

    topEdgeNode->setPhysicsBody( topEdgeBody );

    this->addChild( topEdgeNode );

	//bottom edge
	auto bottomEdgeBody = PhysicsBody::createBox(cocos2d::Size(visibleSize.width, 2), PHYSICSBODY_MATERIAL_DEFAULT);
	bottomEdgeBody->setDynamic(false);
	bottomEdgeBody->setCollisionBitmask(FLOOR_BITMASK);
	bottomEdgeBody->setContactTestBitmask(true);

	auto bottomEdgeNode = Node::create();
	bottomEdgeNode->setPosition(Vec2(visibleSize.width/2 + origin.x, origin.y));

	bottomEdgeNode->setPhysicsBody(bottomEdgeBody);

	this->addChild(bottomEdgeNode);

	//left edge
	auto leftEdgeBody = PhysicsBody::createBox(cocos2d::Size(3, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT);
	leftEdgeBody->setDynamic(false);
	leftEdgeBody->setCollisionBitmask(LEFT_OBSTACLE_BITMASK);
	leftEdgeBody->setContactTestBitmask(true);

	auto leftEdgeNode = Node::create();
	leftEdgeNode->setPosition(Vec2(origin.x, visibleSize.height/2 + origin.y));

	leftEdgeNode->setPhysicsBody(leftEdgeBody);

	this->addChild(leftEdgeNode);

	//right edge
	auto rightEdgeBody = PhysicsBody::createBox(cocos2d::Size(3, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT);
	rightEdgeBody->setDynamic(false);
	rightEdgeBody->setCollisionBitmask(RIGHT_OBSTACLE_BITMASK);
	rightEdgeBody->setContactTestBitmask(true);

	auto rightEdgeNode = Node::create();
	rightEdgeNode->setPosition(Vec2(visibleSize.width + origin.x, visibleSize.height/2 + origin.y));

	rightEdgeNode->setPhysicsBody(rightEdgeBody);

	this->addChild(rightEdgeNode);

    NinjaM::Node *box = new NinjaM::Terrain(visibleSize, Vec2(visibleSize.width / 2 , 0), Vec2::ZERO, "HelloWorld.png", 0.0);
    box->spawn(this);

    NinjaM::Node *rightMovementTouch = new NinjaM::MovementTouch(visibleSize, Vec2(visibleSize.width / 2 + origin.x, 0), Vec2::ZERO, 0.0, RYUNOSUKE_SPEED, ((NinjaM::Ryunosuke*)ryunosuke));
    rightMovementTouch->spawn(this);
    ((NinjaM::MovementTouch*)rightMovementTouch)->setEventDispatcher();

    NinjaM::Node *leftMovementTouch = new NinjaM::MovementTouch(visibleSize, Vec2::ZERO, Vec2::ZERO, 0.0, -RYUNOSUKE_SPEED, ((NinjaM::Ryunosuke*)ryunosuke));
    leftMovementTouch->spawn(this);
    ((NinjaM::MovementTouch*)leftMovementTouch)->setEventDispatcher();



    return true;
}


void LevelOneScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
