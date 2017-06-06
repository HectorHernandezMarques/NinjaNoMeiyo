#include "LevelOneScene.h"
#include "SimpleAudioEngine.h"
#include ".\Ryunosuke.h"
#include ".\MovementTouch.h"
#include ".\Surface.h"
#include ".\Limit.h"

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

    NinjaM::Node *ryunosuke = new NinjaM::Ryunosuke(visibleSize, Vec2((5)*cocos2d::Sprite::create("BoxSample.png")->getContentSize().width, (5800 / 80)*cocos2d::Sprite::create("BoxSample.png")->getContentSize().height), Vec2::ZERO, "Ryunosuke1D.png", 0.0, cocos2d::Sprite::create("BoxSample.png")->getContentSize());
    ryunosuke->spawn(this);
	((NinjaM::Ryunosuke*)ryunosuke)->setEventDispatcher();
	
	/*
	//top edge
    auto topEdgeBody = PhysicsBody::createBox( cocos2d::Size(visibleSize.width, 1), PHYSICSBODY_MATERIAL_DEFAULT);
	topEdgeBody->setDynamic(false);
	topEdgeBody->setCollisionBitmask(AIR_BITMASK);
	topEdgeBody->setContactTestBitmask(true);

    auto topEdgeNode = Node::create();
    topEdgeNode->setPosition( Vec2(visibleSize.width/2, visibleSize.height) );

    topEdgeNode->setPhysicsBody( topEdgeBody );

    this->addChild( topEdgeNode );

	//bottom edge
	NinjaM::Node *floor = new NinjaM::Terrain(visibleSize, Vec2(0, 0), Vec2::ZERO, "FloorTest.png", 0.0);
	floor->spawn(this);

	//left edge
	auto leftEdgeBody = PhysicsBody::createBox(cocos2d::Size(3, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT);
	leftEdgeBody->setDynamic(false);
	leftEdgeBody->setCollisionBitmask(LEFT_OBSTACLE_BITMASK);
	leftEdgeBody->setContactTestBitmask(true);

	auto leftEdgeNode = Node::create();
	leftEdgeNode->setPosition(Vec2(0, visibleSize.height/2));

	leftEdgeNode->setPhysicsBody(leftEdgeBody);

	this->addChild(leftEdgeNode);

	//right edge
	auto rightEdgeBody = PhysicsBody::createBox(cocos2d::Size(3, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT);
	rightEdgeBody->setDynamic(false);
	rightEdgeBody->setCollisionBitmask(RIGHT_OBSTACLE_BITMASK);
	rightEdgeBody->setContactTestBitmask(true);

	auto rightEdgeNode = Node::create();
	rightEdgeNode->setPosition(Vec2(floor->getNodeSprite()->getContentSize().width, visibleSize.height/2));

	rightEdgeNode->setPhysicsBody(rightEdgeBody);

	this->addChild(rightEdgeNode);
    NinjaM::Node *box = new NinjaM::Terrain(visibleSize, Vec2(700, floor->getNodeSprite()->getContentSize().height), Vec2::ZERO, "Box.png", 0.0);
    ((NinjaM::Terrain*)box)->spawn(this, AIR_BITMASK,  LEFT_OBSTACLE_BITMASK, RIGHT_OBSTACLE_BITMASK, CEILING_BITMASK);

	NinjaM::Node *boxED = new NinjaM::Terrain(visibleSize, Vec2(700 + box->getNodeSprite()->getContentSize().height * 2, floor->getNodeSprite()->getContentSize().height + box->getNodeSprite()->getContentSize().height), Vec2::ZERO, "BoxED.png", 0.0);
	((NinjaM::Terrain*)boxED)->spawn(this, EDGE_FLOOR_LEFT_BITMASK, EDGE_LEFT_OBSTACLE_BITMASK, AIR_BITMASK, CEILING_BITMASK);

	NinjaM::Node *boxEI = new NinjaM::Terrain(visibleSize, Vec2(700, floor->getNodeSprite()->getContentSize().height + box->getNodeSprite()->getContentSize().height), Vec2::ZERO, "BoxEI.png", 0.0);
	((NinjaM::Terrain*)boxEI)->spawn(this, EDGE_FLOOR_RIGHT_BITMASK, AIR_BITMASK, EDGE_RIGHT_OBSTACLE_BITMASK, CEILING_BITMASK);

	NinjaM::Node *boxC = new NinjaM::Terrain(visibleSize, Vec2(700 + box->getNodeSprite()->getContentSize().height, floor->getNodeSprite()->getContentSize().height + box->getNodeSprite()->getContentSize().height), Vec2::ZERO, "BoxC.png", 0.0);
	((NinjaM::Terrain*)boxC)->spawn(this, FLOOR_BITMASK, AIR_BITMASK, AIR_BITMASK, CEILING_BITMASK);
*/
    NinjaM::Node *rightMovementTouch = new NinjaM::MovementTouch(visibleSize, Vec2(visibleSize.width / 2, 0), Vec2::ZERO, 0.0, RYUNOSUKE_SPEED, ((NinjaM::Ryunosuke*)ryunosuke));
    rightMovementTouch->spawn(this);
    ((NinjaM::MovementTouch*)rightMovementTouch)->setEventDispatcher();

    NinjaM::Node *leftMovementTouch = new NinjaM::MovementTouch(visibleSize, Vec2::ZERO, Vec2::ZERO, 0.0, -RYUNOSUKE_SPEED, ((NinjaM::Ryunosuke*)ryunosuke));
    leftMovementTouch->spawn(this);
    ((NinjaM::MovementTouch*)leftMovementTouch)->setEventDispatcher();

	this->createWorld("TileMaps/level1.tmx", cocos2d::Sprite::create("BoxSample.png")->getContentSize());

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

