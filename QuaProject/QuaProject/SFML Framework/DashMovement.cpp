#include "stdafx.h"
#include "DashMovement.h"
#include "Enemy.h"
#include "Player.h"

void DashMovement::LoadAnimation(const std::string& filePath)
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

void DashMovement::PlayState(const std::string& state, Enemy* enemy)
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

DashMovement::DashMovement(const std::string& name)
{
    animationFilePath = "animations/purpleFish.csv";
    LoadAnimation(animationFilePath);
}

void DashMovement::Update(float dt, Enemy* enemy, Player* player)
{
    dashTimer += dt;
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
    if (isDashing)
    {
        enemy->SetPosition(enemy->GetPosition() + enemy->GetDirection() * enemy->GetSpeed() * dashSpeedMultiplier * dt);

        // ��� ���� �ð��� ������ "Idle" ���·� ����
        if (dashTimer >= dashDuration)
        {
            dashTimer = 0.f; // Ÿ�̸� �ʱ�ȭ
            isDashing = false;
            PlayState("Idle", enemy);
        }
        else
        {
            PlayState("Dash", enemy); // ��� ���� ����
        }
    }
    else
    {
        enemy->SetPosition(enemy->GetPosition() + enemy->GetDirection() * enemy->GetSpeed() * dt);
        // "Idle" ���·� ���� �� ���

        // ��� ������ ä��� ��� ����
        if (dashTimer >= dashInterval)
        {
            dashTimer = 0.f; // Ÿ�̸� �ʱ�ȭ
            isDashing = true;
            PlayState("Dash", enemy);
        }
        else
        {
            PlayState("Idle", enemy); // ��� ���� ���� "Idle" ���� ����
        }

    }
}
