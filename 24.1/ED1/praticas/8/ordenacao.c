#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
int compare(const char* aluno1, const char* aluno2) {
    return strcmp(aluno1, aluno2);
}

void ordena(Aluno *alunos, int n)
{
    int h;

    for (h = 1; h < n; h = (3 * h) + 1){}

    do
    {
        h = (h - 1) / 3;
        for (int i = h; i < n; i++)
        {
            char aux[21];
            strcpy(aux, alunos[i].nome);
            int j = i;
            while (compare(alunos[j - h].nome, aux) == 1)
            {
                strcpy(alunos[j].nome, alunos[j - h].nome);
                j = j - h;
                if (j < h)
                {
                    break;
                }
                
            }
            strcpy(alunos[j].nome, aux);
        }

    } while (h != 1);
    
}


/* Manter como especificado */
void imprimeResposta(Aluno* alunos, int n, int k) {
    printf("%s\n", alunos[k-1].nome);
}

/* Manter como especificado */
Aluno* alocaAlunos(int n) {
    Aluno* new = (Aluno*) malloc(n * sizeof(Aluno));
    return new;
}

/* Manter como especificado */
void liberaAlunos(Aluno** alunos) {
    free(*alunos);
    *alunos = NULL;
}

/* Manter como especificado */
void leAlunos(Aluno* alunos, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", alunos[i].nome);
    }
}

/* Manter como especificado */
void leQuantidades(int* n, int* k) {
    scanf("%d %d", n, k);
}

