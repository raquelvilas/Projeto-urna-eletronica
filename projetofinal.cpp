#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
typedef struct
{
    char n[8];
    int  v;
} candidato;

int x,y,agent,i,j,maior,vencedor,total,empatado;
int final = 0;
int en = 1;
int h = 140;
char texto[30];
char agentes[80];
char eleitor[3];
char empate[30];

main()
{
    candidato p[7]= {"Jett",0,
                     "Yoru",0,
                     "Neon",0,
                     "Reyna",0,
                     "Phoenix",0,
                     "Raze",0
                    };


    initwindow (1533,720,"SISTEMA DE VOTACAO: DUELISTAS");
    readimagefile("valorant_bg.bmp" , 0,0,1056,720);
    readimagefile("Choose.bmp", 1056,0,1533,720);
    readimagefile("Linha_sep.bmp", 1054,0,1058,720);
    readimagefile("Finalizar.bmp", 400,680,526,708);

    {
        sprintf(eleitor,"%d",en);
        outtextxy(1294,220,eleitor);
    }

    readimagefile("Jett.bmp" , 140,90,400,370);
    readimagefile("Yoru.bmp" , 400,90,660,370);
    readimagefile("Neon.bmp" , 660,90,920,370);
    readimagefile("Reyna.bmp" , 140,370,400,650);
    readimagefile("Phoenix.bmp" , 400,370,660,650);
    readimagefile("Raze.bmp" , 660,370,920,650);

    while(!kbhit())
    {
        x = mousex();
        y = mousey();
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            {
                if(final == 0 and x > 140 and x < 400 and y > 90 and y < 370)
                {
                    readimagefile("Jett_chosen.bmp" , 140,90,400,370);
                    readimagefile("Jett_info.bmp" , 1056,0,1533,720);
                    readimagefile("Selecionar.bmp", 1231,676,1358,704);
                    agent = 1 ;

                }
                else if (final == 0)
                    readimagefile("Jett.bmp" , 140,90,400,370);
            }
            {
                if(final == 0 and x > 400 and x < 660 and y > 90 and y < 370)
                {
                    readimagefile("Yoru_chosen.bmp" , 400,90,660,370);
                    readimagefile("Yoru_info.bmp" , 1056,0,1533,720);
                    readimagefile("Selecionar.bmp", 1231,676,1358,704);
                    agent = 2 ;
                }
                else if (final == 0)
                    readimagefile("Yoru.bmp" , 400,90,660,370);
            }
            {
                if(final == 0 and  x > 660 and x < 920 and y > 90 and y < 370)
                {
                    readimagefile("Neon_chosen.bmp" , 660,90,920,370);
                    readimagefile("Neon_info.bmp" , 1056,0,1533,720);
                    readimagefile("Selecionar.bmp", 1231,676,1358,704);
                    agent = 3 ;
                }
                else if (final == 0)
                    readimagefile("Neon.bmp" , 660,90,920,370);
            }
            {
                if(final == 0 and x > 140 and x < 400 and y > 370 and y < 650)
                {
                    readimagefile("Reyna_chosen.bmp" , 140,370,400,650);
                    readimagefile("Reyna_info.bmp" , 1056,0,1533,720);
                    readimagefile("Selecionar.bmp", 1231,676,1358,704);
                    agent = 4 ;
                }
                else if (final == 0)
                    readimagefile("Reyna.bmp" , 140,370,400,650);
            }
            {
                if(final == 0 and x > 400 and x < 660 and y > 370 and y < 650)
                {
                    readimagefile("Phoenix_chosen.bmp" , 400,370,660,650);
                    readimagefile("Phoenix_info.bmp" , 1056,0,1533,720);
                    readimagefile("Selecionar.bmp", 1231,676,1358,704);
                    agent = 5 ;
                }
                else if (final == 0)
                    readimagefile("Phoenix.bmp" , 400,370,660,650);
            }
            {
                if(final == 0 and x > 660 and x < 920 and y > 370 and y < 650)
                {
                    readimagefile("Raze_chosen.bmp" , 660,370,920,650);
                    readimagefile("Raze_info.bmp" , 1056,0,1533,720);
                    readimagefile("Selecionar.bmp", 1231,676,1358,704);
                    agent = 6 ;
                }
                else if (final == 0)
                    readimagefile("Raze.bmp" , 660,370,920,650);

            }
            {
                if(final == 0 and x > 1231 and x < 1358 and y > 676 and y < 704)
                {
                    switch(agent)
                    {
                    case 1:
                        p[0].v++;
                        break;
                    case 2:
                        p[1].v++;
                        break;
                    case 3:
                        p[2].v++;
                        break;
                    case 4:
                        p[3].v++;
                        break;
                    case 5:
                        p[4].v++;
                        break;
                    case 6:
                        p[5].v++;
                        break;
                    }
                    readimagefile("Selecionar_p.bmp", 1231,676,1358,704);
                    delay(300);
                    readimagefile("Selecionar.bmp", 1231,676,1358,704);

                    readimagefile("Choose.bmp", 1056,0,1533,720);
                    delay(100);
                    {
                        en++;
                        sprintf(eleitor,"%d",en);
                        outtextxy(1294,220,eleitor);
                    }

                }

                vencedor = 0;
                maior = p[0].v;
                total = p[0].v + p[1].v + p[2].v + p[3].v + p[4].v + p[5].v;
                for (i=0; i < 6; i++)
                {
                    if (p[i].v > maior)
                    {
                        maior = p[i].v;
                        vencedor = i;
                    }
                    else if (i != vencedor and p[i].v == maior)
                    {
                        vencedor = 99;
                    }
                }

                if(final == 0 and x > 400 and x < 528 and y > 680 and y < 708)
                {
                    final = 1;
                    readimagefile("Finalizar_p.bmp", 400,680,526,708);
                    delay(300);
                    readimagefile("Finalizar.bmp", 400,680,526,708);

                    switch(vencedor)
                    {
                    case 0:
                        readimagefile("Jett_v.bmp", 0,0,1533,720);
                        break;
                    case 1:
                        readimagefile("Yoru_v.bmp", 0,0,1533,720);
                        break;
                    case 2:
                        readimagefile("Neon_v.bmp", 0,0,1533,720);
                        break;
                    case 3:
                        readimagefile("Reyna_v.bmp", 0,0,1533,720);
                        break;
                    case 4:
                        readimagefile("Phoenix_v.bmp", 0,0,1533,720);
                        break;
                    case 5:
                        readimagefile("Raze_v.bmp", 0,0,1533,720);
                        break;
                    }

                    if(vencedor == 99)
                    {
                        snprintf(empate,30,"Nenhum agente venceu.");
                        outtextxy(1140,40,empate);
                    }
                    else
                    {
                        snprintf(texto,30,"Vencedor: %s com %d votos.",p[vencedor].n,p[vencedor].v);
                        outtextxy(1140,40,texto);
                    }

                    snprintf(agentes,80,"Agentes:");
                    outtextxy(1140,140,agentes);

                    for (i=0; i < 6; i++)
                    {
                        h = h + 50;
                        snprintf(agentes,80,"Codenome %s teve %d votos.",p[i].n,p[i].v);
                        outtextxy(1140,h,agentes);
                    }

                    snprintf(texto,30,"Total de votos %d.",total);
                    outtextxy(1140,540,texto);

                    readimagefile("Fechar.bmp", 1370,532,1496,560);
                }
                if(final == 1 and x > 1370 and x < 1496 and y > 532 and y < 560)
                {
                    readimagefile("Fechar_p.bmp", 1370,532,1496,560);
                    delay(300);
                    readimagefile("Fechar.bmp", 1370,532,1496,560);
                    return 0;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }

    }

    getchar();
    closegraph();

    //Imagens por Valorant e Excharny.
}
