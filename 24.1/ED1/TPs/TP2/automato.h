# ifndef automato_h
# define automato_h

#include "matriz.h"

typedef struct automato
{
    Matriz* reticulado;
    
    int nLinhas;
    int nColunas;

    int geracao;
}Automato;

Matriz* alocarReticulado( int tamanho );
void desalocarReticulado( Automato* automato );
void LeituraReticulado( Automato* automato );
void imprimeReticulado( Automato* automato );
void evoluirReticulado( Automato* automato );


# endif
