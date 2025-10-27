/***************************************************************************
 *   upecman.h                                Version 20160529.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
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
/* definitions */

#ifndef VERSION
#define VERSION "20160529.013231" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */
#define LABL 23 /**< Number of lines in labyrinth */
#define LABC 21 /**< Number of columns in labyrinth */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

const char labmodel[LABL][LABC] =
{
    /*01234567890123456789*/
    {"####################"},    /* 0*/
    {"#........##........#"},    /* 1*/
    {"#o##.###.##.###.##o#"},    /* 2*/
    {"#..................#"},    /* 3*/
    {"#.##.#.######.#.##.#"},    /* 4*/
    {"#....#...##...#....#"},    /* 5*/
    {"####.###.##.###.####"},    /* 6*/
    {"   #.#...B....#.#   "},    /* 7*/
    {"   #.#.##--##.#.#   "},    /* 8*/
    {"####.#.#  P #.#.####"},    /* 9*/
    {"    ...#  I #...    "},    /*10*/
    {"####.#.#  C #.#.####"},    /*11*/
    {"   #.#.######.#.#   "},    /*12*/
    {"   #.#........#.#   "},    /*13*/
    {"####.#.######.#.####"},    /*14*/
    {"#........##........#"},    /*15*/
    {"#o##.###.##.###.##o#"},    /*16*/
    {"#..#.....@......#..#"},    /*17*/
    {"##.#.#.######.#.#.##"},    /*18*/
    {"#....#...##...#....#"},    /*19*/
    {"#.######.##.######.#"},    /*20*/
    {"#..................#"},    /*21*/
    {"####################"}     /*22*/
};


typedef enum e_ghostmode {chase, scatter, afraid, dead} t_ghostmode;
typedef enum e_direction {up, left, down, right} t_direction;
typedef enum e_ghosts {blinky, pinky, inky, clyde} t_ghosts;

typedef struct st_position
{
    int y; /* line */
    int x; /* column */
} t_pos;

typedef struct st_pacman
{
    t_pos pos; /* current pacman position */
    t_pos posicaoanterior;
    t_direction premove; /* intencao de muda a direcao */
    t_direction dir; /* direction */
    int life; /* how many lifes pacman has */
    int score; /* dot = 10 point; pill = 50 points; ghost = 750 points; cherry = 500 */
    int dot;
    int pill;
    int ghost;
    int cherry,cherry2,cherry3;
    t_pos posicaoinicial;
} t_pacman;

typedef struct st_ghost
{
    t_pos pos; /* ghost position */
    t_pos posicaoanterior; /* ghost posição anterior */
    char itemAnterior; /* u
                          sado caracter onde o entrou */

    t_direction dir; /* ghost current direction */
    t_pos starget; /* ghost scatter preferred corner */
    t_ghostmode mode; /* chase, scatter, afraid or dead */
    t_pos posicaoinicial;
    int tempoMorte;
} t_ghost;

typedef struct st_pacdata
{
    char lab[LABL][LABC]; /* the labyrinth map */
    t_pacman pacman; /* pacman data */
    t_ghost ghost[4]; /* ghost[blinky], ghost[pinky], ghost[inky], ghost[clyde] */
    int tempoContado;
    int tempoInicioAfraid;
    int tempoatual;

} t_game;


/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
t_game upecman_init(void); /* initialize game variables */
void menu(); /* Menu */
void printlab(t_game g); /* print the labyrinth */
t_game movepac(t_game g);/* função movimento do pacman */
t_game pointjogo(t_game g); /*placar do jogo */
t_game entjogo(t_game g, int kin); /* laço do usuario */
t_game movimentoblinky(t_game g); /* movimento blinky */
t_game placarpac(t_game g);
void colorlab(t_game g); /*colorir */
t_game cereja (t_game g); /* cerejas */
t_game movimentopinky(t_game g); /* movimentação do pinky */
t_game movimentoclyde(t_game g); /* movimentação do clyde */
t_game movimentoinky(t_game g); /* moviemento do inky */
t_game contador(t_game g); /* contador do jogo */
t_game colisaopac(t_game g); /* colisao */
t_game modoAfraid(t_game g); /* modo afraid */
t_game corrigindo_print (t_game g);
int gameOver(t_game);
int vitoria(t_game);
int bolinhasRestantes(t_game g);

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

