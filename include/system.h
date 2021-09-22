#pragma once

namespace sf
{
class RenderWindow;
}

class System
{
public:
    virtual ~System() = default;
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Destroy() = 0;
};

class DrawInterface
{
public:
    virtual ~DrawInterface() = default;
    virtual void Draw(sf::RenderWindow& window) = 0;
};

class DrawImGuiInterface
{
public:
    virtual ~DrawImGuiInterface() = default;
    virtual void DrawImGui() = 0;
};