#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>


#define sfCf sfTexture_createFromFile
#define sfWc sfRenderWindow_create

bool tpiccolo = false;
bool tmedio = false;
bool tgrande = false;
bool mieti = false;
bool forag = false;
bool barb = false;
bool cann = false;
bool cot = false;
bool uvaa = false;
bool oli = false;

bool facile = false;
bool difficile = false;
bool si_1 = false;
bool no_1 = false;
bool si_2 = false;
bool no_2 = false;



//dichiarazione funzioni
int main(sfRenderWindow* wp, sfRenderWindow* wimp);
int menu(sfRenderWindow* window, sfEvent event, sfRenderWindow* wp, sfRenderWindow* wimp);
int if_click(sfRenderWindow* window, sfEvent event, sfRenderWindow* wp, sfRenderWindow* wimp);
int profilo(sfRenderWindow* window, sfEvent event, sfRenderWindow* wimp);
int impostazioni(sfRenderWindow* window, sfEvent event, sfRenderWindow* wp);
int avvia(sfRenderWindow* window, sfRenderWindow* wimp, sfRenderWindow* wp);










int main(sfRenderWindow* wp, sfRenderWindow* wimp) {

    // creazione della finestra
    sfVideoMode mode = { 1920, 1080, 32 };

    
    //creazione della texture e dello sprite
    sfTexture* texture = sfTexture_createFromFile("assets/fattoria.jpg", NULL);
    sfSprite* sprite = sfSprite_create();
    if (!texture) return 1;

    sfTexture* texture02 = sfTexture_createFromFile("assets/start.jpg", NULL);
    sfSprite* button = sfSprite_create();
    if (!texture02) return 1;


    //creazione del vettore 2 dimensioni
    sfVector2f scale = { 1.12, 1.12 };
    sfVector2f scale_button = { 1, 1 };
    sfVector2f pos_button = { 930,797 };
    sfVector2i pos_default = { 560,600 };


    //inizializzazione della texture e dello sprite
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(button, texture02, sfTrue);
    sfSprite_setScale(button, scale_button);
    sfSprite_setPosition(button, pos_button);

    sfRenderWindow* window = sfRenderWindow_create(mode, "Gioco", sfResize | sfClose, NULL);
    if (!window) return 1;

    sfMouse_setPosition((sfVector2i){560,600}, (const sfWindow*)window);

    //display della finestra
    sfRenderWindow_display(window);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, button, NULL);
    sfRenderWindow_display(window);


    // Loop principale
    while (sfRenderWindow_isOpen(window)) {
        // Gestione degli eventi
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {

            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }


        }



        //comandi
        sfVector2i mouse = sfMouse_getPosition((const sfWindow*)window);


        printf("position = (%d;%d)\n", mouse.x, mouse.y);



        if_click(window, event, wp, wimp);

        return 0;


    }
    return 0;
}

int menu(sfRenderWindow* window, sfEvent event, sfRenderWindow* wp, sfRenderWindow* wimp) {

    int x;
    x = 1;
    if (x == 1) {
        const char* frasemenu = "Menù di Gioco";
        const char* frasevoce = "- Profilo";
        const char* frasevoce2 = "- Impostazioni";
        const char* frasevoce3 = "AVVIA";


        sfRenderWindow_setTitle(window, "Menu di gioco");

        //scritta menu di gioco
        sfText* text = sfText_create();
        sfVector2f testob = { 838,349 };
        sfFont* font = sfFont_createFromFile("font/G_ari_bd.ttf");
        sfText_setFont(text, font);
        sfText_setString(text, frasemenu);
        sfText_setCharacterSize(text, 47);
        sfText_setColor(text, sfBlack);
        sfText_setPosition(text, testob);
        sfText_setFillColor(text, sfRed);
        sfText_setOutlineThickness(text, 4.0);
        sfRenderWindow_drawText(window, text, NULL);

        //voce 1 menu di gioco = profilo
        sfText* voce1 = sfText_create();
        sfVector2f voce1b = { 890, 460 };
        sfText_setFont(voce1, font);
        sfText_setString(voce1, frasevoce);
        sfText_setCharacterSize(voce1, 35);
        sfText_setColor(voce1, sfBlack);
        sfText_setPosition(voce1, voce1b);
        sfText_setFillColor(voce1, sfWhite);
        sfText_setOutlineThickness(voce1, 4.0);
        sfRenderWindow_drawText(window, voce1, NULL);

        //voce 2 menu di gioco = impostazioni
        sfText* voce2 = sfText_create();
        sfVector2f voce2b = { 890, 558 };
        sfText_setFont(voce2, font);
        sfText_setString(voce2, frasevoce2);
        sfText_setCharacterSize(voce2, 35);
        sfText_setColor(voce2, sfBlack);
        sfText_setPosition(voce2, voce2b);
        sfText_setFillColor(voce2, sfWhite);
        sfText_setOutlineThickness(voce2, 4.0);
        sfRenderWindow_drawText(window, voce2, NULL);

        //voce 3 menu di gioco = avvia
        sfText* voce3 = sfText_create();
        sfVector2f voce3b = { 940, 840 };
        sfText_setFont(voce3, font);
        sfText_setString(voce3, frasevoce3);
        sfText_setCharacterSize(voce3, 45);
        sfText_setColor(voce3, sfBlack);
        sfText_setPosition(voce3, voce3b);
        sfText_setFillColor(voce3, sfYellow);
        sfText_setOutlineThickness(voce3, 4.0);
        sfRenderWindow_drawText(window, voce3, NULL);
    }

    if_click(window, event, wp, wimp);

    return 0;

}

int if_click(sfRenderWindow* window, sfEvent event, sfRenderWindow* wp, sfRenderWindow* wimp) {

    sfTime sleepTime = sfMilliseconds(1000);

    //funzionamento bottone e transizione sfondi
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 930 && mouse.x <= 1009) {
        if (mouse.y >= 800 && mouse.y <= 828) {
            printf("button pressed--->");

            //sfondo di transizione
            sfTexture* texture03 = sfTexture_createFromFile("assets/inquadratura.jpg", NULL);
            sfSprite* sfondo = sfSprite_create();
            if (!texture03) return 1;

            sfRenderWindow_display(window);
            sfSprite_setTexture(sfondo, texture03, sfTrue);
            sfRenderWindow_drawSprite(window, sfondo, NULL);

            menu(window, event, wp, wimp);


        }
    }

    //collegamento con bottone avvia
    if (mouse.x >= 934 && mouse.x <= 1072) {
        if (mouse.y >= 848 && mouse.y <= 890) {
            printf("Avvia pressed--->");

            avvia(window, wimp, wp);

            sfSleep(sleepTime);

        }
    }

    //collegamento con bottone impostazioni
    if (mouse.x >= 800 && mouse.x <= 1120) {
        if (mouse.y >= 565 && mouse.y <= 598) {
            printf("Impostazioni pressed--->");

            impostazioni(window, event, wp);

            sfSleep(sleepTime);

        }
    }

    //collegamento con bottone personaggio
    if (mouse.x >= 800 && mouse.x <= 1026) {
        if (mouse.y >= 467 && mouse.y <= 496) {
            printf("Profilo pressed--->");

            profilo(window, event, wimp);

            sfSleep(sleepTime);

        }
    }

    return 0;
}

