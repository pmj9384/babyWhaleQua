#include "stdafx.h"
#include "AniPlayer3.h"

AniPlayer3::AniPlayer3(const std::string& name)
	:GameObject(name)
{
}

void AniPlayer3::Init()
{
	PlayState("Idle");
}

void AniPlayer3::Update(float dt)
{
    animationTimer += dt;

    // Idle�� Run ������ �ִϸ��̼� ó��
    if (currentState == "Idle" || currentState == "Run") {
        if (animationTimer >= animationInterval) {
            animationTimer = 0.f;

            // ���� ������ ��ȯ
            const auto& textures = stateTextures[currentState];
            currentFrame = (currentFrame + 1) % textures.size();

            const sf::Texture& texture = TEXTURE_MGR.Get(textures[currentFrame]);
            body.setTexture(texture);
        }
    }
}

void AniPlayer3::PlayState(const std::string& state)
{
    if (currentState != state) {
        currentState = state;
        currentFrame = 0;
        animationTimer = 0.f;

        // ���� ���� �� ù ��° �ؽ�ó�� ����
        const auto& textures = stateTextures[state];
        if (!textures.empty()) {
            const sf::Texture& texture = TEXTURE_MGR.Get(textures[0]);
            body.setTexture(texture);
        }
    }
}

void AniPlayer3::SetLevel(int level)
{
    std::string filePath;

    switch (level) {
    case 1:
        filePath = "animations/QuaLevel1.csv";
        break;
    case 2:
        filePath = "animations/QuaLevel2.csv";
        break;
    case 3:
        filePath = "animations/QuaLevel3.csv";
        break;
    case 4:
        filePath = "animations/QuaLevel4.csv";
        break;
    case 5:
        filePath = "animations/QuaLevel5.csv";
        break;
    case 6:
        filePath = "animations/QuaLevel6.csv";
        break;
    case 7:
        filePath = "animations/QuaLevel7.csv";
        break;
    case 8:
        filePath = "animations/QuaLevel8.csv";
        break;
    case 9:
        filePath = "animations/QuaLevel9.csv";
        break;
    case 10:
        filePath = "animations/QuaLevel10.csv";
        break;
    default:
        std::cerr << "[ERROR] Invalid level: " << level << std::endl;
        return;
    }
    try {
        // CSV ���� �ε� (��� ����)
        rapidcsv::Document doc(filePath, rapidcsv::LabelParams(0, -1));
        stateTextures.clear();

        // ������ �ε�
        for (size_t i = 0; i < doc.GetRowCount(); ++i) {
            std::string state = doc.GetCell<std::string>(0, i);       // ID ��
            std::string texturePath = doc.GetCell<std::string>(1, i); // TEXTURE PATH ��

            // ����� �޽���
            std::cout << "[DEBUG] Loaded state: " << state
                << ", texturePath: " << texturePath << std::endl;

            stateTextures[state].push_back(texturePath); // ���º� �ؽ�ó �߰�
        }

        // �ʱ� ���� ����
        PlayState("Idle");
    }
    catch (const std::exception& e) {
        std::cerr << "[ERROR] Failed to load CSV: " << filePath << " - " << e.what() << std::endl;
    }
}

void AniPlayer3::SetDirection(bool right)
{
    if (isFacingRight != right) 
    {
        isFacingRight = right;
        body.setScale(isFacingRight ? 1.f : -1.f, 1.f); // ���� ��ȯ
    }
}

