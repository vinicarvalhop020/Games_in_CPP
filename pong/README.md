# Games_in_CPP

# 🎮 Jogos em C++

Este repositório reúne pequenos jogos implementados em **C++**, feitos para estudo e diversão.  
Cada jogo foi desenvolvido com foco em praticar conceitos de **programação**, **estruturas de dados**, **lógica de jogos** e uso de bibliotecas gráficas simples.

---

## 📂 Jogos disponíveis

### 🟢 Pong
O clássico **PONG**, considerado o primeiro jogo de videogame da história.  
Neste projeto, dois jogadores controlam suas raquetes para rebater a bola, tentando impedir que ela ultrapasse sua área.

- 👾 **Modo de jogo:** 1 jogador local
- ⌨️ **Controles:**
  - Jogador 1: `↑` (cima) / `↓` (baixo)
- ⚙️ **Recursos:** colisão com as bordas, reinício automático da rodada.  

---

## 🚀 Como compilar e executar

Clone o repositório:
```bash
git clone https://github.com/vinicarvalhop020/Games_in_CPP
cd pong


g++ main.cpp ball.cpp paddle.cpp paddle_ia.cpp -o pong -lsfml-graphics -lsfml-window -lsfml-system
./pong
