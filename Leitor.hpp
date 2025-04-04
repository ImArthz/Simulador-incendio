#if !defined(Leitor)
#define Leitor
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Leitor
{
private:
    string Input;
    string output;
    int size

public:
    Leitor(/* args */);
    ~Leitor();
    string get_Input();
    void set_Input(string Input);
    string get_output();
    void set_output(string output);
    int **Input();
    int getTamanho();
    void setTamanho(int Tamanho);

};
#endif // LLeito
