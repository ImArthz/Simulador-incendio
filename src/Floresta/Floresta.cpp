#include "Floresta.hpp"

using namespace std;

Floresta::Floresta(int n, int m) : linhas(n), colunas(m), iteracao_atual(0) {
    matriz.resize(n, vector<int>(m, 1));
}

void Floresta::propagarIncendio(bool com_vento, const vector<string>& direcoes) {
    vector<pair<int, int>> novas_chamas;
    vector<pair<int, int>> direcoes_propagacao;

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
        int valor_antigo = matriz[pos.first][pos.second];
        matriz[pos.first][pos.second] = 2;
        mudancas.push_back({{pos.first, pos.second}, {valor_antigo, 2}});
    }
}

int Floresta::getFocosAtivos() const {
    int total = 0;
    for (const auto& linha : matriz) {
        total += count(linha.begin(), linha.end(), 2);
    }
    return total;
}

void Floresta::salvarMatriz(const string& arquivo_saida) const {
    ofstream arquivo(arquivo_saida, ios::app);
    for (const auto& linha : matriz) {
        for (int val : linha) {
            arquivo << val << " ";
        }
        arquivo << "\n";
    }
    arquivo << "\n";
}
void Floresta::carregarMatriz(const vector<vector<int>>& nova_matriz) {
    matriz = nova_matriz;
    linhas = matriz.size();
    if(linhas > 0) colunas = matriz[0].size();
}

void Floresta::setIncendioInicial(int x, int y) {
    incendio_inicial = {x, y};
    matriz[x][y] = 2;
}

vector<vector<int>> Floresta::getMatriz() const {
    return matriz;
}

void Floresta::atualizarMatriz(int x, int y, int valor) {
    if (x >= 0 && x < linhas && y >= 0 && y < colunas) {
        int valor_antigo = matriz[x][y];
        if(valor != valor_antigo) {
            mudancas.push_back({{x,y}, {valor_antigo, valor}});
            matriz[x][y] = valor;
        }
    }
}

void Floresta::limparMudancas() {
    mudancas.clear();
}

const vector<pair<pair<int, int>, pair<int, int>>>& Floresta::getMudancas() const {
    return mudancas;
}