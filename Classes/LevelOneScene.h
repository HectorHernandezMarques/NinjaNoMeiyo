#ifndef __LEVELONE_SCENE_H__
#define __LEVELONE_SCENE_H__

#include "cocos2d.h"

class LevelOneScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(LevelOneScene);

private:

    cocos2d::PhysicsWorld *sceneWorld;
};

#endif // __LEVELONE_SCENE_H__
