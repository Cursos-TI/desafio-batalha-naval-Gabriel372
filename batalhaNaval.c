#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define linha 6
#define coluna 6
struct Coordenadas {
    int horizontal[2];
    int vertical[2];
};

void imprimirTabuleiro(int matriz[linha][coluna]);
void perguntaInicial(int *x, int *y,char modoDePosicionamento[10],struct Coordenadas *coordenadas);
void definirCoordenada(int *x, int *y, struct Coordenadas *coordenadas, int ehHorizontal);
int stringEnumero(char string[100]);

void criarTabuleiro(int matriz[linha][coluna]) {
    for (int i = 0; i < linha ; i++) {
for (int j = 0; j < coluna ; j++)
{
    matriz[i][j] = 0;
}
    }
}

void imprimirTabuleiro(int matriz[linha][coluna]) {
 printf("           1a col.|2a col.|3a col.|4a col.|5a col.|6a col.\n");
    for (int i = 0; i < linha ; i++) {
            printf("%da linha   ",i + 1);
for ( int j = 0; j < coluna ; j++)
{
    printf("   %d    ",matriz[i][j]);
}
    printf("\n");
    }
}

void perguntaInicial(int *x,int *y,char modoDePosicionamento[10], struct Coordenadas *coordenadas){
if (strcmp(modoDePosicionamento, "horizontal") == 0)
{
    int ehHorizontal = 1;
    definirCoordenada(x,y,coordenadas,ehHorizontal);
}
else if (strcmp(modoDePosicionamento, "vertical") == 0){
    int ehHorizontal = 0;
    definirCoordenada(x,y,coordenadas,ehHorizontal);
}
}

void posicionamentoNoTabuleiro(int matriz[6][6],int *x,int *y,char modoDePosicionamento[10]){
    if (strcmp(modoDePosicionamento, "horizontal") == 0){
    for (int i = 0; i <= *x ; i++) {
for (int j = *y; j <= *y + 2 ; j++)
{
    matriz[*x][j] = 3;
}
   }
}
else if (strcmp(modoDePosicionamento, "vertical") == 0){
    for (int i = *x; i <= *x + 2; i++) {
        matriz[i][*y] = 3;
    }
}
}

void resposta(int matriz[6][6],struct Coordenadas *coordenadas){
        printf("======================================================================================\n");
        printf("Resultado:\n");
        printf("Navio posicionado na horizontal, coordenadas: (%da linha) e (%da coluna)\n",coordenadas->horizontal[0],coordenadas->horizontal[1]);
        printf("Navio posicionado na vertical, coordenadas: (%da linha) e (%da coluna)\n", coordenadas->vertical[0],coordenadas->vertical[1]);
        printf("\n");
        for (int i = 0; i < linha; i++)
        {
for ( int j = 0; j < coluna ; j++)
{
    printf("%d ",matriz[i][j]);
}
    printf("\n");
    }
    printf("\n");
}

void definirCoordenada(int *x, int *y, struct Coordenadas *coordenadas, int ehHorizontal) {
    char string[100];
    do {
        printf("Vamos posicionar o navio na %s.\n", ehHorizontal ? "horizontal" : "vertical");
        printf("Digite uma %s onde o navio ficara:\n", ehHorizontal ? "linha (de 1 a 6)" : "coluna (de 1 a 4)");
        fgets(string, sizeof(string), stdin);
        if (!stringEnumero(string)) {
            printf("Erro: nao foi digitado um numero.\n");
            continue;
        }
        *x = atoi(string) - 1;
        if (*x < 0 || *x > (ehHorizontal ? 5 : 3)) {
        printf("Erro: posicao invalida.\n");
        }
    } while (!stringEnumero(string) || *x < 0 || *x > (ehHorizontal ? 5 : 3));
    do {
        printf("Digite uma %s onde o navio ocupara 3 posicoes a partir desta:\n", ehHorizontal ? "coluna (de 1 a 4)" : "linha (de 1 a 6)");
        fgets(string, sizeof(string), stdin);
        if (!stringEnumero(string)) {
            printf("Erro: nao foi digitado um numero.\n");
            continue;
        }
        *y = atoi(string) - 1;
        if (*y < 0 || *y > (ehHorizontal ? 3 : 5)) {
            printf("Erro: essa posicao faz o navio ultrapassar o tabuleiro.\n");
        }
    } while (!stringEnumero(string) || *y < 0 || *y > (ehHorizontal ? 3 : 5));
if (ehHorizontal) {
    coordenadas->horizontal[0] = *x + 1;
    coordenadas->horizontal[1] = *y + 1;
}
else{
    coordenadas->vertical[0] = *x + 1;
    coordenadas->vertical[1] = *y + 1;
}
}

int stringEnumero(char string[100]) { 
    if (string[0] == '\0') return 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] < '0' || string[i] > '9') {
            return 0;
        }
     return 1;
    }
    return 1;
}

int main() {
    struct Coordenadas coordenadas = {{0, 0}, {0, 0}};
    int matriz[6][6];
    int x;
    int y;
    criarTabuleiro(matriz); 
    imprimirTabuleiro(matriz);
    perguntaInicial(&x, &y,"horizontal",&coordenadas);
    posicionamentoNoTabuleiro(matriz, &x, &y,"horizontal");
    perguntaInicial(&x, &y,"vertical",&coordenadas);
    posicionamentoNoTabuleiro(matriz, &x, &y,"vertical");
    resposta(matriz, &coordenadas);
    return 0;
}
