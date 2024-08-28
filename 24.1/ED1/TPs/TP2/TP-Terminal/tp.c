#include "automato.h"




int main(int argc, char const *argv[])
{
    Automato automato;

    LeituraReticulado(&automato);

    evoluirReticulado(&automato);

    imprimeReticulado(&automato);

    desalocarReticulado(&automato);

    return 0;
}