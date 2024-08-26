#ifndef AUTOMATO
#define AUTOMATO

#include <stdbool.h>

typedef struct automato
{
    int tamanho;
    int** reticulado;
    
    int geracao;
}Automato;

int** alocarReticulado( int );
void desalocarReticulado( int**, int );
void LeituraReticulado( Automato*);
void imprimeReticulado( Automato* );
int vizinhosVivos( Automato*, int, int );
void evoluirReticulado( Automato* );
void copiarReticulado( Automato* , int** );
bool pesquisaCelula( Automato*, int, int );

#endif // !AUTOMATO