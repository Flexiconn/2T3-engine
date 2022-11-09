#pragma once
#include <GLFW/glfw3.h>
#include "RenderManager.h"
#include "Scene.h"
#include <stdio.h>

class GameState
{
public:
	GameState(Scene startScene);
	~GameState();
	void Loop();
	void ChangeScene(Scene scene);
	static GameState* getInstance() {
		if (!instance)
			return nullptr;
		return instance;
	}
private:
	Scene nextScene;
	bool hasNextScene;
	static GameState* instance;
	Scene currentScene;
	GLFWwindow* window;
	RenderManager renderManager;
};

void GameState::ChangeScene(Scene scene) {
	nextScene = scene;
	hasNextScene = true;
}

void GameState::Loop() {
	std::vector<GameObject> startList = currentScene.GetObjectStartList();
	for (GameObject object : startList)
	{
		object.Start();
	}

	currentScene.ObjectHasStarted();
	
	std::vector<GameObject> updateList = currentScene.GetObjectUpdateList();
	for (GameObject object : updateList)
	{
		object.Update();
	}
	//renderManager.RenderFrame();

	if (hasNextScene == true) {
		hasNextScene = false;
		currentScene = nextScene;
	}
}

GameState::GameState(Scene startScene)
{
	currentScene = startScene;
	window = glfwCreateWindow(800, 600, "Game", NULL, NULL);
	renderManager = RenderManager();
	renderManager.SetUp(window);

}

GameState::~GameState()
{
}