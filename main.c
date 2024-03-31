#include <stdio.h>
#define TAM 3
#define XIS 1
#define BOLINHA 2

// DECLARAÇÃO DE FUNÇOES
void imprimeTabuleiro(int t[TAM][TAM]);
int fazJogada(int t[TAM][TAM], int jogadaDe);
int verificaVitoria(int t[TAM][TAM], int jogador);
int verificaVelha(int t[TAM][TAM]);

// EXECUÇÃO DO PROGRAMA
int main()
{
    int tabuleiro[TAM][TAM] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int jogando = 1, vezDe, jogadaInvalida = 0, vitoria = 0, velha = 0;
    char c;
    printf("Jogo da Velha\n");

    vezDe = XIS;
    while(jogando)
    {
        imprimeTabuleiro(tabuleiro);
        jogadaInvalida = fazJogada(tabuleiro, vezDe);
        vitoria = verificaVitoria(tabuleiro, vezDe);
        velha = verificaVelha(tabuleiro);

        if(velha || vitoria)
            jogando = 0;
        if(!jogadaInvalida)
            vezDe = (vezDe == BOLINHA)? XIS: BOLINHA;
    }

    imprimeTabuleiro(tabuleiro);
    vezDe = (vezDe == BOLINHA)? XIS: BOLINHA;
    if(verificaVelha(tabuleiro))
        printf("Deu velha!\n");
    else
        printf("O jogador %c venceu!\n", (vezDe == BOLINHA)? 'o': 'x');
    return 0;
}

// IMPLEMENTAÇÃO
void imprimeTabuleiro(int t[TAM][TAM])
{
    int i, j;
    char c;
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            switch (t[i][j])
            {
            case 0:
                c = ' ';
                break;
            case BOLINHA:
                c = 'o';
                break;
            case XIS:
                c = 'x';
                break;
            }
            if(j == 1)
                printf("| %c |", c);
            else
                printf(" %c ", c);
        }
            
        if(i != TAM - 1)
            printf("\n---|---|---\n");
    }
    printf("\n");
}

int fazJogada(int t[TAM][TAM], int jogadaDe)
{
    int x, y;
    printf("Entre com as coordenadas: ");
    scanf("%d %d", &x, &y);

    x--;
    y--;
    if(t[x][y] != 0 || x >= TAM  || x < 0 || y >= TAM || y < 0)
    {
        printf("Jogada invalida!\n");
        return 1;
    }

    if(jogadaDe == BOLINHA)
        t[x][y] = BOLINHA;
    else
        t[x][y] = XIS;

    return 0;
}

int verificaVitoria(int t[TAM][TAM], int jogador)
{
    // Verifica linhas e colunas
    for (int i = 0; i < TAM; i++) {
        if (t[i][0] == jogador && t[i][1] == jogador && t[i][2] == jogador)
            return 1; // Vitória nas linhas
        if (t[0][i] == jogador && t[1][i] == jogador && t[2][i] == jogador)
            return 1; // Vitória nas colunas
    }
    
    // Verifica diagonais
    if ((t[0][0] == jogador && t[1][1] == jogador && t[2][2] == jogador) ||
        (t[0][2] == jogador && t[1][1] == jogador && t[2][0] == jogador))
        return 1; // Vitória nas diagonais

    return 0; // Não há vitória
}

int verificaVelha(int t[TAM][TAM])
{
    int i, j;

    for (i = 0; i < TAM; i++)
        for(j = 0; j < TAM; j++)
            if(t[i][j] == 0)
                return 0; // Existe um espaço
    
    return 1; // Não existe nenhum espeço -> Deu velha
}