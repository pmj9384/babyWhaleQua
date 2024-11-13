#pragma once

class UiHud : public GameObject
{
protected:

	sf::Text textScore;
	sf::Text textHighScore;

	sf::Sprite iconAmmoIcon;
	sf::Text textAmmo;
	sf::RectangleShape gaugeHp;
	sf::Text textWave;
	sf::Text textZombieCount;

	sf::Vector2f gaugeHpMaxSize = { 400.f, 50.f };

public:
	UiHud(const std::string& name = "");
	~UiHud() = default;

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

	void SetScore(int s);
	void SetHiScore(int s);
	void SetAmmo(int current, int total);
	void SetHp(int hp, int max);
	void SetWave(int w);
	void SetZombieCount(int count);
};
