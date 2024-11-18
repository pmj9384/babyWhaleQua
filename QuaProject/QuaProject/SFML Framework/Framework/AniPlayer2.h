#pragma once

class AniPlayer2 : public GameObject
{
public:
	struct ClipInfo
	{
		std::string idle;
		std::string move;
		bool flipX = false;
		sf::Vector2f point;
	};

protected:
	sf::Sprite body;
	Animator animator;

	sf::Vector2f direction;
	float speed = 500.f;

	std::map<std::string, AnimationClip> temp;
	std::vector<ClipInfo> clipInfos;
	ClipInfo* currentClipInfo;

public:
	AniPlayer2(const std::string& name = "");
	~AniPlayer2() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};
