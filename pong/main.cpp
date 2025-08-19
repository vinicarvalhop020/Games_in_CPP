//Utilizando a sfml para abrir uma janela, sera usado para testes futuros em jogos
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "ball.h"
#include "paddle.h"
#include "paddle_ia.h"


void read_comand(char& command) {
    //Le comandos do teclado e
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        command = 'u';
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        command = 'd';
    }
    else 
    {
        command = ' ';
    }
}


int main()
{
    //Cria a janela
    int windowWidth = 1920;
    int windowHeight = 1080;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong Game");
    window.setFramerateLimit(60); // Limita a taxa de quadros para 60 FPS
    int ball_velocity = 10; 
    ball minhaBola(windowWidth/2, windowHeight/2, ball_velocity, ball_velocity); // Cria uma bola na posição (350, 50) com velocidade (5, 5)
    paddle player1(100, 100, 20, 100); // Cria um paddle para o jogador 1
    paddle_ia player2(windowWidth - 100, 100, 20, 100); // Cria um paddle para o jogador 2 (IA)
    char command = ' ';
    float ia_velocity = 10; 

    //Loop principal
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Atualiza a bola
        minhaBola.updatePosition(); // Atualiza a posição da bola
        minhaBola.rebatidaBorda(window.getSize().x, window.getSize().y); // Verifica colisão com as bordas
        window.clear(sf::Color::Black);
        minhaBola.draw(window); // Desenha a bola na janela
        minhaBola.rebatidaPaddle(player1.getX(), player1.getY(), player1.getWidth(), player1.getHeight()); // Verifica colisão com o paddle do jogador 1
        minhaBola.rebatidaPaddle(player2.getX(), player2.getY(), player2.getWidth(), player2.getHeight()); // Verifica colisão com o paddle do jogador 2
        // Atualiza o paddle do player
        read_comand(command);

        if (command == 'u') {
            player1.updatePosition(-10, windowHeight); // Move o paddle para cima
        } else if (command == 'd') {
            player1.updatePosition(10, windowHeight); // Move o paddle para baixo
        }
        else {
            player1.updatePosition(0,windowHeight); // Não move o paddle}
        }

        player1.draw(window); // Desenha o paddle na janela

        //player 2 (no futuro sera uma IA)
        //por enquanto só desenha o paddle do player 2
        player2.draw(window); // Desenha o paddle
        player2.updatePosition(minhaBola.getY(), windowHeight, ia_velocity); // Atualiza a posição do paddle IA com base na posição da bola

        minhaBola.reset(windowWidth); // Reseta a bola se ela sair da tela
        window.display();

    }

    return 0;
}

//para compilar:
// g++ main.cpp ball.cpp paddle.cpp paddle_ia.cpp -o pong -lsfml-graphics -lsfml-window -lsfml-system