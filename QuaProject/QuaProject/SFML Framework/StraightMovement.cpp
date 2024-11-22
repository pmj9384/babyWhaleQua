#include "stdafx.h"
#include "StraightMovement.h"

void StraightMovement::LoadAnimation(const std::string& filePath)
{
    try
    {
        rapidcsv::Document doc(filePath);
        stateTextures.clear();

        for (size_t i = 0; i < doc.GetRowCount(); ++i)
        {
            std::string state = doc.GetCell<std::string>(0, i); // ป๓ลย (Run ต๎)
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

StraightMovement::StraightMovement(const std::string& name)
{
	animationFilePath = "animations/redFish.csv";
	LoadAnimation(animationFilePath);
}

void StraightMovement::Update(float dt, Enemy* enemy, Player* player)
{
	sf::Vector2f direction = enemy->GetDirection();
	enemy->SetPosition(enemy->GetPosition() + direction * enemy->GetSpeed() * dt);

    animationTimer += dt;

    if (animationTimer >= animationInterval)
    {
        animationTimer = 0.f;

        const auto& textures = stateTextures["Run"];
        if (!textures.empty())
        {
            currentFrame = (currentFrame + 1) % textures.size();
            const sf::Texture& texture = TEXTURE_MGR.Get(textures[currentFrame]);
            enemy->GetBody().setTexture(texture);
            enemy->GetBody().setTextureRect({ 0, 0, (int)texture.getSize().x, (int)texture.getSize().y });
        }
    }
}
