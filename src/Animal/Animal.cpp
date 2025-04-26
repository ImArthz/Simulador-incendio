#include "Animal.hpp"
#include "../Floresta/Floresta.hpp"
#include <iostream>
#include <climits> 
#include <limits> 
using namespace std;

Animal::Animal(int x, int y)
    : posicao({x, y}), passos(0), encontros_agua(0), vivo(true),
      iteracao_morte(-1) {}

void Animal::mover(Floresta &floresta) {
    if (!vivo) return;

    auto matriz = floresta.getMatriz();
    vector<pair<int, int>> direcoes = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<pair<int, int>> opcoes;
    pair<int, int> pos_agua = {-1, -1};
    int menor_distancia = INT_MAX; 

    // Explora as direções
    for (const auto &dir : direcoes) {
        int nx = posicao.first + dir.first;
        int ny = posicao.second + dir.second;

        if (nx >= 0 && static_cast<size_t>(nx) < matriz.size() && ny >= 0 &&
            static_cast<size_t>(ny) < matriz[0].size()) {
            int valor = matriz[nx][ny];

            // Verifica a água
            if (valor == 4) {
                if (menor_distancia > 1) {
                    menor_distancia = 1; // Distância até a água encontrada
                    pos_agua = {nx, ny}; // Salva a posição da água
                }
                opcoes.push_back({nx, ny});
                break; // Sai do loop se a água for encontrada
            }

            // Verifica outros obstáculos e o fogo
            if (valor == 2) {
                // O animal apaga o fogo se consumir água
                if (pos_agua.first != -1) {
                    matriz[nx][ny] = 0; // Apaga o fogo
                    floresta.atualizarMatriz(nx, ny, 0); // Registra a mudança
                    cout << "Fogo apagado na posição (" << nx << ", " << ny << ")\n";
                }
            } else if (valor != 2) {
                opcoes.push_back({nx, ny});
            }
        }
    }

    // Prioriza mover para a água se encontrada
    if (pos_agua.first != -1) {
        posicao = pos_agua; // Move para a posição da água
        historico_posicoes.push_back(pos_agua);
        passos++;
        encontros_agua++;
        floresta.atualizarMatriz(pos_agua.first, pos_agua.second, 0);
    } else if (!opcoes.empty()) {
        auto nova_pos = opcoes.front();
        posicao = nova_pos;
        historico_posicoes.push_back(nova_pos);
        passos++;
    } else {
        vivo = false; // O animal morreu se não houver opções
        iteracao_morte = floresta.getIteracaoAtual();
        cout << "Animal morreu na iteração " << iteracao_morte << endl;
    }

    // Exibe a posição atual do animal
    cout << "Posição atual do animal: (" << posicao.first << ", " << posicao.second << ")\n";
}

bool Animal::estaVivo() const { return vivo; }
int Animal::getPassos() const { return passos; }
int Animal::getEncontrosAgua() const { return encontros_agua; }
int Animal::getIteracaoMorte() const { return iteracao_morte; }
pair<int, int> Animal::getPosicao() const { return posicao; }
void Animal::setPosicao(int x, int y) { posicao = {x, y}; }