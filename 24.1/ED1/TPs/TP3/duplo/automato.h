# ifndef automato_h
# define automato_h
#include "double_hash.h"

typedef struct automato
{
    TabelaHash* reticulado;
    
    int tam;

    int geracao;
    
}Automato;

TabelaHash* alocarReticulado( int tamanho );
void desalocarReticulado( Automato* automato );
void LeituraReticulado( Automato* automato );
void imprimeReticulado( Automato* automato );
void evoluirReticulado( Automato* automato );

# endif
