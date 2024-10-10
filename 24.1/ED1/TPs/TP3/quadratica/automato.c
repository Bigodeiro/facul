#include "automato.h"
#include <stdio.h>
#include <stdlib.h>
#include "quad_hash.h"


//*Função encapsulada para alocar um reticulado
TabelaHash* alocarReticulado( int tam )
{
    return iniciaTabela(tam);
}

//Função encapsulada para desalocar um reticulado
void desalocarReticulado( Automato* automato )
{
    destroiTabela(automato->reticulado);
}

//*Função para ler um reticulado, alocando o esqueleto da matriz e inserindo as células vivas
void LeituraReticulado( Automato* automato )
{
    int tam, geracoes;

    scanf("%d %d", &tam, &geracoes);

    automato->tam = tam;

    automato->geracao = geracoes;

    automato->reticulado = alocarReticulado(tam);

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            int celula;

            scanf("%d", &celula);

            if (celula == 1)
            {
                insereCelula(automato->reticulado, (Celula) {i, j});
            }
        }
    }

}

//Função encapsulada para imprimir um reticulado
void imprimeReticulado( Automato* automato )
{
    imprimeTabela(automato->reticulado, automato->tam);
}

//Função para verificar se uma célula pode ser acessada (nao tem índice negativo e não ultrapassa o tamanho do reticulado)
bool podeAcessar( int x, int y, int tam )
{
    return x >= 0 && x < tam && y >= 0 && y < tam;
}

int vizinhosVivos( TabelaHash* reticulado, Celula celula, int tam )
{
    int vizinhos = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            int x = celula.x + i;
            int y = celula.y + j;

            if (podeAcessar(x, y, tam) && pesquisaCelula(reticulado, (Celula) {x, y}))
            {
                vizinhos++;
            }
        }
    }

    return vizinhos;
}


void evoluirReticulado( Automato* automato )
{
    for (int i = 0; i < automato->geracao; i++) //Para cada geração
    {
        TabelaHash* novaGeracao = iniciaTabela(automato->tam);

        for (int j = 0; j < automato->tam; j++)
        {
            for (int k = 0; k < automato->tam; k++) //Para cada célula do reticulado
            {
                int vizinhos = 0;

                for (int l = -1; l <= 1; l++)
                {
                    for (int m = -1; m <= 1; m++) //Para cada vizinho
                    {
                        if (l == 0 && m == 0)
                        {
                            continue; //Faz com que pesquisaCelula não seja chamado para a própria célula
                        }
                        
                        int x = k + m;
                        int y = j + l;

                        //Como é short circuited, não dá segmentation fault
                        if (podeAcessar(x, y, automato->tam) && pesquisaCelula(automato->reticulado, (Celula) {x, y}))
                        {
                            vizinhos++;
                        }
                    }
                }

                if (vizinhos == 3 || (vizinhos == 2 && pesquisaCelula( automato->reticulado, (Celula) {k, j})))
                {
                    insereCelula(novaGeracao, (Celula) {k, j});
                }
            }
        }

        destroiTabela(automato->reticulado);

        automato->reticulado = novaGeracao;
    }
}