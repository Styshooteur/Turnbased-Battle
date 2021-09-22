#pragma once

#include <string>
#include <array>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Socket.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/System/Vector2.hpp>

#include "morpion_settings.h"
#include "system.h"

namespace morpion
{

class MorpionClient : public System
{
public:
    sf::Socket::Status Connect(sf::IpAddress address, unsigned short portNumber);
    MorpionPhase GetPhase() const;
    bool IsConnected() const;
    void Init() override;
    void ReceivePacket(sf::Packet& packet);
    void Update() override;
    void Destroy() override;
    int GetPlayerNumber() const;
    void SendNewMove(sf::Vector2i position);
    const std::array<Move, 9>& GetMoves() const;
    unsigned char GetMoveIndex() const;
    std::string_view GetEndMessage() const;
private:
    sf::TcpSocket socket_;
    MorpionPhase phase_ = MorpionPhase::CONNECTION;
    std::array<Move, 9> moves_{};
    unsigned char currentMoveIndex_ = 0;
    std::string endMessage_;
    PlayerNumber playerNumber_ = 255u;
};


class MorpionView : public DrawImGuiInterface
{
public:
    MorpionView(MorpionClient& client);
    void DrawImGui() override;
private:
    MorpionClient& client_;
    std::string ipAddressBuffer_ = "localhost";
    int portNumber_ = serverPortNumber;
    std::array<int, 2> currentPosition_{};
};
}