void LevelOneScene::createWorld(std::string path, Size boxSize)
{
	auto map = TMXTiledMap::create(path);
	TMXObjectGroup *objects = map->getObjectGroup("Textures");
	ValueVector vectorObjects = objects->getObjects();
	ValueMap properties;
	Size tiledBoxSize(-1, -1);

	for (const auto& object : vectorObjects)
	{
		properties = object.asValueMap();
		if (tiledBoxSize.height == -1)
		{
			tiledBoxSize.width = properties["width"].asInt();
			tiledBoxSize.height = properties["height"].asInt();
		}
		auto sprite = Sprite::create(properties["type"].asString());
		sprite->setPosition(Vec2((properties["x"].asInt() / tiledBoxSize.width)*boxSize.width, (properties["y"].asInt() / tiledBoxSize.height)*boxSize.height));
		sprite->setAnchorPoint(Vec2::ZERO);
		this->addChild(sprite, 0);
	}

	objects = map->getObjectGroup("Surfaces");
	vectorObjects = objects->getObjects();

	for (const auto& object : vectorObjects)
	{
		properties = object.asValueMap();

		Size surfaceSize((properties["width"].asInt() / tiledBoxSize.width)*boxSize.width, (properties["height"].asInt() / tiledBoxSize.height)*boxSize.height);
		NinjaM::Node *box = new NinjaM::Surface(Director::getInstance()->getVisibleSize(), Vec2((properties["x"].asInt() / tiledBoxSize.width)*boxSize.width, ((properties["y"].asInt() / tiledBoxSize.height) + (properties["height"].asInt() / tiledBoxSize.height) - 1)*boxSize.height), Vec2::ZERO, "", 0.0, surfaceSize);
		((NinjaM::Surface*)box)->spawn(this, properties["upperSurfaceBitmask"].asInt(), properties["rightSurfaceBitmask"].asInt(), properties["leftSurfaceBitmask"].asInt(), properties["lowerSurfaceBitmask"].asInt());
	}

	objects = map->getObjectGroup("Limits");
	vectorObjects = objects->getObjects();

	for (const auto& object : vectorObjects)
	{
		properties = object.asValueMap();

		Size surfaceSize((properties["width"].asInt() / tiledBoxSize.width)*boxSize.width, (properties["height"].asInt() / tiledBoxSize.height)*boxSize.height);
		NinjaM::Node *box = new NinjaM::Limit(Director::getInstance()->getVisibleSize(), Vec2((properties["x"].asInt() / tiledBoxSize.width)*boxSize.width, ((properties["y"].asInt() / tiledBoxSize.height) + (properties["height"].asInt() / tiledBoxSize.height) - 1)*boxSize.height), Vec2::ZERO, "", 0.0, surfaceSize);
		((NinjaM::Limit*)box)->spawn(this, properties["limitBitmask"].asInt());
	}
}