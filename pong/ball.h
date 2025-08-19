#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class ball {
private:
    int x, y; // posição
    int vx, vy; // velocidade
    sf::CircleShape shape; // forma da bola
    sf::Color color; // cor da bola

public:
    ball();
    ball(int x, int y, int vx, int vy);

    int getX();
    int getY();
    int getVX();
    int getVY();

    void setX(int newX);
    void setY(int newY);
    void setVX(int newVX);
    void setVY(int newVY);

    void updatePosition();
    void rebatidaBorda(int windowWidth, int windowHeight);
    void rebatidaPaddle(int paddleX, int paddleY, int paddleWidth, int paddleHeight);
    void reset(int windowWidth);
    void draw(sf::RenderWindow& window);
};