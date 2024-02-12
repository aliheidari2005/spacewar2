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


void change_info(struct lasami* puser ,struct lasami* phead ) {
    system("cls");
    int i =0;
    char pass[40];
    char confirmpass[20];
    char email[20];
    char key ;
    struct lasami* ptemp = phead;
    char name[40];
    int input = 0 ;
    while(1) {
        system("cls");
        printf("change name enter 1\nchange pass enter 2\nchange email enter 3\n enter : 4 finish");
        scanf("%d",&input);

        if (input==1){
            system("cls");
            printf("enter your new name :\n");
            scanf("%s",name);
            while(1){
                    if(strcmp(ptemp->info.username , name) == 0){
                        //name karbari vojod dard yek nam digar vared konid
                        system("cls");
                        printf("name tekrari ast pleas enter again name\n");
                        scanf("%s",name);
                        ptemp = phead ;
                        _getch();
                        continue;
                    }
                    else{
                        ptemp=ptemp->pnext;    
                    }
                    if(ptemp== NULL){
                        //strcmp(ptemp->info.username,name);
                    break;
                    }
            }
        
        strcpy(puser->info.username,name);
        }
        
        else if(input==2) {
            while(1)
            {
                i = 0;
                pass[i] = '\0';
                while(key != '\r' && key != ' ')
                {
                    
                    key = _getch();
                    if(key == '\b' && i>=0)
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

                    }
                    else{
                        strcpy(puser->info.password,pass);
                        break;
                    }
                }
            }

        }    
        /////////////////
    if(input==3)
    {
        system("cls");
        printf("enter your email:");
        scanf("%s",email);
        strcpy(puser->info.email,email);
    }    
    if(input==4)
    {
        return;
    }
    }
}

void history(struct lasami* puser1 ,struct lasami* puser2 ){
    system("cls");
    printf("%s\t\t\t\t\t\t%d\t\t\t\t\t%d\n",puser1->info.username,puser1->info.win,puser1->info.lose);
    printf("%s\t\t\t\t\t\t%d\t\t\t\t\t%d\n",puser2->info.username,puser2->info.win,puser2->info.lose);
    FILE* history;
    history = fopen("E:\\Ali\\sanati\\programing\\paianterm\\histori.bin","a+b");
    
}


