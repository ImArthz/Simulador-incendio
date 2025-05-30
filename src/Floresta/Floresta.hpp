#ifndef FLORESTA_HPP
#define FLORESTA_HPP

#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <algorithm>

using namespace std;

class Floresta {
private:
    int linhas;
    int colunas;
    std::vector<std::vector<int>> matriz;
    std::pair<int, int> incendio_inicial;
    int iteracao_atual;
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> mudancas; // ((x,y), (valor_antigo, valor_novo))

public:
    Floresta(int n, int m);

    void carregarMatriz(const std::vector<std::vector<int>>& nova_matriz);
    void setIncendioInicial(int x, int y);
    void propagarIncendio(bool com_vento, const std::vector<std::string>& direcoes_vento);
    void atualizarMatriz(int x, int y, int valor);
    void salvarMatriz(const std::string& arquivo_saida) const;
    int getFocosAtivos() const;
    
    std::vector<std::vector<int>> getMatriz() const;
    int getIteracaoAtual() const { return iteracao_atual; }
    void setIteracaoAtual(int iteracao) { iteracao_atual = iteracao; }
    
    void limparMudancas();
    const std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& getMudancas() const;
};

#endif