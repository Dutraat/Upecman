/***************************************************************************
 *   upecman.c                                Version 20160529.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file upecman.c
 * @ingroup GroupUnique
 * @brief Pacman Ncurses
 * @details This program really do a nice job as a template, and template only!
 * @version 20160529.013231
 * @date 2016-05-29
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *      $make
 * ou
 *      $gcc upecman.c -o upecman.x -Wall -lncurses -g -Og
 *          -Wextra -ansi -pedantic-errors -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <time.h>
//#include <curses.h>
#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <assert.h> /* Verify assumptions with assert */
#include <unistd.h> /* UNIX standard function */
#include "upecman.h" /* To be created for this template if needed */
#include <time.h>  /* Time and date functions */
#include <math.h>  /* Mathematics functions */
#include <limits.h> /* VariousC limits */

/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./upecman -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
int main(int argc, char *argv[])
{
    menu();
    IFDEBUG("main()\n");
    int opt; /* return from getopt() */
    t_game g; /* the game */
    const char *sready = "Aperte q para sair do jogo"; /* ready string */
    int kin; /* keyboard input */

    IFDEBUG("Starting optarg loop...\n");

    /* getopt() configured options
     *        -h  help
     *        -c  copyright & version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hvc")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'v':
                verb++;
                break;
            case 'c':
                copyr();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* ...and we are done */
    IFDEBUG("Starting the game now...\n");

    g = upecman_init();

    printlab(g);

    mvprintw(10, 25, "%s", sready);
    refresh();
     g.tempoatual = 0;

    while(1)
    {
        kin = getch();
        if(kin == 'q')
            break;
        else
        {
            g = entjogo(g, kin);
            g = movepac(g);
            g = placarpac(g);
            g = pointjogo(g);
            g = contador(g);
            g = cereja(g);
            g = movimentoblinky(g);
            g = movimentopinky(g);
            g = movimentoclyde(g);
            g = movimentoinky(g);
            g = modoAfraid(g);
            g = corrigindo_print(g);
            g.lab[g.pacman.posicaoanterior.y][g.pacman.posicaoanterior.x] = ' ';
            g.lab[g.pacman.pos.y][g.pacman.pos.x] = '@';
            g.lab[g.ghost[blinky].posicaoanterior.y][g.ghost[blinky].posicaoanterior.x] = g.ghost[blinky].itemAnterior;
            g.ghost[blinky].itemAnterior = g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x];
            g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x] = 'B';
            g.lab[g.ghost[pinky].posicaoanterior.y][g.ghost[pinky].posicaoanterior.x] = g.ghost[pinky].itemAnterior;
            g.ghost[pinky].itemAnterior = g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x];
            g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x] = 'P';
            g.lab[g.ghost[clyde].posicaoanterior.y][g.ghost[clyde].posicaoanterior.x] = g.ghost[clyde].itemAnterior;
            g.ghost[clyde].itemAnterior = g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x];
            g.lab [g.ghost[clyde].pos.y][g.ghost[clyde].pos.x] = 'C' ;
            g.lab[g.ghost[inky].posicaoanterior.y][g.ghost[inky].posicaoanterior.x] = g.ghost[inky].itemAnterior;
            g.ghost[inky].itemAnterior = g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x];
            g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x] = 'I';


            int restantes = bolinhasRestantes(g);
        if (restantes == 0) {
        int continuar = vitoria(g);
        if (continuar) {
            g = upecman_init();
            printlab(g);
        } else {
            break;
        }
    }
            g = colisaopac(g);
            if (g.pacman.life <= 0) {
                int continuar = gameOver(g);
                if (continuar) {
                    g = upecman_init();
                    printlab(g);
                } else {
                    break;
                }
            }


            colorlab(g);
            refresh();

            usleep(166670); /* wait 16666 microseconds to avoid frying the processor (1/60 s) */
            g.tempoatual++;
            if(g.tempoatual > 100000) // Evitar exceto de valores na memoria
              g.tempoatual = 0;
        }
    }

    /* write your code here */
      endwin();
    return EXIT_SUCCESS;

}






/* -----------------Entrada_do_Jogo-------------------------------------------- */
t_game entjogo(t_game g, int kin)
{
    {
        if ( kin == KEY_LEFT)
            g.pacman.premove = left;
        if( kin == KEY_RIGHT)
            g.pacman.premove = right;
        if( kin == KEY_UP)
            g.pacman.premove = up;
        if( kin == KEY_DOWN)
            g.pacman.premove = down;
    }

    return g;
  }

