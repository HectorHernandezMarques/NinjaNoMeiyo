#ifndef __LEVELONE_SCENE_H__
#define __LEVELONE_SCENE_H__

#include "Definitions.h"
#include "cocos2d.h"
#include "./Models/Node.h"
#include "./Models/Characters/Ryunosuke.h"
#include "./Models/Input/Touch/Touch.h"
#include "./Models/Physics/PhysicBox.h"
#include "./Models/Maps/MapBuilder.h"
#include "./Views/Node.h"
#include "./Views/Map.h"
#include "./Views/Input/Touch/Controller.h"

class LevelOneScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(LevelOneScene); 
	void x(float dt);
	void y(float dt);
	bool onContactBegin(cocos2d::PhysicsContact &contact);

private:

    cocos2d::PhysicsWorld *sceneWorld;

	NinjaNoMeiyo::Models::Node *node;
	NinjaNoMeiyo::Views::Node *nodeView;
	NinjaNoMeiyo::Views::Map *viewMap;
	NinjaNoMeiyo::Views::Input::Touch::Controller *controller;
	//void createWorld(std::string path, cocos2d::Size boxSize);
};

#endif // __LEVELONE_SCENE_H__
