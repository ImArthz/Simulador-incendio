#include "Leitor.hpp"
#include <stdexcept>

using namespace std;

Leitor::Leitor() : input_path(""), output_path("") {}
Leitor::~Leitor() {}

void Leitor::setInputPath(const string& path) { input_path = path; }
void Leitor::setOutputPath(const string& path) { output_path = path; }

pair<int, int> Leitor::getDimensoes() const {
    ifstream arquivo(input_path);
    int n, m;
    arquivo >> n >> m;
    return {n, m};
}

pair<int, int> Leitor::getIncendioInicial() const {
    ifstream arquivo(input_path);
    int n, m, x, y;
    arquivo >> n >> m >> x >> y;
    return {x, y};
}

vector<vector<int>> Leitor::lerMatriz() const {
    ifstream arquivo(input_path);
    int n, m, x, y;
    arquivo >> n >> m >> x >> y;

    vector<vector<int>> matriz(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arquivo >> matriz[i][j];
        }
    }
    return matriz;

}  
pair<int, int> Leitor::getPosicaoAnimalInicial() const {
    ifstream arquivo(input_path);
    int n, m, x, y;
    arquivo >> n >> m >> x >> y;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val;
            arquivo >> val;
            if (val == 0) {
                return {i, j};
            }
        }
    }
    throw runtime_error("Nenhuma posição segura encontrada para o animal");
}