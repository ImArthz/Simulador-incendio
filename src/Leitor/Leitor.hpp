#ifndef LEITOR_HPP
#define LEITOR_HPP

#include <string>
#include <vector>
#include <fstream>

class Leitor {
private:
    std::string input_path;
    std::string output_path;
    
public:
    Leitor();
    ~Leitor();
    
    void setInputPath(const std::string& path);
    void setOutputPath(const std::string& path);
    
    std::vector<std::vector<int>> lerMatriz() const;
    void salvarMatriz(const std::vector<std::vector<int>>& matriz) const;
    
    std::pair<int, int> getDimensoes() const;
    std::pair<int, int> getIncendioInicial() const;
    std::pair<int, int> getPosicaoAnimalInicial() const;
};

#endif