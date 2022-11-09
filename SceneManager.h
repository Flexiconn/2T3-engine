#pragma once
#include "Scene.h"
#include "GameState.h"
class SceneManager
{
public:
	void setScene(Scene scene);
	SceneManager();
	~SceneManager();
private:

};

void SceneManager::setScene(Scene scene) {
	GameState::getInstance()->ChangeScene(scene);
}
SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
}