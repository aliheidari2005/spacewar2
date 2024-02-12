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
    FILE* history;
    history = fopen("E:\\Ali\\sanati\\programing\\paianterm\\histori.bin","r+b");
    if (history == NULL) {
        history = fopen("E:\\Ali\\sanati\\programing\\paianterm\\histori.bin", "w+b");
    }
    
}


void saveData(struct lasami* phead)
{
    FILE *pFile;
    pFile = fopen("E:\\Ali\\sanati\\programing\\paianterm\\asami.bin", "wb");
    while(phead)
    {

            fwrite(&phead->info, sizeof(struct asami), 1, pFile);
        
        phead = phead->pnext;
    }
}




COORD moveDirection(COORD position, int dx, int dy) {
        // Check if the next position is not a wall            
                position.X += dx;
                position.Y += dy;
                return position;
}


BOOL keyPressed(int key) {
    //This function returns a short integer that indicates whether a particular key is pressed or not.
    return GetAsyncKeyState(key);
    //returns a non-zero value if the key is currently pressed. If not, it will return 0.
}

typedef struct mygamer
{
    int health ;
    int shot ;

}mygamer;

mygamer gamer1;
mygamer gamer2;


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
                        //win_player1();
                        //lose_player2();
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
                        /*win_player2();
                        lose_player1();                                
                    */
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
                    //win_player2();
                    //lose_player1();
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


