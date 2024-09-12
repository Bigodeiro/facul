#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAZIA "!!!!!!!\0"

// Manter como especificado
void inicia (Hash *hash, int m, int p) {
    hash->m = m;
    hash->p = p;

    hash->pesos  = malloc( p * sizeof(int) );
    hash->chaves = malloc( m * sizeof(Chave) );
    
    for (int i = 0; i < m; i++)
    {
        strcpy( hash->chaves[i], VAZIA );
    }
    
}

// Manter como especificado
void libera(Hash *hash) {
    free(hash->pesos);
    free(hash->chaves);
}

int H(Hash* hash, Chave chave) {
    int total = 0;
    int tamChave = strlen(chave);

    for (int i = 0; i < tamChave; i++)
        total += ( ( chave[i] * ( hash->pesos[ i % hash->p ] ) ) );
    
    
    return (total) % hash->m;
}

// Manter como especificado
int insere (Hash *hash, Chave chave) {
    
    int pos = H(hash, chave);

    int j = 0;
    while ( ( strcmp( chave, hash->chaves[ (pos + j) % hash->m ] ) != 0 ) &&
            ( strcmp( VAZIA, hash->chaves[ (pos + j) % hash->m ] ) != 0 ) && j < hash->m )
    {
        j++;
    }

    if ( strcmp( chave, hash->chaves[ (pos + j) % hash->m ] ) == 0 )
    {
        return -1;
    }

    strcpy( hash->chaves[ (pos + j) % hash->m ], chave);
    
    
    return (pos + j) % hash->m;
}