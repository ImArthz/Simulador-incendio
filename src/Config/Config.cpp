#include "Config.hpp"
#include <vector>
#include <string>
#include <random>
#include <ctime>

Config::Config() : interaction_limit(100) {
    std::srand(std::time(nullptr));
    vento_ativo = (std::rand() % 2) == 1;

    std::vector<std::string> todas_direcoes = {"cima", "baixo", "esquerda", "direita"};
    int num_direcoes = 1 + (std::rand() % 3); // Número randômico entre 1 e 3

    while(direcoes_vento.size() < static_cast<size_t>(num_direcoes)) { // Mudança aqui
        int idx = std::rand() % todas_direcoes.size();
        direcoes_vento.push_back(todas_direcoes[idx]);
        todas_direcoes.erase(todas_direcoes.begin() + idx);
    }
}

Config::~Config() {}

void Config::setInteractionLimit(short int limit) {
    interaction_limit = limit;
}

short int Config::getInteractionLimit() const {
    return interaction_limit;
}

void Config::setVento(bool ativo) {
    vento_ativo = ativo;
}

bool Config::getVento() const {
    return vento_ativo;
}

void Config::setDirecoesVento(const std::vector<std::string>& direcoes) {
    direcoes_vento = direcoes;
}

std::vector<std::string> Config::getDirecoesVento() const {
    return direcoes_vento;
}