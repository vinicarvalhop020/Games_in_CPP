#include <SFML/Graphics.hpp>
#include "paddle_ia.h"

paddle_ia::paddle_ia() : paddle() {
    shape.setFillColor(sf::Color::Red); 
}

paddle_ia::paddle_ia(int x, int y, int width, int height) : paddle(x, y, width, height) {
    shape.setFillColor(sf::Color::Red); 
}

void paddle_ia::updatePosition(float ballY, int windowHeight, int velocity) {
    //se a posicao da bola é menor que a posicao x do paddle
    float paddle_center = static_cast<float>(y) + static_cast<float>(height) / 2;
    if (ballY < paddle_center) {
        paddle::updatePosition(-velocity, windowHeight); // Move o paddle para cima
    }
    else if (ballY > paddle_center) {
        paddle::updatePosition(velocity, windowHeight); // Move o paddle para baixo
    }
    // Caso contrário, o paddle permanece na mesma posição
}


