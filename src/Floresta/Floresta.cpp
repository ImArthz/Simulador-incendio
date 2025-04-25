#include "Floresta.hpp"

Floresta::Floresta(int n, int m) : linhas(n), colunas(m), iteracao_atual(0) {
    matriz.resize(n, std::vector<int>(m, 1));
}

void Floresta::propagarIncendio(bool com_vento, const std::vector<std::string>& direcoes) {
    std::vector<std::pair<int, int>> novas_chamas;
    std::vector<std::pair<int, int>> direcoes_propagacao;

    if (com_vento) {
        for (const auto& dir : direcoes) {
            if (dir == "cima") direcoes_propagacao.push_back({-1,0});
            if (dir == "baixo") direcoes_propagacao.push_back({1,0});
            if (dir == "esquerda") direcoes_propagacao.push_back({0,-1});
            if (dir == "direita") direcoes_propagacao.push_back({0,1});
        }
    } else {
        direcoes_propagacao = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    }

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (matriz[i][j] == 2) {
                for (const auto& dir : direcoes_propagacao) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if (ni >= 0 && ni < linhas && nj >= 0 && nj < colunas && matriz[ni][nj] == 1) {
                        novas_chamas.push_back({ni, nj});
                    }
                }
                matriz[i][j] = 3;
            }
        }
    }

    for (const auto& pos : novas_chamas) {
        matriz[pos.first][pos.second] = 2;
    }
}

int Floresta::getFocosAtivos() const {
    int count = 0;
    for (const auto& linha : matriz) {
        count += std::count(linha.begin(), linha.end(), 2);
    }
    return count;
}

void Floresta::salvarMatriz(const std::string& arquivo_saida) const {
    std::ofstream arquivo(arquivo_saida, std::ios::app);
    for (const auto& linha : matriz) {
        for (int val : linha) {
            arquivo << val << " ";
        }
        arquivo << "\n";
    }
    arquivo << "\n";
}