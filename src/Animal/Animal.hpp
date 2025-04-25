#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Floresta;

class Animal {
private:
    pair<int, int> posicao;
    int passos;
    int encontros_agua;
    bool vivo;
    int iteracao_morte;
    vector<pair<int, int>> historico_posicoes;

public:
    Animal(int x, int y);

    void mover(Floresta& floresta);
    bool estaVivo() const;
    int getPassos() const;
    int getEncontrosAgua() const;
    int getIteracaoMorte() const;
    pair<int, int> getPosicao() const;
    void setPosicao(int x, int y);
    vector<pair<int, int>> getHistoricoPosicoes() const { return historico_posicoes; }
};

#endif