COORD shot_w(COORD* player1_bullet, char zamin[30][99] , int* ajazeh, int height , BOOL* player1bulletmoving , int*x ,struct lasami* puser1 ,struct lasami* puser2 ) {

    if (player1_bullet->Y != -1 && zamin[player1_bullet->Y -1][player1_bullet->X ] != -37 && zamin[player1_bullet->Y -1][player1_bullet->X ] != '2' && zamin[player1_bullet->Y -1][player1_bullet->X ] != '1' && rooh1== FALSE ) 
    {   
        if (zamin[player1_bullet->Y - 1][player1_bullet->X] == -70)
        {
            if(narenjak==1)
            {
                
                miror[i]= (COORD) {player1_bullet->Y-1,player1_bullet->X};
                i++;
                
                //return player1_bullet ;
                // پاک کردن ایینه 
                //zamin[player1_bullet->Y][player1_bullet->X]=' ';                         
                //*mirror=0;
                //zamin[player1_bullet->Y -1 ][player1_bullet->X]=' ';
                for(int i = player1_bullet->Y-1 ; i<= player1_bullet->Y+1 ; i++) {
                    for(int j= player1_bullet->X-1 ; j<= player1_bullet->X+1;j++) {
                        if(zamin[i][j]=='2' || zamin[i][j]=='1')
                        {
                            if(zamin[i][j]=='1')
                            {
                                gamer1.health--;
                                if(gamer1.health==0)
                                {
                                    puser1->info.lose++;
                                    puser2->info.win++;
                                    system("cls");
                                    printf("user1 : 0                                                    user2:1");
                                }
                            }
                            if(zamin[i][j]=='2')
                            {
                                gamer2.health--;
                                if(gamer2.health==0)
                                {
                                                                        puser2->info.lose++;
                                    puser1->info.win++;
                                    system("cls");
                                    printf("user1 : 1                                                    user2:0");
                                }
                            }
                        
                        }
                    }
                }
                player1_bullet->X = -1;
                player1_bullet->Y  = -1;
                *player1bulletmoving = FALSE;
                *x=0;
                narenjak=0;
                *ajazeh=4;
                return miror[i-1];      
            }
            else if(narenjak == 0)
            {
                if(zamin[player1_bullet->Y +1 ][player1_bullet->X] != -37 && zamin[player1_bullet->Y +1 ][player1_bullet->X] != -70 && zamin[player1_bullet->Y +1 ][player1_bullet->X] != '2' && zamin[player1_bullet->Y +1 ][player1_bullet->X] != '1' ) 
                {
                    //if(counterrooh<8)
                    //{
                        player1_bullet->Y++;
                        *ajazeh=1;
                      //  couterrooh++
                    //}
                }
            
                else if(zamin[player1_bullet->Y +1 ][player1_bullet->X ] == -70)
                {
                    player1_bullet->Y--;
                    *ajazeh=4;
                } 
                else if(zamin[player1_bullet->Y +1][player1_bullet->X ] == -37)
                {
                    player1_bullet->X = -1;
                    player1_bullet->Y = -1;
                    *player1bulletmoving = FALSE;
                    *x=0;
                    *ajazeh=1;
                }
                
                else if(zamin[player1_bullet->Y +1][player1_bullet->X ] == '1')
                {
                    player1_bullet->X = -1;
                    player1_bullet->Y = -1;
                    *player1bulletmoving = FALSE;
                    *x=0;                    
                   // *ajazeh=0;

                    if(shot==5)
                    {
                        gamer1.health-=2 ;
                        countershotdoganeh++;
                        if(countershotdoganeh==5)
                        {

                            countershotdoganeh=0;
                            shot = 0;
                        }
                    }
                    else 
                    {
                        //gamer1.shot-- ;
                        gamer1.health=gamer1.health-1 ;
                        
                    } 
                    if(gamer1.health==0)
                    {
                                                            puser1->info.lose++;
                                    puser2->info.win++;
                        zamin1=1;
                        system("cls");
                        printf("user1 : 0                                                    user2:1");

                    }    
                                
                }
                            
                else if(zamin[player1_bullet->Y +1][player1_bullet->X ] == '2')
                {
                    player1_bullet->X = -1;
                    player1_bullet->Y = -1;
                    *player1bulletmoving = FALSE;
                    *x=0;

                    if(shot == 5)
                    {
                        //gamer1.shot-- ;
                        gamer2.health=gamer2.health-2 ;
                        countershotdoganeh++;
                        if(countershotdoganeh==5)
                        {
                            countershotdoganeh=0;
                            shot = 0;
                        }
                    }
                    else if(shot != 5)
                    {
                        gamer2.health-- ;   
                    } 
                    if(gamer2.health==0)
                    {

                                    puser2->info.lose++;
                                    puser1->info.win++;

                        system("cls");
                        zamin1=1;

                        printf("user1 : 1                                                    user2:0");
                    }                              
                }                       
            }
        }
        else if(zamin[player1_bullet->Y-1][player1_bullet->X ] != -70)
        {
            player1_bullet->Y--;
        }                                                
    
    }
    else if(rooh1==TRUE)
    {
        player1_bullet->Y--;
        if(zamin[player1_bullet->Y-1][player1_bullet->X]=='2')
        {
            player1_bullet->X=-1;
            player1_bullet->Y=-1;
            *player1bulletmoving = FALSE;            
            *x=0;
            gamer2.health--;
            if(gamer2.health==0)
            {
                zamin1=1;
            }
        }
    }
    else if(zamin[player1_bullet->Y-1][player1_bullet->X ] == -37 )
    {
        if(narenjak==1)
        {
            for(int i = player1_bullet->Y -2 ; i <= player1_bullet->Y+2 ; i++ ){
                for(int j = player1_bullet->X -2 ; j <= player1_bullet->X +2 ; j++){
                    if(zamin[i][j] == '2')
                    {
                        gamer2.health--;                        
                        if(gamer2.health==0)
                        {
                                    puser2->info.lose++;
                                    puser1->info.win++;
                            system("cls");
                            printf("user1 : 1                                                    user2:0");
                        }
                    }
                    if(zamin[i][j] == '1')
                    {
                        gamer1.health--;
                        if(gamer1.health==0)
                        {

                                    puser1->info.lose++;
                                    puser2->info.win++;


                                                        system("cls");
                        printf("user1 : 0                                                    user2:1");

                        }
                    }
                }
            }
            narenjak = 0;
        }
        player1_bullet->X = -1;
        player1_bullet->Y = -1;
        *player1bulletmoving = FALSE;
        *x=0;
    }
    else if(zamin[player1_bullet->Y-1][player1_bullet->X ] == '2')
    {
        player1_bullet->X = -1;
        player1_bullet->Y = -1;
        *player1bulletmoving = FALSE;
        *x=0;
        if(shot==5)
        {
            gamer2.health=gamer2.health-2;
            countershotdoganeh++;
            if(countershotdoganeh==5)
            {
                countershotdoganeh=0;
                shot=0;
            }    
        }
        else
        {
            gamer2.health--;
            if(narenjak==1)
            {
                narenjak=0;
            }
            if(gamer2.health==0)
            {
                                    puser2->info.lose++;
                                    puser1->info.win++;

                        system("cls");
                        printf("user1 : 1                                                    user2:0");
            }
        }                           
            
    }
    else if(zamin[player1_bullet->Y -1][player1_bullet->X ] == '1')
    {
        player1_bullet->X = -1;
        player1_bullet->Y = -1;
        *player1bulletmoving = FALSE;
        *x=0;
        gamer1.health--;
        if(gamer1.health==0)
        {
                                    puser1->info.lose++;
                                    puser2->info.win++;            
                        system("cls");
                        printf("user1 : 0                                                    user2:1");
        }                       
    }
    if (player1_bullet->Y >= height || player1_bullet->Y < 0 ) 
    {
        *player1bulletmoving = FALSE;
        player1_bullet->X = -1;
        player1_bullet->Y = -1;
        *x=0;
    }
}


