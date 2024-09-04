#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz* iniciaMatriz( int tam )
{
    Matriz* matriz = (Matriz*) malloc( sizeof(Matriz) );

    //Aloca o vetor de listas das colunas e das linhas (o "esqueleto" da matriz)
    matriz->vetColunas = (Lista*) malloc( tam * sizeof(Lista) );
    matriz->vetLinhas = (Lista*) malloc( tam * sizeof(Lista) );

    //Este for aloca cada cabeça de cada linha e de coluna
    for (int i = 0; i < tam; i++)
    {
        //Procede iniciar uma lista de células
        Celula* cabecaColuna = (Celula*) malloc( sizeof(Celula) );

        cabecaColuna->x = -1;
        cabecaColuna->y = -1;
        
        cabecaColuna->baixoProx = NULL;
        cabecaColuna->direitaProx = NULL;

        matriz->vetColunas[i].pCabeca = cabecaColuna;
        matriz->vetColunas[i].pUltimo = cabecaColuna;

        //Mesmo processo para as linhas
        Celula* cabecaLinha = (Celula*) malloc( sizeof(Celula) );

        cabecaLinha->x = -1;
        cabecaLinha->y = -1;
        
        cabecaLinha->baixoProx = NULL;
        cabecaLinha->direitaProx = NULL;

        matriz->vetLinhas[i].pCabeca = cabecaLinha;
        matriz->vetLinhas[i].pUltimo = cabecaLinha;
    }

    return matriz;
}


void desalocaMatriz( Matriz* matriz, int tam )
{
    //Passando por cada linha liberando as celulas e depois liberando a cabeça da linha
    for (int i = 0; i < tam; i++)
    {
        //Primeiro, liberamos as celulas de cada linha
        Celula* aux = matriz->vetLinhas[i].pCabeca->direitaProx;
        while (aux != NULL)
        { 
            Celula* temp = aux;
            aux = aux->direitaProx; //sem perder o ponteiro da celula atual

            free(temp);
        }

        //depois liberamos a cabeça da linha
        free(matriz->vetLinhas[i].pCabeca);
    }

    //Como as celulas ja foram liberadas, so precisamos liberar as cabeças das colunas
    for (int i = 0; i < tam; i++)
    {
        free(matriz->vetColunas[i].pCabeca);
    }

    //depois que todas as listas forem liberadas liberamos os vetores de listas
    free(matriz->vetLinhas); 
    free(matriz->vetColunas);

    //por fim, liberamos a struct matriz
    free(matriz);
}


bool insereCelula( Matriz* matriz, int x, int y )
{
    //Alocação da nova célula
    Celula* celula = (Celula*) malloc( sizeof(Celula) );

    //Preenchimento dos campos da célula
    celula->x = x;
    celula->y = y;

    celula->baixoProx = NULL;
    celula->direitaProx = NULL;

    //Se a lista da linha y estiver vazia, a célula é inserida como a primeira
    if (matriz->vetLinhas[y].pCabeca->direitaProx == NULL)
    {
        matriz->vetLinhas[y].pCabeca->direitaProx = celula;
        matriz->vetLinhas[y].pUltimo = celula;
    }else //Se não, a célula é inserida na posição correta
    {
        //A celula aux ira percorrer a lista até chegar no final, ou ate achar uma celula com x maior que o x da celula a ser inserida
        Celula* aux = matriz->vetLinhas[y].pCabeca->direitaProx;
        while ( aux->direitaProx != NULL )
        {
            aux = aux->direitaProx;
        }

        //Se a celula auxiliar for a ultima da lista, devemos atualizar o ponteiro para a ultima celula
        if (aux->direitaProx == NULL)
        {
            matriz->vetLinhas[y].pUltimo = celula;
        }

        //Aqui, a celula a ser inserida é colocada na posição correta
        celula->direitaProx = aux->direitaProx;
        aux->direitaProx = celula;
    }

    //Aqui, o mesmo processo é feito para a lista da coluna x
    if (matriz->vetColunas[x].pCabeca->baixoProx == NULL)
    {
        matriz->vetColunas[x].pCabeca->baixoProx = celula;
        matriz->vetColunas[x].pUltimo = celula;
    }else
    {
        Celula* aux = matriz->vetColunas[x].pCabeca->baixoProx;
        while ( aux->baixoProx != NULL )
        {
            aux = aux->baixoProx;
        }

        if (aux->baixoProx == NULL)
        {
            matriz->vetColunas[x].pUltimo = celula;
        }

        celula->baixoProx = aux->baixoProx;
        aux->baixoProx = celula;
    }

    return false;
}

bool pesquisaCelula( Matriz* matriz, int x, int y )
{
    Celula* aux = matriz->vetLinhas[y].pCabeca->direitaProx;

    //A celula aux ira percorrer a lista até chegar no final, ou até achar uma celula com x maior que o x da celula a ser pesquisada
    while (aux != NULL && aux->x <= x)
    {
        //Se a celula auxiliar tiver x igual ao x da celula a ser pesquisada, a celula foi encontrada
        if (aux->x == x)
        {
            return true;
        }

        aux = aux->direitaProx;
    }

    //Se a função chegou aqui é porque a celula não foi encontrada
    return false;
}

void imprimeMatriz( Matriz* matriz, int tam)
{
    //Os dois for's percorrem a matriz, juntamente com um auxiliar que percorre as listas
    for (int i = 0; i < tam; i++)
    {
        Celula* aux = matriz->vetLinhas[i].pCabeca->direitaProx;
        for (int j = 0; j < tam; j++)
        {
            //Se a celula auxiliar tiver x igual a j, a celula esta viva e deve ser impressa e o auxiliar avança
            if (aux != NULL && aux->x == j)
            {
                printf("1 ");
                aux = aux->direitaProx;
            }else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}