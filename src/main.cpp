#include <iostream>
#include "Leitor/Leitor.hpp"
#include "Floresta/Floresta.hpp"
#include "Animal/Animal.hpp"
#include "Config/Config.hpp"
#include "Simulador/Simulador.hpp"

int main() {
    Leitor leitor;
    leitor.setInputPath("data/input.dat");
    leitor.setOutputPath("data/output.dat");

    auto dimensoes = leitor.getDimensoes();
    auto incendio_inicial = leitor.getIncendioInicial();
    auto animal_pos = leitor.getPosicaoAnimalInicial();

    Floresta floresta(dimensoes.first, dimensoes.second);
    floresta.carregarMatriz(leitor.lerMatriz());
    floresta.setIncendioInicial(incendio_inicial.first, incendio_inicial.second);

    Animal animal(animal_pos.first, animal_pos.second);

    Config config;
    config.setInteractionLimit(100);
    config.setVento(false);

    Simulador simulador(floresta, animal, config);
    simulador.executarSimulacao();
    simulador.salvarResultados("data/output.dat");


    return 0;
}
