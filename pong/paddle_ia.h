#include "paddle.h"

class paddle_ia : public paddle {
    public:
        paddle_ia();
        paddle_ia(int x, int y, int width, int height);
        void updatePosition(float ballY, int windowHeight, int velocity); // Atualiza a posição do paddle com base na posição da bola
};