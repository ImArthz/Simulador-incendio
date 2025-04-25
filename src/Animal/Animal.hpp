#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <vector>
#include <utility>
#include <algorithm>
#include "Floresta/Floresta.hpp"

class Floresta;

class Animal {
private:
    std::pair<int, int> posicao;
    int passos;
    int encontros_agua;
    bool vivo;
    int iteracao_morte;

public:
    Animal(int x, int y);
    
    void mover(Floresta& floresta);
    bool estaVivo() const;
    int getPassos() const;
    int getEncontrosAgua() const;
    int getIteracaoMorte() const;
    std::pair<int, int> getPosicao() const;
    void setPosicao(int x, int y);
};

#endif