/* ----------------------------------------Movimentacao_Pacman-------------------------------------------- */
t_game movepac(t_game g)
{
    if (g.pacman.premove == left && g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != '#')
        g.pacman.dir = left;
    if (g.pacman.premove == right && g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != '#')
        g.pacman.dir = right;
    if (g.pacman.premove == up && g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#')
        g.pacman.dir = up;
    if (g.pacman.premove == down && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '#' && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '-')
        g.pacman.dir = down;

    g.pacman.posicaoanterior.y = g.pacman.pos.y;
    g.pacman.posicaoanterior.x = g.pacman.pos.x;


  if (g.pacman.dir == left && g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != '#')
    g.pacman.pos.x--;
  if (g.pacman.dir == right && g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != '#')
    g.pacman.pos.x++;
  if (g.pacman.dir == up && g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#')
    g.pacman.pos.y--;
  if (g.pacman.dir == down && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '#' && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '-')
    g.pacman.pos.y++;

  int p = g.pacman.pos.x;

 if (g.pacman.pos.x == 0 && g.pacman.pos.y == 10)
  p = 18;
 if (g.pacman.pos.x == 19 && g.pacman.pos.y == 10)
    p = 1;
  g.pacman.pos.x = p;

return g;
}
/* ---------------------------------Pontuacao_do_jogo-------------------------------------------- */
t_game pointjogo(t_game g)
{
    int f;

  if (g.lab[g.pacman.pos.y][g.pacman.pos.x] == '.') {
      g.pacman.score += 10;
       g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
  }
      if (g.lab[g.pacman.pos.y][g.pacman.pos.x] == 'o')
      {
        for (f= blinky; f <= clyde; f++)
        {
          g.ghost[f].mode = afraid;
        }
        g.pacman.score += 50;
       g.tempoInicioAfraid = g.tempoatual;
      }
      return g;

}
/* -----------------Placar_do_jogo-------------------------------------------- */
t_game placarpac(t_game g)
{

    mvprintw(1, 25, "+==========================+");
    mvprintw(2, 25, "|       SCOREBOARD         |");
    mvprintw(3, 25, "+--------------------------+");
    mvprintw(4, 25, "|   SCORE:    %6d       |", g.pacman.score);
    mvprintw(6, 25, "+==========================+");
    mvprintw(5, 25, "|   LIVES:    %6d       |", g.pacman.life);
            refresh();
              return g;
}
/* -----------------------------------------Contador--------------------------------------------------*/
t_game contador(t_game g) {
    int tempo = g.tempoatual;

    for (int f = blinky; f <= clyde; f++) {
        if (g.ghost[f].mode == dead)
        {    int tempoNoDead = g.tempoatual - g.ghost[f].tempoMorte;
            if (tempoNoDead > 7) {
                g.ghost[f].mode = scatter;
            }
            continue;
        }

        if (g.ghost[f].mode == afraid) {
            int tempoAfraid = g.tempoatual - g.tempoInicioAfraid;
            if (tempoAfraid > 37) {
                g.ghost[f].mode = chase;
            }
            continue;
        }

        if ((tempo) <= 37 ||
            ((tempo) >  132 && (tempo) <= 158) ||
            ((tempo) >  301 && (tempo) <= 327) ||
            ((tempo) > 433 && (tempo) <=  459)) {
            g.ghost[f].mode = scatter;
        }  else {
            g.ghost[f].mode = chase;
        }
    }
    return g;
}

/* -----------------------Cereja--------------------------------------------*/
t_game cereja(t_game g) {
    char cerejapos = g.lab[g.pacman.pos.y][g.pacman.pos.x];
    if (((g.tempoatual >= 37 && g.tempoatual <= 47) ||
         (g.tempoatual >= 67 && g.tempoatual <= 77) ||
         (g.tempoatual >= 97 && g.tempoatual <= 107))
         && g.pacman.cherry == 0) {
        g.lab[17][10] = '%';

        if (cerejapos == '%') {
            g.lab[17][10] = ' ';
            g.pacman.score += 500;
            g.pacman.cherry = 1;
        }
    } else {
        g.lab[17][10] = ' ';
        if (g.tempoatual > 20 && g.tempoatual < 30) {
            g.pacman.cherry = 0;
        }
        if (g.tempoatual > 40 && g.tempoatual < 70) {
            g.pacman.cherry = 0;
        }
    }
    return g;
}



/* ---------------Corrigindo_print------------------------------------------------ */

t_game corrigindo_print(t_game g) {
    for (int f = blinky; f <= clyde; f++) {
        int x_anterior = g.ghost[f].posicaoanterior.x;
        int y_anterior = g.ghost[f].posicaoanterior.y;

        if (g.ghost[f].itemAnterior == '.' ||
            g.ghost[f].itemAnterior == '%' ||
            g.ghost[f].itemAnterior == 'o' ||
            g.ghost[f].itemAnterior == ' ') {
            g.lab[y_anterior][x_anterior] = g.ghost[f].itemAnterior;
        }
    }

 g.lab[8][9] = '-';
        g.lab[8][10] = '-';


    int px_anterior = g.pacman.posicaoanterior.x;
    int py_anterior = g.pacman.posicaoanterior.y;

    if (g.lab[py_anterior][px_anterior] != 'B' &&
        g.lab[py_anterior][px_anterior] != 'P' &&
        g.lab[py_anterior][px_anterior] != 'I' &&
        g.lab[py_anterior][px_anterior] != 'C' &&
        g.lab[py_anterior][px_anterior] != '-') {
        g.lab[py_anterior][px_anterior] = ' ';
    }

    for (int f = blinky; f <= clyde; f++) {
        int x_atual = g.ghost[f].pos.x;
        int y_atual = g.ghost[f].pos.y;

        if (g.lab[y_atual][x_atual] == 'B' ||
            g.lab[y_atual][x_atual] == 'P' ||
            g.lab[y_atual][x_atual] == 'I' ||
            g.lab[y_atual][x_atual] == 'C') {
            g.ghost[f].pos.x = g.ghost[f].posicaoanterior.x;
            g.ghost[f].pos.y = g.ghost[f].posicaoanterior.y;
        } else {
            g.ghost[f].itemAnterior = g.lab[y_atual][x_atual];

            g.lab[y_atual][x_atual] =
                (f == blinky ? 'B' :
                f == pinky ? 'P' :
                f == inky ? 'I' :
                f == clyde ? 'C' : ' ');
        }
    }

    int px_atual = g.pacman.pos.x;
    int py_atual = g.pacman.pos.y;

    if (g.lab[py_atual][px_atual] != 'B' &&
        g.lab[py_atual][px_atual] != 'P' &&
        g.lab[py_atual][px_atual] != 'I' &&
        g.lab[py_atual][px_atual] != 'C') {
        g.lab[py_atual][px_atual] = '@';
    }

    return g;
}

/* ---------------Modo_Afraid------------------------------------------------ */
t_game modoAfraid(t_game g) {
    for (int f = blinky; f <= clyde; f++) {
    if (g.ghost[f].mode == afraid) {

        int target_x = g.pacman.pos.x * -1;
        int target_y = g.pacman.pos.y * -1;

        if (g.lab[target_y][target_x] != '#' && g.lab[target_y][target_x] != '-' &&
            g.lab[target_y][target_x] != '@' && g.lab[target_y][target_x] != 'B' &&
            g.lab[target_y][target_x] != 'P' && g.lab[target_y][target_x] != 'I' &&
            g.lab[target_y][target_x] != 'C') {
            g.ghost[f].starget.x = target_x;
            g.ghost[f].starget.y = target_y;
            }
        }
    }
    return g;
}

 /* ---------------Movimentacao_Blinky---------------------------------------- */
t_game movimentoblinky(t_game g)
{
    int scatteralvox = 19;
    int scatteralvoy = 0;
    int chasealvox = g.pacman.pos.x;
    int chasealvoy = g.pacman.pos.y;
    int blinkyx = g.ghost[blinky].pos.x;
    int blinkyy = g.ghost[blinky].pos.y;

    int casaanteriorblinkyx = g.ghost[blinky].posicaoanterior.x;
    int casaanteriorblinkyy = g.ghost[blinky].posicaoanterior.y;

    g.ghost[blinky].posicaoanterior.x = blinkyx;
    g.ghost[blinky].posicaoanterior.y = blinkyy;

    g.ghost[blinky].starget.x = chasealvox;
    g.ghost[blinky].starget.y = chasealvoy;

 if (g.ghost[blinky].mode == dead) {
        g.ghost[blinky].pos.x = 8;
        g.ghost[blinky].pos.y = 9;
        return g;
    }
    if (g.ghost[blinky].mode == scatter)
    {
        g.ghost[blinky].starget.x = scatteralvox;
        g.ghost[blinky].starget.y = scatteralvoy;
    }

    int distup = (g.lab[blinkyy - 1][blinkyx] != '#' &&
                  !(blinkyy - 1 == casaanteriorblinkyy && blinkyx == casaanteriorblinkyx)) ?
        pow(blinkyx - g.ghost[blinky].starget.x, 2) +
        pow((blinkyy - 1) - g.ghost[blinky].starget.y, 2) : INT_MAX;

    int distdown = (g.lab[blinkyy + 1][blinkyx] != '#' &&
                    g.lab[blinkyy + 1][blinkyx] != '-' &&
                    !(blinkyy + 1 == casaanteriorblinkyy && blinkyx == casaanteriorblinkyx)) ?
        pow(blinkyx - g.ghost[blinky].starget.x, 2) +
        pow((blinkyy + 1) - g.ghost[blinky].starget.y, 2) : INT_MAX;

    int distleft = (g.lab[blinkyy][blinkyx - 1] != '#' &&
                    !(blinkyy == casaanteriorblinkyy && blinkyx - 1 == casaanteriorblinkyx)) ?
        pow((blinkyx - 1) - g.ghost[blinky].starget.x, 2) +
        pow(blinkyy - g.ghost[blinky].starget.y, 2) : INT_MAX;

    int distright = (g.lab[blinkyy][blinkyx + 1] != '#' &&
                     !(blinkyy == casaanteriorblinkyy && blinkyx + 1 == casaanteriorblinkyx)) ?
        pow((blinkyx + 1) - g.ghost[blinky].starget.x, 2) +
        pow(blinkyy - g.ghost[blinky].starget.y, 2) : INT_MAX;

    if (distup <= distdown && distup <= distleft && distup <= distright)
    {
        g.ghost[blinky].pos.y--;
    }

    if (distdown <= distup && distdown <= distleft && distdown <= distright)
    {
        g.ghost[blinky].pos.y++;
    }

    if (distleft <= distup && distleft <= distdown && distleft <= distright)
    {
        g.ghost[blinky].pos.x--;
    }

    if (distright <= distup && distright <= distdown && distright <= distleft)
    {
        g.ghost[blinky].pos.x++;
    }

    if (g.ghost[blinky].pos.x == 0 && g.ghost[blinky].pos.y == 10)
    {
        g.ghost[blinky].pos.x = 18;
    }
    if (g.ghost[blinky].pos.x == 19 && g.ghost[blinky].pos.y == 10)
    {
        g.ghost[blinky].pos.x = 1;
    }
    usleep(8500);
    return g;
}

/* -------------------------Movimentacao_Pinky------------------------------ */
t_game movimentopinky(t_game g)
{
    int scatterpinky_x = 0;
    int scatterpinky_y = 0;
    int pinky_x = g.ghost[pinky].pos.x;
    int pinky_y = g.ghost[pinky].pos.y;
    int coordanterior_x = g.ghost[pinky].posicaoanterior.x;
    int coordanterior_y = g.ghost[pinky].posicaoanterior.y;

    g.ghost[pinky].posicaoanterior.x = pinky_x;
    g.ghost[pinky].posicaoanterior.y = pinky_y;

    if (g.ghost[pinky].mode == dead) {
        g.ghost[pinky].pos.x = g.ghost[pinky].posicaoinicial.x;
        g.ghost[pinky].pos.y = g.ghost[pinky].posicaoinicial.y;
        return g;
    }

     if (pinky_x == 10 && pinky_y > 7 && g.lab[pinky_y - 1][pinky_x] != '#')
    {
        g.ghost[pinky].pos.y--;
        return g;
    }


       if (g.ghost[pinky].mode == chase)
         {
         if (g.pacman.dir == up)
         {
             g.ghost[pinky].starget.x = g.pacman.pos.x;
             g.ghost[pinky].starget.y = g.pacman.pos.y - 4;
         }
         if (g.pacman.dir == down)
         {
             g.ghost[pinky].starget.x = g.pacman.pos.x;
             g.ghost[pinky].starget.y = g.pacman.pos.y + 4;
         }
         if (g.pacman.dir == left)
         {
             g.ghost[pinky].starget.x = g.pacman.pos.x - 4;
             g.ghost[pinky].starget.y = g.pacman.pos.y;
         }
         if (g.pacman.dir == right)
         {
             g.ghost[pinky].starget.x = g.pacman.pos.x + 4;
             g.ghost[pinky].starget.y = g.pacman.pos.y;
         }
    }

    if (g.ghost[pinky].mode == scatter)
    {
        g.ghost[pinky].starget.x = scatterpinky_x;
        g.ghost[pinky].starget.y = scatterpinky_y;
    }



    int pinkyUp = (g.lab[pinky_y - 1][pinky_x] != '#' &&
                  !(pinky_y - 1 == coordanterior_y && pinky_x == coordanterior_x)) ?
        pow(pinky_x - g.ghost[pinky].starget.x, 2) + pow((pinky_y - 1) - g.ghost[pinky].starget.y, 2) : INT_MAX;

    int pinkyDown = (g.lab[pinky_y + 1][pinky_x] != '#' && g.lab[pinky_y + 1][pinky_x] != '-' &&
                    !(pinky_y + 1 == coordanterior_y && pinky_x == coordanterior_x)) ?
        pow(pinky_x - g.ghost[pinky].starget.x, 2) + pow((pinky_y + 1) - g.ghost[pinky].starget.y, 2) : INT_MAX;

    int pinkyRight = (g.lab[pinky_y][pinky_x + 1] != '#' &&
                    !(pinky_y == coordanterior_y && pinky_x + 1 == coordanterior_x)) ?
        pow((pinky_x + 1) - g.ghost[pinky].starget.x, 2) + pow(pinky_y - g.ghost[pinky].starget.y, 2) : INT_MAX;

    int pinkyLeft = (g.lab[pinky_y][pinky_x - 1] != '#' &&
                    !(pinky_y == coordanterior_y && pinky_x - 1 == coordanterior_x)) ?
        pow((pinky_x - 1) - g.ghost[pinky].starget.x, 2) + pow(pinky_y - g.ghost[pinky].starget.y, 2) : INT_MAX;



    if (pinkyUp <= pinkyDown && pinkyUp <= pinkyLeft && pinkyUp <= pinkyRight)
    {
        g.ghost[pinky].pos.y--;
    }
    if (pinkyDown <= pinkyUp && pinkyDown <= pinkyLeft && pinkyDown <= pinkyRight)
    {
        g.ghost[pinky].pos.y++;
    }
    if (pinkyLeft <= pinkyUp && pinkyLeft <= pinkyDown && pinkyLeft <= pinkyRight)
    {
        g.ghost[pinky].pos.x--;
    }
    if (pinkyRight <= pinkyUp && pinkyRight <= pinkyDown && pinkyRight <= pinkyLeft)
    {
        g.ghost[pinky].pos.x++;
    }

    if (g.ghost[pinky].pos.x == 0 && g.ghost[pinky].pos.y == 10)
    {
        g.ghost[pinky].pos.x = 18;
    }
    if (g.ghost[pinky].pos.x == 19 && g.ghost[pinky].pos.y == 10)
    {
        g.ghost[pinky].pos.x = 1;
    }
    usleep(8500);
    return g;
}
/*-------------------Movimentacao_clyde-------------------------------------*/
t_game movimentoclyde(t_game g)
{
    int scatteralvox = 0;
    int scatteralvoy = 22;
    int clydex = g.ghost[clyde].pos.x;
    int clydey = g.ghost[clyde].pos.y;

    int casaanteriorclydex = g.ghost[clyde].posicaoanterior.x;
    int casaanteriorclydey = g.ghost[clyde].posicaoanterior.y;

    g.ghost[clyde].posicaoanterior.x = clydex;
    g.ghost[clyde].posicaoanterior.y = clydey;

    if (g.ghost[clyde].mode == dead) {

        g.ghost[clyde].pos.x = g.ghost[clyde].posicaoinicial.x;
        g.ghost[clyde].pos.y = g.ghost[clyde].posicaoinicial.y;
        return g;
    }






    if (clydex == 10 && clydey > 7 && g.lab[clydey - 1][clydex] != '#')
    {
        g.ghost[clyde].pos.y--;
        return g;
    }

    int pacman_dist = pow(g.pacman.pos.x - clydex, 2) + pow(g.pacman.pos.y - clydey, 2);

    if (pacman_dist > 64)
    {
        g.ghost[clyde].starget.x = g.pacman.pos.x;
        g.ghost[clyde].starget.y = g.pacman.pos.y;
    }
    else
    {
        g.ghost[clyde].starget.x = scatteralvox;
        g.ghost[clyde].starget.y = scatteralvoy;
    }

    int distup = (g.lab[clydey - 1][clydex] != '#' &&
                  !(clydey - 1 == casaanteriorclydey && clydex == casaanteriorclydex)) ?
        pow(clydex - g.ghost[clyde].starget.x, 2) + pow((clydey - 1) - g.ghost[clyde].starget.y, 2) : INT_MAX;

    int distdown = (g.lab[clydey + 1][clydex] != '#' &&
                    g.lab[clydey + 1][clydex] != '-' &&
                    !(clydey + 1 == casaanteriorclydey && clydex == casaanteriorclydex)) ?
        pow(clydex - g.ghost[clyde].starget.x, 2) + pow((clydey + 1) - g.ghost[clyde].starget.y, 2) : INT_MAX;

    int distleft = (g.lab[clydey][clydex - 1] != '#' &&
                    !(clydey == casaanteriorclydey && clydex - 1 == casaanteriorclydex)) ?
        pow((clydex - 1) - g.ghost[clyde].starget.x, 2) + pow(clydey - g.ghost[clyde].starget.y, 2) : INT_MAX;

    int distright = (g.lab[clydey][clydex + 1] != '#' &&
                     !(clydey == casaanteriorclydey && clydex + 1 == casaanteriorclydex)) ?
        pow((clydex + 1) - g.ghost[clyde].starget.x, 2) + pow(clydey - g.ghost[clyde].starget.y, 2) : INT_MAX;

    if (distup <= distdown && distup <= distleft && distup <= distright)
    {
        g.ghost[clyde].pos.y--;
    }
    if (distdown <= distup && distdown <= distleft && distdown <= distright)
    {
        g.ghost[clyde].pos.y++;
    }
    if (distleft <= distup && distleft <= distdown && distleft <= distright)
    {
        g.ghost[clyde].pos.x--;
    }
    if (distright <= distup && distright <= distdown && distright <= distleft)
    {
        g.ghost[clyde].pos.x++;
    }

    if (g.ghost[clyde].pos.x == 0 && g.ghost[clyde].pos.y == 10)
    {
        g.ghost[clyde].pos.x = 18;
    }
    if (g.ghost[clyde].pos.x == 19 && g.ghost[clyde].pos.y == 10)
    {
        g.ghost[clyde].pos.x = 1;
    }
    usleep(8500);
    return g;
}

/* -----------------Movimentacao_Inky-------------------------------------- */
t_game movimentoinky(t_game g)
{
    int inkyx = g.ghost[inky].pos.x;
    int inkyy = g.ghost[inky].pos.y;

    int casaanteriorinkyx = g.ghost[inky].posicaoanterior.x;
    int casaanteriorinkyy = g.ghost[inky].posicaoanterior.y;

    g.ghost[inky].posicaoanterior.x = inkyx;
    g.ghost[inky].posicaoanterior.y = inkyy;


     if (g.ghost[inky].mode == dead) {
         g.ghost[inky].pos.x = g.ghost[inky].posicaoinicial.x;
        g.ghost[inky].pos.y = g.ghost[inky].posicaoinicial.y;
        return g;
    }


    if (inkyx == 10 && inkyy > 4 && g.lab[inkyy - 1][inkyx] != '#')
    {
        g.ghost[inky].pos.y--;
        return g;
    }

    if (inkyx == 10 && inkyy == 4)
    {
        g.ghost[inky].mode = chase;
    }

    int alvo_inky_x = g.pacman.pos.x;
    int alvo_inky_y = g.pacman.pos.y;

    if (g.pacman.dir == right) alvo_inky_x += 2;
    if (g.pacman.dir == left) alvo_inky_x -= 2;
    if (g.pacman.dir == up) alvo_inky_y -= 2;
    if (g.pacman.dir == down) alvo_inky_y += 2;

    int alvo_chase_inky_x = 2 * alvo_inky_x - g.ghost[blinky].pos.x;
    int alvo_chase_inky_y = 2 * alvo_inky_y - g.ghost[blinky].pos.y;

    if (g.ghost[inky].mode == chase)
    {
        g.ghost[inky].starget.x = alvo_chase_inky_x;
        g.ghost[inky].starget.y = alvo_chase_inky_y;
    }

    if (g.ghost[inky].mode == scatter)
    {
        g.ghost[inky].starget.x = 19;
        g.ghost[inky].starget.y = 22;
    }

    int distup = (g.lab[inkyy - 1][inkyx] != '#' &&
                  !(inkyy - 1 == casaanteriorinkyy && inkyx == casaanteriorinkyx)) ?
        pow(inkyx - g.ghost[inky].starget.x, 2) + pow((inkyy - 1) - g.ghost[inky].starget.y, 2) : INT_MAX;

    int distdown = (g.lab[inkyy + 1][inkyx] != '#' &&
                    g.lab[inkyy + 1][inkyx] != '-' &&
                    !(inkyy + 1 == casaanteriorinkyy && inkyx == casaanteriorinkyx)) ?
        pow(inkyx - g.ghost[inky].starget.x, 2) + pow((inkyy + 1) - g.ghost[inky].starget.y, 2) : INT_MAX;

    int distleft = (g.lab[inkyy][inkyx - 1] != '#' &&
                    !(inkyy == casaanteriorinkyy && inkyx - 1 == casaanteriorinkyx)) ?
        pow((inkyx - 1) - g.ghost[inky].starget.x, 2) + pow(inkyy - g.ghost[inky].starget.y, 2) : INT_MAX;

    int distright = (g.lab[inkyy][inkyx + 1] != '#' &&
                     !(inkyy == casaanteriorinkyy && inkyx + 1 == casaanteriorinkyx)) ?
        pow((inkyx + 1) - g.ghost[inky].starget.x, 2) + pow(inkyy - g.ghost[inky].starget.y, 2) : INT_MAX;

    if (distup <= distdown && distup <= distleft && distup <= distright)
    {
        g.ghost[inky].pos.y--;
    }

    if (distdown <= distup && distdown <= distleft && distdown <= distright)
    {
        g.ghost[inky].pos.y++;
    }

    if (distleft <= distup && distleft <= distdown && distleft <= distright)
    {
        g.ghost[inky].pos.x--;
    }

    if (distright <= distup && distright <= distdown && distright <= distleft)
    {
        g.ghost[inky].pos.x++;
    }

    if (g.ghost[inky].pos.x == 0 && g.ghost[inky].pos.y == 10)
    {
        g.ghost[inky].pos.x = 18;
    }
    if (g.ghost[inky].pos.x == 19 && g.ghost[inky].pos.y == 10)
    {
        g.ghost[inky].pos.x = 1;
    }
    usleep(8500);
    return g;
}

/* ------------------Cores_do_jogo------------------------------------------ */
void colorlab(t_game g) {
    int i, j, f;

   for (i = 0; i < LABL; i++)
   for (j = 0; j < LABC; j++) {
     if (g.lab[i][j] == '.')
       attron(COLOR_PAIR(6)), mvprintw(i, j, "."), attroff(COLOR_PAIR(6));
     if (g.lab[i][j] == '#')
        attron(COLOR_PAIR(5)), mvprintw(i, j, "#"), attroff(COLOR_PAIR(5));
      if (g.lab[i][j] == '%') {
                attron(COLOR_PAIR(1));
                mvprintw(i, j, "%%");
                attroff(COLOR_PAIR(1));
                              }


       if (g.lab[i][j] == 'o')
         attron(COLOR_PAIR(6)), mvprintw(i, j, "o"), attroff(COLOR_PAIR(6));

       if (g.lab[17][10] == '%')
         attron(COLOR_PAIR(1)), mvprintw(17, 10, "%%"), attroff(COLOR_PAIR(1));

        if (g.lab[i][j] != '.' && g.lab[i][j] != '#' && g.lab[i][j] != 'o')
           mvprintw(i, j, "%c", g.lab[i][j]);
        }

    for (f = blinky; f <= clyde; f++) {
        if (g.ghost[f].mode == chase || g.ghost[f].mode == scatter )
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f + 1, NULL);

        if (g.ghost[f].mode == dead)
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f + 1, NULL);

        if (g.ghost[f].mode == afraid)
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 5, NULL);
    }

    mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
    refresh();
    curs_set(0);
}

