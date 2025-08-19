#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.h"


ball::ball() : x(0), y(0), vx(0), vy(0) {
    shape.setRadius(10); // Define o raio da bola
    shape.setFillColor(sf::Color::Red); // Define a cor da bola
    shape.setPosition(static_cast<float>(x), static_cast<float>(y)); // Define a posição inicial da bola
}
ball::ball(int x, int y, int vx, int vy) : x(x), y(y), vx(vx), vy(vy) {
    shape.setRadius(10); // Define o raio da bola
    shape.setFillColor(sf::Color::Red); // Define a cor da bola
    shape.setPosition(static_cast<float>(x), static_cast<float>(y)); // Define a posição inicial da bola
}

int ball::getX(){
    return x;
}

int ball::getY(){
    return y;
}

int ball::getVX(){
    return vx;
}

int ball::getVY(){
    return vy;
}

void ball::setX(int newX){
    x = newX;
}
void ball::setY(int newY){
    y = newY;
}

void ball::setVX(int newVX){
    vx = newVX;
}

void ball::setVY(int newVY){
    vy = newVY;
}
//funcoes
void ball::updatePosition() {
    x += vx;
    y += vy;
}

void ball::rebatidaBorda(int windowWidth, int windowHeight) {

    if (y <= 0 || y >= windowHeight) {
        vy = -vy; // Inverte a velocidade vertical
    }
}

void ball::rebatidaPaddle(int paddleX, int paddleY, int paddleWidth, int paddleHeight) {
    if (x >= paddleX && x <= paddleX + paddleWidth && y >= paddleY && y <= paddleY + paddleHeight) {
        vx = -vx; // Inverte a velocidade vertical ao colidir com o paddle
    }
}

void ball::reset(int windowWidth) {
    if  (x < 0 || x > windowWidth) {
        // Reseta a posição da bola para o centro da tela
        x = windowWidth / 2;
        y = 300; // Posição vertical fixa, pode ser ajustada
    }
}

void ball::draw(sf::RenderWindow& window) {
    //recebe como parametro a janela onde sera desenhada a bola
    shape.setPosition(static_cast<float>(x), static_cast<float>(y)); // Define a posição da bola
    window.draw(shape); // Desenha a bola na janela
}



//exemplo de uso