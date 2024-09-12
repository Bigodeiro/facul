#include <stdio.h>
#include <string.h>
#include "hash.h"

int main() {
    Hash hash;
    Chave chave;
    int nCasos;

    // PREENCHER COM OUTRAS VARIÁVEIS
    int m, p, ultimaPos;

    // Ler a quantidade de casos
    // printf("Insira o numero de casos de teste ");
    scanf( "%d", &nCasos );

    while (nCasos-- > 0) {
        
        // Lendo tamanho da tabela e quantidade de pesos
        // printf("Insira o tamanho da tabela hash e o tamanho do vetor de pesos ");
        scanf( "%d %d", &m, &p );

        // Iniciar Hash
        inicia( &hash, m, p );

        // Lendo pesos
        for (int i = 0; i < p; i++)
        {
            // printf("Insira o valor do %d peso ", i);
            scanf("%d", &hash.pesos[i]);

        }
        

        // Lendo quantidade de chaves
        int nChaves;
        // printf("insira o numero de chaves ");
        scanf("%d", &nChaves);

        // Lendo chaves
        for (int i = 0; i < nChaves; i++)
        {
            // printf("insira a %d chave ", i);
            scanf("%s", chave);

            // int length = strlen(chave);

            // for (int i = 0; chave[i]; i++)
            // {
            //     if (chave[i] >= 'A' && chave[i] <= 'Z') 
            //     {
            //         chave[i] += 'a' - 'A';
            //     }
            // }

            // int k = 0;

            // for (int J = 0; J < length; J++) {
            //     if ((chave[J] >= 'A' && chave[J] <= 'Z') ||
            //         (chave[J] >= 'a' && chave[J] <= 'z') ||
            //         (chave[J] >= '0' && chave[J] <= '9')) {
            //         chave[k++] = chave[J];
            //     }
            // }
            
            // chave[k] = '\0';

            ultimaPos = insere(&hash, chave);
        }

        // Imprimir resposta
        printf("%d\n", ultimaPos);

        // Liberar Hash
        libera( &hash ); 
    }

    return 0;
}