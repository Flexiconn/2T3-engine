#include <string>
struct XYZ {
	float X;
	float Y;
	float Z;
};

class GameObject
{

public:
	void Start();
	void Update();
	XYZ GetPosition();
	XYZ GetRotation();
	XYZ GetScale();
	void SetPosition(XYZ);
	void SetRotation(XYZ);
	void SetScale(XYZ);
	GameObject();
	~GameObject();

private:
	int id;
	std::string name;
	XYZ rotation, position, scale;
};

GameObject::GameObject()
{

}

GameObject::~GameObject()
{
}

XYZ GameObject::GetPosition() {
	return position;
}

XYZ GameObject::GetRotation() {
	return rotation;
}

XYZ GameObject::GetScale() {
	return scale;
}

void GameObject::SetPosition(XYZ _position) {
	position = _position;
}

void GameObject::SetRotation(XYZ _rotation) {
	rotation = _rotation;
}

void GameObject::SetScale(XYZ _scale) {
	scale = _scale;
}

