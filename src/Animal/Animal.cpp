#include "Animal.hpp"

Animal::Animal(int x, int y) : 
    posicao({x, y}), 
    passos(0), 
    encontros_agua(0), 
    vivo(true), 
    iteracao_morte(-1) {}

void Animal::mover(Floresta& floresta) {
    if (!vivo) return;

    auto matriz = floresta.getMatriz();
    std::vector<std::pair<int, int>> direcoes = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    std::vector<std::pair<int, int>> opcoes;

    for (const auto& dir : direcoes) {
        int nx = posicao.first + dir.first;
        int ny = posicao.second + dir.second;

        if (nx >= 0 && nx < matriz.size() && ny >= 0 && ny < matriz[0].size()) {
            int valor = matriz[nx][ny];
            if (valor != 2 && valor != 3) {
                opcoes.push_back({nx, ny});
            }
        }
    }

    std::sort(opcoes.begin(), opcoes.end(), [&matriz](const auto& a, const auto& b) {
        return matriz[a.first][a.second] > matriz[b.first][b.second];
    });

    if (!opcoes.empty()) {
        auto nova_pos = opcoes.front();
        posicao = nova_pos;
        passos++;

        if (matriz[nova_pos.first][nova_pos.second] == 4) {
            encontros_agua++;
            floresta.atualizarMatriz(nova_pos.first, nova_pos.second, 0);
            
            for (const auto& dir : direcoes) {
                int ax = nova_pos.first + dir.first;
                int ay = nova_pos.second + dir.second;
                if (ax >= 0 && ax < matriz.size() && ay >= 0 && ay < matriz[0].size()) {
                    if (matriz[ax][ay] == 3 || matriz[ax][ay] == 0) {
                        floresta.atualizarMatriz(ax, ay, 1);
                    }
                }
            }
        }
    }
    else {
        vivo = false;
        iteracao_morte = floresta.getIteracaoAtual();
    }
}


bool Animal::estaVivo() const { return vivo; }
int Animal::getPassos() const { return passos; }
int Animal::getEncontrosAgua() const { return encontros_agua; }
int Animal::getIteracaoMorte() const { return iteracao_morte; }
std::pair<int, int> Animal::getPosicao() const { return posicao; }
void Animal::setPosicao(int x, int y) { posicao = {x, y}; }