COORD shot_s(COORD* player1_bullet, char zamin[30][99] , int* ajazeh, int height , BOOL* player1bulletmoving , int* x,struct lasami* puser1 ,struct lasami* puser2 ){
                
    if (player1_bullet->X != -1 && zamin[player1_bullet->Y +1][player1_bullet->X ] != -37 && zamin[player1_bullet->Y +1][player1_bullet->X ] != '2'&& zamin[player1_bullet->Y +1][player1_bullet->X ] != '1' && rooh1== FALSE ) 
    {            
        if (zamin[player1_bullet->Y + 1][player1_bullet->X] == -70)
        {
            if(narenjak==1)
            {
                miror[i]= (COORD) {player1_bullet->Y+1,player1_bullet->X};
                i++;

                for(int i = player1_bullet->Y -1 ; i<= player1_bullet->Y+1 ; i++){
                    for(int j= player1_bullet->X-1 ; j<= player1_bullet->X+1;j++){
                        if(zamin[i][j]=='2' || zamin[i][j]=='1')
                        {
                            if(zamin[i][j]=='1')
                            {
                                gamer1.health--;
                                if(gamer1.health==0)
                                {
                                                                        puser1->info.lose++;
                                    puser2->info.win++;

                                }
                            }
                            if(zamin[i][j]=='2')
                            {
                                gamer2.health--;
                                if(gamer2.health==0)
                                {
                                                                        puser2->info.lose++;
                                    puser1->info.win++;

                                }
                            }
  
                        }
                    }
                }
                player1_bullet->X = -1;
                player1_bullet->Y = -1;                        
                *player1bulletmoving = FALSE;
                *x=0;
                narenjak=0;
                *ajazeh=4;
                return miror[i-1];      

            }

            else if(narenjak==0)
            {
                if(zamin[player1_bullet->Y -1 ][player1_bullet->X] != -37 && zamin[player1_bullet->Y -1 ][player1_bullet->X] != -70 && zamin[player1_bullet->Y -1 ][player1_bullet->X] != '2' && zamin[player1_bullet->Y -1 ][player1_bullet->X] != '1') 
                {   
                    player1_bullet->Y --;
                    *ajazeh=4;
                }
                else if(zamin[player1_bullet->Y -1 ][player1_bullet->X ] == -70){
                    player1_bullet->Y++;
                    *ajazeh=1;
                } 
                else if(zamin[player1_bullet->Y -1][player1_bullet->X ] == -37){
                    *player1bulletmoving = FALSE;
                    player1_bullet->X = -1;
                    player1_bullet->Y = -1;
                    *x=0;                   
                    *ajazeh=4;

                }
                else if(zamin[player1_bullet->Y -1 ][player1_bullet->X] == '2')
                {
                    player1_bullet->X = -1;
                    player1_bullet->Y = -1;
                    *player1bulletmoving = FALSE;
                    *x=0;                   
                    if(shot==5)
                    {
                        gamer2.health=gamer2.health-2 ;
                        countershotdoganeh++;
                        if(countershotdoganeh==5)
                        {
                            countershotdoganeh=0;
                            shot = 0;
                        }
                    }
                    else if(shot!=5)
                    {
                        gamer2.health-- ;                        
                    }
                    if(gamer2.health==0)
                    {
                                                            puser2->info.lose++;
                                    puser1->info.win++;
                        win_player1();
                        lose_player2();
                    }                            
                }
                else if(zamin[player1_bullet->Y -1 ][player1_bullet->X] == '1')
                {
                    player1_bullet->X = -1;
                    player1_bullet->Y = -1;
                    *player1bulletmoving = FALSE;
                    *x=0;
                    if(shot==5)
                    {
                        gamer1.health-=2 ;
                        countershotdoganeh++;
                        if(countershotdoganeh==5)
                        {
                            countershotdoganeh=0;
                            shot = 0;
                        }
                    }
                    else if(shot != 5)
                    {
                        gamer1.health=gamer1.health-1 ;
                        
                    }                                        
                    if(gamer1.health==0)
                    {
                                                            puser1->info.lose++;
                                    puser2->info.win++;
                        win_player2();
                        lose_player1();                                
                    }                            
                }                           
            }
        }
        else if(zamin[player1_bullet->Y+1][player1_bullet->X ] != -70)
        {
            player1_bullet->Y++;
        }                                                
    }
    else if(rooh1==TRUE)
    {
        player1_bullet->Y++;

    }    


    else if(zamin[player1_bullet->Y +1][player1_bullet->X ] == -37 )
    {
        if(narenjak==1)
        {
            for(int i = player1_bullet->Y -2 ; i <= player1_bullet->Y+2 ; i++ ){
                for(int j = player1_bullet->X -2 ; j <= player1_bullet->X +2 ; j++){
                    if(zamin[i][j] == '2')
                    {
                        gamer2.health--;                        
                        if(gamer2.health==0)
                        {
     
                                         puser2->info.lose++;
                                    puser1->info.win++;
                            //return;
                        }
                    }
                    if(zamin[i][j] == '1')
                    {
                        gamer1.health--;
                        if(gamer1.health==0)
                        {
                                                                puser1->info.lose++;
                                    puser2->info.win++;
                         //   return;
                        }
                    }
                }
            }
            narenjak = 0;
        }

        player1_bullet->X = -1;
        player1_bullet->Y = -1;
        *player1bulletmoving = FALSE;
        *x=0;
    }
            else if(zamin[player1_bullet->Y +1][player1_bullet->X ] == '2' )
            {
                player1_bullet->X = -1;
                player1_bullet->Y = -1;
                *player1bulletmoving = FALSE;
                *x=0;
                if(shot==5)
                {
                    gamer2.health=gamer2.health-2;
                    countershotdoganeh++;
                    if(countershotdoganeh==5)
                    {
                        countershotdoganeh=0;
                        shot=0;
                    }    
                }
                else
                {
                    gamer2.health--;
                    if(narenjak==1)
                    {
                        narenjak=0;
                    }
                    if(gamer2.health==0)
                    {
                                                            puser2->info.lose++;
                                    puser1->info.win++;
                      
                    }
                }  

            }
            else if(zamin[player1_bullet->Y +1][player1_bullet->X ] == '1' )
            {
                player1_bullet->X = -1;
                player1_bullet->Y = -1;
                *player1bulletmoving = FALSE;
                *x=0;
                gamer1.health--;
                if(gamer1.health==0)
                {
                                                        puser1->info.lose++;
                                    puser2->info.win++;
                    win_player2();
                    lose_player1();
                }
            }                   
            if (player1_bullet->Y == height || player1_bullet->Y == 0 ) 
            {
                *player1bulletmoving = FALSE;
                player1_bullet->X = -1;
                player1_bullet->Y = -1;
                *x=0;
            }

}


