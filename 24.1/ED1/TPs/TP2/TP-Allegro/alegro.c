#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "automato.h"
#include "matriz.h"

#define LARGURA_TELA 512
#define ALTURA_TELA 512

int main(int argc, char const *argv[])
{
    Automato automato;
    LeituraReticulado(&automato);

    //*Incializações do allegro
    al_init();
    al_init_primitives_addon();

    //*definições da janela
    ALLEGRO_DISPLAY * display = al_create_display(LARGURA_TELA,ALTURA_TELA);
    al_set_window_position(display, 200, 200);

    //*Declarações necessárias
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 3.0);

    //*Código necessario para poder fechar a janela no "x"
    ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);


    //*loop principal
    while(true){
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
            break;

        al_clear_to_color(al_map_rgb(0,0,0));

        //*Desenha o reticulado
        if(event.type == ALLEGRO_EVENT_TIMER)
        {
            if(automato.geracao > 0)
            {
                int aux = automato.geracao;
                automato.geracao = 1;
                evoluirReticulado(&automato);
                automato.geracao = aux - 1;
            }

            for (int i = 0; i < automato.tam; i++)
            {
                for (int j = 0; j < automato.tam; j++)
                {
                    if ( pesquisaCelula( automato.reticulado, i, j ))
                    {
                        al_draw_filled_rectangle(i * LARGURA_TELA/automato.tam, j * ALTURA_TELA/automato.tam, (i+1) * LARGURA_TELA/automato.tam, (j+1) * ALTURA_TELA/automato.tam, al_map_rgb(255,255,255));
                    }
                }
            }
        }
        al_flip_display();
    }

    //evoluirReticulado(&automato);

    //imprimeReticulado(&automato);

    desalocarReticulado(&automato);

    return 0;
}