int profilo(sfRenderWindow* window, sfEvent event, sfRenderWindow* wimp) {

    // Testo del menu e avvia
    const char* backmenudx = "Impostazioni";
    const char* avviastrng = "AVVIA";
    const char* fraseavatar = "Il tuo Avatar";
    const char* fraseveicoli = "Scegli il tuo veicolo";
    const char* trattorep = "TRATTORE PICCOLO";
    const char* trattorem = "TRATTORE MEDIO";
    const char* trattoreg = "TRATTORE GRANDE";
    const char* mietitrice = "MIETITRICE";
    const char* mietitriceforaggio = "MIET.FORAGGIO";
    const char* barbabietole = "BARBABIETOLE";
    const char* cannedazucchero = "CANNE ZUCCHERO";
    const char* cotone = "COTONE TEC.";
    const char* uva = "GRAPPOLI UVA";
    const char* olive = "OLIVE TECN.";

    const char* scelta_s = "hai scelto iL TRATTORE PICCOLO";
    const char* scelta_s1 = "hai scelto il TRATTORE MEDIO";
    const char* scelta_s2 = "hai scelto il TRATTORE GRANDE";
    const char* scelta_s3 = "hai scelto la MIETITRICE";
    const char* scelta_s4 = "hai scelto la MIETITRICE per FORAGGIO";
    const char* scelta_s5 = "hai scelto il RACCOGLITORE di BARBABIETOLE";
    const char* scelta_s6 = "hai scelto il RACCOGLITORE di CANNE DA ZUCCHERO";
    const char* scelta_s7 = "hai scelto il RACCOGLITORE di COTONE";
    const char* scelta_s8 = "hai scelto il RACCOGLITORE di UVA";
    const char* scelta_s9 = "hai scelto il RACCOGLITORE di OLIVE";

    const char* calendario_s = "Calendario dei Raccolti";
    const char* avviso1 = "Ricordati che durante il gioco\npotrai consultare la mappa dei\n raccolti quante volte vorrai !!";

    bool x = false;
    bool x1 = false;
    bool x2 = false;
    bool x3 = false;
    bool x4 = false;
    bool x5 = false;
    bool x6 = false;
    bool x7 = false;
    bool x8 = false;
    bool x9 = false;

    
   




   

    //-----------------------------------------------------------------------------------------------------------------------------------------------------


    // Modalità video per la nuova finestra
    sfVideoMode mode = { 1920, 1080, 32 };


    // Caricamento texture e sprite
    //sfondo
    sfTexture* textup = sfTexture_createFromFile("assets/inquadratura.jpg", NULL);
    if (!textup) return 1;

    //avatar
    sfTexture* texta = sfTexture_createFromFile("assets/avatar.jpg", NULL);
    sfSprite* butta = sfSprite_create();
    if (!texta) return 1;

    //trattori
    sfTexture* textt = sfTexture_createFromFile("assets/trattori.jpg", NULL);
    sfSprite* buttt = sfSprite_create();
    if (!textt) return 1;

    //mietitrici
    sfTexture* textm = sfTexture_createFromFile("assets/mietitrici.jpg", NULL);
    sfSprite* buttm = sfSprite_create();
    if (!textm) return 1;

    //tecnologie
    sfTexture* texttec = sfTexture_createFromFile("assets/tecnologie.jpg", NULL);
    sfSprite* butttec = sfSprite_create();
    if (!texttec) return 1;

    //raccolti
    sfTexture* textr = sfTexture_createFromFile("assets/raccolti.jpg", NULL);
    sfSprite* buttr = sfSprite_create();
    if (!textr) return 1;

    //raccolti 2
    sfTexture* textr2 = sfTexture_createFromFile("assets/raccolti.jpg", NULL);
    sfSprite* buttr2 = sfSprite_create();
    if (!textr) return 1;

    //raccolti 3
    sfTexture* textr3 = sfTexture_createFromFile("assets/raccolti.jpg", NULL);
    sfSprite* buttr3 = sfSprite_create();
    if (!textr) return 1;

    //raccolti 4
    sfTexture* textr4 = sfTexture_createFromFile("assets/raccolti.jpg", NULL);
    sfSprite* buttr4 = sfSprite_create();
    if (!textr) return 1;

    //raccolti 5
    sfTexture* textr5 = sfTexture_createFromFile("assets/raccolti.jpg", NULL);
    sfSprite* buttr5 = sfSprite_create();
    if (!textr) return 1;

    //raccolti 6
    sfTexture* textr6 = sfTexture_createFromFile("assets/raccolti.jpg", NULL);
    sfSprite* buttr6 = sfSprite_create();
    if (!textr) return 1;

    //raccolti 7
    sfTexture* textr7 = sfTexture_createFromFile("assets/raccolti.jpg", NULL);
    sfSprite* buttr7 = sfSprite_create();
    if (!textr) return 1;

    //raccolti 8
    sfTexture* textr8 = sfTexture_createFromFile("assets/raccolti.jpg", NULL);
    sfSprite* buttr8 = sfSprite_create();
    if (!textr) return 1;

    //raccolti 9
    sfTexture* textr9 = sfTexture_createFromFile("assets/raccolti.jpg", NULL);
    sfSprite* buttr9 = sfSprite_create();
    if (!textr) return 1;

    //raccolti 10
    sfTexture* textr10 = sfTexture_createFromFile("assets/raccolti.jpg", NULL);
    sfSprite* buttr10 = sfSprite_create();
    if (!textr) return 1;



    //sfondo
    sfSprite* spritep = sfSprite_create();
    sfVector2f scalep = { 1.12f, 1.12f };
    sfSprite_setTexture(spritep, textup, sfTrue);
    sfSprite_setScale(spritep, scalep);


    //immagine avatar
    sfVector2f scale = { 1.12, 1.12 };
    sfVector2f pos_button = { 170,250 };

    sfSprite_setTexture(butta, texta, sfTrue);
    sfSprite_setScale(butta, scale);
    sfSprite_setPosition(butta, pos_button);


    //immagine trattori
    sfVector2f pos_button2 = { 825,335 };

    sfSprite_setTexture(buttt, textt, sfTrue);
    sfSprite_setScale(buttt, scale);
    sfSprite_setPosition(buttt, pos_button2);


    //imaggine mietitrici
    sfVector2f pos_button3 = { 1200,335 };

    sfSprite_setTexture(buttm, textm, sfTrue);
    sfSprite_setScale(buttm, scale);
    sfSprite_setPosition(buttm, pos_button3);


    //immagine tecnologie
    sfVector2f pos_button4 = { 880,570 };

    sfSprite_setTexture(butttec, texttec, sfTrue);
    sfSprite_setScale(butttec, scale);
    sfSprite_setPosition(butttec, pos_button4);



    //-----------------------------------------------------------------------------------------------------------------------------------------------------



    // Creazione della finestra
    sfRenderWindow* wp = sfRenderWindow_create(mode, "Profilo", sfResize | sfClose, NULL);
    if (!wp) return 1;

    //-----------------------------------------------------------------------------------------------------------------------------------------------------

    // Creazione del testo laterale 
    sfFont* font = sfFont_createFromFile("font/G_ari_bd.ttf");
    if (!font) return 1;
    sfText* backdx = sfText_create();
    sfVector2f testobackdx = { 1450.0f, 890.0f };
    sfText_setFont(backdx, font);
    sfText_setString(backdx, backmenudx);
    sfText_setCharacterSize(backdx, 47);
    sfText_setFillColor(backdx, sfWhite);
    sfText_setOutlineColor(backdx, sfBlack);
    sfText_setOutlineThickness(backdx, 4.0f);
    sfText_setPosition(backdx, testobackdx);

    //creazione del pulsante avvia
    sfText* avviabutton = sfText_create();
    sfVector2f ab = { 940, 840 };
    sfText_setFont(avviabutton, font);
    sfText_setString(avviabutton, avviastrng);
    sfText_setCharacterSize(avviabutton, 45);
    sfText_setColor(avviabutton, sfBlack);
    sfText_setPosition(avviabutton, ab);
    sfText_setFillColor(avviabutton, sfYellow);
    sfText_setOutlineThickness(avviabutton, 4.0);
    sfRenderWindow_drawText(wp, avviabutton, NULL);

    //voce 1 profilo = avatar
    sfText* avatar = sfText_create();
    sfVector2f testoa = { 270,157 };
    sfText_setFont(avatar, font);
    sfText_setString(avatar, fraseavatar);
    sfText_setCharacterSize(avatar, 50);
    sfText_setFillColor(avatar, sfWhite);
    sfText_setOutlineColor(avatar, sfBlack);
    sfText_setOutlineThickness(avatar, 4.0f);
    sfText_setPosition(avatar, testoa);

    //voce 2 profilo = scegli il veicolo
    sfText* veicoli = sfText_create();
    sfVector2f testov = { 938,264 };
    sfText_setFont(veicoli, font);
    sfText_setString(veicoli, fraseveicoli);
    sfText_setCharacterSize(veicoli, 45);
    sfText_setFillColor(veicoli, sfWhite);
    sfText_setOutlineColor(veicoli, sfBlack);
    sfText_setOutlineThickness(veicoli, 4.0f);
    sfText_setPosition(veicoli, testov);

    //voce 3 profilo = trattore piccolo
    sfText* trattorepic = sfText_create();
    sfVector2f testotp = { 827,456 };
    sfText_setFont(trattorepic, font);
    sfText_setString(trattorepic, trattorep);
    sfText_setCharacterSize(trattorepic, 9);
    sfColor orange = sfColor_fromRGB(255, 128, 0);
    sfText_setFillColor(trattorepic, orange);
    sfText_setOutlineColor(trattorepic, sfBlack);
    sfText_setOutlineThickness(trattorepic, 4.0f);
    sfText_setPosition(trattorepic, testotp);

    //voce 4 profilo = trattore medio
    sfText* trattoremed = sfText_create();
    sfVector2f testotm = { 945,456 };
    sfText_setFont(trattoremed, font);
    sfText_setString(trattoremed, trattorem);
    sfText_setCharacterSize(trattoremed, 9);
    sfText_setFillColor(trattoremed, sfCyan);
    sfText_setOutlineColor(trattoremed, sfBlack);
    sfText_setOutlineThickness(trattoremed, 4.0f);
    sfText_setPosition(trattoremed, testotm);

    //voce 5 profilo = trattore grande
    sfText* trattoregra = sfText_create();
    sfVector2f testotg = { 1047,456 };
    sfText_setFont(trattoregra, font);
    sfText_setString(trattoregra, trattoreg);
    sfText_setCharacterSize(trattoregra, 9);
    sfText_setFillColor(trattoregra, sfMagenta);
    sfText_setOutlineColor(trattoregra, sfBlack);
    sfText_setOutlineThickness(trattoregra, 4.0f);
    sfText_setPosition(trattoregra, testotg);

    //voce 6 profilo = mietitrice
    sfText* miet = sfText_create();
    sfVector2f testomiet = { 1232,460 };
    sfText_setFont(miet, font);
    sfText_setString(miet, mietitrice);
    sfText_setCharacterSize(miet, 12);
    sfColor dark_green = sfColor_fromRGB(0, 143, 57);
    sfText_setFillColor(miet, dark_green);
    sfText_setOutlineColor(miet, sfBlack);
    sfText_setOutlineThickness(miet, 4.0f);
    sfText_setPosition(miet, testomiet);

    //voce 7 profilo = mietitrice foraggio
    sfText* mietf = sfText_create();
    sfVector2f testomietf = { 1350,460 };
    sfText_setFont(mietf, font);
    sfText_setString(mietf, mietitriceforaggio);
    sfText_setCharacterSize(mietf, 12);
    sfText_setFillColor(mietf, dark_green);
    sfText_setOutlineColor(mietf, sfBlack);
    sfText_setOutlineThickness(mietf, 4.0f);
    sfText_setPosition(mietf, testomietf);

    //voce 8 profilo = barbabietole
    sfText* b = sfText_create();
    sfVector2f testobarba = { 886,664 };
    sfText_setFont(b, font);
    sfText_setString(b, barbabietole);
    sfText_setCharacterSize(b, 10);
    sfText_setFillColor(b, sfYellow);
    sfText_setOutlineColor(b, sfBlack);
    sfText_setOutlineThickness(b, 4.0f);
    sfText_setPosition(b, testobarba);

    //voce 9 profilo = canne da zucchero
    sfText* c = sfText_create();
    sfVector2f testocanne = { 980,663 };
    sfText_setFont(c, font);
    sfText_setString(c, cannedazucchero);
    sfText_setCharacterSize(c, 12);
    sfText_setFillColor(c, sfRed);
    sfText_setOutlineColor(c, sfBlack);
    sfText_setOutlineThickness(c, 4.0f);
    sfText_setPosition(c, testocanne);

    //voce 10 profilo = cotone
    sfText* co = sfText_create();
    sfVector2f testocotone = { 1102,663 };
    sfText_setFont(co, font);
    sfText_setString(co, cotone);
    sfText_setCharacterSize(co, 13);
    sfText_setFillColor(co, sfGreen);
    sfText_setOutlineColor(co, sfBlack);
    sfText_setOutlineThickness(co, 4.0f);
    sfText_setPosition(co, testocotone);

    //voce 11 profilo = uva
    sfText* u = sfText_create();
    sfVector2f testouva = { 1200,663 };
    sfText_setFont(u, font);
    sfText_setString(u, uva);
    sfText_setCharacterSize(u, 13);
    sfColor purple = sfColor_fromRGB(160, 32, 240);
    sfText_setFillColor(u, purple);
    sfText_setOutlineColor(u, sfBlack);
    sfText_setOutlineThickness(u, 4.0f);
    sfText_setPosition(u, testouva);

    //voce 12 profilo = olive
    sfText* ol = sfText_create();
    sfVector2f testoolive = { 1314,663 };
    sfText_setFont(ol, font);
    sfText_setString(ol, olive);
    sfText_setCharacterSize(ol, 13);
    sfText_setFillColor(ol, sfBlue);
    sfText_setOutlineColor(ol, sfBlack);
    sfText_setOutlineThickness(ol, 4.0f);
    sfText_setPosition(ol, testoolive);

    //voce 1 profilo->veicolo-> scelta veicolo
    sfText* scelta = sfText_create();
    sfVector2f testos = { 767,780 };
    sfText_setFont(scelta, font);
    sfText_setString(scelta, scelta_s);
    sfText_setCharacterSize(scelta, 30);
    sfText_setFillColor(scelta, orange);
    sfText_setOutlineColor(scelta, sfBlack);
    sfText_setOutlineThickness(scelta, 4.0f);
    sfText_setPosition(scelta, testos);

    //voce 2 profilo->veicolo-> scelta veicolo
    sfText* scelta2 = sfText_create();
    sfVector2f testos2 = { 767,780 };
    sfText_setFont(scelta2, font);
    sfText_setString(scelta2, scelta_s1);
    sfText_setCharacterSize(scelta2, 30);
    sfText_setFillColor(scelta2, sfCyan);
    sfText_setOutlineColor(scelta2, sfBlack);
    sfText_setOutlineThickness(scelta2, 4.0f);
    sfText_setPosition(scelta2, testos2);

    //voce 3 profilo->veicolo-> scelta veicolo
    sfText* scelta3 = sfText_create();
    sfVector2f testos3 = { 767,780 };
    sfText_setFont(scelta3, font);
    sfText_setString(scelta3, scelta_s2);
    sfText_setCharacterSize(scelta3, 30);
    sfText_setFillColor(scelta3, sfMagenta);
    sfText_setOutlineColor(scelta3, sfBlack);
    sfText_setOutlineThickness(scelta3, 4.0f);
    sfText_setPosition(scelta3, testos3);

    //voce 4 profilo->veicolo->scelta veicolo
    sfText* scelta4 = sfText_create();
    sfVector2f testos4 = { 880,780 };
    sfText_setFont(scelta4, font);
    sfText_setString(scelta4, scelta_s3);
    sfText_setCharacterSize(scelta4, 30);
    sfText_setFillColor(scelta4, dark_green);
    sfText_setOutlineColor(scelta4, sfBlack);
    sfText_setOutlineThickness(scelta4, 4.0f);
    sfText_setPosition(scelta4, testos4);

    //voce 5 profilo->veicolo->scelta veicolo
    sfText* scelta5 = sfText_create();
    sfVector2f testos5 = { 780,780 };
    sfText_setFont(scelta5, font);
    sfText_setString(scelta5, scelta_s4);
    sfText_setCharacterSize(scelta5, 30);
    sfText_setFillColor(scelta5, dark_green);
    sfText_setOutlineColor(scelta5, sfBlack);
    sfText_setOutlineThickness(scelta5, 4.0f);
    sfText_setPosition(scelta5, testos5);

    //voce 6 profilo->veicolo->scelta veicolo
    sfText* scelta6 = sfText_create();
    sfVector2f testos6 = { 670,780 };
    sfText_setFont(scelta6, font);
    sfText_setString(scelta6, scelta_s5);
    sfText_setCharacterSize(scelta6, 30);
    sfText_setFillColor(scelta6, sfYellow);
    sfText_setOutlineColor(scelta6, sfBlack);
    sfText_setOutlineThickness(scelta6, 4.0f);
    sfText_setPosition(scelta6, testos6);

    //voce 7 profilo->veicolo->scelta veicolo
    sfText* scelta7 = sfText_create();
    sfVector2f testos7 = { 670,780 };
    sfText_setFont(scelta7, font);
    sfText_setString(scelta7, scelta_s6);
    sfText_setCharacterSize(scelta7, 30);
    sfText_setFillColor(scelta7, sfRed);
    sfText_setOutlineColor(scelta7, sfBlack);
    sfText_setOutlineThickness(scelta7, 4.0f);
    sfText_setPosition(scelta7, testos7);

    //voce 8 profilo->veicolo->scelta veicolo
    sfText* scelta8 = sfText_create();
    sfVector2f testos8 = { 760,780 };
    sfText_setFont(scelta8, font);
    sfText_setString(scelta8, scelta_s7);
    sfText_setCharacterSize(scelta8, 30);
    sfText_setFillColor(scelta8, sfGreen);
    sfText_setOutlineColor(scelta8, sfBlack);
    sfText_setOutlineThickness(scelta8, 4.0f);
    sfText_setPosition(scelta8, testos8);

    //voce 9 profilo->veicolo->scelta veicolo
    sfText* scelta9 = sfText_create();
    sfVector2f testos9 = { 780,780 };
    sfText_setFont(scelta9, font);
    sfText_setString(scelta9, scelta_s8);
    sfText_setCharacterSize(scelta9, 30);
    sfText_setFillColor(scelta9, purple);
    sfText_setOutlineColor(scelta9, sfBlack);
    sfText_setOutlineThickness(scelta9, 4.0f);
    sfText_setPosition(scelta9, testos9);

    //voce 10 profilo->veicolo->scelta veicolo
    sfText* scelta10 = sfText_create();
    sfVector2f testos10 = { 760,780 };
    sfText_setFont(scelta10, font);
    sfText_setString(scelta10, scelta_s9);
    sfText_setCharacterSize(scelta10, 30);
    sfText_setFillColor(scelta10, sfBlue);
    sfText_setOutlineColor(scelta10, sfBlack);
    sfText_setOutlineThickness(scelta10, 4.0f);
    sfText_setPosition(scelta10, testos10);


    //-----------------------------------------------------------------------------------------------------------------------------------------------------



    sfMouse_setPosition((sfVector2i){1123,525}, (const sfWindow*)window);

    // Ciclo principale
    while (sfRenderWindow_isOpen(wp)) {
        sfEvent eventp;
        while (sfRenderWindow_pollEvent(wp, &eventp)) {
            if (eventp.type == sfEvtClosed) {
                sfRenderWindow_close(wp);
            }
        }

        sfRenderWindow_close(window);

        //comandi
        sfVector2i mouse = sfMouse_getPositionRenderWindow(wp);
        printf("position = (%d;%d)\n", mouse.x, mouse.y);


        //funzionamento button impostazioni
        if (mouse.x >= 1452 && mouse.x <= 1738) {
            if (mouse.y >= 900 && mouse.y <= 939) {
                printf("Impostazioni pressed--->");

                sfRenderWindow_close(wp);

                impostazioni(window, event, wp);

            }
        }

        //funzionamento avvia 
        if (mouse.x >= 934 && mouse.x <= 1072) {
            if (mouse.y >= 848 && mouse.y <= 890) {
                printf("Avvia pressed--->");

                sfRenderWindow_close(wp);

                avvia(window, wimp, wimp);

            }
        }


        //-----------------------------------------------------------------------------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------------------------------------------------------------------------


        //funzionamento trattore piccolo
        if (mouse.x >= 825 && mouse.x <= 930) {
            if (mouse.y >= 338 && mouse.y <= 483) {
                printf("Small Tractor pressed-->");

                tpiccolo = true;
                tmedio = false;
                tgrande = false;
				mieti = false;
				forag = false;
				barb = false;
				cann = false;
				cot = false;
				uvaa = false;
				oli = false;

             

                sfSprite_setPosition(buttt, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(buttm, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butttec, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butta, (sfVector2f) { -900, -900 });

                sfText_setPosition(avatar, (sfVector2f) { -900, -900 });
                sfText_setPosition(veicoli, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattorepic, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoremed, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoregra, (sfVector2f) { -900, -900 });
                sfText_setPosition(miet, (sfVector2f) { -900, -900 });
                sfText_setPosition(mietf, (sfVector2f) { -900, -900 });
                sfText_setPosition(b, (sfVector2f) { -900, -900 });
                sfText_setPosition(c, (sfVector2f) { -900, -900 });
                sfText_setPosition(co, (sfVector2f) { -900, -900 });
                sfText_setPosition(u, (sfVector2f) { -900, -900 });
                sfText_setPosition(ol, (sfVector2f) { -900, -900 });
            }
        }


        //-----------------------------------------------------------------------------------------------------------------------------------------------------


        //funzionamento trattore medio
        if (mouse.x >= 941 && mouse.x <= 1039) {
            if (mouse.y >= 340 && mouse.y <= 477) {
                printf("Medium Tractor pressed-->");

                tmedio = true;
                tpiccolo = false;
                tgrande = false;
				mieti = false;
				forag = false;
                barb = false;
				cann = false;
				cot = false;
				uvaa = false;
				oli = false;

               


                sfSprite_setPosition(buttt, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(buttm, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butttec, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butta, (sfVector2f) { -900, -900 });

                sfText_setPosition(avatar, (sfVector2f) { -900, -900 });
                sfText_setPosition(veicoli, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattorepic, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoremed, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoregra, (sfVector2f) { -900, -900 });
                sfText_setPosition(miet, (sfVector2f) { -900, -900 });
                sfText_setPosition(mietf, (sfVector2f) { -900, -900 });
                sfText_setPosition(b, (sfVector2f) { -900, -900 });
                sfText_setPosition(c, (sfVector2f) { -900, -900 });
                sfText_setPosition(co, (sfVector2f) { -900, -900 });
                sfText_setPosition(u, (sfVector2f) { -900, -900 });
                sfText_setPosition(ol, (sfVector2f) { -900, -900 });
            }
        }


        //-----------------------------------------------------------------------------------------------------------------------------------------------------


        //funzionamento trattore grande
        if (mouse.x >= 1040 && mouse.x <= 1147) {
            if (mouse.y >= 340 && mouse.y <= 477) {
                printf("Big Tractor pressed-->");

                tgrande = true;
                tpiccolo = false;
                tmedio = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = false;
                cot = false;
                uvaa = false;
                oli = false;

                sfSprite_setPosition(buttt, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(buttm, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butttec, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butta, (sfVector2f) { -900, -900 });

                sfText_setPosition(avatar, (sfVector2f) { -900, -900 });
                sfText_setPosition(veicoli, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattorepic, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoremed, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoregra, (sfVector2f) { -900, -900 });
                sfText_setPosition(miet, (sfVector2f) { -900, -900 });
                sfText_setPosition(mietf, (sfVector2f) { -900, -900 });
                sfText_setPosition(b, (sfVector2f) { -900, -900 });
                sfText_setPosition(c, (sfVector2f) { -900, -900 });
                sfText_setPosition(co, (sfVector2f) { -900, -900 });
                sfText_setPosition(u, (sfVector2f) { -900, -900 });
                sfText_setPosition(ol, (sfVector2f) { -900, -900 });
            }
        }

        //-----------------------------------------------------------------------------------------------------------------------------------------------------

        //funzionamento mietitrice
        if (mouse.x >= 1202 && mouse.x <= 1327) {
            if (mouse.y >= 338 && mouse.y <= 483) {
                printf("Mietitrice pressed-->");

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = true;
                forag = false;
                barb = false;
                cann = false;
                cot = false;
                uvaa = false;
                oli = false;

                sfSprite_setPosition(buttt, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(buttm, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butttec, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butta, (sfVector2f) { -900, -900 });

                sfText_setPosition(avatar, (sfVector2f) { -900, -900 });
                sfText_setPosition(veicoli, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattorepic, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoremed, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoregra, (sfVector2f) { -900, -900 });
                sfText_setPosition(miet, (sfVector2f) { -900, -900 });
                sfText_setPosition(mietf, (sfVector2f) { -900, -900 });
                sfText_setPosition(b, (sfVector2f) { -900, -900 });
                sfText_setPosition(c, (sfVector2f) { -900, -900 });
                sfText_setPosition(co, (sfVector2f) { -900, -900 });
                sfText_setPosition(u, (sfVector2f) { -900, -900 });
                sfText_setPosition(ol, (sfVector2f) { -900, -900 });
            }
        }

        //-----------------------------------------------------------------------------------------------------------------------------------------------------

        //funzionamento mietitrice foraggio
        if (mouse.x >= 1342 && mouse.x <= 1458) {
            if (mouse.y >= 338 && mouse.y <= 483) {
                printf("Mietitrice foraggio pressed-->");

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = true;
                barb = false;
                cann = false;
                cot = false;
                uvaa = false;
                oli = false;

                
                sfSprite_setPosition(buttt, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(buttm, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butttec, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butta, (sfVector2f) { -900, -900 });

                sfText_setPosition(avatar, (sfVector2f) { -900, -900 });
                sfText_setPosition(veicoli, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattorepic, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoremed, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoregra, (sfVector2f) { -900, -900 });
                sfText_setPosition(miet, (sfVector2f) { -900, -900 });
                sfText_setPosition(mietf, (sfVector2f) { -900, -900 });
                sfText_setPosition(b, (sfVector2f) { -900, -900 });
                sfText_setPosition(c, (sfVector2f) { -900, -900 });
                sfText_setPosition(co, (sfVector2f) { -900, -900 });
                sfText_setPosition(u, (sfVector2f) { -900, -900 });
                sfText_setPosition(ol, (sfVector2f) { -900, -900 });
            }
        }

        //-----------------------------------------------------------------------------------------------------------------------------------------------------

        //funzionamento barbabietole
        if (mouse.x >= 882 && mouse.x <= 977) {
            if (mouse.y >= 573 && mouse.y <= 687) {
                printf("Barbabietole pressed-->");

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = true;
                cann = false;
                cot = false;
                uvaa = false;
                oli = false;
                
                sfSprite_setPosition(buttt, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(buttm, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butttec, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butta, (sfVector2f) { -900, -900 });

                sfText_setPosition(avatar, (sfVector2f) { -900, -900 });
                sfText_setPosition(veicoli, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattorepic, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoremed, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoregra, (sfVector2f) { -900, -900 });
                sfText_setPosition(miet, (sfVector2f) { -900, -900 });
                sfText_setPosition(mietf, (sfVector2f) { -900, -900 });
                sfText_setPosition(b, (sfVector2f) { -900, -900 });
                sfText_setPosition(c, (sfVector2f) { -900, -900 });
                sfText_setPosition(co, (sfVector2f) { -900, -900 });
                sfText_setPosition(u, (sfVector2f) { -900, -900 });
                sfText_setPosition(ol, (sfVector2f) { -900, -900 });
            }
        }

        //-----------------------------------------------------------------------------------------------------------------------------------------------------

        //funzionamento canne da zucchero
        if (mouse.x >= 989 && mouse.x <= 1081) {
            if (mouse.y >= 573 && mouse.y <= 687) {
                printf("Canne da Zucchero pressed-->");

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = true;
                cot = false;
                uvaa = false;
                oli = false;

               

                sfSprite_setPosition(buttt, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(buttm, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butttec, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butta, (sfVector2f) { -900, -900 });

                sfText_setPosition(avatar, (sfVector2f) { -900, -900 });
                sfText_setPosition(veicoli, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattorepic, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoremed, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoregra, (sfVector2f) { -900, -900 });
                sfText_setPosition(miet, (sfVector2f) { -900, -900 });
                sfText_setPosition(mietf, (sfVector2f) { -900, -900 });
                sfText_setPosition(b, (sfVector2f) { -900, -900 });
                sfText_setPosition(c, (sfVector2f) { -900, -900 });
                sfText_setPosition(co, (sfVector2f) { -900, -900 });
                sfText_setPosition(u, (sfVector2f) { -900, -900 });
                sfText_setPosition(ol, (sfVector2f) { -900, -900 });
            }
        }

        //-----------------------------------------------------------------------------------------------------------------------------------------------------

        //funzionamento cotone
        if (mouse.x >= 1096 && mouse.x <= 1191) {
            if (mouse.y >= 573 && mouse.y <= 687) {
                printf("Cotone pressed-->");

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = false;
                cot = true;
                uvaa = false;
                oli = false;

                sfSprite_setPosition(buttt, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(buttm, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butttec, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butta, (sfVector2f) { -900, -900 });

                sfText_setPosition(avatar, (sfVector2f) { -900, -900 });
                sfText_setPosition(veicoli, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattorepic, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoremed, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoregra, (sfVector2f) { -900, -900 });
                sfText_setPosition(miet, (sfVector2f) { -900, -900 });
                sfText_setPosition(mietf, (sfVector2f) { -900, -900 });
                sfText_setPosition(b, (sfVector2f) { -900, -900 });
                sfText_setPosition(c, (sfVector2f) { -900, -900 });
                sfText_setPosition(co, (sfVector2f) { -900, -900 });
                sfText_setPosition(u, (sfVector2f) { -900, -900 });
                sfText_setPosition(ol, (sfVector2f) { -900, -900 });
            }
        }

        //-----------------------------------------------------------------------------------------------------------------------------------------------------

        //funzionamento uva
        if (mouse.x >= 1203 && mouse.x <= 1299) {
            if (mouse.y >= 573 && mouse.y <= 687) {
                printf("Uva pressed-->");

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = false;
                cot = false;
                uvaa = true;
                oli = false;

                
                sfSprite_setPosition(buttt, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(buttm, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butttec, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butta, (sfVector2f) { -900, -900 });

                sfText_setPosition(avatar, (sfVector2f) { -900, -900 });
                sfText_setPosition(veicoli, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattorepic, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoremed, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoregra, (sfVector2f) { -900, -900 });
                sfText_setPosition(miet, (sfVector2f) { -900, -900 });
                sfText_setPosition(mietf, (sfVector2f) { -900, -900 });
                sfText_setPosition(b, (sfVector2f) { -900, -900 });
                sfText_setPosition(c, (sfVector2f) { -900, -900 });
                sfText_setPosition(co, (sfVector2f) { -900, -900 });
                sfText_setPosition(u, (sfVector2f) { -900, -900 });
                sfText_setPosition(ol, (sfVector2f) { -900, -900 });
            }
        }

        //-----------------------------------------------------------------------------------------------------------------------------------------------------

        //funzionamento olive
        if (mouse.x >= 1310 && mouse.x <= 1404) {
            if (mouse.y >= 573 && mouse.y <= 687) {
                printf("Olive pressed-->");

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = false;
                cot = false;
                uvaa = false;
                oli = true;

                

                sfSprite_setPosition(buttt, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(buttm, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butttec, (sfVector2f) { -900, -900 });
                sfSprite_setPosition(butta, (sfVector2f) { -900, -900 });

                sfText_setPosition(avatar, (sfVector2f) { -900, -900 });
                sfText_setPosition(veicoli, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattorepic, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoremed, (sfVector2f) { -900, -900 });
                sfText_setPosition(trattoregra, (sfVector2f) { -900, -900 });
                sfText_setPosition(miet, (sfVector2f) { -900, -900 });
                sfText_setPosition(mietf, (sfVector2f) { -900, -900 });
                sfText_setPosition(b, (sfVector2f) { -900, -900 });
                sfText_setPosition(c, (sfVector2f) { -900, -900 });
                sfText_setPosition(co, (sfVector2f) { -900, -900 });
                sfText_setPosition(u, (sfVector2f) { -900, -900 });
                sfText_setPosition(ol, (sfVector2f) { -900, -900 });
            }
        }
        //-----------------------------------------------------------------------------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------------------------------------------------------------------------

        // Disegna gli sprite e i testi
        sfRenderWindow_drawSprite(wp, spritep, NULL);
        sfRenderWindow_drawSprite(wp, butta, NULL);
        sfRenderWindow_drawSprite(wp, buttt, NULL);
        sfRenderWindow_drawSprite(wp, buttm, NULL);
        sfRenderWindow_drawSprite(wp, butttec, NULL);
        sfRenderWindow_drawSprite(wp, buttr, NULL);
        sfRenderWindow_drawSprite(wp, buttr2, NULL);
        sfRenderWindow_drawSprite(wp, buttr3, NULL);
        sfRenderWindow_drawSprite(wp, buttr4, NULL);
        sfRenderWindow_drawSprite(wp, buttr5, NULL);
        sfRenderWindow_drawSprite(wp, buttr6, NULL);
        sfRenderWindow_drawSprite(wp, buttr7, NULL);
        sfRenderWindow_drawSprite(wp, buttr8, NULL);
        sfRenderWindow_drawSprite(wp, buttr9, NULL);
        sfRenderWindow_drawSprite(wp, buttr10, NULL);



        sfRenderWindow_drawText(wp, backdx, NULL);
        sfRenderWindow_drawText(wp, avviabutton, NULL);
        sfRenderWindow_drawText(wp, avatar, NULL);
        sfRenderWindow_drawText(wp, veicoli, NULL);
        sfRenderWindow_drawText(wp, trattorepic, NULL);
        sfRenderWindow_drawText(wp, trattoremed, NULL);
        sfRenderWindow_drawText(wp, trattoregra, NULL);
        sfRenderWindow_drawText(wp, miet, NULL);
        sfRenderWindow_drawText(wp, mietf, NULL);
        sfRenderWindow_drawText(wp, b, NULL);
        sfRenderWindow_drawText(wp, c, NULL);
        sfRenderWindow_drawText(wp, co, NULL);
        sfRenderWindow_drawText(wp, u, NULL);
        sfRenderWindow_drawText(wp, ol, NULL);


        //-----------------------------------------------------------------------------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------------------------------------------------------------------------

        
        //proietta la scritta della scelta trattore piccolo
        if (mouse.x >= 825 && mouse.x <= 930) {
            if (mouse.y >= 338 && mouse.y <= 483) {

                tpiccolo = true;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = false;
                cot = false;
                uvaa = false;
                oli = false;

                
                int minX = 837, minY = 351;
                int maxX = 920, maxY = 540;

                // Controlla se il mouse esce dai limiti e rimettilo dentro
                if (mouse.x < minX) mouse.x = minX;
                if (mouse.y < minY) mouse.y = minY;
                if (mouse.x > maxX) mouse.x = maxX;


                // Imposta la nuova posizione del mouse
                sfMouse_setPositionRenderWindow(mouse, wp);


                sfRenderWindow_drawText(wp, scelta, NULL);

                //immagine raccolti
                sfVector2f pos_button5 = { 820,280 };
                sfSprite_setTexture(buttr, textr, sfTrue);
                sfSprite_setScale(buttr, scale);
                sfSprite_setPosition(buttr, pos_button5);

                //calendario
                sfText* calendario = sfText_create();
                sfVector2f testocal = { 1055,235 };
                sfText_setFont(calendario, font);
                sfText_setString(calendario, calendario_s);
                sfText_setCharacterSize(calendario, 30);
                sfText_setFillColor(calendario, sfWhite);
                sfText_setOutlineColor(calendario, sfBlack);
                sfText_setOutlineThickness(calendario, 4.0f);
                sfText_setPosition(calendario, testocal);

                //avviso
                sfText* avviso = sfText_create();
                sfVector2f testoav = { 179,369 };
                sfText_setFont(avviso, font);
                sfText_setString(avviso, avviso1);
                sfText_setCharacterSize(avviso, 30);
                sfText_setFillColor(avviso, sfWhite);
                sfText_setOutlineColor(avviso, sfBlack);
                sfText_setOutlineThickness(avviso, 4.0f);
                sfText_setPosition(avviso, testoav);

                sfRenderWindow_drawText(wp, calendario, NULL);
                sfRenderWindow_drawText(wp, avviso, NULL);
                
            }
            else {
                sfSprite_setPosition(buttr, (sfVector2f) { -900, -900 });

            }

            if (mouse.y > 535 && !x) {
                sfMouse_setPosition((sfVector2i){1300,800}, (const sfWindow*)window);

                x = true;
            }


            // Reset del flag se il mouse torna sotto 525
            if (mouse.y <= 525) {
                x = false;
            }


        }



        //-----------------------------------------------------------------------------------------------------------------------------------------------------


        //proietta la scritta della scelta trattore medio
        if (mouse.x >= 941 && mouse.x <= 1039) {
            if (mouse.y >= 340 && mouse.y <= 477) {

                tmedio = true;
                tpiccolo = false;              
                tgrande = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = false;
                cot = false;
                uvaa = false;
                oli = false;

                int minX2 = 950, minY2 = 351;
                int maxX2 = 1037, maxY2 = 540;


                // Controlla se il mouse esce dai limiti e rimettilo dentro
                if (mouse.x < minX2) mouse.x = minX2;
                if (mouse.y < minY2) mouse.y = minY2;
                if (mouse.x > maxX2) mouse.x = maxX2;

                sfMouse_setPositionRenderWindow(mouse, wp);

                sfRenderWindow_drawText(wp, scelta2, NULL);

                //immagine raccolti
                sfVector2f pos_button5 = { 820,280 };
                sfSprite_setTexture(buttr2, textr2, sfTrue);
                sfSprite_setScale(buttr2, scale);
                sfSprite_setPosition(buttr2, pos_button5);

                //calendario
                sfText* calendario = sfText_create();
                sfVector2f testocal = { 1055,235 };
                sfText_setFont(calendario, font);
                sfText_setString(calendario, calendario_s);
                sfText_setCharacterSize(calendario, 30);
                sfText_setFillColor(calendario, sfWhite);
                sfText_setOutlineColor(calendario, sfBlack);
                sfText_setOutlineThickness(calendario, 4.0f);
                sfText_setPosition(calendario, testocal);

                //avviso
                sfText* avviso = sfText_create();
                sfVector2f testoav = { 179,369 };
                sfText_setFont(avviso, font);
                sfText_setString(avviso, avviso1);
                sfText_setCharacterSize(avviso, 30);
                sfText_setFillColor(avviso, sfWhite);
                sfText_setOutlineColor(avviso, sfBlack);
                sfText_setOutlineThickness(avviso, 4.0f);
                sfText_setPosition(avviso, testoav);

                sfRenderWindow_drawText(wp, calendario, NULL);
                sfRenderWindow_drawText(wp, avviso, NULL);
            }
        else {
                sfSprite_setPosition(buttr2, (sfVector2f) { -900, -900 });
        }

            if (mouse.y > 535 && !x1) {
                sfMouse_setPosition((sfVector2i){1300,800}, (const sfWindow*)wp);

                x1 = true;
            }


            // Reset del flag se il mouse torna sotto 525
            if (mouse.y <= 525) {
                x1 = false;
            }

         
            

        }


				

        //-----------------------------------------------------------------------------------------------------------------------------------------------------


        //proietta la scritta della scelta trattore grande
        if (mouse.x >= 1040 && mouse.x <= 1147) {
            if (mouse.y >= 340 && mouse.y <= 477) {

                tgrande = true;
                tmedio = false;
                tpiccolo = false;              
                mieti = false;
                forag = false;
                barb = false;
                cann = false;
                cot = false;
                uvaa = false;
                oli = false;


				int minX3 = 1050, minY3 = 351;
				int maxX3 = 1137, maxY3 = 540;

                // Controlla se il mouse esce dai limiti e rimettilo dentro
                if (mouse.x < minX3) mouse.x = minX3;
                if (mouse.y < minY3) mouse.y = minY3;
                if (mouse.x > maxX3) mouse.x = maxX3;

                sfMouse_setPositionRenderWindow(mouse, wp);


                sfRenderWindow_drawText(wp, scelta3, NULL);

                //immagine raccolti
                sfVector2f pos_button5 = { 820,280 };
                sfSprite_setTexture(buttr3, textr3, sfTrue);
                sfSprite_setScale(buttr3, scale);
                sfSprite_setPosition(buttr3, pos_button5);

                //calendario
                sfText* calendario = sfText_create();
                sfVector2f testocal = { 1055,235 };
                sfText_setFont(calendario, font);
                sfText_setString(calendario, calendario_s);
                sfText_setCharacterSize(calendario, 30);
                sfText_setFillColor(calendario, sfWhite);
                sfText_setOutlineColor(calendario, sfBlack);
                sfText_setOutlineThickness(calendario, 4.0f);
                sfText_setPosition(calendario, testocal);

                //avviso
                sfText* avviso = sfText_create();
                sfVector2f testoav = { 179,369 };
                sfText_setFont(avviso, font);
                sfText_setString(avviso, avviso1);
                sfText_setCharacterSize(avviso, 30);
                sfText_setFillColor(avviso, sfWhite);
                sfText_setOutlineColor(avviso, sfBlack);
                sfText_setOutlineThickness(avviso, 4.0f);
                sfText_setPosition(avviso, testoav);

                sfRenderWindow_drawText(wp, calendario, NULL);
                sfRenderWindow_drawText(wp, avviso, NULL);
            }
        }
        else {
            sfSprite_setPosition(buttr3, (sfVector2f) { -900, -900 });
        }

        if (mouse.y > 535 && !x2) {
            sfMouse_setPosition((sfVector2i){1123,525}, (const sfWindow*)wp);

            x2 = true;
        }


        // Reset del flag se il mouse torna sotto 525
        if (mouse.y <= 525) {
            x2 = false;
        }

        //---------------------------------------------------------------------------------------------------------------------------------------------------

        //proietta la scritta della scelta mietitrice
        if (mouse.x >= 1202 && mouse.x <= 1327) {
            if (mouse.y >= 338 && mouse.y <= 483) {

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = true;
                forag = false;
                barb = false;
                cann = false;
                cot = false;
                uvaa = false;
                oli = false;

				int minX4 = 1212, minY4 = 351;
				int maxX4 = 1325, maxY4 = 540;

                // Controlla se il mouse esce dai limiti e rimettilo dentro
                if (mouse.x < minX4) mouse.x = minX4;
                if (mouse.y < minY4) mouse.y = minY4;
                if (mouse.x > maxX4) mouse.x = maxX4;

                sfMouse_setPositionRenderWindow(mouse, wp);

                sfRenderWindow_drawText(wp, scelta4, NULL);

                //immagine raccolti
                sfVector2f pos_button5 = { 820,280 };
                sfSprite_setTexture(buttr4, textr4, sfTrue);
                sfSprite_setScale(buttr4, scale);
                sfSprite_setPosition(buttr4, pos_button5);

                //calendario
                sfText* calendario = sfText_create();
                sfVector2f testocal = { 1055,235 };
                sfText_setFont(calendario, font);
                sfText_setString(calendario, calendario_s);
                sfText_setCharacterSize(calendario, 30);
                sfText_setFillColor(calendario, sfWhite);
                sfText_setOutlineColor(calendario, sfBlack);
                sfText_setOutlineThickness(calendario, 4.0f);
                sfText_setPosition(calendario, testocal);

                //avviso
                sfText* avviso = sfText_create();
                sfVector2f testoav = { 179,369 };
                sfText_setFont(avviso, font);
                sfText_setString(avviso, avviso1);
                sfText_setCharacterSize(avviso, 30);
                sfText_setFillColor(avviso, sfWhite);
                sfText_setOutlineColor(avviso, sfBlack);
                sfText_setOutlineThickness(avviso, 4.0f);
                sfText_setPosition(avviso, testoav);

                sfRenderWindow_drawText(wp, calendario, NULL);
                sfRenderWindow_drawText(wp, avviso, NULL);
            }
        }
        else {
            sfSprite_setPosition(buttr4, (sfVector2f) { -900, -900 });
        }

        if (mouse.y > 535 && !x3) {
            sfMouse_setPosition((sfVector2i){1300,800}, (const sfWindow*)wp);

            x3 = true;
        }


        // Reset del flag se il mouse torna sotto 525
        if (mouse.y <= 525) {
            x3 = false;
        }

        //---------------------------------------------------------------------------------------------------------------------------------------------------

        //proietta la scritta della scelta mietitrice
        if (mouse.x >= 1342 && mouse.x <= 1458) {
            if (mouse.y >= 338 && mouse.y <= 483) {

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = true;
                barb = false;
                cann = false;
                cot = false;
                uvaa = false;
                oli = false;

				int minX5 = 1352, minY5 = 351;
				int maxX5 = 1445, maxY5 = 540;


                // Controlla se il mouse esce dai limiti e rimettilo dentro
                if (mouse.x < minX5) mouse.x = minX5;
                if (mouse.y < minY5) mouse.y = minY5;
                if (mouse.x > maxX5) mouse.x = maxX5;

                sfMouse_setPositionRenderWindow(mouse, wp);

                sfRenderWindow_drawText(wp, scelta5, NULL);

                //immagine raccolti
                sfVector2f pos_button5 = { 820,280 };
                sfSprite_setTexture(buttr5, textr5, sfTrue);
                sfSprite_setScale(buttr5, scale);
                sfSprite_setPosition(buttr5, pos_button5);

                //calendario
                sfText* calendario = sfText_create();
                sfVector2f testocal = { 1055,235 };
                sfText_setFont(calendario, font);
                sfText_setString(calendario, calendario_s);
                sfText_setCharacterSize(calendario, 30);
                sfText_setFillColor(calendario, sfWhite);
                sfText_setOutlineColor(calendario, sfBlack);
                sfText_setOutlineThickness(calendario, 4.0f);
                sfText_setPosition(calendario, testocal);

                //avviso
                sfText* avviso = sfText_create();
                sfVector2f testoav = { 179,369 };
                sfText_setFont(avviso, font);
                sfText_setString(avviso, avviso1);
                sfText_setCharacterSize(avviso, 30);
                sfText_setFillColor(avviso, sfWhite);
                sfText_setOutlineColor(avviso, sfBlack);
                sfText_setOutlineThickness(avviso, 4.0f);
                sfText_setPosition(avviso, testoav);

                sfRenderWindow_drawText(wp, calendario, NULL);
                sfRenderWindow_drawText(wp, avviso, NULL);
            }
        }
        else {
            sfSprite_setPosition(buttr5, (sfVector2f) { -900, -900 });
        }

        if (mouse.y > 535 && !x4) {
            sfMouse_setPosition((sfVector2i){1123,525}, (const sfWindow*)wp);


            x4 = true;
        }


        // Reset del flag se il mouse torna sotto 525
        if (mouse.y <= 525) {
            x4 = false;
        }

        //---------------------------------------------------------------------------------------------------------------------------------------------------

        //proietta la scritta della scelta barbabietole
        if (mouse.x >= 882 && mouse.x <= 977) {
            if (mouse.y >= 573 && mouse.y <= 687) {

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = true;
                cann = false;
                cot = false;
                uvaa = false;
                oli = false;

                int minX5 = 890, minY5 = 582;
                int maxX5 = 970, maxY5 = 700;


                // Controlla se il mouse esce dai limiti e rimettilo dentro
                if (mouse.x < minX5) mouse.x = minX5;
                if (mouse.y < minY5) mouse.y = minY5;
                if (mouse.x > maxX5) mouse.x = maxX5;

                sfMouse_setPositionRenderWindow(mouse, wp);


                sfRenderWindow_drawText(wp, scelta6, NULL);

                //immagine raccolti
                sfVector2f pos_button5 = { 820,280 };
                sfSprite_setTexture(buttr6, textr6, sfTrue);
                sfSprite_setScale(buttr6, scale);
                sfSprite_setPosition(buttr6, pos_button5);

                //calendario
                sfText* calendario = sfText_create();
                sfVector2f testocal = { 1055,235 };
                sfText_setFont(calendario, font);
                sfText_setString(calendario, calendario_s);
                sfText_setCharacterSize(calendario, 30);
                sfText_setFillColor(calendario, sfWhite);
                sfText_setOutlineColor(calendario, sfBlack);
                sfText_setOutlineThickness(calendario, 4.0f);
                sfText_setPosition(calendario, testocal);

                //avviso
                sfText* avviso = sfText_create();
                sfVector2f testoav = { 179,369 };
                sfText_setFont(avviso, font);
                sfText_setString(avviso, avviso1);
                sfText_setCharacterSize(avviso, 30);
                sfText_setFillColor(avviso, sfWhite);
                sfText_setOutlineColor(avviso, sfBlack);
                sfText_setOutlineThickness(avviso, 4.0f);
                sfText_setPosition(avviso, testoav);

                sfRenderWindow_drawText(wp, calendario, NULL);
                sfRenderWindow_drawText(wp, avviso, NULL);
            }
        }
        else {
            sfSprite_setPosition(buttr6, (sfVector2f) { -900, -900 });
        }
        

        //--------------------------------------------------------------------------------------------------------------------------------------------------

        //proietta la scritta della scelta canne da zucchero
        if (mouse.x >= 989 && mouse.x <= 1081) {
            if (mouse.y >= 573 && mouse.y <= 687) {

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = true;
                cot = false;
                uvaa = false;
                oli = false;

				int minX6 = 1000, minY6 = 582;
				int maxX6 = 1070, maxY6 = 700;

                // Controlla se il mouse esce dai limiti e rimettilo dentro
                if (mouse.x < minX6) mouse.x = minX6;
                if (mouse.y < minY6) mouse.y = minY6;
                if (mouse.x > maxX6) mouse.x = maxX6;

                sfMouse_setPositionRenderWindow(mouse, wp);



                sfRenderWindow_drawText(wp, scelta7, NULL);

                //immagine raccolti
                sfVector2f pos_button5 = { 820,280 };
                sfSprite_setTexture(buttr7, textr7, sfTrue);
                sfSprite_setScale(buttr7, scale);
                sfSprite_setPosition(buttr7, pos_button5);

                //calendario
                sfText* calendario = sfText_create();
                sfVector2f testocal = { 1055,235 };
                sfText_setFont(calendario, font);
                sfText_setString(calendario, calendario_s);
                sfText_setCharacterSize(calendario, 30);
                sfText_setFillColor(calendario, sfWhite);
                sfText_setOutlineColor(calendario, sfBlack);
                sfText_setOutlineThickness(calendario, 4.0f);
                sfText_setPosition(calendario, testocal);

                //avviso
                sfText* avviso = sfText_create();
                sfVector2f testoav = { 179,369 };
                sfText_setFont(avviso, font);
                sfText_setString(avviso, avviso1);
                sfText_setCharacterSize(avviso, 30);
                sfText_setFillColor(avviso, sfWhite);
                sfText_setOutlineColor(avviso, sfBlack);
                sfText_setOutlineThickness(avviso, 4.0f);
                sfText_setPosition(avviso, testoav);

                sfRenderWindow_drawText(wp, calendario, NULL);
                sfRenderWindow_drawText(wp, avviso, NULL);
            }
        }
        else {
            sfSprite_setPosition(buttr7, (sfVector2f) { -900, -900 });
        }

		

        //--------------------------------------------------------------------------------------------------------------------------------------------------

        //proietta la scritta della scelta cotone
        if (mouse.x >= 1096 && mouse.x <= 1191) {
            if (mouse.y >= 573 && mouse.y <= 687) {

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = false;
                cot = true;
                uvaa = false;
                oli = false;

				int minX7 = 1100, minY7 = 582;
				int maxX7 = 1180, maxY7 = 700;

				// Controlla se il mouse esce dai limiti e rimettilo dentro 
				if (mouse.x < minX7) mouse.x = minX7;
				if (mouse.y < minY7) mouse.y = minY7;
				if (mouse.x > maxX7) mouse.x = maxX7;

				sfMouse_setPositionRenderWindow(mouse, wp);

                sfRenderWindow_drawText(wp, scelta8, NULL);

                //immagine raccolti
                sfVector2f pos_button5 = { 820,280 };
                sfSprite_setTexture(buttr8, textr8, sfTrue);
                sfSprite_setScale(buttr8, scale);
                sfSprite_setPosition(buttr8, pos_button5);

                //calendario
                sfText* calendario = sfText_create();
                sfVector2f testocal = { 1055,235 };
                sfText_setFont(calendario, font);
                sfText_setString(calendario, calendario_s);
                sfText_setCharacterSize(calendario, 30);
                sfText_setFillColor(calendario, sfWhite);
                sfText_setOutlineColor(calendario, sfBlack);
                sfText_setOutlineThickness(calendario, 4.0f);
                sfText_setPosition(calendario, testocal);

                //avviso
                sfText* avviso = sfText_create();
                sfVector2f testoav = { 179,369 };
                sfText_setFont(avviso, font);
                sfText_setString(avviso, avviso1);
                sfText_setCharacterSize(avviso, 30);
                sfText_setFillColor(avviso, sfWhite);
                sfText_setOutlineColor(avviso, sfBlack);
                sfText_setOutlineThickness(avviso, 4.0f);
                sfText_setPosition(avviso, testoav);

                sfRenderWindow_drawText(wp, calendario, NULL);
                sfRenderWindow_drawText(wp, avviso, NULL);
            }
        }
        else {
            sfSprite_setPosition(buttr8, (sfVector2f) { -900, -900 });
        }

		

        //--------------------------------------------------------------------------------------------------------------------------------------------------

        //proietta la scritta della scelta uva
        if (mouse.x >= 1203 && mouse.x <= 1299) {
            if (mouse.y >= 573 && mouse.y <= 687) {

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = false;
                cot = false;
                uvaa = true;
                oli = false;


				int minX8 = 1210, minY8 = 582;
				int maxX8 = 1290, maxY8 = 700;

				// Controlla se il mouse esce dai limiti e rimettilo dentro
				if (mouse.x < minX8) mouse.x = minX8;
				if (mouse.y < minY8) mouse.y = minY8;
				if (mouse.x > maxX8) mouse.x = maxX8;

				sfMouse_setPositionRenderWindow(mouse, wp);

                sfRenderWindow_drawText(wp, scelta9, NULL);

                //immagine raccolti
                sfVector2f pos_button5 = { 820,280 };
                sfSprite_setTexture(buttr9, textr9, sfTrue);
                sfSprite_setScale(buttr9, scale);
                sfSprite_setPosition(buttr9, pos_button5);

                //calendario
                sfText* calendario = sfText_create();
                sfVector2f testocal = { 1055,235 };
                sfText_setFont(calendario, font);
                sfText_setString(calendario, calendario_s);
                sfText_setCharacterSize(calendario, 30);
                sfText_setFillColor(calendario, sfWhite);
                sfText_setOutlineColor(calendario, sfBlack);
                sfText_setOutlineThickness(calendario, 4.0f);
                sfText_setPosition(calendario, testocal);

                //avviso
                sfText* avviso = sfText_create();
                sfVector2f testoav = { 179,369 };
                sfText_setFont(avviso, font);
                sfText_setString(avviso, avviso1);
                sfText_setCharacterSize(avviso, 30);
                sfText_setFillColor(avviso, sfWhite);
                sfText_setOutlineColor(avviso, sfBlack);
                sfText_setOutlineThickness(avviso, 4.0f);
                sfText_setPosition(avviso, testoav);

                sfRenderWindow_drawText(wp, calendario, NULL);
                sfRenderWindow_drawText(wp, avviso, NULL);
            }
        }
        else {
            sfSprite_setPosition(buttr9, (sfVector2f) { -900, -900 });
        }

		


        //--------------------------------------------------------------------------------------------------------------------------------------------------

        //proietta la scritta della scelta olive
        if (mouse.x >= 1310 && mouse.x <= 1404) {
            if (mouse.y >= 573 && mouse.y <= 687) {

                tpiccolo = false;
                tmedio = false;
                tgrande = false;
                mieti = false;
                forag = false;
                barb = false;
                cann = false;
                cot = false;
                uvaa = false;
                oli = true;

				int minX9 = 1320, minY9 = 582;
				int maxX9 = 1395, maxY9 = 700;

				// Controlla se il mouse esce dai limiti e rimettilo dentro
				if (mouse.x < minX9) mouse.x = minX9;
				if (mouse.y < minY9) mouse.y = minY9;
				if (mouse.x > maxX9) mouse.x = maxX9;

				sfMouse_setPositionRenderWindow(mouse, wp);

                sfRenderWindow_drawText(wp, scelta10, NULL);

                //immagine raccolti
                sfVector2f pos_button5 = { 820,280 };
                sfSprite_setTexture(buttr10, textr10, sfTrue);
                sfSprite_setScale(buttr10, scale);
                sfSprite_setPosition(buttr10, pos_button5);

                //calendario
                sfText* calendario = sfText_create();
                sfVector2f testocal = { 1055,235 };
                sfText_setFont(calendario, font);
                sfText_setString(calendario, calendario_s);
                sfText_setCharacterSize(calendario, 30);
                sfText_setFillColor(calendario, sfWhite);
                sfText_setOutlineColor(calendario, sfBlack);
                sfText_setOutlineThickness(calendario, 4.0f);
                sfText_setPosition(calendario, testocal);

                //avviso
                sfText* avviso = sfText_create();
                sfVector2f testoav = { 179,369 };
                sfText_setFont(avviso, font);
                sfText_setString(avviso, avviso1);
                sfText_setCharacterSize(avviso, 30);
                sfText_setFillColor(avviso, sfWhite);
                sfText_setOutlineColor(avviso, sfBlack);
                sfText_setOutlineThickness(avviso, 4.0f);
                sfText_setPosition(avviso, testoav);

                sfRenderWindow_drawText(wp, calendario, NULL);
                sfRenderWindow_drawText(wp, avviso, NULL);
            }
        }
        else {
            sfSprite_setPosition(buttr10, (sfVector2f) { -900, -900 });
        }




        //---------------------------------------------------------------------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------------------------------------------------------------

        // Aggiorna la finestra
        sfRenderWindow_display(wp);




    }




    return 0;

}

int impostazioni(sfRenderWindow* window, sfEvent event, sfRenderWindow* wp) {

  


    // Testo del menu e avvia
    const char* backmenudx = "Profilo";
    const char* avviastr = "AVVIA";

    const char* t1_1 = "Impostazioni di Gioco";
    const char* t2_2 = "- difficoltà: ";
    const char* t3_3 = "facile";
    const char* t4_4 = "difficile";
    const char* t5_5 = "-  spawn animali\n      selvatici: ";
    const char* t6_6 = "si";
    const char* t7_7 = "no";
    const char* t8_8 = "- missioni:";
    const char* t9_9 = "si";
    const char* t10_10 = "no";

    const char* easy = "hai selezionato la modalità FACILE";
    const char* hard = "hai selezionato la modalità DIFFICILE";
    const char* si1 = "hai selezionato lo SPAWN degli ANIMALI";
    const char* no1 = "hai de-selezionato lo SPAWN degli ANIMALI";
    const char* si2 = "hai selezionato le MISSIONI";
    const char* no2 = "hai de-selezionato le MISSIONI";
    // Modalità video per la nuova finestra
    sfVideoMode mode = { 1920, 1080, 32 };

    // Caricamento texture e sprite
    sfTexture* textuimp = sfTexture_createFromFile("assets/inquadratura.jpg", NULL);
    if (!textuimp) return 1;

    sfSprite* spriteimp = sfSprite_create();
    sfVector2f scaleimp = { 1.12f, 1.12f };
    sfSprite_setTexture(spriteimp, textuimp, sfTrue);
    sfSprite_setScale(spriteimp, scaleimp);

    // Creazione della finestra
    sfRenderWindow* wimp = sfRenderWindow_create(mode, "Impostazioni", sfResize | sfClose, NULL);
    if (!wimp) return 1;

    // Creazione del testo
    sfFont* font = sfFont_createFromFile("font/G_ari_bd.ttf");
    if (!font) return 1;
    sfText* backdx = sfText_create();
    sfVector2f testobackdx = { 180.0f, 890.0f };
    sfText_setFont(backdx, font);
    sfText_setString(backdx, backmenudx);
    sfText_setCharacterSize(backdx, 47);
    sfText_setFillColor(backdx, sfWhite);
    sfText_setOutlineColor(backdx, sfBlack);
    sfText_setOutlineThickness(backdx, 4.0f);
    sfText_setPosition(backdx, testobackdx);

    //creazione del pulsante avvia
    sfText* avviabuttonp = sfText_create();
    sfVector2f abp = { 940, 840 };
    sfText_setFont(avviabuttonp, font);
    sfText_setString(avviabuttonp, avviastr);
    sfText_setCharacterSize(avviabuttonp, 45);
    sfText_setColor(avviabuttonp, sfBlack);
    sfText_setPosition(avviabuttonp, abp);
    sfText_setFillColor(avviabuttonp, sfYellow);
    sfText_setOutlineThickness(avviabuttonp, 4.0);
    sfRenderWindow_drawText(wimp, avviabuttonp, NULL);

    //creazione testo 1
    sfText* t1 = sfText_create();
    sfVector2f tb1 = { 894, 245 };
    sfText_setFont(t1, font);
    sfText_setString(t1, t1_1);
    sfText_setCharacterSize(t1, 45);
    sfColor lime = sfColor_fromRGB(0, 255, 0);
    sfText_setPosition(t1, tb1);
    sfText_setFillColor(t1, lime);
    sfText_setOutlineColor(t1, sfBlack);
    sfText_setOutlineThickness(t1, 4.0);
    sfRenderWindow_drawText(wimp, t1, NULL);

    //creazione testo 2
    sfText* t2 = sfText_create();
    sfVector2f tb2 = { 534, 402 };
    sfText_setFont(t2, font);
    sfText_setString(t2, t2_2);
    sfText_setCharacterSize(t2, 45);
    sfText_setPosition(t2, tb2);
    sfText_setFillColor(t2, sfWhite);
    sfText_setOutlineColor(t2, sfBlack);
    sfText_setOutlineThickness(t2, 4.0);
    sfRenderWindow_drawText(wimp, t2, NULL);

    //creazione testo 3
    sfText* t3 = sfText_create();
    sfVector2f tb3 = { 1000, 410 };
    sfText_setFont(t3, font);
    sfText_setString(t3, t3_3);
    sfText_setCharacterSize(t3, 35);
    sfText_setPosition(t3, tb3);
    sfText_setFillColor(t3, sfWhite);
    sfText_setOutlineColor(t3, sfBlack);
    sfText_setOutlineThickness(t3, 4.0);
    sfRenderWindow_drawText(wimp, t3, NULL);

    //creazione testo 4
    sfText* t4 = sfText_create();
    sfVector2f tb4 = { 1210, 410 };
    sfText_setFont(t4, font);
    sfText_setString(t4, t4_4);
    sfText_setCharacterSize(t4, 35);
    sfText_setPosition(t4, tb4);
    sfText_setFillColor(t4, sfWhite);
    sfText_setOutlineColor(t4, sfBlack);
    sfText_setOutlineThickness(t4, 4.0);
    sfRenderWindow_drawText(wimp, t4, NULL);

    //creazione testo 5
    sfText* t5 = sfText_create();
    sfVector2f tb5 = { 517, 528 };
    sfText_setFont(t5, font);
    sfText_setString(t5, t5_5);
    sfText_setCharacterSize(t5, 38);
    sfText_setPosition(t5, tb5);
    sfText_setFillColor(t5, sfWhite);
    sfText_setOutlineColor(t5, sfBlack);
    sfText_setOutlineThickness(t5, 4.0);
    sfRenderWindow_drawText(wimp, t5, NULL);

    //creazione testo 6
    sfText* t6 = sfText_create();
    sfVector2f tb6 = { 1017, 557 };
    sfText_setFont(t6, font);
    sfText_setString(t6, t6_6);
    sfText_setCharacterSize(t6, 38);
    sfText_setPosition(t6, tb6);
    sfText_setFillColor(t6, sfWhite);
    sfText_setOutlineColor(t6, sfBlack);
    sfText_setOutlineThickness(t6, 4.0);
    sfRenderWindow_drawText(wimp, t6, NULL);

    //creazione testo 7
    sfText* t7 = sfText_create();
    sfVector2f tb7 = { 1240, 557 };
    sfText_setFont(t7, font);
    sfText_setString(t7, t7_7);
    sfText_setCharacterSize(t7, 38);
    sfText_setPosition(t7, tb7);
    sfText_setFillColor(t7, sfWhite);
    sfText_setOutlineColor(t7, sfBlack);
    sfText_setOutlineThickness(t7, 4.0);
    sfRenderWindow_drawText(wimp, t7, NULL);

    //creazione testo 8
    sfText* t8 = sfText_create();
    sfVector2f tb8 = { 543, 693 };
    sfText_setFont(t8, font);
    sfText_setString(t8, t8_8);
    sfText_setCharacterSize(t8, 45);
    sfText_setPosition(t8, tb8);
    sfText_setFillColor(t8, sfWhite);
    sfText_setOutlineColor(t8, sfBlack);
    sfText_setOutlineThickness(t8, 4.0);
    sfRenderWindow_drawText(wimp, t8, NULL);

    //creazione testo 9
    sfText* t9 = sfText_create();
    sfVector2f tb9 = { 1017, 707 };
    sfText_setFont(t9, font);
    sfText_setString(t9, t9_9);
    sfText_setCharacterSize(t9, 35);
    sfText_setPosition(t9, tb9);
    sfText_setFillColor(t9, sfWhite);
    sfText_setOutlineColor(t9, sfBlack);
    sfText_setOutlineThickness(t9, 4.0);
    sfRenderWindow_drawText(wimp, t9, NULL);

    //creazione testo 10
    sfText* t10 = sfText_create();
    sfVector2f tb10 = { 1240, 707 };
    sfText_setFont(t10, font);
    sfText_setString(t10, t10_10);
    sfText_setCharacterSize(t10, 35);
    sfText_setPosition(t10, tb10);
    sfText_setFillColor(t10, sfWhite);
    sfText_setOutlineColor(t10, sfBlack);
    sfText_setOutlineThickness(t10, 4.0);
    sfRenderWindow_drawText(wimp, t10, NULL);

    //hai selezionato facile
    sfText* teasy = sfText_create();
    sfVector2f veasy = { 1250, 900 };
    sfText_setFont(teasy, font);
    sfText_setString(teasy, easy);
    sfText_setCharacterSize(teasy, 35);
    sfText_setPosition(teasy, veasy);
    sfText_setFillColor(teasy, sfBlue);
    sfText_setOutlineColor(teasy, sfBlack);
    sfText_setOutlineThickness(teasy, 4.0);
    sfRenderWindow_drawText(wimp, teasy, NULL);


    //hai selezionato difficile
    sfText* thard = sfText_create();
    sfVector2f vhard = { 1250, 900 };
    sfText_setFont(thard, font);
    sfText_setString(thard, hard);
    sfText_setCharacterSize(thard, 35);
    sfText_setPosition(thard, vhard);
    sfText_setFillColor(thard, sfBlue);
    sfText_setOutlineColor(thard, sfBlack);
    sfText_setOutlineThickness(thard, 4.0);
    sfRenderWindow_drawText(wimp, thard, NULL);

    //hai selezionato si1
    sfText* tsi1 = sfText_create();
    sfVector2f vsi1 = { 1143, 900 };
    sfText_setFont(tsi1, font);
    sfText_setString(tsi1, si1);
    sfText_setCharacterSize(tsi1, 35);
    sfText_setPosition(tsi1, vsi1);
    sfText_setFillColor(tsi1, sfBlue);
    sfText_setOutlineColor(tsi1, sfBlack);
    sfText_setOutlineThickness(tsi1, 4.0);
    sfRenderWindow_drawText(wimp, tsi1, NULL);

    //hai selezionato no1
    sfText* tno1 = sfText_create();
    sfVector2f vno1 = { 1143, 900 };
    sfText_setFont(tno1, font);
    sfText_setString(tno1, no1);
    sfText_setCharacterSize(tno1, 35);
    sfText_setPosition(tno1, vno1);
    sfText_setFillColor(tno1, sfBlue);
    sfText_setOutlineColor(tno1, sfBlack);
    sfText_setOutlineThickness(tno1, 4.0);
    sfRenderWindow_drawText(wimp, tno1, NULL);

    //hai selezionato si2
    sfText* tsi2 = sfText_create();
    sfVector2f vsi2 = { 1250, 900 };
    sfText_setFont(tsi2, font);
    sfText_setString(tsi2, si2);
    sfText_setCharacterSize(tsi2, 35);
    sfText_setPosition(tsi2, vsi2);
    sfText_setFillColor(tsi2, sfBlue);
    sfText_setOutlineColor(tsi2, sfBlack);
    sfText_setOutlineThickness(tsi2, 4.0);
    sfRenderWindow_drawText(wimp, tsi2, NULL);

    //hai selezionato no2
    sfText* tno2 = sfText_create();
    sfVector2f vno2 = { 1250, 900 };
    sfText_setFont(tno2, font);
    sfText_setString(tno2, no2);
    sfText_setCharacterSize(tno2, 35);
    sfText_setPosition(tno2, vno2);
    sfText_setFillColor(tno2, sfBlue);
    sfText_setOutlineColor(tno2, sfBlack);
    sfText_setOutlineThickness(tno2, 4.0);
    sfRenderWindow_drawText(wimp, tno2, NULL);



    
    sfMouse_setPosition((sfVector2i){1021,174}, (const sfWindow*)wimp);

    // Ciclo principale
    while (sfRenderWindow_isOpen(wimp)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(wimp, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(wimp);
            }
        }

        sfRenderWindow_close(window);

        //comandi
        sfVector2i mouse = sfMouse_getPositionRenderWindow(wimp);
        printf("position = (%d;%d)\n", mouse.x, mouse.y);

        //funzionamento button personaggio
        if (mouse.x >= 180 && mouse.x <= 466) {
            if (mouse.y >= 900 && mouse.y <= 939) {
                printf("Personaggio pressed--->");

                sfRenderWindow_close(wimp);

                profilo(window, event, wimp);

            }
        }

        //funzionamento avvia 
        if (mouse.x >= 934 && mouse.x <= 1072) {
            if (mouse.y >= 848 && mouse.y <= 890) {
                printf("Avvia pressed--->");

                sfRenderWindow_close(wimp);

                avvia(window, wimp, wimp);

            }
        }

        //funzionamento facile
        if (mouse.x >= 996 && mouse.x <= 1088) {
            if (mouse.y >= 412 && mouse.y <= 447) {
                printf("Facile pressed--->");

                facile = true;
                difficile = false;
                si_1 = false;
                no_1 = false;
				si_2 = false;
				no_2 = false;

                
                
                sfRenderWindow_drawText(wimp, teasy, NULL);

                

                sfRenderWindow_display(wimp);

                sfTime duration = sfSeconds(1.0f);
                sfSleep(duration);
            }
        }

        //funzionamento difficile
        if (mouse.x >= 1207 && mouse.y <= 1337) {
            if (mouse.y >= 417 && mouse.y <= 445) {
                printf("Difficile pressed--->");

                difficile = true;
                facile = false;
				si_1 = false;
				no_1 = false;
				si_2 = false;
				no_2 = false;

                

                sfRenderWindow_drawText(wimp, thard, NULL);

                sfRenderWindow_display(wimp);

                sfTime duration = sfSeconds(1.0f);
                sfSleep(duration);
            }
        }

        //funzionamento si 1
        if (mouse.x >= 1021 && mouse.x <= 1052) {
            if (mouse.y >= 575 && mouse.y <= 593) {
                printf("si1 pressed--->");

                
                si_1 = true;
                no_1 = false;
				si_2 = false;
				no_2 = false;

               

                sfRenderWindow_drawText(wimp, tsi1, NULL);

                

                sfRenderWindow_display(wimp);

                sfTime duration = sfSeconds(1.0f);
                sfSleep(duration);
            }
        }

        //funzionamento no 1
        if (mouse.x >= 1240 && mouse.x <= 1285) {
            if (mouse.y >= 575 && mouse.y <= 593) {
                printf("no1 pressed--->");

                
                
                si_1 = false;
                no_1 = true;
				si_2 = false;
				no_2 = false;

                



                sfRenderWindow_drawText(wimp, tno1, NULL);

                

                sfRenderWindow_display(wimp);

                sfTime duration = sfSeconds(1.0f);
                sfSleep(duration);


            }
        }

        //funzionamento si 2
        if (mouse.x >= 1015 && mouse.x <= 1045) {
            if (mouse.y >= 717 && mouse.y <= 742) {
                printf("si2 pressed--->");

                
                
                si_2 = true;
                no_2 = false;



                sfRenderWindow_drawText(wimp, tsi2, NULL);

                

                sfRenderWindow_display(wimp);

                sfTime duration = sfSeconds(1.0f);
                sfSleep(duration);
            }
        }

        //funzionamento no 2
        if (mouse.x >= 1241 && mouse.x <= 1283) {
            if (mouse.y >= 723 && mouse.y <= 740) {
                printf("no2 pressed--->");

                
                si_2 = false;
                no_2 = true;


                sfRenderWindow_drawText(wimp, tno2, NULL);

               

                sfRenderWindow_display(wimp);

                sfTime duration = sfSeconds(1.0f);
                sfSleep(duration);

                
            }
        }

        // Disegna lo sprite e il testo
        sfRenderWindow_drawSprite(wimp, spriteimp, NULL);

        sfRenderWindow_drawText(wimp, backdx, NULL);
        sfRenderWindow_drawText(wimp, avviabuttonp, NULL);
        sfRenderWindow_drawText(wimp, t1, NULL);
        sfRenderWindow_drawText(wimp, t2, NULL);
        sfRenderWindow_drawText(wimp, t3, NULL);
        sfRenderWindow_drawText(wimp, t4, NULL);
        sfRenderWindow_drawText(wimp, t5, NULL);
        sfRenderWindow_drawText(wimp, t6, NULL);
        sfRenderWindow_drawText(wimp, t7, NULL);
        sfRenderWindow_drawText(wimp, t8, NULL);
        sfRenderWindow_drawText(wimp, t9, NULL);
        sfRenderWindow_drawText(wimp, t10, NULL);

        

        


        // Aggiorna la finestra
        sfRenderWindow_display(wimp);
    }

    avvia(window, wimp, wimp);

    return 0;

}

//distugge la render window -> collegamento con l'inizio del gioco -> introduzione
int avvia(sfRenderWindow* window, sfRenderWindow* wimp, sfRenderWindow* wp) {

    bool TP = false;
    bool TM = false;
    bool TG = false;
    bool MT = false;
    bool FO = false;
    bool BA = false;
    bool CA = false;
    bool CO = false;
    bool UV = false;
    bool OL = false;

    bool F = false;
    bool D = false;
    bool S1 = false;
    bool N1 = false;
    bool S2 = false;
    bool N2 = false;




    const char* intro = "C'era una volta, in una terra sperduta una\n vecchia fattoria, in questo posto vi erano\n un sacco di animali e distese enormi di piantagioni\n purtroppo in seguito alla carestia tutto è morto. \n Tu giovane avventuriera dovrai risistemare \n tutta la fattoria per poi decorarla e crearci \n tutto quello che vorrai";
    const char* intro2 = "Sei pronta?";
    const char* intro3 = "START";


    sfVideoMode mode = { 1920, 1080, 32 };

    sfTexture* textuint = sfTexture_createFromFile("assets/introduzione.jpg", NULL);
    sfSprite* spriteint = sfSprite_create();
    if (!textuint) return 1;

    sfVector2f scaleint = { 1.12, 1.12 };

    sfSprite_setTexture(spriteint, textuint, sfTrue);
    sfSprite_setScale(spriteint, scaleint);

    sfRenderWindow* wintro = sfRenderWindow_create(mode, "Introduzione", sfResize | sfClose, NULL);
    if (!wintro) return 1;



    //testo
    sfFont* font = sfFont_createFromFile("font/G_ari_bd.ttf");
    if (!font) return 1;
    sfText* introd = sfText_create();
    sfVector2f introv = { 120.0f, 97.0f };
    sfText_setFont(introd, font);
    sfText_setString(introd, intro);
    sfText_setCharacterSize(introd, 47);
    sfText_setFillColor(introd, sfWhite);
    sfText_setOutlineColor(introd, sfBlack);
    sfText_setOutlineThickness(introd, 4.0f);
    sfText_setPosition(introd, introv);

    //testo2
    sfText* introd2 = sfText_create();
    sfVector2f introv2 = { 120.0f, 588.0f };
    sfText_setFont(introd2, font);
    sfText_setString(introd2, intro2);
    sfText_setCharacterSize(introd2, 47);
    sfText_setFillColor(introd2, sfWhite);
    sfText_setOutlineColor(introd2, sfBlack);
    sfText_setOutlineThickness(introd2, 4.0f);
    sfText_setPosition(introd2, introv2);

    //testo3
    sfText* introd3 = sfText_create();
    sfVector2f introv3 = { 860, 886 };
    sfText_setFont(introd3, font);
    sfText_setString(introd3, intro3);
    sfText_setCharacterSize(introd3, 47);
    sfText_setFillColor(introd3, sfYellow);
    sfText_setOutlineColor(introd3, sfBlack);
    sfText_setOutlineThickness(introd3, 4.0f);
    sfText_setPosition(introd3, introv3);




    sfRenderWindow_close(window);

    while (sfRenderWindow_isOpen(wintro)) {
        sfEvent event2;
        while (sfRenderWindow_pollEvent(wintro, &event2)) {
            if (event2.type == sfEvtClosed) {
                sfRenderWindow_close(wintro);
            }
        }

        


             
        
        //comandi
        sfVector2i mouse = sfMouse_getPositionRenderWindow(wintro);
        printf("position = (%d;%d)\n", mouse.x, mouse.y);

        //funzionamento button start
        if (mouse.x >= 854 && mouse.x <= 1020) {
            if (mouse.y >= 889 && mouse.y <= 944) {
                printf("Start pressed--->");

                sfTime duration = sfSeconds(0.25f);
                sfSleep(duration);

                sfRenderWindow_close(wintro);

                if (tpiccolo) {
                    TP = true;
                    printf("tpiccolo OK--->");
                }

                if (tmedio) {
                    TM = true;
                    printf("tmedio OK--->");
                }

                if (tgrande) {
                    TG = true;
                    printf("tgrande OK--->");
                }

                if (mieti) {
                    MT = true;
                    printf("mieti OK--->");
                }

                if (forag) {
                    FO = true;
                    printf("forag OK--->");
                }

                if (barb) {
                    BA = true;
                    printf("barb OK--->");
                }

                if (cann) {
                    CA = true;
                    printf("cann OK--->");
                }

                if (cot) {
                    CO = true;
                    printf("cot OK--->");
                }

                if (uvaa) {
                    UV = true;
                    printf("uvaa OK--->");
                }

                if (oli) {
                    OL = true;
                    printf("oli OK--->");
                }

                if (facile) {
                    F = true;
                    printf("facile OK--->");
                }

                if (difficile) {
                    D = true;
                    printf("difficile OK--->");
                }

				if (si_1) {
					S1 = true;
					printf("si_1 OK--->");
				}

				if (no_1) {
					N1 = true;
					printf("no_1 OK--->");
				}

				if (si_2) {
					S2 = true;
					printf("si_2 OK--->");
				}

				if (no_2) {
					N2 = true;
					printf("no_2 OK--->");
				}


                // Chiamata alla funzione fattoria con tutte le variabili
                extern int fattoria(bool* TP, bool* TM, bool* TG, bool* MT, bool* FO, bool* BA, bool* CA, bool* CO, bool* UV, bool* OL, bool* F, bool* D, bool* S1, bool* N1, bool* S2, bool* N2);
                return fattoria(&TP, &TM, &TG, &MT, &FO, &BA, &CA, &CO, &UV, &OL, &F, &D, &S1, &N1, &S2, &N2);
            }


            


            sfRenderWindow_drawSprite(wintro, spriteint, NULL);
            sfRenderWindow_drawText(wintro, introd, NULL);
            sfRenderWindow_drawText(wintro, introd2, NULL);
            sfRenderWindow_drawText(wintro, introd3, NULL);
            sfRenderWindow_display(wintro);
        }

        
    }
    return 0;

}




