/* -------------------------Colisão_Pacman------------------------------- */
t_game colisaopac(t_game g)
{
    for (int f = blinky; f <= clyde; f++)
    {
        if (g.ghost[f].pos.x == g.pacman.pos.x && g.ghost[f].pos.y == g.pacman.pos.y)
        {
            if (g.ghost[f].mode == dead)
                continue;

            if (g.ghost[f].mode == scatter || g.ghost[f].mode == chase)
            {
                g.pacman.life--;

                g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';
                g.pacman.pos.x = g.pacman.posicaoinicial.x;
                g.pacman.pos.y = g.pacman.posicaoinicial.y;

                for (int f_reset = blinky; f_reset <= clyde; f_reset++)
                {
                    g.lab[g.ghost[f_reset].pos.y][g.ghost[f_reset].pos.x] = ' ';
                    g.ghost[f_reset].pos.x = g.ghost[f_reset].posicaoinicial.x;
                    g.ghost[f_reset].pos.y = g.ghost[f_reset].posicaoinicial.y;
                    g.ghost[f_reset].mode = scatter;
                    g.ghost[f_reset].itemAnterior = ' ';

                    switch (f_reset)
                    {
                        case blinky: g.lab[g.ghost[f_reset].pos.y][g.ghost[f_reset].pos.x] = 'B'; break;
                        case pinky:  g.lab[g.ghost[f_reset].pos.y][g.ghost[f_reset].pos.x] = 'P'; break;
                        case inky:   g.lab[g.ghost[f_reset].pos.y][g.ghost[f_reset].pos.x] = 'I'; break;
                        case clyde:  g.lab[g.ghost[f_reset].pos.y][g.ghost[f_reset].pos.x] = 'C'; break;
                    }
                }

                g.lab[g.pacman.pos.y][g.pacman.pos.x] = '@';
            }

            if (g.ghost[f].mode == afraid)
            {

                g.pacman.score += 750;
                g.ghost[f].mode = dead;
                g.ghost[f].tempoMorte = g.tempoatual;
                g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x] = ' ';
                g.ghost[f].itemAnterior = ' ';

                if (f == blinky) {
                    g.ghost[f].pos.x = 8;
                    g.ghost[f].pos.y = 9;
                }
                else {
                    g.ghost[f].pos.x = g.ghost[f].posicaoinicial.x;
                    g.ghost[f].pos.y = g.ghost[f].posicaoinicial.y;
                }

                switch (f)
                {
                    case blinky: g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x] = 'B'; break;
                    case pinky:  g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x] = 'P'; break;
                    case inky:   g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x] = 'I'; break;
                    case clyde:  g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x] = 'C'; break;
                }

            }
        }
    }
    if (g.pacman.life <= 0) {
        gameOver(g);
 }

    return g;
}


