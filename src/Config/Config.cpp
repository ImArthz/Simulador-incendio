#include "Config.hpp"
#include <vector>
#include <string>
Config::Config() : interaction_limit(100), vento_ativo(false) {}

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