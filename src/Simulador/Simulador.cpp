#include "Simulador.hpp"

Simulador::Simulador(const Floresta& f, const Animal& a, const Config& c) 
    : floresta(f), animal(a), config(c), iteracao_atual(0) {}

Simulador::~Simulador() {}

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

        ofstream arquivo(config.getVento() ? "data/output_vento.dat" : "data/output_normal.dat", ios::app);
        arquivo << "Iteração " << iteracao_atual + 1 << ":\n";
        
        // Salvar matriz atual
        auto matriz_atual = floresta.getMatriz();
        for(size_t i = 0; i < matriz_atual.size(); i++) {
            for(size_t j = 0; j < matriz_atual[0].size(); j++) {
                arquivo << matriz_atual[i][j] << " ";
            }
            arquivo << "\n";
        }
        
        // Registrar mudanças específicas
        arquivo << "\nMudanças nesta iteração:\n";
        for(const auto& mudanca : floresta.getMudancas()) {
            int x = mudanca.first.first;
            int y = mudanca.first.second;
            int valor_antigo = mudanca.second.first;
            int valor_novo = mudanca.second.second;
            
            arquivo << "• (" << x << "," << y << ") mudou de " << valor_antigo << " para " << valor_novo;
            
            // Adicionar descrição da mudança
            if(valor_novo == 2 && valor_antigo == 1) arquivo << " (árvore pegou fogo)";
            else if(valor_novo == 3 && valor_antigo == 2) arquivo << " (árvore queimou completamente)";
            else if(valor_novo == 0 && valor_antigo == 4) arquivo << " (água foi consumida pelo animal)";
            else if(valor_novo == 1 && valor_antigo == 0) arquivo << " (área regenerada pela água)";
            else if(valor_novo == 2) arquivo << " (novo foco de incêndio)";
            
            arquivo << "\n";
        }
        
        arquivo << "\nPosição atual do animal: (" << animal.getPosicao().first << "," << animal.getPosicao().second << ")\n\n";
        
        // Limpar mudanças para próxima iteração
        floresta.limparMudancas();
        
        if (floresta.getFocosAtivos() == 0) break;
    }
}

void Simulador::salvarResultados(const string& arquivo_saida) const {
    ofstream arquivo(arquivo_saida, ios::app);
    arquivo << "\n=== RESULTADOS DA SIMULAÇÃO ===\n";
    arquivo << "Caminho do animal:\n";
    auto historico = animal.getHistoricoPosicoes();
    
    // Imprime o caminho com setas
    for (size_t i = 0; i < historico.size(); i++) {
        arquivo << "(" << historico[i].first << "," << historico[i].second << ")";
        if (i < historico.size() - 1) {
            arquivo << " -> ";
        }
    }
    arquivo << "\n\nTotal de passos: " << animal.getPassos();
    arquivo << "\nEncontros com água: " << animal.getEncontrosAgua();
    arquivo << "\nSobreviveu? " << (animal.estaVivo() ? "Sim" : "Não");
    if (!animal.estaVivo()) {
        arquivo << "\nMorreu na iteração: " << animal.getIteracaoMorte();
    }
    arquivo << "\n===========================\n";
}