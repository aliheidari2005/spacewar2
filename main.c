#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define PLAYER1_UP 'W'
#define PLAYER1_DOWN 'S'
#define PLAYER1_LEFT 'A'
#define PLAYER1_RIGHT 'D'
#define PLAYER1_SHOOT 'C'

#define PLAYER2_UP 'I'
#define PLAYER2_DOWN 'K'
#define PLAYER2_LEFT 'J'
#define PLAYER2_RIGHT 'L'
#define PLAYER2_SHOOT 'N'


int width = 99;
int countershotdoganeh = 0;
int narenjak = 0;
int shot =0;
int counterooh = 0;
int shot2 =0;
int counterooh2 = 0;
int countershotdoganeh2 = 0;
int i =0;
int zamin1 = 0;
int zamin2 = 0;
BOOL rooh1 = FALSE;
BOOL rooh2 = FALSE; 
//COORD listmiror[40] ;
//COORD miror;
COORD miror[40];






struct asami{
    char username[40];
    char password[20];
    char email[100];
    int win ;
    int lose ;
    int ID;
};

struct lasami{
    
    struct asami info ;
    struct lasami* pnext ; 

};

typedef struct histori{
    char win_1[40];
    char win_2[40];
    char win_kol[40];


}histori;

