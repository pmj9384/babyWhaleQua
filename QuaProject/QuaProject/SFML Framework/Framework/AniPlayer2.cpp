#include "stdafx.h"
#include "AniPlayer2.h"

AniPlayer2::AniPlayer2(const std::string& name)
	: GameObject(name)
{
}

void AniPlayer2::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void AniPlayer2::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void AniPlayer2::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void AniPlayer2::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(body, originPreset);
	}
}

void AniPlayer2::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	body.setOrigin(origin);
}

void AniPlayer2::Init()
{
	std::string textureId = "graphics/RubySheet.png";

	int width = 256;
	int height = 256;


	{
		AnimationClip clip;
		clip.id = "IdleSide";
		clip.fps = 3;
		clip.loopType = AnimationLoopTypes::Loop;
		clip.frames.push_back({ textureId, { 0, 3 * height, width, height } });
		clip.frames.push_back({ textureId, { 1 * width, 5 * height, width, height } });
		temp.insert({ "IdleSide", clip });
	}
	{
		AnimationClip clip;
		clip.id = "IdleDown";
		clip.fps = 3;
		clip.loopType = AnimationLoopTypes::Loop;
		clip.frames.push_back({ textureId, { 1 * width, 3 * height, width, height } });
		clip.frames.push_back({ textureId, { 2 * width, 5 * height, width, height } });
		temp.insert({ "IdleDown", clip });
	}
	{
		AnimationClip clip;
		clip.id = "IdleUp";
		clip.fps = 3;
		clip.loopType = AnimationLoopTypes::Loop;
		clip.frames.push_back({ textureId, { 2 * width, 3 * height, width, height } });
		clip.frames.push_back({ textureId, { 3 * width, 5 * height, width, height } });
		temp.insert({ "IdleUp", clip });
	}
	{
		AnimationClip clip;
		clip.id = "MoveSide";
		clip.fps = 10;
		clip.loopType = AnimationLoopTypes::Loop;
		for (int i = 0; i < 4; ++i)
		{
			clip.frames.push_back({ textureId, { i * width, 0, width, height } });
		}
		temp.insert({ "MoveSide", clip });
	}
	{
		AnimationClip clip;
		clip.id = "MoveUp";
		clip.fps = 10;
		clip.loopType = AnimationLoopTypes::Loop;
		for (int i = 0; i < 4; ++i)
		{
			clip.frames.push_back({ textureId, { i * width, height, width, height } });
		}
		temp.insert({ "MoveUp", clip });
	}
	{
		AnimationClip clip;
		clip.id = "MoveDown";
		clip.fps = 10;
		clip.loopType = AnimationLoopTypes::Loop;
		for (int i = 0; i < 4; ++i)
		{
			clip.frames.push_back({ textureId, { i * width, 2 * height, width, height } });
		}
		temp.insert({ "MoveDown", clip });
	}

	clipInfos.push_back({ "IdleSide", "MoveSide", false, Utils::GetNormal({-1.f, -1.f}) });
	clipInfos.push_back({ "IdleUp", "MoveUp", false, {0.f, -1.f} });
	clipInfos.push_back({ "IdleSide", "MoveSide", true, Utils::GetNormal({1.f, -1.f}) });

	clipInfos.push_back({ "IdleSide", "MoveSide", false, {-1.f, 0.f} });
	clipInfos.push_back({ "IdleSide", "MoveSide", true, {1.f, 0.f} });

	clipInfos.push_back({ "IdleSide", "MoveSide", false, Utils::GetNormal({-1.f, -1.f}) });
	clipInfos.push_back({ "IdleDown", "MoveDown", false, {0.f, 1.f} });
	clipInfos.push_back({ "IdleSide", "MoveSide", true, Utils::GetNormal({1.f, -1.f}) });


	animator.SetTarget(&body);
}

void AniPlayer2::Release()
{
}

void AniPlayer2::Reset()
{
	//body.setTexture(TEXTURE_MGR.Get("graphics/RubySheet.png"));
	//body.setTextureRect({ 0, 0, 256, 256 });
	animator.Play(&temp["IdleDown"]);
	currentClipInfo = &clipInfos[6];
	SetOrigin(Origins::BC);
}

void AniPlayer2::Update(float dt)
{
	animator.Update(dt);

	direction.x = InputMgr::GetAxis(Axis::Horizontal);
	direction.y = InputMgr::GetAxis(Axis::Vertical);
	float mag = Utils::Magnitude(direction);
	if (mag > 1.f)
	{
		Utils::Normalize(direction);
	}
	SetPosition(position + direction * speed * dt);

	if (direction.x != 0.f || direction.y != 0.f)
	{
		auto min = std::min_element(clipInfos.begin(), clipInfos.end(),
			[this](const ClipInfo& lhs, const ClipInfo& rhs)
			{
				float d1 = Utils::Distance(direction, lhs.point);
				float d2 = Utils::Distance(direction, rhs.point);
				return d1 < d2;
			}
		);
		currentClipInfo = &(*min);
	}

	//SetScale({ currentClipInfo->flipX ? -1.f : 1.f, 1.f });
	if (currentClipInfo->flipX)
	{
		SetScale({ -1.f, 1.0f });
	}
	else
	{
		SetScale({ 1.f, 1.0f });
	}

	const auto& clipId = (direction.x != 0.f || direction.y != 0.f) ? currentClipInfo->move : currentClipInfo->idle;

	if (animator.GetCurrentClipId() != clipId)
	{
		animator.Play(&temp[clipId]);
	}

}

void AniPlayer2::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
