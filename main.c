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


char login_page() {
	int n;	
//	printf("hi\n\n\n");
    do {
    	printf("Hi welcome to the game\nsign_up enter : 1\nsign_in enter : 2\nstart game:3\nchange info :4\nhistory:5\nexit : 6\n");
    	scanf("%d",&n);
		if(n==1)
        	return n;
    	
        else if(n==2)
        	return n;
		
        else if (n==3)
        	return n;
        
        else if (n==4)
        	return n;
        
        else if (n==5)
        	return n;
        
        else if (n==6)
        	exit(0);
        
        else {
			printf("Invailid chose pleas try again");
		}
        system("cls");
	} while(n != 6);
}


struct lasami* read_from_file(int *maxId)
{
    FILE *pfile;
    pfile = fopen("E:\\Ali\\sanati\\programing\\paianterm\\asami.bin" , "r+b");
    if (pfile == NULL) {
        pfile = fopen("E:\\Ali\\sanati\\programing\\paianterm\\asami.bin" , "W+b");
    }
    struct lasami *phead = NULL, *pnew, *plast = NULL;
    struct asami temp;
    while(fread(&temp, sizeof(struct asami), 1, pfile))
    {
        pnew = (struct lasami *)malloc(sizeof(struct lasami));
        pnew->pnext = NULL;
        if(phead == NULL)
        {
            phead = pnew;
        }
        else
        {
            plast->pnext = pnew;
        }
        pnew->info = temp;
        plast = pnew;
    }
    fclose(pfile);
    if(phead == NULL)
    {
        phead = (struct lasami*)malloc(sizeof(struct lasami));
        phead->pnext = NULL;
        phead->info.ID = 0;
        *maxId = 0;
    }
    else
    {
        *maxId = pnew->info.ID;
    }
    return phead;
}


struct lasami* sign_up(struct lasami* phead,int maxId){
while(1) {
    system("cls");
    char name[40];
    char pass[20];
    char confirmpass[20];
    char email[100];
    char key='a';
    int i = 0;
    int static ID = 0;
    struct lasami* ptemp = phead;
    printf("enter youe user name :");
    scanf("%s",name);
    while(1)
    {
    if(strcmp(ptemp->info.username , name) == 0)
    {
        system("cls");
        printf("you should change your name enter again");
        scanf("%s",name);
        _getch();
        ptemp = phead;
        continue;
    }
    if(ptemp->pnext)
    {
        ptemp = ptemp->pnext;
        continue;
    }
    break;
}

    system("cls");
    while(1)
    {
        printf("pleas enter your pass:\n");
        i = 0;
        pass[i] = '\0';
        key='\0';
        while(key != '\r' && key != ' ')
        {
            

             key = _getch();
            if(key == '\b' && i>0)
            {
                
                pass[i] = '\0';    
                printf("\b \b");
                i--;
                
            }
            else 
            {
                pass[i]=key;
                i++;
                printf("*");
            }
        }
            if(strlen(pass) >= 7) {

                printf("\npleas enter your pass again:\n");
                key='\0';
                i=0;
                while(key != '\r' && key != ' ')
                {
                    
                    key = _getch();
                    if(key == '\b' && i>0)
                    {
                        i--;
                        confirmpass[i] = '\0';
                        printf("\b");
                    }
                    else 
                    {
                        confirmpass[i]=key;
                        i++;
                        printf("*");
                    }
                }
                    if(strcmp(pass,confirmpass) != 0 )
                    {
                        //khoroj
                        continue;
                    }
            }            
            else
            {
                printf("\n");
                continue;
            }
        break;
    }
    system("cls");
    printf("pleas enter your email:\n");
    scanf("%s",email);    
    ptemp->pnext = (struct lasami* )malloc(sizeof(struct lasami));
    ptemp=ptemp->pnext;
    ptemp->pnext=NULL;
    strcpy(ptemp->info.username ,name);
    strcpy(ptemp->info.username ,pass);
    strcpy(ptemp->info.username ,email);
    ID++;
    ptemp->info.ID = ID + maxId;
    ptemp->info.win = 0;
    ptemp->info.lose = 0;
    return ptemp;
}
}
 
struct lasami* sign_in(struct lasami* phead) {
    char name[40];
    char email[100];
    char pass[20];
    int input = 0;
    char key='a';
    char confirmpass[20];
    int i =0;
    struct lasami* ptemp;
    while(1){
        ptemp = phead ;
        printf("enter your name:\n");
        scanf("%s",name); 
        while(1)
        {

            if(strcmp(ptemp->info.username , name ) == 0 ) {
                while(1){
                    printf("enter your pass:\n");
                    scanf("%s",pass);
                    if (strcmp(ptemp->info.password , pass ) == 0){
                        ///game menu 
                        //return ;
                    }
                    else {
                        while(1){
                            printf("enter 1 : try again\n enter 2 : forgot pass");
                            if(input==2) {
                                printf("enter your email:\n");
                                scanf("%s",email);
                                if(strcmp(ptemp->info.email , email) == 0){
                                    while(1)
                                    {
                                        printf("enter your new pass\n");
                                        i = 0;
                                        pass[i] = '\0';
                                        while(key != '\r' && key != ' ')
                                        {
                                            key = _getch();
                                            if(key == '\b')
                                            {
                                                pass[i] = '\0';
                                                i--;
                                                printf("\b");
                                            }
                                            else 
                                            {
                                                pass[i]=key;
                                                i++;
                                                printf("*");
                                            }
                                            if(strlen(pass) >= 8){
                                                key='\0';
                                                while(key != '\r' && key != ' ')
                                                {                                                    
                                                    key = _getch();
                                                    if(key == '\b')
                                                    {
                                                        confirmpass[i] = '\0';
                                                        i--;
                                                        printf("\b");
                                                    }
                                                    else 
                                                    {
                                                        confirmpass[i]=key;
                                                        i++;
                                                        printf("*");
                                                    }
                                                }
                                                if(strcmp(pass,confirmpass) != 0 )
                                                {
                                                    continue;
                                                }
                                                strcpy(ptemp->info.password,pass);

                                            }
                                            else{
                                                break;
                                            }
                                        }
                                    }                                          
                                }
                            else {
                                continue;
                            }                                
                            }
                            else if(input==1) {
                                break;
                            }
                        }                    
                    }     
                                                            
                }
            }    
            else {
                while(1){
                    printf("enter 1 : try again\nenter 2 : exit\n");
                    scanf("%d",&input);                    
                    if(input==1){
                        break;
                    }
                    if(input==2){
                        //exit();
                        //return ;
                    }
                }                                                   
            }

        if(ptemp->pnext)
        {
            break;
        }
        ptemp = ptemp->pnext;
    }
        return ptemp;
    }
}

