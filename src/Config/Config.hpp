#ifndef CONFIG_HPP
#define CONFIG_HPP
#include <string>
#include <vector>

using namespace std;

class Config {
private:
    short int interaction_limit;
    bool vento_ativo;
    vector<string> direcoes_vento;
    
public:
    Config();
    ~Config();
    
    void setInteractionLimit(short int limit);
    short int getInteractionLimit() const;
    
    void setVento(bool ativo);
    bool getVento() const;
    
    void setDirecoesVento(const vector<string>& direcoes);
    vector<string> getDirecoesVento() const;
};

#endif