COORD shot_i(COORD* player2_bullet, char zamin[30][99] , int* ajazeh2, int height , BOOL* player2bulletmoving , int* y,struct lasami* puser1 ,struct lasami* puser2 ) {
    if (player2_bullet->Y != -1 && zamin[player2_bullet->Y -1][player2_bullet->X ] != -37 && zamin[player2_bullet->Y -1][player2_bullet->X ] != '2' && zamin[player2_bullet->Y -1][player2_bullet->X ] != '1' ) 
    {            
        if (zamin[player2_bullet->Y - 1][player2_bullet->X] == -70)
        {
            if(narenjak==1)
            {
                miror[i]= (COORD) {player2_bullet->Y-1,player2_bullet->X};
                i++;
                
                //return player1_bullet ;
                // پاک کردن ایینه 
                for(int i = player2_bullet->Y-2 ; i<= player2_bullet->Y+1 ; i++) {
                    for(int j= player2_bullet->X-1 ; j<= player2_bullet->X+1;j++) {
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
                            else if(zamin[i][j]=='2')
                            {
                                gamer2.health--;
                                if(gamer2.health==0)
                                {
                                                                puser2->info.lose++;
                                    puser1->info.win++;
                                }
                            }
                            else if(zamin[i][j]=='2' && zamin[i][j]=='1')
                            {
                                gamer1.health--;
                                if(gamer1.health==0)
                                {
                                                                  puser1->info.lose++;
                                    puser2->info.win++;
                                }                                
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
                player2_bullet->X = -1;
                player2_bullet->Y  = -1;
                *player2bulletmoving = FALSE;
                *y=0;
                narenjak=0;
                *ajazeh2=4;
                return miror[i-1];      
            }
            else if(narenjak==0)
            {
                if(zamin[player2_bullet->Y +1 ][player2_bullet->X] != -37 && zamin[player2_bullet->Y +1 ][player2_bullet->X] != -70 && zamin[player2_bullet->Y +1 ][player2_bullet->X] != '2' && zamin[player2_bullet->Y +1 ][player2_bullet->X] != '1') 
                {
                    player2_bullet->Y++;
                    *ajazeh2=1;
                    
                }
            
                else if(zamin[player2_bullet->Y +1 ][player2_bullet->X ] == -70)
                {
                    player2_bullet->Y--;
                    *ajazeh2=4;
                } 
                else if(zamin[player2_bullet->Y +1][player2_bullet->X ] == -37)
                {
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *player2bulletmoving = FALSE;
                    *y=0;
                    *ajazeh2=1;
                }
                
                else if(zamin[player2_bullet->Y +1][player2_bullet->X ] == '1')
                {
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *player2bulletmoving = FALSE;
                    *y=0;                    
                   // *ajazeh=0;

                    if(shot==5)
                    {
                        gamer1.health=gamer1.health-2 ;
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
                            
                else if(zamin[player2_bullet->Y +1][player2_bullet->X ] == '2')
                {
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *player2bulletmoving = FALSE;
                    *y=0;
                    //*ajazeh=0;

                    if(shot==5)
                    {
                     //   gamer1.shot-- ;
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
                        gamer2.health=gamer2.health-1 ;
                        
                    } 
                    if(gamer2.health==0)
                    {
                        system("cls");
                        zamin1=1;
                                                                                puser2->info.lose++;
                                    puser1->info.win++;
                    }                              
                }                       
            }
        }
        else if(zamin[player2_bullet->Y+1][player2_bullet->X ] != -70)
        {
            player2_bullet->Y--;
        }                                                
    }
    else if(zamin[player2_bullet->Y -1][player2_bullet->X ] == -37 )
    {

        player2_bullet->X = -1;
        player2_bullet->Y = -1;
        *player2bulletmoving = FALSE;
        *y=0;
        if(narenjak==1)
        {
            for(int i = player2_bullet->Y -3 ; i <= player2_bullet->Y+1 ; i++ ){
                for(int j = player2_bullet->X -2 ; j <= player2_bullet->X -2 ; j++){
                    if(zamin[i][j] == '2')
                    {
                        gamer1.health--;                        
                    }
                }
            }
            narenjak = 0;
        }
    }
    else if(rooh2==TRUE)
    {
        player2_bullet->Y--;
        if(zamin[player2_bullet->Y-1][player2_bullet->X]=='2')
        {
            player2_bullet->X=-1;
            player2_bullet->Y=-1;
            *player2bulletmoving = FALSE;            
            *y=0;
            gamer2.health--;
            if(gamer2.health==0)
            {                                                                puser2->info.lose++;
                                    puser1->info.win++;
                zamin1=1;
            }
        }
    }





    else if(zamin[player2_bullet->Y -1][player2_bullet->X ] == '2')
    {
        player2_bullet->X = -1;
        player2_bullet->Y = -1;
        *player2bulletmoving = FALSE;
        *y=0;
        gamer2.health--;
        if(narenjak==1)
        {
            narenjak=0;
        }
        if(gamer2.health==0)
        {                                                                puser2->info.lose++;
                                    puser1->info.win++;
        }                           
            
    }
    else if(zamin[player2_bullet->Y -1][player2_bullet->X ] == '1')
    {
        player2_bullet->X = -1;
        player2_bullet->Y = -1;
        *player2bulletmoving = FALSE;
        *y=0;
        gamer1.health--;
        if(gamer1.health==0)
        {
                                                                              puser1->info.lose++;
                                    puser2->info.win++;
        }                       
    }
    if (player2_bullet->Y >= height || player2_bullet->Y < 0 ) 
    {
        *player2bulletmoving = FALSE;
        player2_bullet->X = -1;
        player2_bullet->Y = -1;
        *y=0;
    }

}

COORD shot_k(COORD* player2_bullet, char zamin[30][99] , int* ajazeh2, int height , BOOL* player2bulletmoving , int* y,struct lasami* puser1 ,struct lasami* puser2 ){

   if (player2_bullet->X != -1 && zamin[player2_bullet->Y +1][player2_bullet->X ] != -37 && zamin[player2_bullet->Y +1][player2_bullet->X ] != '2'&& zamin[player2_bullet->Y +1][player2_bullet->X ] != '1' && rooh2 == FALSE ) 
    {            
        if (zamin[player2_bullet->Y + 1][player2_bullet->X] == -70)
        {
            if(narenjak==1)
            {
                miror[i]= (COORD) {player2_bullet->Y+1,player2_bullet->X};
                i++;                
                // پاک کردن ایینه 
                for(int i = player2_bullet->Y ; i<= player2_bullet->Y+2 ; i++){
                    for(int j= player2_bullet->X-1 ; j<= player2_bullet->X+1;j++){
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
                player2_bullet->X = -1;
                player2_bullet->Y = -1;                        
                *player2bulletmoving = FALSE;
                *y=0;
                narenjak=0;
                *ajazeh2=4;
                return miror[i-1];      

            }

            else if(narenjak==0)
            {
                if(zamin[player2_bullet->Y -1 ][player2_bullet->X] != -37 && zamin[player2_bullet->Y -1 ][player2_bullet->X] != -70 && zamin[player2_bullet->Y -1 ][player2_bullet->X] != '2' && zamin[player2_bullet->Y -1 ][player2_bullet->X] != '1') 
                {   
                    player2_bullet->Y --;
                    *ajazeh2=4;
                }
                else if(zamin[player2_bullet->Y -1 ][player2_bullet->X ] == -70){
                    player2_bullet->Y++;
                    *ajazeh2=1;
                } 
                else if(zamin[player2_bullet->Y -1][player2_bullet->X ] == -37){
                    *player2bulletmoving = FALSE;
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *y=0;                   
                    *ajazeh2=4;

                }
                else if(zamin[player2_bullet->Y -1 ][player2_bullet->X] == '2')
                {
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *player2bulletmoving = FALSE;
                    *y=0;                   
                    if(shot2==5)
                    {
                        gamer2.health=gamer2.health-2 ;
                        countershotdoganeh2++;
                        if(countershotdoganeh2==5)
                        {
                            countershotdoganeh2=0;
                            shot2 = 0;
                        }
                    }
                    else if(shot2!=5)
                    {
                        gamer2.health=gamer2.health-1 ;                        
                    }
                    if(gamer2.health==0)
                    {
                                                                                  puser2->info.lose++;
                                    puser1->info.win++;
                    }                            
                }
                else if(zamin[player2_bullet->Y -1 ][player2_bullet->X] == '1'){
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *player2bulletmoving = FALSE;
                    *y=0;
                    if(shot2==5)
                    {
                        gamer1.health-=2 ;
                        countershotdoganeh2++;
                        if(countershotdoganeh2==5)
                        {
                            countershotdoganeh2=0;
                            shot2 = 0;
                        }
                    }
                    else if(shot2 != 5)
                    {
                        gamer1.health=gamer1.health-1 ;
                        
                    }   
                    
                                       
                    if(gamer1.health==0){
                                                                                      puser1->info.lose++;
                                    puser2->info.win++;                              
                    }                            
                }                           
        }
    }
            else if(zamin[player2_bullet->Y+1][player2_bullet->X ] != -70)
            {
                player2_bullet->Y++;
            }

}

    else if(rooh2==TRUE)
    {
        player2_bullet->Y++;

    }    
            else if(zamin[player2_bullet->Y +1][player2_bullet->X ] == -37 )
            {
                if(narenjak==1)
                {
                    for(int i = player2_bullet->Y -2 ; i <= player2_bullet->Y+2 ; i++ ){
                        for(int j = player2_bullet->X -2 ; j <= player2_bullet->X +2 ; j++){
                            if(zamin[i][j] == '2')
                            {
                                gamer2.health--;                        
                                if(gamer2.health==0)
                                {
                                                                                     puser2->info.lose++;
                                    puser1->info.win++;               //return;
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
                player2_bullet->X = -1;
                player2_bullet->Y = -1;
                *player2bulletmoving = FALSE;
                *y=0;
}
            else if(zamin[player2_bullet->Y +1][player2_bullet->X ] == '2' )
            {
                player2_bullet->X = -1;
                player2_bullet->Y = -1;
                *player2bulletmoving = FALSE;
                *y=0;
                if(shot2==5)
                {
                    gamer2.health=gamer2.health-2;
                    countershotdoganeh2++;
                    if(countershotdoganeh2==5)
                    {
                        countershotdoganeh2=0;
                        shot2=0;
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
            else if(zamin[player2_bullet->Y +1][player2_bullet->X ] == '1' )
            {
                player2_bullet->X = -1;
                player2_bullet->Y = -1;
                *player2bulletmoving = FALSE;
                gamer1.health--;
                *y=0;
                if(gamer1.health==0)
                {
                                                                                   puser1->info.lose++;
                                    puser2->info.win++;
                }
            }                   
            if (player2_bullet->Y >= height || player2_bullet->Y < 0 ) {
                *player2bulletmoving = FALSE;
                player2_bullet->X = -1;
                player2_bullet->Y = -1;
                *y=0;
                //*ajazeh = 0;
}
}

COORD shot_l(COORD* player2_bullet, char zamin[30][99] , int* ajazeh2, int height , BOOL* player2bulletmoving , int* y,struct lasami* puser1 ,struct lasami* puser2 ){
    if (player2_bullet-> X != -1 && zamin[player2_bullet->Y][player2_bullet->X +1 ] != -37 && zamin[player2_bullet->Y][player2_bullet->X +1 ] != '2' && zamin[player2_bullet->Y][player2_bullet->X +1 ] != '1'&& rooh2== FALSE ) 
    {            
        if (zamin[player2_bullet->Y][player2_bullet->X + 1] == -70)
        {
            if(narenjak==1)
            {

                miror[i]= (COORD) {player2_bullet->Y,player2_bullet->X+1};
                i++;

                for(int i = player2_bullet->Y -1 ; i<= player2_bullet->Y+1 ; i++){
                    for(int j= player2_bullet->X-1 ; j<= player2_bullet->X+1;j++){
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

                player2_bullet->X = -1;
                player2_bullet->Y = -1;                        
                *player2bulletmoving = FALSE;
                *y=0;
                narenjak=0;
                *ajazeh2=3;
                return miror[i-1];  
            }
            else if(narenjak==0)
            {

                if(zamin[player2_bullet->Y][player2_bullet->X - 1] != -37 && zamin[player2_bullet->Y][player2_bullet->X - 1] != -70 && zamin[player2_bullet->Y][player2_bullet->X -1 ] != '2' && zamin[player2_bullet->Y][player2_bullet->X  -1 ] != '1'  ) 
                {
                    player2_bullet->X--;
                    *ajazeh2=2;
                }
                else if(zamin[player2_bullet->Y][player2_bullet->X - 1] == -70){
                    player2_bullet->X++;
                    *ajazeh2=3;
                }
                else if(zamin[player2_bullet->Y][player2_bullet->X - 1] == -37){
                    *player2bulletmoving = FALSE;
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *y= 0;
                    *ajazeh2=2;

                }
                else if(zamin[player2_bullet->Y][player2_bullet->X - 1] == '2'){
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *player2bulletmoving = FALSE;
                    *y = 0;
                    if(shot2==5)
                    {
                        gamer2.health=gamer2.health-2 ;
                        countershotdoganeh++;
                        if(countershotdoganeh2==5)
                        {
                            countershotdoganeh2=0;
                            shot2 = 0;
                        }
                    }      
                    else if(shot2!=5)
                    {
                        gamer2.health-- ;                        
                    }
                    if(gamer2.health==0)
                    {                                    puser2->info.lose++;
                                    puser1->info.win++;
                        zamin1=1;
                      
                    }                                                                    
                }
                else if(zamin[player2_bullet->Y][player2_bullet->X - 1] == '1') {
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *player2bulletmoving = FALSE;
                    *y = 0;                            
                    if(shot2==5)
                    {
                        gamer1.health-=2 ;
                        countershotdoganeh2++;
                        if(countershotdoganeh2==5)
                        {
                            countershotdoganeh2=0;
                            shot2 = 0;
                        }
                    }
                    else if(shot2 != 5)
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
                else if(zamin[player2_bullet->Y][player2_bullet->X + 1] != -70){
                    player2_bullet->X++;
                }                                                
        }
            else if(rooh2==TRUE)
    {
        player2_bullet->X++;

    }       
                else if(zamin[player2_bullet->Y][player2_bullet->X +1 ] == -37 ){

       if(narenjak==1)
        {
            for(int i = player2_bullet->Y -2 ; i <= player2_bullet->Y+2 ; i++ ){
                for(int j = player2_bullet->X -2 ; j <= player2_bullet->X +2 ; j++){
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


                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *player2bulletmoving = FALSE;
                    *y = 0;
                }
                else if(zamin[player2_bullet->Y][player2_bullet->X + 1] == '2'){
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *player2bulletmoving = FALSE;
                    *y = 0;            
        if(shot2==5)
        {
            gamer2.health=gamer2.health-2;
            countershotdoganeh2++;
            if(countershotdoganeh2==5)
            {
                countershotdoganeh2=0;
                shot2=0;
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
                else if(zamin[player2_bullet->Y][player2_bullet->X + 1] == '1'){
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *player2bulletmoving = FALSE;
                    gamer1.health--;
                    *y = 0;
                    if(gamer1.health==0){
                                                                                   puser1->info.lose++;
                                    puser2->info.win++;
                    }                            
                }                        
                if (player2_bullet->X >= width) {
                    *player2bulletmoving = FALSE;
                    player2_bullet->X = -1;
                    player2_bullet->Y = -1;
                    *y = 0;            
                }

}


void shot_j(COORD* player2_bullet, char zamin[30][99] , int* ajazeh2, int height , BOOL* player2bulletmoving , int* y,struct lasami* puser1 ,struct lasami* puser2 ){
                if (player2_bullet->X != -1 && zamin[player2_bullet->Y][player2_bullet->X - 1 ] != -37 && zamin[player2_bullet->Y][player2_bullet->X - 1 ] != '2' && zamin[player2_bullet->Y][player2_bullet->X - 1 ] != '1' ) {            
                    if (zamin[player2_bullet->Y][player2_bullet->X - 1] == -70){
                        if(zamin[player2_bullet->Y][player2_bullet->X + 1] != -37 && zamin[player2_bullet->Y][player2_bullet->X + 1] != -70 && zamin[player2_bullet->Y][player2_bullet->X + 1 ] != '2') {
                            player2_bullet->X++;
                            *ajazeh2 =3;
                        }
                        else if(zamin[player2_bullet->Y][player2_bullet->X + 1] == -70){
                            player2_bullet->X--;
                            *ajazeh2=2;
                        } 
                        else if(zamin[player2_bullet->Y][player2_bullet->X + 1] == -37){
                            player2_bullet->X = -1;
                            player2_bullet->Y = -1;
                            *player2bulletmoving = FALSE;                    
                            *y = 0;
                        
                        }
                        else if(zamin[player2_bullet->Y][player2_bullet->X + 1 ] == '2'){
                            player2_bullet->X = -1;
                            player2_bullet->Y = -1;
                            gamer2.health--;
                            *player2bulletmoving = FALSE;                    
                            *y = 0;
                            if(gamer2.health==0){
                                                                                            puser2->info.lose++;
                                    puser1->info.win++;
                            }
                        }
                    }
                        else if(zamin[player2_bullet->Y][player2_bullet->X - 1] != -70){
                            player2_bullet->X--;
                        }                                                
                }
                        else if(zamin[player2_bullet->Y][player2_bullet->X  -1 ] == -37 ){
                            player2_bullet->X = -1;
                            player2_bullet->Y = -1;
                            *player2bulletmoving = FALSE;
                            *y = 0;
              
                        }
                        else if(zamin[player2_bullet->Y][player2_bullet->X  -1 ] == '2' ){
                            player2_bullet->X = -1;
                            player2_bullet->Y = -1;
                            *player2bulletmoving = FALSE;
                            *y = 0;
                            gamer2.health--;
                            if(gamer2.health == 0){
                                                                                             puser2->info.lose++;
                                    puser1->info.win++;
                            }
                        }
                        else if(zamin[player2_bullet->Y][player2_bullet->X  -1 ] == '1' ){
                            player2_bullet->X = -1;
                            player2_bullet->Y = -1;
                            *player2bulletmoving = FALSE;
                            *y = 0;
                            gamer1.health--;
                            if(gamer1.health==0){
                                                                                               puser1->info.lose++;
                                    puser2->info.win++;
                                
                            }

                        }
                        if (player2_bullet->X >= width || player2_bullet->X < 0 ) {
                            *player2bulletmoving = FALSE;
                            player2_bullet->X = -1;
                            player2_bullet->Y = -1;
                            *y = 0;
                        }   
}



int playgame(struct lasami* puser1 ,struct lasami* puser2 ) {

//    int tir =2;
    int tir1;
    int tir2;
    int x = 0;
    int y = 0;
    int life = 0;
    int ajazeh = 3;
    int ajazeh2 = 3;
    int height = 30;
    char zamin[30][99] = { 0 };
    gamer1.health = 3;
    gamer2.health = 3;
    COORD player1_pos = { 7, 15 };
    COORD player2_pos = { 91, 15 };
    COORD player1_bullet = { -1 , -1 };
    COORD player2_bullet = { -1, -1 };
    COORD lastplayer1move = { 7 , 15 };
    COORD lastplayer2move = { 91 , 15 };
    BOOL player1bulletmoving = FALSE ; 
    BOOL player2bulletmoving = FALSE ; 

    //DWORD stands for “Double Word” and is used to represent 32-bit unsigned integers
    DWORD bytes_written;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    
    
    
    while (1) {
        srand(time(NULL));
        // Clear screen
        system("cls");

        // Input handling for Player 1
        if (keyPressed(PLAYER1_UP)) 
        {
            if(zamin[(player1_pos.Y)-1][(player1_pos.X)] != -37 && zamin[(player1_pos.Y)-1][(player1_pos.X)] != -70 && rooh1==FALSE) 
            {
                        if (zamin[(player1_pos.Y)-1][(player1_pos.X)] == 64)
                        {
                            player1_pos.Y = 15;
                            player1_pos.X = 7;
                            lastplayer1move = moveDirection(player1_pos, 0, -1);
                            gamer1.health--;
                        }
                        else if(zamin[(player1_pos.Y)-1][(player1_pos.X)] == 36 )
                        {
                            if (player1_pos.X == 12)
                            {
                                player1_pos.Y = 26;
                                player1_pos.X = 86;
                                lastplayer1move = moveDirection(player1_pos, 0, -1);
                            }
                            else if (player1_pos.X == 86)
                            {
                                player1_pos.Y = 26 ;
                                player1_pos.X = 12 ;
                                lastplayer1move = moveDirection(player1_pos, 0, -1);
                            }
                        }
                        else if (zamin[(player1_pos.Y)-1][(player1_pos.X)] == 42 )
                        {
                            life =1;
                            player1_pos = moveDirection(player1_pos, 0 , -1);
                            gamer1.health+=5;
                            // ajazeh=4;

                        }
                        else if (zamin[(player1_pos.Y)-1][(player1_pos.X)] == '2'){
                        
                        
                        }
                        ///
                        else if(zamin[(player1_pos.Y)-1][(player1_pos.X)] == '#'){
                        
                            //if (counterooh <= 7){ 
                                player1_pos = moveDirection(player1_pos,0,-1);
                                lastplayer1move = moveDirection(player1_pos, 0, -1);
                                counterooh++;
                                rooh1 = TRUE ;
                                ajazeh=4;

                                /*if(counterooh > 7) {
                                    rooh = FALSE;
                                }*/
                            //}
                        }
                        else if(zamin[(player1_pos.Y)-1][(player1_pos.X)] == '%'){ 
                            if(player1_pos.X==28)
                            {   
                                tir1 =1;
                                shot =5;
                            }
                            else if (player1_pos.X ==70)
                            {
                                tir2 = 2 ; 
                                shot = 5;
                            }
                            player1_pos = moveDirection(player1_pos,0,-1);
                            lastplayer1move = moveDirection(player1_pos, 0, -1);                        
                            gamer1.shot=gamer1.shot+5;
                            
                        }
                        else if(zamin[(player1_pos.Y)-1][(player1_pos.X)] == '!')
                        {
                        
                            narenjak = 1 ;
                            player1_pos = moveDirection(player1_pos,0,-1);
                            lastplayer1move = moveDirection(player1_pos, 0, -1);  
                            
                        }
                        else 
                        {                    
                            lastplayer1move = moveDirection(player1_pos, 0, -1);
                            player1_pos = moveDirection(player1_pos, 0, -1);
                            if(player1bulletmoving == FALSE)
                            {
                                ajazeh = 4;
                            }
                        }

            }////
            else if(rooh1== TRUE)
            {
                if(counterooh <= 7 )
                {
                    lastplayer1move = moveDirection(player1_pos, 0, -1);
                    player1_pos = moveDirection(player1_pos, 0, -1);
                    counterooh++;
                    if(counterooh==7)
                    {
                        rooh1=FALSE;
                        counterooh=0;
                    }
                }

            }

            else if(zamin[(player1_pos.Y)-1][(player1_pos.X)] == -37 || zamin[(player1_pos.Y)-1][(player1_pos.X)] == -70 ) 
            {
            
            }
        
        }
    
        if (keyPressed(PLAYER1_DOWN)) {

            if(zamin[(player1_pos.Y)+1][(player1_pos.X)] != -37 && zamin[(player1_pos.Y)+1][(player1_pos.X)] != -70 && rooh1==FALSE) 
            {
                
                if (zamin[(player1_pos.Y)+1][(player1_pos.X)] == 64)
                {
                    player1_pos.Y = 15;
                    player1_pos.X = 7;
                    lastplayer1move = moveDirection(player1_pos, 0, +1);                        
                    gamer1.health--;
                }
                else if (zamin[(player1_pos.Y)+1][(player1_pos.X)] == 36){
                    if (player1_pos.X == 12){
                        player1_pos.Y = 28;
                        player1_pos.X = 86;
                        lastplayer1move = moveDirection(player1_pos, 0, +1);                        

                    }
                else if (player1_pos.X == 86){
                    player1_pos.Y = 28 ;
                    player1_pos.X = 12 ;
                    lastplayer1move = moveDirection(player1_pos, 0, +1);                        

                }
            }
                else if (zamin[(player1_pos.Y)+1][(player1_pos.X)] == 42)
                {
                    life = 1;
                    player1_pos = moveDirection(player1_pos, 0 , 1);
                    gamer1.health+=5;                     ///// اضاقه کردن قلب به کاربر
                }
                else if (zamin[(player1_pos.Y)+1][(player1_pos.X)] == '2'){
        
                }
                else if(zamin[(player1_pos.Y)+1][(player1_pos.X)] == '#'){
                    //if (counterooh <= 7) {
                        player1_pos = moveDirection(player1_pos,0 ,+1);
                        lastplayer1move = moveDirection(player1_pos, 0, +1);
                        counterooh++;
                        rooh1 = TRUE ;
                        ajazeh=1;

                        /*if(counterooh > 7) {
                        rooh = FALSE;
                    }*/
                    //}
                }
                else if(zamin[(player1_pos.Y)+1][(player1_pos.X)] == '%') {
                    if(player1_pos.X==28)
                    { 
                        tir1 =1 ;
                        shot =5;
                    }
                    else if (player1_pos.X ==70)
                    {
                        tir2 = 2 ;
                        shot = 5;
                    }
                    player1_pos = moveDirection(player1_pos,0,1);
                    lastplayer1move = moveDirection(player1_pos, 0, 1);                        
                    gamer1.shot=gamer1.shot+5;
                    
                }
                else if(zamin[(player1_pos.Y)+1][(player1_pos.X)] == '!') 
                {
                    narenjak = 1 ;
                    player1_pos = moveDirection(player1_pos,0,+1);
                    lastplayer1move = moveDirection(player1_pos, 0, +1);  
                    
                }                                        
    
                else 
                {
                    lastplayer1move = moveDirection(player1_pos, 0, 1);
                    player1_pos = moveDirection(player1_pos, 0, 1);
                    if(player1bulletmoving == FALSE)
                    {
                        ajazeh = 1;
                    }
                }
        }
        else if(rooh1== TRUE)
        {
            if(counterooh <= 7 ){
                lastplayer1move = moveDirection(player1_pos, 0, 1);
                player1_pos = moveDirection(player1_pos, 0, 1);
                counterooh++;
                if(counterooh==7)
                {
                    rooh1=FALSE;
                    counterooh=0;
                }
            }

        }                    

    else if(zamin[(player1_pos.Y)+1][(player1_pos.X)] == -37 || zamin[(player1_pos.Y)+1][(player1_pos.X)] == -70)
    {

    }
        
        }

        if (keyPressed(PLAYER1_LEFT)){
         
            if(zamin[(player1_pos.Y)][(player1_pos.X)-1] != -37 && zamin[(player1_pos.Y)][(player1_pos.X)-1] != -70 && rooh1 == FALSE) {
                if (zamin[(player1_pos.Y)][(player1_pos.X)-1] == 64){
                    player1_pos.Y = 15;
                    player1_pos.X = 7;
                    lastplayer1move = moveDirection(player1_pos, -1, 0);
                    gamer1.health--;
               }
                else if (zamin[(player1_pos.Y)][(player1_pos.X)-1] == 36) {
                    if (player1_pos.X == 13){
                        player1_pos.Y = 27;
                        player1_pos.X = 85;
                        lastplayer1move = moveDirection(player1_pos, -1, 0);

                    }
                    else if (player1_pos.X == 87){
                        player1_pos.Y = 27 ;
                        player1_pos.X = 11 ;
                        lastplayer1move = moveDirection(player1_pos, -1, 0);
                    }
                }
                else if (zamin[(player1_pos.Y)][(player1_pos.X)-1] == 42){
                    player1_pos = moveDirection(player1_pos, -1 , 0);
                    //zamin[(player1_pos.Y)][(player1_pos.X)-1] = ' ';
                    life = 1;
                    gamer1.health+=5;
                    ///// اضاقه کردن قلب به کاربر
                }
                else if (zamin[(player1_pos.Y)-1][(player1_pos.X)] == '2'){

                }
                else if(zamin[(player1_pos.Y)][(player1_pos.X)-1] == '#') {
                    if (counterooh <= 7) {
                        player1_pos = moveDirection(player1_pos,-1,0);
                        lastplayer1move = moveDirection(player1_pos, -1, 0);
                        counterooh++;
                        rooh1 = TRUE ;
                            /*if(counterooh > 7) {
                            rooh = FALSE;
                        }*/
                    }
                }
                else if(zamin[(player1_pos.Y)][(player1_pos.X)-1] == '%') {
                    if(player1_pos.X -1==28) tir1 =1 , shot =5;
                    else if (player1_pos.X -1 ==70) tir2 = 2 , shot = 5;
                    player1_pos = moveDirection(player1_pos,-1,0);
                    lastplayer1move = moveDirection(player1_pos, -1, 0);                        
                    gamer1.shot=gamer1.shot+5;
                    
                }
                else if(zamin[(player1_pos.Y)][(player1_pos.X)-1] == '!') 
                {
                    narenjak = 1 ;
                    player1_pos = moveDirection(player1_pos,-1,0);
                    lastplayer1move = moveDirection(player1_pos, -1, 0);  
                    
                }                                
               else{ 
                    lastplayer1move = moveDirection(player1_pos, -1, 0);
                    player1_pos = moveDirection(player1_pos, -1, 0);
                    if(player1bulletmoving == FALSE){
                        ajazeh = 2;
                    }
               }
            }
            else if(rooh1== TRUE){
                if(counterooh <= 7 ){
                    lastplayer1move = moveDirection(player1_pos, -1, 0);
                    player1_pos = moveDirection(player1_pos, -1, 0);
                    counterooh++;
                    if(counterooh==7){
                        rooh1=FALSE;
                        counterooh=0;
                    }
                }

            }            
            else if(zamin[(player1_pos.Y)][(player1_pos.X)-1] == -37 || zamin[(player1_pos.Y)][(player1_pos.X)-1] == -70) {
            }
            
        }
           
        if (keyPressed(PLAYER1_RIGHT)) {

                //move_w(zamin , player1_pos , lastplayer1move  ,ajazeh , life );

            if(zamin[(player1_pos.Y)][(player1_pos.X)+1] != -37 && zamin[(player1_pos.Y)][(player1_pos.X)+1] != -70 && rooh1==FALSE) {
                if (zamin[(player1_pos.Y)][(player1_pos.X)+1] == 64){
                    player1_pos.Y = 15;
                    player1_pos.X = 7;
                    gamer1.health--;
                }
                else if (zamin[(player1_pos.Y)][(player1_pos.X)+1] == 36) {
                    if ((player1_pos.X)+1 == 12){
                        player1_pos.Y = 27;
                        player1_pos.X = 87;
                    }
                    else if((player1_pos.X) == 85){
                        player1_pos.Y = 27 ;
                        player1_pos.X = 13 ;
                    }
                }
                else if (zamin[(player1_pos.Y)][(player1_pos.X)+1] == 42){
                    player1_pos = moveDirection(player1_pos, 1 , 0);
                    //zamin[(player1_pos.Y)][(player1_pos.X)-1] = ' ';
                    gamer1.health+=5;
                    life = 1;            
                }
                else if (zamin[(player1_pos.Y)-1][(player1_pos.X)] == '2'){
                        
                }
                else if(zamin[(player1_pos.Y)][(player1_pos.X)+1] == '#') {
                    if (counterooh <= 7) {
                        player1_pos = moveDirection(player1_pos,1,0);
                        lastplayer1move = moveDirection(player1_pos, 1, 0);
                        counterooh++;
                        rooh1 = TRUE ;
                        //  ajazeh=4;

                        /*if(counterooh > 7) {
                            rooh = FALSE;
                        }*/
                    }
                }  
                else if(zamin[(player1_pos.Y)][(player1_pos.X)+1] == '%') {
                    if(player1_pos.X +1==28) tir1 =1 , shot =5;
                    else if (player1_pos.X+1 ==70) tir2 = 2 , shot = 5;
                    player1_pos = moveDirection(player1_pos,1,0);
                    lastplayer1move = moveDirection(player1_pos, 1, 0);                        
                    gamer1.shot=gamer1.shot+5;
                    
                }
                else if(zamin[(player1_pos.Y)][(player1_pos.X)+1] == '!') 
                {
                    narenjak = 1 ;
                    player1_pos = moveDirection(player1_pos,+1,0);
                    lastplayer1move = moveDirection(player1_pos, +1, 0);  
                    
                }                                              

                else{
                    lastplayer1move = moveDirection(player1_pos, 1, 0);
                    player1_pos = moveDirection(player1_pos, 1, 0);            
                    if(player1bulletmoving == FALSE){
                        ajazeh = 3;
                    }
                    }
            }
            
                        else if(rooh1 == TRUE) {
                            if (counterooh <= 7) {
                                player1_pos = moveDirection(player1_pos,1,0);
                                lastplayer1move = moveDirection(player1_pos, 1, 0);
                                counterooh++;
                                if(counterooh == 7){
                                    rooh1 = FALSE;
                                    counterooh=0;
                                }
                            }
                            
                        }
            else if (zamin[(player1_pos.Y)][(player1_pos.X)+1] == -37 || zamin[(player1_pos.Y)][(player1_pos.X)+1] == -70) {

            }
        }              
       
        if (keyPressed(PLAYER1_SHOOT) && !player1bulletmoving) {

            if(rooh1==TRUE){
                counterooh++;
                if(counterooh==7){
                 rooh1=FALSE;   
                }
            }
            player1_bullet=lastplayer1move;
            //player1_bullet.X = player1_pos.X+lastplayer1move.X;
            //player1_bullet.Y = player1_pos.Y+lastplayer1move.Y;
            if(x == 0){
                player1bulletmoving =  TRUE;
                x=1;
            }
        }

        // Input handling for Player 2
        
        if (keyPressed(PLAYER2_UP)){
            if(zamin[(player2_pos.Y)-1][(player2_pos.X)] != -37 && zamin[(player2_pos.Y)-1][(player2_pos.X)] != -70 && rooh2 ==FALSE) {
                    if (zamin[(player2_pos.Y)-1][(player2_pos.X)] == 64){
                            player2_pos.Y = 15;
                            player2_pos.X = 91;
                            lastplayer2move = moveDirection(player2_pos, 0, -1);
                            gamer2.health--;

                    }
                    else if(zamin[(player2_pos.Y)-1][(player2_pos.X)] == 36 ){
                        if (player2_pos.X == 12){
                            player2_pos.Y = 26;
                            player2_pos.X = 86;
                            lastplayer2move = moveDirection(player2_pos, 0, -1);

                        }
                        else if (player2_pos.X == 86){
                            player2_pos.Y = 26 ;
                            player2_pos.X = 12 ;
                           lastplayer2move = moveDirection(player2_pos, 0, -1);

                        }
                    }
                    else if (zamin[(player2_pos.Y)-1][(player2_pos.X)] == 42 ){
                        //zamin[player2_pos.Y -1 ][player2_pos.X] = ' ';
                        life =1;
                        player2_pos = moveDirection(player2_pos, 0 , -1);
                        gamer2.health+=5;
                        lastplayer2move = moveDirection(player2_pos, 0, -1);
                    
                    }
                    else if (zamin[(player2_pos.Y)-1][(player2_pos.X)] == '1'){
    
                    }
                    else if(zamin[(player1_pos.Y)-1][(player1_pos.X)] == '#'){ 
                        if (counterooh <= 7) 
                        {
                            player2_pos = moveDirection(player2_pos,0,-1);
                            lastplayer2move = moveDirection(player2_pos, 0, -1);
                            counterooh++;
                            rooh2 = TRUE ;
                        }
                    }
                    else if(zamin[(player2_pos.Y)-1][(player2_pos.X)] == '%'){ 
                        if(player2_pos.X==28) tir1 =1 , shot2 =5;
                        else if (player2_pos.X ==70) tir2 = 2 , shot2 = 5;
                        player2_pos = moveDirection(player2_pos,0,-1);
                        lastplayer2move = moveDirection(player2_pos, 0, -1);                        
                        gamer1.shot=gamer1.shot+5;
                        
                    }             
                    else if(zamin[(player2_pos.Y)-1][(player2_pos.X)] == '!'){
                    
                        narenjak = 1 ;
                        player2_pos = moveDirection(player2_pos,0,-1);
                        lastplayer2move = moveDirection(player2_pos, 0, -1);  
                        
                    }                           

                    else{
                        lastplayer2move = moveDirection(player2_pos, 0, -1);
                        player2_pos = moveDirection(player2_pos, 0, -1);
                        if(player2bulletmoving == FALSE){
                            ajazeh2 = 4;
                        }
                    }
    
            }
            else if(rooh2== TRUE)
            {
                if(counterooh <= 7 )
                {
                    lastplayer2move = moveDirection(player2_pos, 0, -1);
                    player2_pos = moveDirection(player2_pos, 0, -1);
                    counterooh++;
                    if(counterooh==7)
                    {
                        rooh2=FALSE;
                        counterooh=0;
                    }
                }

            }
                        
            else if(zamin[(player2_pos.Y)-1][(player2_pos.X)] == -37 || zamin[(player2_pos.Y)-1][(player2_pos.X)] == -70 ) {
            
            }
        }
        
        if (keyPressed(PLAYER2_DOWN)){
            if(zamin[(player2_pos.Y)+1][(player2_pos.X)] != -37 && zamin[(player2_pos.Y)+1][(player2_pos.X)] != -70 && rooh2==FALSE ) {
                if (zamin[(player2_pos.Y)+1][(player2_pos.X)] == 64){
                    player2_pos.Y = 15;
                    player2_pos.X = 91;
                    gamer2.health--;
                }
                else if (zamin[(player2_pos.Y)+1][(player2_pos.X)] == 36){
                        if (player2_pos.X == 12){
                            player2_pos.Y = 28;
                            player2_pos.X = 86;
                        }
                        else if (player2_pos.X == 86){
                            player2_pos.Y = 28 ;
                            player2_pos.X = 12 ;
                        }
                }
                else if (zamin[(player2_pos.Y)+1][(player2_pos.X)] == 42){
                    player2_pos = moveDirection(player2_pos, 0 , 1);
                    zamin[(player2_pos.Y)+1][(player2_pos.X)] = ' ';
                    gamer2.health+=5;                     ///// اضاقه کردن قلب به کاربر
                    life = 1;
                }
                else if (zamin[(player2_pos.Y)-1][(player2_pos.X)] == '1') {
                
                }
                else if(zamin[(player2_pos.Y)+1][(player2_pos.X)] == '#'){
                    if (counterooh <= 7) {
                        player2_pos = moveDirection(player2_pos,0,1);
                        lastplayer2move = moveDirection(player2_pos, 0, 1);
                        counterooh++;
                        rooh2 = TRUE ;
                        /*if(counterooh > 7) {
                        rooh = FALSE;
                    }*/
                    }
                }
                else if(zamin[(player2_pos.Y)+1][(player2_pos.X)] == '%') {
                    if(player2_pos.X==28) tir1 =1 , shot2 =5;
                    else if (player2_pos.X ==70) tir2 = 2 , shot2 = 5;
                    player2_pos = moveDirection(player2_pos,0,1);
                    lastplayer2move = moveDirection(player2_pos, 0, 1);                        
                    gamer1.shot=gamer1.shot+5;
                    
                }
                else if(zamin[(player2_pos.Y)+1][(player2_pos.X)] == '!'){ 
                    narenjak = 1 ;
                    player2_pos = moveDirection(player2_pos,0,+1);
                    lastplayer2move = moveDirection(player2_pos, 0, +1);  
                    
                }                 
                else {
                    lastplayer2move = moveDirection(player2_pos, 0, 1);
                    player2_pos = moveDirection(player2_pos, 0, 1);
                    if(player2bulletmoving == FALSE){
                        ajazeh2 = 1;
                    }
                }
            }
            else if(rooh2== TRUE){
                if(counterooh <= 7 ){
                    lastplayer2move = moveDirection(player2_pos, 0, 1);
                    player2_pos = moveDirection(player2_pos, 0, 1);
                    counterooh++;
                    if(counterooh==7){
                        rooh2=FALSE;
                        counterooh=0;
                    }
                }

            }                        
            
            else if(zamin[(player2_pos.Y)+1][(player2_pos.X)] == -37 || zamin[(player2_pos.Y)+1][(player2_pos.X)] == -70){
            
            }
        }
        
        if (keyPressed(PLAYER2_LEFT)){
            if(zamin[(player2_pos.Y)][(player2_pos.X)-1] != -37 && zamin[(player2_pos.Y)][(player2_pos.X)-1] != -70 && rooh2==FALSE) {
                if (zamin[(player2_pos.Y)][(player2_pos.X)-1] == 64){
                    player2_pos.Y = 15;
                    player2_pos.X = 91;
                    gamer2.health--;
                    lastplayer2move = moveDirection(player2_pos, -1, 0);
                
                }
                else if (zamin[(player2_pos.Y)][(player2_pos.X)-1] == 36) {
                    if (player2_pos.X == 13){
                        player2_pos.Y = 27;
                        player2_pos.X = 85;
                        lastplayer2move = moveDirection(player2_pos, -1, 0);

                    }
                    else if (player2_pos.X == 87){
                        player2_pos.Y = 27 ;
                        player2_pos.X = 11 ;
                        lastplayer2move = moveDirection(player2_pos, -1, 0);

                    }
                }
                else if (zamin[(player2_pos.Y)][(player2_pos.X)-1] == 42){
                    player2_pos = moveDirection(player2_pos, -1 , 0);
                    //zamin[(player2_pos.Y)][(player2_pos.X)-1] = ' ';
                    life = 1;
                    gamer2.health+=5;
                    ///// اضاقه کردن قلب به کاربر
                }
                else if (zamin[(player2_pos.Y)-1][(player2_pos.X)] == '1'){

                }
                else if(zamin[(player2_pos.Y)][(player2_pos.X)-1] == '#') {
                    if (counterooh <= 7) {
                        player2_pos = moveDirection(player2_pos,-1,0);
                        lastplayer2move = moveDirection(player2_pos, -1, 0);
                        counterooh++;
                        rooh2 = TRUE ;
                            /*if(counterooh > 7) {
                            rooh = FALSE;
                        }*/
                    }
                }  
                else if(zamin[(player2_pos.Y)][(player2_pos.X)-1] == '%') {
                    if(player2_pos.X -1==28) tir1 =1 , shot2 =5;
                    else if (player2_pos.X -1 ==70) tir2 = 2 , shot2 = 5;
                    player2_pos = moveDirection(player2_pos,-1,0);
                    lastplayer2move = moveDirection(player2_pos, -1, 0);                        
                    gamer2.shot=gamer2.shot+5;
                    
                }
                else if(zamin[(player2_pos.Y)][(player2_pos.X)-1] == '!') 
                {
                    narenjak = 1 ;
                    player2_pos = moveDirection(player2_pos,-1,0);
                    lastplayer2move = moveDirection(player2_pos, -1, 0);  
                    
                }                                                  
                else{
                    lastplayer2move = moveDirection(player2_pos, -1, 0);
                    player2_pos = moveDirection(player2_pos, -1, 0);
                    if(player2bulletmoving == FALSE){
                        ajazeh2 = 2;
                    }
                }
            }
            else if(rooh2== TRUE){
                if(counterooh <= 7 ){
                    lastplayer2move = moveDirection(player2_pos, -1, 0);
                    player2_pos = moveDirection(player2_pos, -1, 0);
                    counterooh++;
                    if(counterooh==7){
                        rooh2=FALSE;
                        counterooh=0;
                    }
                }
            }                  

            else if(zamin[(player2_pos.Y)][(player2_pos.X)-1] == -37 || zamin[(player2_pos.Y)][(player2_pos.X)-1] == -70) {
            }
        }
        
       if (keyPressed(PLAYER2_RIGHT)){
            if(zamin[(player2_pos.Y)][(player2_pos.X)+1] != -37 && zamin[(player2_pos.Y)][(player2_pos.X)+1] != -70 && rooh1==FALSE ) {
                if (zamin[(player2_pos.Y)][(player2_pos.X)+1] == 64){
                    player2_pos.Y = 15;
                    player2_pos.X = 91;
                    gamer2.health--;
                }
                else if (zamin[(player2_pos.Y)][(player2_pos.X)+1] == 36) {
                    if ((player2_pos.X)+1 == 12){
                        player2_pos.Y = 27;
                        player2_pos.X = 87;
                    }
                    else if((player2_pos.X) == 85){
                        player2_pos.Y = 27 ;
                        player2_pos.X = 13 ;
                    }
                }
                else if (zamin[(player2_pos.Y)][(player2_pos.X)+1] == 42){
                    player2_pos = moveDirection(player2_pos, 0 , 0);
                    //zamin[(player2_pos.Y)][(player2_pos.X)-1] = ' ';
                    gamer2.health+=5;
                    life = 1;            
                }
                else if (zamin[(player2_pos.Y)-1][(player2_pos.X)] == '1'){
                        
                }
                
                else if(zamin[(player2_pos.Y)][(player2_pos.X)+1] == '#') {
                    if (counterooh <= 7) {
                        player2_pos = moveDirection(player2_pos,1,0);
                        lastplayer2move = moveDirection(player2_pos, 1, 0);
                        counterooh++;
                        rooh2 = TRUE ;
                        //  ajazeh=4;

                        /*if(counterooh > 7) {
                            rooh = FALSE;
                        }*/
                    }
                }  
                else if(zamin[(player2_pos.Y)][(player2_pos.X)+1] == '%') {
                    if(player2_pos.X +1==28) tir1 =1 , shot2 =5;
                    else if (player2_pos.X+1 ==70) tir2 = 2 , shot2 = 5;
                    player2_pos = moveDirection(player2_pos,1,0);
                    lastplayer2move = moveDirection(player2_pos, 1, 0);                        
                    gamer2.shot=gamer2.shot+5;
                    
                }
                else if(zamin[(player2_pos.Y)][(player2_pos.X)+1] == '!') 
                {
                    narenjak = 1 ;
                    player2_pos = moveDirection(player2_pos,+1,0);
                    lastplayer2move = moveDirection(player2_pos, +1, 0);  
                    
                }                                              

                else {
                    lastplayer2move = moveDirection(player2_pos, 1, 0);
                    player2_pos = moveDirection(player2_pos, 1, 0);            
                    if(player2bulletmoving == FALSE){
                        ajazeh2 = 3;
                    }
                }
            //    }
            
            }
            else if (zamin[(player2_pos.Y)][(player2_pos.X)+1] == -37 || zamin[(player2_pos.Y)][(player2_pos.X)+1] == -70){

            }

        }
        
        if (keyPressed(PLAYER2_SHOOT) && !player2bulletmoving ){
            player2_bullet = lastplayer2move;
            if(y == 0){
                player2bulletmoving =  TRUE;
                y=1;
            }
        }
    

   // Update bullet positions

        /// last move write 1  
        if (player1bulletmoving && ajazeh == 3 ) 
        {  
            shot_d(&player1_bullet ,zamin , &ajazeh , width , &player1bulletmoving , &x , puser1,puser2 );
                      
        }
        
        ///// last move left 1       
        if(player1bulletmoving && ajazeh == 2 ) 
        {    
               shot_a(&player1_bullet ,zamin , &ajazeh , width , &player1bulletmoving , &x, puser1,puser2 );
            
        }            

        ////////last move down 1         
        if(player1bulletmoving && ajazeh == 1 )
        {            
            shot_s(&player1_bullet ,zamin , &ajazeh , width , &player1bulletmoving , &x, puser1,puser2);
            
        }
        
        /////last movw up  1
        if(player1bulletmoving && ajazeh == 4 ) 
        {    
            shot_w(&player1_bullet ,zamin , &ajazeh , width , &player1bulletmoving , &x, puser1,puser2 );   
        
        }

        //last move up 2
        if (player2bulletmoving && ajazeh2 ==4)
        {    
            shot_i(&player2_bullet ,zamin , &ajazeh2 , width , &player2bulletmoving , &y, puser1,puser2);   
            //zamin[player1_bullet.Y -1 ][player1_bullet.X]=' ';
        }

        // last move down2
        if (player2bulletmoving && ajazeh2 ==1)
        {    
            shot_k(&player2_bullet ,zamin , &ajazeh2 , width , &player2bulletmoving , &y, puser1,puser2);   
            //zamin[player1_bullet.Y -1 ][player1_bullet.X]=' ';
        }
    
        // last move write 2
        if (player2bulletmoving && ajazeh2 ==3)
        {    
            shot_l(&player2_bullet ,zamin , &ajazeh2 , width , &player2bulletmoving , &y, puser1,puser2);   
            //zamin[player1_bullet.Y -1 ][player1_bullet.X]=' ';
        }      

        // move left 2    
        if (player2bulletmoving && ajazeh2 ==2)
        {
            shot_j(&player2_bullet ,zamin , &ajazeh2 , width , &player2bulletmoving , &y, puser1,puser2);   

        }



        // Draw map

/////////////////////////////////////////////////////////////////////////
	/*for(int i = 0 ; i < height ; i++) {
		for(int j = 0 ; j < width ; j++) {
			
				///wall
				if( (i==6  && ((j >=5 && j <= 15 ) || (j<=93 && j>=83)))  || ( i >= 7 && i <= 24 && (j== 15 || j==83)) || (i ==24  && ((j>=5 && j<=15) || (j<=93 && j>=83))) || ((((i >= 7 && i<= 10)  || (i>=20 && i<=23)) && (j==16 || j==82)))  ||  (((i==8 || i==9) || (i==21 || i==22)) && (j==17 || j==81)) || ((j>=35 && j<=43) && (i==22)) || (((i==3 || i==4 || i==5) && (j==29 ||j==69 )) || (i==25 || i==26 || i==27) && (j==29 ||j==69 )) ||  (((i >= 8 && i <= 12) || (i>=16 && i<=20)) && (j==49 || j==49)) || (i==0 || j==0 || i== height-1) || (i==14 && (j==7 || j==91)) || (j==98) || ((j<=63 && j>= 55)&& i==9)   ) {		
					zamin[i][j]=219;	
				}
				///mirror
				else if(( j==49 && i==13) || (j==49 && i==14)|| (j==49 && i==15) || ((i==3 || i==4 || i==5) && (j==30)) || ((i==6 || i==24 )&& (j==4 || j==94)) || ((i==27 || i==26 ||i==25) && j==68 ))   {
					zamin[i][j]=186;	
				}
                else if(i==24 && (j==23)) {	
					zamin[i][j]='@';
				}
                else if(i==8 && j==75){
					zamin[i][j]='@';
                }

				///teleport
				else if(i==27 && (j==12 || j==86)){
					zamin[i][j]='$';
				}
				////health
				else if (i==5 && j==49) {
                    int healthX=i;
                    int healthY=j;


					if(life == 0){
                        zamin[i][j]='*';
                    }
                    else if(life ==1){
                        zamin[i][j]=' ';
                        while(1)
                        {
                             healthX = rand() % 30;
                             healthY = rand() % 99;
                            if(zamin[healthX][healthY] != 219 && zamin[healthX][healthY] != 186 && zamin[healthX][healthY] != '@' && zamin[healthX][healthY] !='$' )
                            {
                                zamin[healthX][healthY]='*';
                               // life = 0 ;
                                break;
                            }
                            else{
                                continue;
                            }

                            }
                    }
                }
                

                else {
                    zamin[i][j]=' ';
                }               
        }
    }*/

///////zamin2 
 
    //if(zamin1==1){
    /*for(int i = 0; i < height ; i++){
        for(int j = 0; j<width ; j++){


				if ( ((i==5 || i==6) && (j==25 || j==73)) || (i==7 && (j==48 || j==49 || j==50 || j==51 || j==52))|| ((i==25 ||i==26) &&(j==26 || j==72))|| (i==0 || j==0 || i== height-1 || j==98) || (i==14 && (j==7 || j==91))|| (i==15 && (j ==33 || j==65))|| (i==14 && (j==34 || j==64) )|| (i==13 && (j==35 ||j==63)) || (i==12 && (j==36||j==62)) || (i==16 &&( j==34 || j==64)) ||(i==17 && (j==35||j==63))|| (i==18 && (j==36 || j==62))|| ( i==15 &&( j == 45 || j == 46 || j==44 || j==54 ||j==53||j==52 || j==43 || j==55 )) || (i==14 && (j==46)) || (i==16 && (j==52)) || (i==13 && (j==47 || j==48 || j==46 || j==49)) || i==17 && (j==51 || j==50 || j== 52 || j==49) || (i==12 && (j==49) ) || (i==18 && (j==49)) || (i==23 && (j==48 || j==49 || j==50 || j==51 || j==52)) ){		
					zamin[i][j]= 219;						
				}
                else if((i>=10 && i<= 20 && j==16) || (i==5 && j==26) || (i==26 && j==27) || (i==6 && j==72) || (i==25 && j==71) || (i>=10 && i<= 20 && j==82) || (i==16 && j==35) || (i==14 && j==63) || (i==15 && j==47) ){
                    zamin[i][j]= 186;                
                    for(int j =0 ; j<i; j++)
                    {
                        zamin[miror[j].X][miror[j].Y]=' ';
                    }
                }

                // siahchal
                else if((i== 16 && j==47) || (i==14 && j==51)) 
                {	
					zamin[i][j]='@';
				}	
				///teleport
				else if(i==27 && (j==12||j==86)) 
                {
					zamin[i][j]='$';
				}
				////health
				else if (i==5 && j==49) 
                {
					if(life == 0) {
                        zamin[5][49]='*';
                    }
                    else if(life ==1) {
                        zamin[i][j]=' ';
                    }                    
                }
                else if(i==15 && j==49)
                {
                    if(rooh2 == FALSE && rooh1 == FALSE){
                        zamin[i][j] = '#';
                    }
                    else if(rooh2 == TRUE || rooh1 == TRUE ) {
                        if( counterooh > 0 && counterooh<8){
                            zamin[i][j] = ' ';
                        }
                    }                    
                }
                
                else if( i==11 && j==28)
                {
                    zamin[i][j]='%';
                    if(tir1==1)
                    {
                        zamin[i][j]=' '; 
                        //tir1 = 0;
                    } 

                }
                else if(i==19 && j==70)
                {
                    zamin[i][j]='%';
                    if(tir2==2)
                    {
                        zamin[i][j]=' ';                         
                        //tir2 = 0;
                    }
                }
                else if(i==21 && j==50)
                {
                    if(narenjak==1)
                    {
                        zamin[i][j]=' '; 
                    }
                    else if(narenjak==0)
                    {
                        zamin[i][j] = '!';
                    }
                }

                else{
                    zamin[i][j]=' ';
                }

        }		

    }*/
    
    
    if(zamin2=2)
    {    
    	for (int i = 0; i <= 24; i++) {
		for (int j = 0; j <= 99; j++) {

			if (i == 0 || i == 29) {
				zamin[i][j] = 219;
			}
			if (j == 0 || j == 98) {
				zamin[i][j] = 219;
			}

			if (i == 1) {

			}
			if (i == 2) {

			}
			if (i == 3) {

			}
			if (i == 4) {
				if (j == 24) {
					zamin[i][j] = '%';
				}
				if (j == 75) {
					zamin[i][j] = '%';
				}
			}
			if (i == 5) {
				if (j >= 11 && j <= 37) {
					zamin[i][j] = 219;
				}
				if (j >= 63 && j <= 88) {
					zamin[i][j] = 219;
				}
			}
			if (i == 6) {

			}
			if (i == 7) {
				if (j >= 70 && j <= 78) {
					zamin[i][j] = 186;
				}

			}
			if (i == 8){

				if (j >= 11 && j <= 13) {
					zamin[i][j] = 219;
				}
				if (j >= 35 && j <= 37) {
					zamin[i][j] = 219;
				}
				if (j >= 68 && j <= 70) {
					zamin[i][j] = 186;
				}
				if (j >= 78 && j <= 80) {
					zamin[i][j] = 186;
				}
				if (j == 10) {
					zamin[i][j] = 186;
				}
				if (j == 34) {
					zamin[i][j] = 186;
				}

			}
			if (i == 9) {
				if (j >= 14 && j <= 16) {
					zamin[i][j] = 219;
				}
				if (j >= 32 && j <= 34) {
					zamin[i][j] = 219;
				}
				if (j >= 66 && j <= 68) {
					zamin[i][j] = 186;
				}
				if (j >= 80 && j <= 82) {
					zamin[i][j] = 186;
				}
				if (j == 13) {
					zamin[i][j] = 186;
				}
				if (j == 31) {
					zamin[i][j] = 186;
				}

			}
			if (i == 10) {

				if (j >= 17 && j <= 19) {
					zamin[i][j] = 219;
				}
				if (j >= 29 && j <= 31) {
					zamin[i][j] = 219;
				}
				if (j >= 64 && j <= 66) {
					zamin[i][j] = 186;
				}
				if (j >= 82 && j <= 84) {
					zamin[i][j] = 186;
				}
				if (j == 16) {
					zamin[i][j] = 186;
				}
				if (j == 28) {
					zamin[i][j] = 186;
				}
			}
			if (i == 11) {

				
				if (j >= 20 && j <= 22) {
					zamin[i][j] = 219;
				}
				if (j >= 26 && j <= 28) {
					zamin[i][j] = 219;
				}
				if (j >= 64 && j <= 66) {
					zamin[i][j] = 186;
				}
				if (j >= 82 && j <= 84) {
					zamin[i][j] = 186;
				}
				if (j == 19) {
					zamin[i][j] = 186;
				}
				if (j == 25) {
					zamin[i][j] = 186;
				}

			}
			if (i == 12) {

				if (j >= 23 && j <= 25) { 
					zamin[i][j] = 219;
				}
				if (j >= 64 && j <= 66) {
					zamin[i][j] = 186;
				}
				if (j >= 82 && j <= 84) {
					zamin[i][j] = 186;
				}
				if (j == 22) {
					zamin[i][j] = 186;
				}
				if (j == 74) {
					zamin[i][j] = '*';
				}
				if (j == 27) {
					zamin[i][j] = '$';
				}
			}
			if (i == 13) {
				
				if (j >= 20 && j <= 22) {
					zamin[i][j] = 219;
				}
				if (j >= 26 && j <= 28) {
					zamin[i][j] = 219;
				}
				if (j >= 64 && j <= 66) {
					zamin[i][j] = 186;
				}
				if (j >= 82 && j <= 84) {
					zamin[i][j] = 186;
				}
				if (j == 19) {
					zamin[i][j] = 186;
				}
				if (j == 25) {
					zamin[i][j] = 186;
				}
				if (j == 24) {
					zamin[i][j] = '!';
				}
				
			}
			if (i == 14) {

				if (j >= 17 && j <= 19) {
					zamin[i][j] = 219;
				}
				if (j >= 29 && j <= 31) {
					zamin[i][j] = 219;
				}
				if (j >= 64 && j <= 66) {
					zamin[i][j] = 186;
				}
				if (j >= 82 && j <= 84) {
					zamin[i][j] = 186;
				}
				if (j == 16) {
					zamin[i][j] = 186;
				}
				if (j == 28) {
					zamin[i][j] = 186;
				}
				if (j == 77) {
					zamin[i][j] = '#';
				}

			}
			if (i == 15) {

				if (j >= 14 && j <= 16) {
                    zamin[i][j] = 219;
				}
				if (j >= 32 && j <= 34) {
					zamin[i][j] = 219;
				}
				if (j >= 66 && j <= 68) {
					zamin[i][j] = 186;
				}
				if (j >= 80 && j <= 82) {
					zamin[i][j] = 186;
				}
				if (j == 13) {
					zamin[i][j] = 186;
				}
				if (j == 31) {
					zamin[i][j] = 186;
				}
				
			}
			if (i == 16) {

				if (j >= 11 && j <= 13) {
					zamin[i][j] = 219;
				}
				if (j >= 35 && j <= 37) {
					zamin[i][j] = 219;
				}
				if (j >= 68 && j <= 70) {
					zamin[i][j] = 186;
				}
				if (j >= 78 && j <= 80) {
					zamin[i][j] = 186;
				}
				if (j == 10) {
					zamin[i][j] = 186;
				}
				if (j == 34) {
					zamin[i][j] = 186;
				}
			}
			if (i == 17) {
				if (j >= 70 && j <= 78) {
					zamin[i][j] = 186;
				}
			}
			if (i == 18) {

			}
			if (i == 19) {
				if (j >= 11 && j <= 37) {
					zamin[i][j] = 219;
				}
				if (j >= 63 && j <= 88) {
					zamin[i][j] = 219;
				}
			}
			if (i == 20) {

				if (j == 24) {
					zamin[i][j] = '%';
				}
				if (j == 75) {
					zamin[i][j] = '%';
				}
			}
			if (i == 21) {

			}
			if (i == 22) {


			}
			if (i == 23) {

			}
			if (i == 27) {
				if (j == 86) {
					zamin[i][j] = '$';
				}
			}

		}
	}
    } 
            
        
        // Draw players
        zamin[player1_pos.Y][player1_pos.X] = '1';
        zamin[player2_pos.Y][player2_pos.X] = '2';
   
        // Draw bullets
        if (player1_bullet.X < 99 && player1_bullet.X != -1 ) zamin[player1_bullet.Y][player1_bullet.X] = '.';
        if (player2_bullet.X < 99 && player2_bullet.X != -1) zamin[player2_bullet.Y][player2_bullet.X] = '.';
        /// nemayesh rooh , ..
        

        // Output to console

        for (int y = 0; y < 30; y++) {
            
            COORD place;
            place.X = 0;
            place.Y = y;
            WriteConsoleOutputCharacterA(hStdout, zamin[y], 99, place ,&bytes_written);

        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nhealth player 1 : %d\t\t\t\t\t\t\t\t ",gamer1.health);
        printf("health player2 : %d",gamer2.health);
        Sleep(100);
        }
    
    return 0 ;
}


int main() {
    char filename[] = "E:\\Ali\\sanati\\programing\\paianterm\\game.wav";
    PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC);
    int maxId;
    struct lasami* puser1 = NULL ;
    struct lasami* puser2 = NULL ;
    struct lasami* phead = NULL;
    phead = read_from_file(&maxId);    
    
    while(1) {

        switch (login_page())
        {
        case 1:
        if(puser1==NULL){
            puser1=sign_up(phead,maxId);
        }
        else if(puser2 == NULL){
            puser2=sign_up(phead,maxId); 
        }
        else {
            system("cls");
            printf("first log out");
            _getch();
        }
            break;

        case 2:
        if(puser1==NULL){
            puser1=sign_in(phead);
        }
        else if(puser2 == NULL){
            puser2=sign_in(phead);    
        }
        else 
        {
            system("cls");
            printf("first log out");
            _getch();        
        }
        
        break;
        case 3:
        if(puser1 && puser2)
        {
            playgame(puser1, puser2);
            break;
        }
        else
        {
            system("cls");
            printf("you should first login");
            _getch();
            break;
        }
        case 4:
            if(puser1==NULL)
            {
                system("cls");
                printf("you should log in first");
            }
            else
            {
                if(puser2==NULL)
                {
                    change_info(puser1,phead);
                    break;
                }
                while(1)
                {
                    int n;
                    system("cls");
                    printf("1 or 2 ?");
                    scanf("%d",&n);
                    if(n==1)
                    {
                        change_info(puser1,phead);
                        break;

                    }
                    if(n==2)
                    {
                        change_info(puser2,phead);
                        break;
                    }
                }
            }
            break;
        case 5:
            history(puser1 , puser2);
            break;
        case 6:
            exit(0);
        
        }

    }
}
