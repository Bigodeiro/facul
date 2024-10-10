#include "automato.h"
#include <stdio.h>
#include <stdlib.h>
#include "double_hash.h"


//*Função encapsulada para alocar um reticulado
TabelaHash* alocarReticulado( int tam )
{
    return iniciaTabela(tam);
}

//*Função encapsulada para desalocar um reticulado
void desalocarReticulado( Automato* automato )
{
    destroiTabela(automato->reticulado);
}

//*Função para ler um reticulado, salvando as células vivas na tabela hash
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

//*Função encapsulada para imprimir um reticulado
void imprimeReticulado( Automato* automato )
{
    imprimeTabela(automato->reticulado, automato->tam);
}

//*Função para verificar se uma célula pode ser acessada (nao tem índice negativo e não ultrapassa o tamanho do reticulado)
bool podeAcessar( int x, int y, int tam )
{
    return x >= 0 && x < tam && y >= 0 && y < tam;
}

//*Função para verificar quantos vizinhos vivos uma célula tem
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

//*Função para evoluir o reticulado
void evoluirReticulado( Automato* automato )
{
    for (int i = 0; i < automato->geracao; i++) //Para cada geração
    {
        TabelaHash* novaGeracao = iniciaTabela(automato->tam);

        for (int j = 0; j < automato->tam; j++)
        {
            for (int k = 0; k < automato->tam; k++) //Para cada célula do reticulado
            {
                Celula celula = (Celula) {j, k};

                int vizinhos = vizinhosVivos(automato->reticulado, celula, automato->tam);

                if (vizinhos == 3 || (vizinhos == 2 && pesquisaCelula(automato->reticulado, celula)))
                {
                    insereCelula(novaGeracao, celula);
                }
            }
        }

        destroiTabela(automato->reticulado);
        automato->reticulado = novaGeracao;
    }
}
 