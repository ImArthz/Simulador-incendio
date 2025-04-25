#include "Simulador.hpp"

Simulador::Simulador(const Floresta& f, const Animal& a, const Config& c) 
    : floresta(f), animal(a), config(c), iteracao_atual(0) {}

void Simulador::executarSimulacao() {
    int limite = config.getInteractionLimit();
    
    for (iteracao_atual = 0; iteracao_atual < limite; ++iteracao_atual) {
        floresta.setIteracaoAtual(iteracao_atual);

        animal.mover(floresta);
        floresta.propagarIncendio(config.getVento(), config.getDirecoesVento());

        auto pos = animal.getPosicao();
        if (floresta.getMatriz()[pos.first][pos.second] == 2 && animal.estaVivo()) {
            animal.mover(floresta);
        }

        floresta.salvarMatriz(config.getVento() ? "data/output_vento.dat" : "data/output_normal.dat");
        
        if (floresta.getFocosAtivos() == 0) break;
    }
}

void Simulador::salvarResultados(const std::string& arquivo_saida) const {
    // Implementar lógica de salvamento de resultados
}