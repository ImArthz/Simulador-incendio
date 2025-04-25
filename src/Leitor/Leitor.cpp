#include "Leitor.hpp"
#include <stdexcept>

std::pair<int, int> Leitor::getPosicaoAnimalInicial() const {
    std::ifstream arquivo(input_path);
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
    throw std::runtime_error("Nenhuma posição segura encontrada para o animal");
}