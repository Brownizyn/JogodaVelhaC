#include <stdio.h>

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("-----------\n");
    }
    printf("\n");
}

// Função para verificar se há um vencedor
int verificarVitoria(char tabuleiro[3][3]) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return 1; // Vitoria nas linhas
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return 1; // Vitoria nas colunas
    }

    // Verificar diagonais
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return 1; // Vitoria na diagonal principal
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return 1; // Vitoria na diagonal secundária

    return 0; // Nenhum vencedor encontrado
}

// Função para verificar se todas as células estão preenchidas (empate)
int verificarEmpate(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tabuleiro[i][j] == ' ')
                return 0; // Ainda há espaços vazios
    return 1; // Todas as células estão preenchidas
}

int main() {
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int linha, coluna;
    char jogador = 'X'; // Começa com o jogador X

    do {
        exibirTabuleiro(tabuleiro);

        // Obter a jogada do jogador atual
        printf("Jogador %c, insira a linha e a coluna (1-3) separadas por espaço: ", jogador);
        scanf("%d %d", &linha, &coluna);

        // Converter para índices do array
        linha--;
        coluna--;

        // Verificar se a jogada é válida
        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
            // Atualizar o tabuleiro com a jogada
            tabuleiro[linha][coluna] = jogador;

            // Verificar o estado do jogo
            if (verificarVitoria(tabuleiro)) {
                exibirTabuleiro(tabuleiro);
                printf("Jogador %c venceu!\n", jogador);
                break;
            } else if (verificarEmpate(tabuleiro)) {
                exibirTabuleiro(tabuleiro);
                printf("O jogo empatou!\n");
                break;
            }

            // Alternar para o próximo jogador
            jogador = (jogador == 'X') ? 'O' : 'X';
        } else {
            printf("Jogada inválida. Tente novamente.\n");
        }

    } while (1);

    return 0;
}

