#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include "Floresta/Floresta.hpp"
#include "Animal/Animal.hpp"
#include "Config/Config.hpp"

class Simulador {
private:
    Floresta floresta;
    Animal animal;
    Config config;
    int iteracao_atual;
    
public:
    Simulador(const Floresta& f, const Animal& a, const Config& c);
    ~Simulador();
    
    void executarSimulacao();
    void salvarResultados(const std::string& arquivo_saida) const;
};

#endif  