/* --------------------------Tela_GameOver---------------------------------------- */
int gameOver(t_game g) {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    WINDOW *gameOverWindow = newwin(rows, cols, 0, 0);
    box(gameOverWindow, 0, 0);
    refresh();
    wrefresh(gameOverWindow);

    int pacmanY = 5;
    int pacmanX = (cols - 62) / 2;

    wattron(gameOverWindow, COLOR_PAIR(1));
    mvwprintw(gameOverWindow, pacmanY + 0, pacmanX,  "   _____          __  __ ______    ______      ________ _____  ");
    mvwprintw(gameOverWindow, pacmanY + 1, pacmanX,  "  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ ");
    mvwprintw(gameOverWindow, pacmanY + 2, pacmanX,  " | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |");
    mvwprintw(gameOverWindow, pacmanY + 3, pacmanX,  " | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / ");
    mvwprintw(gameOverWindow, pacmanY + 4, pacmanX,  " | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ ");
    mvwprintw(gameOverWindow, pacmanY + 5, pacmanX,  "  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\");
    wattroff(gameOverWindow, COLOR_PAIR(1));



    int scoreY = pacmanY + 7;
    int scoreX = (cols - 20) / 2;
    mvwprintw(gameOverWindow, scoreY, scoreX, "Pontuação final: %d", g.pacman.score);

    int optionsY = scoreY + 2;
    int optionsX = (cols - 41) / 2;
    wattron(gameOverWindow, COLOR_PAIR(4));
    mvwprintw(gameOverWindow, optionsY , optionsX - 10, "Pressione 'r' duas vezes para reiniciar ou pressione'q' para sair");
    wattroff(gameOverWindow, COLOR_PAIR(4));





    int imageY = optionsY + 2;
    int imageX = (cols - 30) / 2;
    wattron(gameOverWindow, COLOR_PAIR(3));
    mvwprintw(gameOverWindow, imageY + 0, imageX,  "              ##############            ");
    mvwprintw(gameOverWindow, imageY + 1, imageX,  "          ######  ++++@@@@######        ");
    mvwprintw(gameOverWindow, imageY + 2, imageX,  "        ####  ++++++++++++@@@@####      ");
    mvwprintw(gameOverWindow, imageY + 3, imageX,  "      ####  ++++++++++++++++@@@@####    ");
    mvwprintw(gameOverWindow, imageY + 4, imageX,  "      ##    ++++++++++++++++++@@@@##    ");
    mvwprintw(gameOverWindow, imageY + 5, imageX,  "    ####  ++++::++++++++++::++++@@####  ");
    mvwprintw(gameOverWindow, imageY + 6, imageX,  "    ##    ########++++++########@@@@##  ");
    mvwprintw(gameOverWindow, imageY + 7, imageX,  "    ##    ##..  ####++####..  ##MM@@##  ");
    mvwprintw(gameOverWindow, imageY + 8, imageX,  "    ##  ++##..  ####++####....##MM@@##  ");
    mvwprintw(gameOverWindow, imageY + 9, imageX,  "    ##  ++########++++++########@@@@##  ");
    mvwprintw(gameOverWindow, imageY + 10, imageX, "    ##  ++++####++++++++++####++@@@@##  ");
    mvwprintw(gameOverWindow, imageY + 11, imageX, "    ##  ++++++++++++++++++++++++@@@@##  ");
    mvwprintw(gameOverWindow, imageY + 12, imageX, "    ##  ++++++++++++++++++++++++@@@@##  ");
    mvwprintw(gameOverWindow, imageY + 13, imageX, "    ##  ++++++++++++++++++++++++@@@@##  ");
    mvwprintw(gameOverWindow, imageY + 14, imageX, "    ##  ++++++++++++++++++++++++@@@@##  ");
    mvwprintw(gameOverWindow, imageY + 15, imageX, "    ##  ++++++++++++++++++++++++@@@@##  ");
    mvwprintw(gameOverWindow, imageY + 16, imageX, "    ##  ++::++++++++##++++++++++@@@@##  ");
    mvwprintw(gameOverWindow, imageY + 17, imageX, "    ##  ####@@++++######++++mm####@@##  ");
    mvwprintw(gameOverWindow, imageY + 18, imageX, "    ######  ########  ########  ######  ");
    mvwprintw(gameOverWindow, imageY + 19, imageX, "    ####      ####      ####      ####  ");
    wattroff(gameOverWindow, COLOR_PAIR(3));

    wrefresh(gameOverWindow);

    int key;
    while ((key = wgetch(gameOverWindow)) != ERR) {
        if (key == 'r') {
            delwin(gameOverWindow);
            clear();
            g = upecman_init();
            return 1;
        } else if (key == 'q') {
            endwin();
            exit(EXIT_SUCCESS);
            return 0;
        }
    }

    return 0;
}
/* --------------------------Tela_Vitoria---------------------------------------- */
int vitoria(t_game g) {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    WINDOW *vitoriaWindow = newwin(rows, cols, 0, 0);
    box(vitoriaWindow, 0, 0);
    refresh();
    wrefresh(vitoriaWindow);






    int pacmanY = 5;
    int pacmanX = (cols - 62) / 2;

    wattron(vitoriaWindow, COLOR_PAIR(6));
    mvwprintw(vitoriaWindow, pacmanY + 0, pacmanX, "  __      _______ _____ _______ ____  _______     __ ");
    mvwprintw(vitoriaWindow, pacmanY + 1, pacmanX, "  \\ \\    / /_   _/ ____|__   __/ __ \\|  __ \\ \\   / /");
    mvwprintw(vitoriaWindow, pacmanY + 2, pacmanX, "   \\ \\  / /  | || |       | | | |  | | |__) \\ \\_/ / ");
    mvwprintw(vitoriaWindow, pacmanY + 3, pacmanX, "    \\ \\/ /   | || |       | | | |  | |  _  / \\   /  ");
    mvwprintw(vitoriaWindow, pacmanY + 4, pacmanX, "     \\  /   _| |_ |____   | | | |__| | | \\ \\  | |   ");
    mvwprintw(vitoriaWindow, pacmanY + 5, pacmanX, "      \\/   |_____|\\_____| |_|  \\____/|_|  \\_\\ |_|  ");
    wattroff(vitoriaWindow, COLOR_PAIR(6));

    int scoreY = pacmanY + 7;
    int scoreX = (cols - 20) / 2;
    mvwprintw(vitoriaWindow, scoreY, scoreX, "Pontuação final: %d", g.pacman.score);

    int optionsY = scoreY + 2;
    int optionsX = (cols - 41) / 2;
    wattron(vitoriaWindow, COLOR_PAIR(4));
    mvwprintw(vitoriaWindow, optionsY, optionsX, "Pressione 'r' para reiniciar ou 'q' para sair");
    wattroff(vitoriaWindow, COLOR_PAIR(4));

    int asciiArtY = optionsY + 4;
    int asciiArtX = (cols - 41) / 2;
    wattron(vitoriaWindow, COLOR_PAIR(6));
    mvwprintw(vitoriaWindow, asciiArtY, asciiArtX,     "                @@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 1, asciiArtX, "                @@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 2, asciiArtX, "          @@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 3, asciiArtX, "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 4, asciiArtX, "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 5, asciiArtX, "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 6, asciiArtX, "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 7, asciiArtX, "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 8, asciiArtX, "    @@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 9, asciiArtX, "    @@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 10, asciiArtX, "    @@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 11, asciiArtX, "    @@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 12, asciiArtX, "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 13, asciiArtX, "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 14, asciiArtX, "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 15, asciiArtX, "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 16, asciiArtX, "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 17, asciiArtX, "          @@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 18, asciiArtX, "                @@@@@@@@@@@@@@");
    mvwprintw(vitoriaWindow, asciiArtY + 19, asciiArtX, "                @@@@@@@@@@@@@@");
    wattroff(vitoriaWindow, COLOR_PAIR(6));

    wrefresh(vitoriaWindow);

    int key;
    while ((key = wgetch(vitoriaWindow)) != ERR) {
        if (key == 'r') {
            delwin(vitoriaWindow);
            clear();
            g = upecman_init();
            return 1;
        } else if (key == 'q') {
            endwin();

            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}

int bolinhasRestantes(t_game g) {
    int i, j, count = 0;
    for (i = 0; i < LABL; i++) {
        for (j = 0; j < LABC; j++) {
            if (g.lab[i][j] == '.') {
                count++;
            }
        }
    }
    return count;
}
/* --------------------------Menu_do_Jogo---------------------------------------- */
void menu(void)
{
 initscr();
    clear();
    noecho();
    curs_set(FALSE);

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);

    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    attron(COLOR_PAIR(4));
    mvprintw(rows / 2 - 1, (cols - 13) / 2, "1. Iniciar Jogo");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(4));
    mvprintw(rows / 2 + 0, (cols - 13) / 2, "2. Como Jogar");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(4));
    mvprintw(rows / 2 + 1, (cols - 13) / 2, "3. Creditos");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(4));
    mvprintw(rows / 2 + 2, (cols - 13) / 2, "4. Sair");
    attroff(COLOR_PAIR(2));

    mvhline(0, 0, '-', cols);
    mvhline(rows - 1, 0, '-', cols);
    mvvline(0, 0, '|', rows);
    mvvline(0, cols - 1, '|', rows);
    attron(COLOR_PAIR(6));
    mvprintw(rows / 4 - 1, (cols - 95), "    ___  _   ___ __  __   _   _  _ ");
    mvprintw(rows / 4,     (cols - 95), "   | _ \\/_\\ / __|  \\/  | /_\\ | \\| |");
    mvprintw(rows / 4 + 1, (cols - 95), "   |  _/ _ \\ (__| |\\/| |/ _ \\| .` |");
    mvprintw(rows / 4 + 2, (cols - 95), "   |_|/_/ \\_\\___|_|  |_/_/ \\_\\_|\\_|");
    mvprintw(rows / 4 + 3, (cols - 95), "                                   ");
    attron(COLOR_PAIR(1));
    mvprintw(rows / 2 - 4, (cols + 60)/2  ,    "         @@@@@@@@@@   ");
    mvprintw(rows / 2 - 3, (cols + 60)/2  ,    "     @@@@@@@@@@@@@@@@@@ ");
    mvprintw(rows / 2 - 2, (cols + 60)/2  ,    "    @@@@@@@@@@@@@@@@@@@@@@ ");
    mvprintw(rows / 2 - 1, (cols + 60)/2  ,    "  @@@@@@    @@@@@@@@@@    @@ ");
    mvprintw(rows / 2,     (cols + 60)/2  ,    " @@@@        @@@@@@      @@@   ");
    mvprintw(rows / 2 + 1, (cols + 60)/2  ,    " @@@@    @@@@@@@@@@    @@@@@@ ");
    mvprintw(rows / 2 + 2, (cols + 60)/2  ,    " @@@@@@    @@@@@@@@@@    @@@@@@ ");
    mvprintw(rows / 2 + 3, (cols + 60)/2  ,    " @@@@@@@@    @@@@@@@@@@    @@@@ ");
    mvprintw(rows / 2 + 4, (cols + 60)/2  ,    " @@@@@@@@    @@@@@@@@@@@@@@@@@@ ");
    mvprintw(rows / 2 + 5, (cols + 60)/2  ,    " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ");
    mvprintw(rows / 2 + 6, (cols + 60)/2  ,    " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ");
    mvprintw(rows / 2 + 7, (cols + 60)/2  ,    " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ");
    mvprintw(rows / 2 + 8, (cols + 60)/2  ,    " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ");
    mvprintw(rows / 2 + 9, (cols + 60)/2  ,    " @@@@  @@@@@@      @@@@@@  @@@@ ");
    mvprintw(rows / 2 + 10,(cols + 60)/2  ,    " @@      @@@@      @@@@      @@ ");
    attron(COLOR_PAIR(6));
    mvprintw(rows / 2 - 5,  (cols = 25)/2,     "                @@@@@@@@@@@@@@");
    mvprintw(rows / 2 - 4,  (cols - 5)/2,      "              @@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 - 3,  (cols - 5)/2,      "          @@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 - 2,  (cols - 5)/2,      "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 - 1,  (cols - 5)/2,      "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2,      (cols - 5)/2,      "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 1,  (cols - 5)/2,      "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 2,  (cols - 5)/2,      "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 3,  (cols - 5)/2,      "    @@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 4,  (cols - 5)/2,      "    @@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 5,  (cols - 5)/2,      "    @@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 6,  (cols - 5)/2,      "    @@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 7,  (cols - 5)/2,      "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 8,  (cols - 5)/2,      "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 9,  (cols - 5)/2,      "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 10, (cols - 5)/2,      "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 11, (cols - 5)/2,      "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 12, (cols - 5)/2,      "          @@@@@@@@@@@@@@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 13, (cols - 5)/2,      "                @@@@@@@@@@@@@@");
    mvprintw(rows / 2 + 14, (cols - 5)/2,      "                @@@@@@@@@@@@@@");
        attroff(COLOR_PAIR(1));
    int escolha = getch();

    switch (escolha) {
        case '1':
            clear();
            upecman_init();
            break;
        case '2':
            clear();

            mvhline(0, 0, '-', cols);
            mvhline(rows - 1, 0, '-', cols);
            mvvline(0, 0, '|', rows);
            mvvline(0, cols - 1, '|', rows);
            mvprintw(7, 50, "============= COMO JOGAR =============");
            mvprintw(8, 50, "1. Use as setas do teclado para mover o Pac-Man:");
            mvprintw(9, 50, "- Seta para cima: move o Pac-Man para cima");
            mvprintw(10, 50, "- Seta para baixo: move o Pac-Man para baixo");
            mvprintw(11, 50, "- Seta para direita: move o Pac-Man para a direita");
            mvprintw(12, 50, "- Seta para esquerda: move o Pac-Man para a esquerda");
            mvprintw(13, 50, "- Pressione 'q' para sair do jogo");
            mvprintw(15, 50, "2. Pontuacao:");
            mvprintw(16, 50, "PELOTA '.' = 10 PONTOS");
            mvprintw(17, 50, "PASTILHAO 'o' = 50 PONTOS");
            mvprintw(18, 50, "CEREJA = 500 PONTOS");
            mvprintw(19, 50, "FANTASMAS 'C, I, B, P' = 750 PONTOS");
            mvprintw(21, 50, "3. Objetivo:");
            mvprintw(22, 50, "- Coma todas as pelotas espalhadas no labirinto para vencer.");
            mvprintw(23, 50, "- Evite ser capturado pelos fantasmas.");
            mvprintw(24, 50, "- Como os pastilhoes para poder comer os fantasmas e ganhar vantagem!");
            mvprintw(26, 50, "VIDAS");
            mvprintw(27, 50, " O Pacman '@' possui 3 vidas");
            mvprintw(28, 50, " Caso o Pacman entre em contato com os fantasmas, ele perde 1 de vida");
            mvprintw(29, 50, " Caso o número de vidas cheguem a 0, o jogo é encerrado");
            attron(COLOR_PAIR(4));
            mvprintw(32, 50, "Pressione q ou Q para retornar ao menu.");
            attroff(COLOR_PAIR(4));

            refresh();

           int key;
            while ((key = getch()) != ERR) {
                fflush(stdin);
                if (key == 'q' || key == 'Q') {
                    menu();
                    return;
                }
            }
            break;

                    case '3':
            clear();

            mvhline(0, 0, '-', cols);
            mvhline(rows - 1, 0, '-', cols);
            mvvline(0, 0, '|', rows);
            mvvline(0, cols - 1, '|', rows);
            mvprintw(7, 55, "|----------------- PARTICIPANTES -------------------|");
            mvprintw(8, 55,  " -Igor Guimaraes Monteiro");
            mvprintw(9, 55,  " -Rafael Brayner Rodrigues");
            mvprintw(10, 55, " -Vinícius Magalhaes de Medeiros");
            mvprintw(11, 55, " -Gabriel Dutra Chaves");
            mvprintw(12, 55, " -Juliana Silva Fonseca Carneiro");
            mvprintw(13, 55, " -Mariana Carla de Souza Pereira");
            mvprintw(14, 55, "|-------------------------------------------------|");
            mvprintw(16, 55, "|----------------- COORDENADOR -------------------|");
            mvprintw(17, 55, "  -PROF. Dr. Ruben Carlo Benante");
            mvprintw(18, 55, "|-------------------------------------------------|");
            attron(COLOR_PAIR(4));
            mvprintw(20, 55, "Pressione q ou Q para retornar ao menu");
            attroff(COLOR_PAIR(4));

            refresh();

            while ((key = getch()) != ERR) {
                fflush(stdin);
                if (key == 'q' || key == 'Q') {
                    menu();
                    return;
                }
            }
            break;
        case '4':
            endwin();
            exit(EXIT_SUCCESS);
            break;
       default:  // Caso a tecla pressionada não seja 1, 2, 3 ou 4
            mvprintw(rows / 2 + 4, (cols - 23) / 2 + 62, "Opcao invalida. Tente novamente.");
            refresh();
            sleep(1);
            menu();
    }
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "upecman", "Pacman Ncurses");
    printf("\nUsage: ./%s [-h|-v|-c]\n", "upecman");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29t
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "upecman", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
t_game upecman_init(void)
{
    IFDEBUG("init()");
    /* initialization */

    t_game g;
    int f, y;

    for(y = 0; y < LABL; y++)
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.posicaoinicial.x = 9;
    g.pacman.posicaoinicial.y = 17;
    g.pacman.dir = left; /* pacman start direction */
    g.pacman.life = 3; /* 3 lifes */
    g.pacman.score = 0; /* 0 points */

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {


        switch(f)
        {
            case blinky:
                g.ghost[f].pos.y = 7; /* blinky start position (line) */
                g.ghost[f].pos.x = 9; /* blinky start position (column) */
                g.ghost[f].posicaoinicial.y = 7;
                g.ghost[f].posicaoinicial.x = 9;
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case pinky:
                g.ghost[f].pos.y = 9; /* pinky start position (line) */
                g.ghost[f].pos.x = 10; /* pinky start position (column) */
                g.ghost[f].posicaoinicial.x = 10;
                g.ghost[f].posicaoinicial.y = 9;
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
                break;
            case inky:
                g.ghost[f].pos.y = 10; /* inky start position (line) */
                g.ghost[f].pos.x = 10; /* inky start position (column) */
                g.ghost[f].posicaoinicial.x = 10;
                g.ghost[f].posicaoinicial.y = 10;
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case clyde:
                g.ghost[f].pos.y = 11; /* clyde start position (line) */
                g.ghost[f].pos.x = 10; /* clyde start position (column) */
                g.ghost[f].posicaoinicial.x = 10;
                g.ghost[f].posicaoinicial.y = 11;
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
        }
        g.ghost[f].dir = left; /* start direction and future direction: left */
        g.ghost[f].mode = chase;
    }

    initscr(); /* start ncurses mode screen */
    cbreak(); /* stop line buffering */
    keypad(stdscr, TRUE); /* grab extended keys */
    noecho(); /* stop echoing chars */
    timeout(0); /* do not wait */
    start_color(); /* initialize the color functionality */

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK); /* Blinky */
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK); /* Pinky */
    init_pair(3, COLOR_CYAN, COLOR_BLACK); /* Inky */
    init_pair(4, COLOR_GREEN, COLOR_BLACK); /* Clyde doesn't have orange :( */
    init_pair(5, COLOR_BLUE, COLOR_BLACK); /* Afraid mode: blue with A_BLINK */
    init_pair(6, COLOR_YELLOW, COLOR_BLACK); /* Pacman */

    return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
void printlab(t_game g)
{
    IFDEBUG("printlab()");

    int y, f;

    /*clear(); / * clear the screen */

    for(y = 0; y < LABL; y++)
    {
        printw("%s\n", g.lab[y]);
     }

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
        mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f + 1, NULL);


    refresh();
}



/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

