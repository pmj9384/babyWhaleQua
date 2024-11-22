#include "stdafx.h"
#include "ChaseMovement.h"
#include "Enemy.h"
#include "Player.h"


void ChaseMovement::LoadAnimation(const std::string& filePath)
{
    try
    {
        rapidcsv::Document doc(filePath);
        stateTextures.clear();

        for (size_t i = 0; i < doc.GetRowCount(); ++i)
        {
            std::string state = doc.GetCell<std::string>(0, i); // ���� (Run ��)
            std::string texturePath = doc.GetCell<std::string>(1, i);
            stateTextures[state].push_back(texturePath);
        }

        std::cout << "[DEBUG] Loaded animation from: " << filePath << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "[ERROR] Failed to load animation: " << filePath << " - " << e.what() << std::endl;
    }
}

void ChaseMovement::PlayState(const std::string& state, Enemy* enemy)
{
    if (currentState != state)
    {
        currentState = state;
        currentFrame = 0;
        animationTimer = 0.f;

        const auto& textures = stateTextures[state];
        if (!textures.empty())
        {
            const sf::Texture& texture = TEXTURE_MGR.Get(textures[currentFrame]);
            enemy->GetBody().setTexture(texture);
            enemy->GetBody().setTextureRect({ 0, 0, (int)texture.getSize().x, (int)texture.getSize().y });
        }
    }
}

ChaseMovement::ChaseMovement(const std::string& name)
{
    animationFilePath = "animations/Shark.csv";
    LoadAnimation(animationFilePath);
}

void ChaseMovement::Update(float dt, Enemy* enemy, Player* player)
{
    animationTimer += dt;
    if (animationTimer >= animationInterval)
    {
        animationTimer = 0.f;
        const auto& textures = stateTextures[currentState];
        if (!textures.empty())
        {
            currentFrame = (currentFrame + 1) % textures.size();
            const sf::Texture& texture = TEXTURE_MGR.Get(textures[currentFrame]);
            enemy->GetBody().setTexture(texture);
            enemy->GetBody().setTextureRect({ 0, 0, (int)texture.getSize().x, (int)texture.getSize().y });
        }
    }
    if (player == nullptr)
    {
        return;
    }

    sf::Vector2f playerPos = player->GetPosition();
    sf::Vector2f enemyPos = enemy->GetPosition();
    float distance = Utils::Distance(playerPos, enemyPos);


    const float MIN_DISTANCE = 150.0f; // �ּҰŸ� 
    const float MAX_DISTANCE = 300.0f; //�ִ�Ÿ�

    if (distance > MAX_DISTANCE)
    {
        if (currentState != "Run")
        {
            PlayState("Run", enemy);
        }                                   
        return;
    }


    // �÷��̾ �ʹ� ������ ������ �̵� ����
    if (distance < MIN_DISTANCE)
    {
        if (currentState != "Eat")
        {
            PlayState("Eat", enemy);
        }
        return;
    }
    if (currentState != "Run")
    {
        PlayState("Run", enemy);
    }
    sf::Vector2f direction = Utils::GetNormal(playerPos - enemyPos);

    if (std::isnan(direction.x) || std::isnan(direction.y)) //������ �̵� ���� ���� ��ġ�� ���Ƽ� ���� ���Ͱ� ��� �Ұ����� ��Ȳ
    {       
        return;
    }

    enemy->SetDirection(direction);
    float speed = enemy->GetSpeed();
    enemy->SetPosition(enemyPos + direction * speed * dt);
}
