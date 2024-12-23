#pragma once

class UiHud : public GameObject
{
public:


protected:

	sf::Text textScore;
	sf::Text textHighScore;

	sf::Sprite iconAmmoIcon;
	sf::Sprite 	iconGameDoum;
	sf::Sprite iconGameOver;
	sf::Sprite iconGameClear;
	sf::Sprite MainWindow;
	sf::Sprite bubble;

	sf::Text textAmmo;
	sf::RectangleShape gaugeHp;
	sf::Text textWave;
	sf::Text textZombieCount;
	
	sf::Vector2f gaugeHpMaxSize = { 400.f, 50.f };

	int currentScore = 0;

	
	HitBox buttonHitBox;           // 메인 화면 버튼
	HitBox buttonHitBox2;
	HitBox buttonHitBox3;
	HitBox buttonHitBox4;
	HitBox buttonHitBox5;

	std::map<Enemy::Types, sf::Text> targetKillTexts; // 적 처치 목표 텍스트
	Wave* wave;
	SceneGame* sceneGame;

	//bool isGameOverVisible;
	float windowWidth = 1920.f;
	float windowHeight = 1080.f;

	float buttonWidth = 200.f;
	float buttonHeight = 50.f;

	bool isBgmPlaying = false;
public:
	bool isGameDoumVisible = false;
	bool isGameClearVisible = true;
	bool isMainWindowVisible = true;
	bool isGameOverVisible = true;
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


	void ShowGameOver(bool show);
	void SetMainWindow(int m);
	bool IsButtonClicked(const sf::Vector2f& mousePos);
	void HandleEvent(const sf::Event& event);

	void UpdateTargetKillText(Enemy::Types type, int remaining); // 텍스트 업데이트 함수
};
