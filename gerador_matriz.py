import numpy as np

# Dimensões da matriz 100x100
N, M = 100, 100

# Inicializando a matriz com valores padrão:
# 1 → Árvore saudável, 0 → Área vazia (segura), 4 → Água
matriz = np.random.choice([1, 0, 4], size=(N, M), p=[0.5, 0.4, 0.1])

# Definindo a posição inicial do incêndio na célula (1, 1) (ajustado para índice 0)
incendio_x, incendio_y = 1, 1
matriz[incendio_x, incendio_y] = 2  # Marcando o incêndio com valor 2

# Encontrando uma posição segura para o animal (célula com valor 0)
safe_positions = np.argwhere(matriz == 0)
animal_position = safe_positions[0]  # Escolhendo a primeira célula segura
matriz[animal_position[0], animal_position[1]] = 3  # Marcando a posição do animal com valor 3

# Salvando a matriz no arquivo 'input.dat'
with open("input.dat", "w") as f:
    # Escrevendo as dimensões da matriz e a posição do incêndio
    f.write(f"{N} {M} {incendio_x} {incendio_y}\n")
    
    # Escrevendo a matriz no arquivo
    for i in range(N):
        f.write(" ".join(map(str, matriz[i])) + "\n")

print("Matriz salva no arquivo 'input.dat'")
