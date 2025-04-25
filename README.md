# Simulador-incendio
## Introdução 
### Projeto Desenvolvido na disciplina de AEDS ( Algoritmos e estudo de dados ), onde é proposto uma simulação de incendio florestal, com a representação do mapa da floresta como um matriz 100 x 100 
 No qual, existem 5 estados na matriz :
 ```bash
 0 - Área segura 
 1 - Área florestal "saudavel"
 2 - Área florestal com inicio de queimada 
 3 - Área florestal completamente queimada 
 4 - Reservatorio de água
```
Também é representado na Floresta um Animal que pode se mover para Direita, Esquerda, Cima , Baixo Onde se o animal se encontrar com o uma area florestal com inicio de queimada esta interação causa a morte do animal 
outra interação é com o Animal e a água onde o animal podera apagar os incideos ao redor utilizando o reservatorio de agua local ( que assim que é usado é setado para uma aréa segura ) e a área florestal em chamas em questão é setada para uma área florestal completamente queimada 

[animal][linkparaimagemanimal]
[area segura][linkparaimagemareasegura]
[area florestal][linkparaimagemareasflorestal]
[area florestal em chamas][linkparaimagemareaflorestalemchamas]
[area florestal completamente queimada][linkparaimagemareaflorestalcompletamentequeimada]
[reservatorio de agua ][linkparaimagemdoreservatoriodeagua]







## Metodologia 







## Estudo de caso / resultados 





## Conclusão 








## Refêrencias 

[![Prática](https://img.shields.io/badge/Prática-PDF-blue?style=for-the-badge&logo=adobe-acrobat-reader)](https://github.com/ImArthz/Simulador-incendio/blob/main/pratica.pdf)  
<br>  
Foi utilizado como referência o PDF do projeto.


[![Link para teste](https://img.shields.io/badge/Link-CODIGO-grenn?style=for-the-badge&logo=adobe-acrobat-reader)](https://github.com/ImArthz/Lattes_CV_Extractor/blob/dcc819a5b9bf4a48841557a2de7d9fc6053b7172/codigos%20de%20plotagem/dados_pandas.py#L10) 




## Método de compilação 

### Makefile
[![makefile](https://img.shields.io/badge/Link-Makefile-red?style=for-the-badge&logo=adobe-acrobat-reader)](https://github.com/ImArthz/Simulador-incendio/blob/main/makefile)

```bash
make clean
```
Limpa todos os arquivos compilados  e o executavel, é importante usar o make clean antes de compilar o codigo para evitar problemas 

```bash
make
```
Compila os arquivos e gera um executavel 


```bash
make run
```
Compila todos os arquivos gera um executavel e o executa 
```bash
run
```
Caso exista um arquivo executavel o roda 


