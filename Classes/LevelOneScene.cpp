#include "LevelOneScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* LevelOneScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

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
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 position((9)*cocos2d::Sprite::create("BoxSample.png")->getContentSize().width, (35)*cocos2d::Sprite::create("BoxSample.png")->getContentSize().height);
	this->ryunosuke = new NinjaNoMeiyo::Models::Characters::Ryunosuke(position);
	this->ryunosukeView = new NinjaNoMeiyo::Views::Node(*this->ryunosuke, *this);
	this->ryunosuke->setCollisionEventDispatchers();

	this->enemy = new NinjaNoMeiyo::Models::Characters::Enemies::Enemy(position + Vec2((30)*cocos2d::Sprite::create("BoxSample.png")->getContentSize().width, 0.0));
	this->enemyView = new NinjaNoMeiyo::Views::Node(*this->enemy, *this);
	this->enemy->setCollisionEventDispatchers();

	NinjaNoMeiyo::Models::Maps::Map map = NinjaNoMeiyo::Models::Maps::MapBuilder::getInstance().get("TileMaps/level1.tmx");
	this->viewMap = new NinjaNoMeiyo::Views::Map(map, *this);

	this->viewMap->spawn();
	this->ryunosukeView->spawn();
	this->enemyView->spawn();

	//auto escuchador = cocos2d::EventListenerPhysicsContact::create();
	//escuchador->onContactBegin = CC_CALLBACK_1(LevelOneScene::onContactBegin, this);
	//escuchador->onContactSeparate = CC_CALLBACK_1(LevelOneScene::onContactBegin, this);
	//this->nodeView->getNodeSprite().getEventDispatcher()->addEventListenerWithSceneGraphPriority(escuchador, &nodeView->getNodeSprite());

	auto followTheSprite = Follow::create(&this->ryunosukeView->getNodeSprite());
	this->runAction(followTheSprite);

	controller = new NinjaNoMeiyo::Views::Input::Touch::Controller(*this, *this->ryunosuke, visibleSize);

	return true;
}

bool LevelOneScene::onContactBegin(PhysicsContact &contact) {
		CCLOG("XD");
	if (contact.getShapeA()->getBody()->getCollisionBitmask() == 3 || contact.getShapeB()->getBody()->getCollisionBitmask() == 3) {
		return true;
	}
	return false;
}

void LevelOneScene::x(float dt) {
}

void LevelOneScene::y(float dt) {
	//this->node->setTexture("DefaultTexture.png");
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