COORD shot_d(COORD* player1_bullet, char zamin[30][99] , int* ajazeh, int width , BOOL* player1bulletmoving , int* x,struct lasami* puser1 ,struct lasami* puser2){


    if (player1_bullet-> X != -1 && zamin[player1_bullet->Y][player1_bullet->X +1 ] != -37 && zamin[player1_bullet->Y][player1_bullet->X +1 ] != '2' && zamin[player1_bullet->Y][player1_bullet->X +1 ] != '1'&& rooh1== FALSE ) 
    {            
        if (zamin[player1_bullet->Y][player1_bullet->X + 1] == -70)
        {
            if(narenjak==1)
            {
                miror[i]= (COORD) {player1_bullet->Y,player1_bullet->X+1};
                i++;
                for(int i = player1_bullet->Y -1 ; i<= player1_bullet->Y+1 ; i++){
                    for(int j= player1_bullet->X-1 ; j<= player1_bullet->X+1;j++){
                        if(zamin[i][j]=='2' || zamin[i][j]=='1')
                        {
                            if(zamin[i][j]=='1')
                            {
                                gamer1.health--;
                                if(gamer1.health==0)
                                {
                                                                        puser1->info.lose++;
                                    puser2->info.win++;
                                    zamin1=1;
                                }
                            }
                            if(zamin[i][j]=='2')
                            {
                                gamer2.health--;
                                if(gamer2.health==0)
                                {                                    puser2->info.lose++;
                                    puser1->info.win++;
                                    zamin1=1;

                                }
                            }

                        }
                    }
                }
                player1_bullet->X = -1;
                player1_bullet->Y = -1;                        
                *player1bulletmoving = FALSE;
                *x=0;
                narenjak=0;
                *ajazeh=3;
                return miror[i-1];    
            }
            else if(narenjak==0)
            {
                if(zamin[player1_bullet->Y][player1_bullet->X - 1] != -37 && zamin[player1_bullet->Y][player1_bullet->X - 1] != -70 && zamin[player1_bullet->Y][player1_bullet->X -1 ] != '2' && zamin[player1_bullet->Y][player1_bullet->X  -1 ] != '1'  ) 
                {
                    player1_bullet->X--;
                    *ajazeh=2;
                }
                else if(zamin[player1_bullet->Y][player1_bullet->X - 1] == -70)
                {
                    player1_bullet->X++;
                    *ajazeh=3;
                }
                else if(zamin[player1_bullet->Y][player1_bullet->X - 1] == -37)
                {
                    *player1bulletmoving = FALSE;
                    player1_bullet->X = -1;
                    player1_bullet->Y = -1;
                    *x = 0;
                    *ajazeh=2;
                
                }
                else if(zamin[player1_bullet->Y][player1_bullet->X - 1] == '2')
                {
                    player1_bullet->X = -1;
                    player1_bullet->Y = -1;
                    *player1bulletmoving = FALSE;
                    *x = 0;                            
                    if(shot==5)
                    {
                        gamer2.health=gamer2.health-2 ;
                        countershotdoganeh++;
                        if(countershotdoganeh==5)
                        {
                            countershotdoganeh=0;
                            shot = 0;
                        }
                    }
                    else if(shot!=5)
                    {
                        gamer2.health-- ;                        
                    }
                    if(gamer2.health==0)
                    {                                    puser2->info.lose++;
                                    puser1->info.win++;
                        zamin1=1;
                      
                    }                 
                
                }
                else if(zamin[player1_bullet->Y][player1_bullet->X - 1] == '1') 
                {
                    player1_bullet->X = -1;
                    player1_bullet->Y = -1;
                    *player1bulletmoving = FALSE;
                    *x = 0;                            
                    if(shot==5)
                    {
                        gamer1.health-=2 ;
                        countershotdoganeh++;
                        if(countershotdoganeh==5)
                        {
                            countershotdoganeh=0;
                            shot = 0;
                        }
                    }
                    else if(shot != 5)
                    {
                        gamer1.health=gamer1.health-1 ;
                        
                    }                                        
                    if(gamer1.health==0)
                    {
                                                                                          puser1->info.lose++;
                                    puser2->info.win++;                             
                    }                                 
                }                                                
            }                   
        }
        else if(zamin[player1_bullet->Y][player1_bullet->X + 1] != -70)
        {
            player1_bullet->X++;
        }                                                
    }
    else if(rooh1==TRUE)
    {
        player1_bullet->X++;

    }       
    else if(zamin[player1_bullet->Y][player1_bullet->X +1 ] == -37 )
    {

       if(narenjak==1)
        {
            for(int i = player1_bullet->Y -2 ; i <= player1_bullet->Y+2 ; i++ ){
                for(int j = player1_bullet->X -2 ; j <= player1_bullet->X +2 ; j++){
                    if(zamin[i][j] == '2')
                    {
                        gamer2.health--;                        
                        if(gamer2.health==0)
                        {
                                                                puser2->info.lose++;
                                    puser1->info.win++;
                            //return;
                        }
                    }
                    if(zamin[i][j] == '1')
                    {
                        gamer1.health--;
                        if(gamer1.health==0)
                        {                                                                  puser1->info.lose++;
                                    puser2->info.win++;
                         //   return;
                        }
                    }
                }
            }
            narenjak = 0;
        }

        player1_bullet->X = -1;
        player1_bullet->Y = -1;
        *player1bulletmoving = FALSE;
        *x = 0;
    }
    else if(zamin[player1_bullet->Y][player1_bullet->X + 1] == '2')
    {
        player1_bullet->X = -1;
        player1_bullet->Y = -1;
        *player1bulletmoving = FALSE;
        *x = 0;                            
        if(shot==5)
        {
            gamer2.health=gamer2.health-2;
            countershotdoganeh++;
            if(countershotdoganeh==5)
            {
                countershotdoganeh=0;
                shot=0;
            }    
        }
        else
        {
            gamer2.health--;
            if(narenjak==1)
            {
                narenjak=0;
            }
            if(gamer2.health==0){
                                                                                puser2->info.lose++;
                                    puser1->info.win++;
              
                zamin1=1;
            }
        }                                               
    }
    else if(zamin[player1_bullet->Y][player1_bullet->X + 1] == '1')
    {
        player1_bullet->X = -1;
        player1_bullet->Y = -1;
        *player1bulletmoving = FALSE;
        *x = 0;
        gamer1.health--;
        if(gamer1.health==0){
            zamin1=1;
                                                                             puser1->info.lose++;
                                    puser2->info.win++;
        }                            
    }                        
    if (player1_bullet->X >= width) 
    {
        *player1bulletmoving = FALSE;
        player1_bullet->X = -1;
        player1_bullet->Y = -1;
        *x = 0;            
    }
}


