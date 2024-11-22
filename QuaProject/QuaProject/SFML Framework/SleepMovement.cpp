#include "stdafx.h"
#include "SleepMovement.h"



void SleepMovement::LoadAnimation(const std::string& filePath)
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

void SleepMovement::PlayState(const std::string& state, Enemy* enemy)
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

    // �ִϸ��̼� ������Ʈ
    animationTimer += animationInterval;
    if (animationTimer >= animationInterval)
    {
        animationTimer = 0.f;

        const auto& textures = stateTextures[state];
        if (!textures.empty())
        {
            currentFrame = (currentFrame + 1) % textures.size();
            const sf::Texture& texture = TEXTURE_MGR.Get(textures[currentFrame]);
            enemy->GetBody().setTexture(texture);
            enemy->GetBody().setTextureRect({ 0, 0, (int)texture.getSize().x, (int)texture.getSize().y });
        }
    }
}
SleepMovement::SleepMovement(const std::string& name)
{
    animationFilePath = "animations/blueFish.csv";
    LoadAnimation(animationFilePath);
}

void SleepMovement::Update(float dt, Enemy* enemy, Player* player)
{
    sleepTimer += dt;

    if (isSleeping)
    {
        // ���� �ӵ��� ������ ����
        PlayState("Idle", enemy);
        enemy->SetPosition(enemy->GetPosition());

        // ���� ���� �ð��� ������ ����
        if (sleepTimer >= sleepDuration)
        {
            sleepTimer = 0.0f;
            isSleeping = false;

        }
    }
    else
    {

        PlayState("Run", enemy);

        sf::Vector2f newPosition = enemy->GetPosition() + enemy->GetDirection() * enemy->GetSpeed() * dt;
        enemy->SetPosition(newPosition);

        // ���� ���·� ��ȯ
        if (sleepTimer >= sleepInterval)
        {
            sleepTimer = 0.0f;
            isSleeping = true;
            sleepInterval = static_cast<float>(Utils::RandomRange(3, 5)); // 3~5�� ������ ���ο� ���͹�
        }
    }
}
