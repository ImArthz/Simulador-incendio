#include "Leitor.hpp"
Leitor::Leitor(){}
void Leitor::set_Input(string Input)
{
    this->Input = Input ;
}
void Leitor::set_Output(string output)
{
    this->output = output ;
}
string Leitor::get_Input()
{
    return Input;

}
string Leitor::get_output()
{
    return output;
}
int **Leitor::Input(){
    fstream arquivo 
    arquivo.open(input,ios::in);
    if(!arquivo)
    {
        cout<<"Erro ao abrir arquivo "<<endl;
        exit(0);
    }
    arquivo >>tamanho;
    arquivo.ignore();
    //function generate 
    int cont = 0 
    for(short int i = 0;i<size;i++)
    {
        string line ;
        generate(arquivo,line);
        for(short int j = 0 ;j<tamanho;j++){
            // config
            continue;
            cont++;
        }
        cout<<endl;   
    }
 
//config
continue;
arquivo.close()
// retorna mapa 
return 0;
}

Leitor::~Leitor()
{
}