COORD shot_a(COORD* player1_bullet, char zamin[30][99] , int* ajazeh, int width, BOOL* player1bulletmoving , int* x,struct lasami* puser1 ,struct lasami* puser2 ){
    if (player1_bullet->X != -1 && zamin[player1_bullet->Y][player1_bullet->X - 1 ] != -37 && zamin[player1_bullet->Y][player1_bullet->X - 1 ] != '2' && zamin[player1_bullet->Y][player1_bullet->X - 1 ] != '1' && rooh1==FALSE ) 
    {            
        if (zamin[player1_bullet->Y][player1_bullet->X - 1] == -70)
        {
            if(narenjak==1){
                miror[i]=(COORD){player1_bullet->Y,player1_bullet->X-1};
                i++;
                for(int i = player1_bullet->Y -1 ; i<= player1_bullet->Y+1 ; i++){
                    for(int j= player1_bullet->X-1 ; j<= player1_bullet->X+1;j++){
                        if(zamin[i][j]=='2' || zamin[i][j]=='1')
                        {
                            if(zamin[i][j]=='1')
                            {
                                gamer1.health--;
                                if(gamer1.health==0)
                                {                                                                  puser1->info.lose++;
                                    puser2->info.win++;
                                    zamin1=1;
                                }
                            }
                            if(zamin[i][j]=='2')
                            {
                                gamer2.health--;
                                if(gamer2.health==0)
                                {                                                                puser2->info.lose++;
                                    puser1->info.win++;
                                    zamin1=1;

                                }
                            }

                        }
                    }
                }                 
                player1_bullet->X = -1;
                player1_bullet->Y = -1;                        
                *player1bulletmoving = FALSE;
                *x=0;
                narenjak=0;
                *ajazeh=2;
                return miror[i-1];               
                    
            }
            else if(narenjak==0)
            {
                if(zamin[player1_bullet->Y][player1_bullet->X + 1] != -37 && zamin[player1_bullet->Y][player1_bullet->X + 1] != -70 && zamin[player1_bullet->Y][player1_bullet->X + 1 ] != '2' && zamin[player1_bullet->Y][player1_bullet->X+1]!='1') {
                player1_bullet->X++;
                *ajazeh =3;
            }
            else if(zamin[player1_bullet->Y][player1_bullet->X - 1] == -70){
                player1_bullet->X--;
                *ajazeh=2;
            } 
            else if(zamin[player1_bullet->Y][player1_bullet->X - 1] == -37){
                player1_bullet->X = -1;
                player1_bullet->Y = -1;
                *player1bulletmoving = FALSE;                    
                *x = 0;
                *ajazeh=3;

            }
            else if(zamin[player1_bullet->Y][player1_bullet->X + 1 ] == '2'){
                player1_bullet->X = -1;
                player1_bullet->Y = -1;
                gamer2.health--;
                *player1bulletmoving = FALSE;                    
                *x = 0;
                if(shot==5)
                {
                    gamer2.health=gamer2.health-2 ;
                    countershotdoganeh++;
                    if(countershotdoganeh==5)
                    {
                        countershotdoganeh=0;
                        shot = 0;
                    }
                }
                else if(shot!=5)
                {
                    gamer2.health-- ;                        
                }                
                        
                if(gamer2.health==0)
                {
                    zamin1=1;
                                                                puser2->info.lose++;
                                    puser1->info.win++;
                }
            }
                else if(zamin[player1_bullet->Y][player1_bullet->X + 1] == '1') 
                {
                    player1_bullet->X = -1;
                    player1_bullet->Y = -1;
                    *player1bulletmoving = FALSE;
                    *x = 0;                            
                    if(shot==5)
                    {
                        gamer1.health-=2 ;
                        countershotdoganeh++;
                        if(countershotdoganeh==5)
                        {
                            countershotdoganeh=0;
                            shot = 0;
                        }
                    }
                    else if(shot != 5)
                    {
                        gamer1.health=gamer1.health-1 ;
                        
                    }                                        
                    if(gamer1.health==0)
                    {
                        zamin1=1;
                                                                                         puser1->info.lose++;
                                    puser2->info.win++;                               
                    }                                 
                }              
    
        }
        }
            else if(zamin[player1_bullet->Y][player1_bullet->X - 1] != -70){
                player1_bullet->X--;
            }                                                
    }
    else if(rooh1==TRUE)
    {
        player1_bullet->X--;

    }        

            else if(zamin[player1_bullet->Y][player1_bullet->X  -1 ] == -37 )
            {
                if(narenjak==1)
                {
                    for(int i = player1_bullet->Y -2 ; i <= player1_bullet->Y+2 ; i++ ){
                        for(int j = player1_bullet->X -2 ; j <= player1_bullet->X +2 ; j++){
                            if(zamin[i][j] == '2')
                            {
                                gamer2.health--;                        
                                if(gamer2.health==0)
                                {                                                                puser2->info.lose++;
                                    puser1->info.win++;
                                    zamin1=1;
                                    //return;
                                }
                            }
                            if(zamin[i][j] == '1')
                            {
                                gamer1.health--;
                                if(gamer1.health==0)
                                {                                                                  puser1->info.lose++;
                                    puser2->info.win++;
                                    zamin1=1;
                                //   return;
                                }
                            }
                        }
                    }
                    narenjak = 0;
                }
                player1_bullet->X = -1;
                player1_bullet->Y = -1;
                *player1bulletmoving = FALSE;
                *x = 0;
    
            }
            else if(zamin[player1_bullet->Y][player1_bullet->X  -1 ] == '2' ){
                player1_bullet->X = -1;
                player1_bullet->Y = -1;
                *player1bulletmoving = FALSE;
                *x = 0;
                if(shot==5)
                {
                    gamer2.health=gamer2.health-2;
                    countershotdoganeh++;
                    if(countershotdoganeh==5)
                    {
                        countershotdoganeh=0;
                        shot=0;
                    }    
                }                
                else
                    {
                        gamer2.health--;
                        if(narenjak==1)
                        {
                            narenjak=0;
                        }
                        if(gamer2.health==0){
                            zamin1=1;
                                                                                     puser2->info.lose++;
                                    puser1->info.win++;
                        }
                    }                          
                
            }
            else if(zamin[player1_bullet->Y][player1_bullet->X  -1 ] == '1' ){
                player1_bullet->X = -1;
                player1_bullet->Y = -1;
                *player1bulletmoving = FALSE;
                *x = 0;
                gamer1.health--;
                if(gamer1.health==0){
                    zamin1=1;
                                                                                   puser1->info.lose++;
                                    puser2->info.win++;
                    
                }

            }
            if (player1_bullet->X >= width || player1_bullet->X < 0 ) {
                *player1bulletmoving = FALSE;
                player1_bullet->X = -1;
                player1_bullet->Y = -1;
                *x = 0;
            }   

}

