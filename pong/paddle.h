//Paddle default, depois sera usado herança para criar paddle dos jogadores

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class paddle {
    protected:
        int x, y; // posição
        int width, height; // dimensões
        sf::RectangleShape shape; // forma do paddle

    public:
        paddle();
        paddle(int x, int y, int width, int height);
        int getX();
        int getY();
        int getWidth();
        int getHeight();
        void setX(int newX);
        void setY(int newY);
        void setWidth(int newWidth);
        void setHeight(int newHeight);
        void updatePosition(int dy, int windowHeight); 
        void draw(sf::RenderWindow& window);
};

