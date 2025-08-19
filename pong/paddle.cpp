#include <SFML/Graphics.hpp>
#include "paddle.h"

paddle::paddle() : x(0), y(0), width(20), height(100) {
    shape.setSize(sf::Vector2f(static_cast<float>(width), static_cast<float>(height))); // Define o tamanho do paddle
    shape.setFillColor(sf::Color::Blue); // Define a cor do paddle
    shape.setPosition(static_cast<float>(x), static_cast<float>(y)); // Define a posição inicial do paddle
}

paddle::paddle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {
    shape.setSize(sf::Vector2f(static_cast<float>(width), static_cast<float>(height))); // Define o tamanho do paddle
    shape.setFillColor(sf::Color::Blue); // Define a cor do paddle
    shape.setPosition(static_cast<float>(x), static_cast<float>(y)); // Define a posição inicial do paddle
}

int paddle::getX() {
    return x;
}

int paddle::getY() {
    return y;
}

int paddle::getWidth() {
    return width;
}

int paddle::getHeight() {
    return height;
}

void paddle::setX(int newX) {
    x = newX;
    shape.setPosition(static_cast<float>(x), static_cast<float>(y)); // Atualiza a posição do paddle
}

void paddle::setY(int newY) {
    y = newY;
    shape.setPosition(static_cast<float>(x), static_cast<float>(y)); // Atualiza a posição do paddle
}

void paddle::setWidth(int newWidth) {
    width = newWidth;
    shape.setSize(sf::Vector2f(static_cast<float>(width), static_cast<float>(height))); // Atualiza o tamanho do paddle
}

void paddle::setHeight(int newHeight) {
    height = newHeight;
    shape.setSize(sf::Vector2f(static_cast<float>(width), static_cast<float>(height))); // Atualiza o tamanho do paddle
}

void paddle::updatePosition(int dy, int windowHeight) {
    if (y + dy < 0 || y + height + dy > windowHeight) { 
        //nao faz nada
    }
    else {
        y += dy; // Atualiza a posição vertical do paddle
    } 
    shape.setPosition(static_cast<float>(x), static_cast<float>(y)); // Atualiza a posição do paddle na forma
}

void paddle::draw(sf::RenderWindow& window) {
    // Desenha o paddle na janela
    shape.setPosition(static_cast<float>(x), static_cast<float>(y)); // Define a posição do paddle
    window.draw(shape); // Desenha o paddle na janela
}