#ifndef CONFIG_HPP
#define CONFIG_HPP
#include <string>
#include <vector>

class Config {
private:
    short int interaction_limit;
    bool vento_ativo;
    std::vector<std::string> direcoes_vento;
    
public:
    Config();
    ~Config();
    
    void setInteractionLimit(short int limit);
    short int getInteractionLimit() const;
    
    void setVento(bool ativo);
    bool getVento() const;
    
    void setDirecoesVento(const std::vector<std::string>& direcoes);
    std::vector<std::string> getDirecoesVento() const;
};

#endif