#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(const std::string& name)
	: name(name), originPreset(Origins::TL)
{

}

void GameObject::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = { 0.f, 0.f };
}
