#ifndef LEITOR_HPP
#define LEITOR_HPP

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Leitor {
private:
    string input_path;
    string output_path;
    
public:
    Leitor() ;
    ~Leitor() ;
    
    void setInputPath(const string& path);
    void setOutputPath(const string& path);
    
    vector<vector<int>> lerMatriz() const;
    void salvarMatriz(const vector<vector<int>>& matriz) const;
    
    pair<int, int> getDimensoes() const;
    pair<int, int> getIncendioInicial() const;
    pair<int, int> getPosicaoAnimalInicial() const;
};

#endif