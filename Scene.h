#pragma once
#include "GameObject.h"
#include <vector>

class Scene
{
public:
	std::vector<GameObject> GetObjectUpdateList();
	std::vector<GameObject> GetObjectStartList();
	void ObjectHasStarted();
	Scene();
	~Scene();
private:
	std::vector<GameObject> updateObjectList;
	std::vector<GameObject> startObjectList;
};

std::vector<GameObject> Scene::GetObjectStartList() {
	return startObjectList;
}

std::vector<GameObject> Scene::GetObjectStartList() {
	return updateObjectList;
}

void Scene::ObjectHasStarted() {
	for (GameObject object : startObjectList)
	{
		updateObjectList.push_back(object);
	}
	startObjectList.clear();
}

Scene::Scene()
{
}

Scene::~Scene()
{
}