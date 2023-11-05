#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

int height=21,width=28;
int carx=21,cary=14,redo,selection=0,obstacleX=3,obstacleY=14,flag=0,score=0,gameEnd=0,flag2,n;
float slepn=1;


char car(int coord)
{
    int m,n,p,q;
    printf("_\n");
    for(m=0;m<=coord+1;m++){
        if(m==coord-1){
            printf("/");}
        else if(m==coord+1){
            printf("\\ \n");}
        else{
            printf(" ");}
    }
    for(n=0;n<=coord+2;n++){
        if(n==coord-2){
            printf("|");}
        else if(n==coord){
            printf("o");}
        else if(n==coord+2){
            printf("| \n");}
        else{
            printf(" ");}
        }
    for(p=0;p<=coord+1;p++){
        if(p==coord-1){
            printf("\\");}
        else if(p==coord+1){
            printf("/\n");}
        else{
            printf(" ");}
        }
    for(q=0;q<=coord;q++){
        if(q==coord){
        printf("v");}
        else{
            printf(" ");}
    }
    return 0;
}


int select(int a){
        switch(a){
            case 1:{
                selection=1;
                return selection;
                break;
            }
            case 2:{
                selection=2;
                return selection;
                break;
            }
        }
}

void display()
{
    printf("Hi Welcome to SPEED FOR NEED.\nDrive safe!\n\n");
    sleep(1);
    int a;
    printf("Select the mode you'd like to play (Enter serial number)\n1.Single player\n2.Multiplayer\n");
    scanf("%d",&a);
    select(a);
    sleep(1);
    if(selection==1){
        system("cls");
        printf("Game controls are as follows \n Player control:-\n A = Left \n D = Right");
        sleep(2);
        printf("\n\nThe game ends when your car collides with the other.");
        sleep(1);
        printf("\n\nWARNING:-WATCH OUT FOR SPEEDING");
        sleep(1);
        printf("\n\nGame starts in  3");
        sleep(1);
        printf("  2");
        sleep(1);
        printf("  1");
        sleep(1);
        printf("   GO");
    }
    else if(selection==2){
        system("cls");
        printf("Game controls are follows \n Player 1:-\n A = Left \n D = Right  \n\n Player 2:-\n J = Left  \n L = Right \n");
        sleep(2);
        printf("\n Instructions-\n");
        sleep(2);
        printf("1.Player 1 controls the primary car. Player 1 wins if he can make it to 200 points without colliding with player 2.");
        sleep(3);
        printf("\n\n 2.Player 2 controls the second car. Player 2 wins if he can bring player 1 to a collision before the latter reaches 200 points.");
        sleep(3);
        printf("\n\n WARNING:-WATCH OUT FOR SPEEDING\n");
        sleep(5);
        printf("\nGame starts in  3");
        sleep(1);
        printf("  2");
        sleep(1);
        printf("  1");
        sleep(1);
        printf("   GO");
    }
}

void track(){
    system("cls");
    int i,j;
    for(i=0;i<=height;i++){
        for(j=0;j<=width;j++){
            if(j==0 || j==width){
                printf("|");
            }
            else{
                if(i==carx && j==cary){
                    car(cary);
                }
                else if(i==obstacleX && j==obstacleY){
                    car(obstacleY);
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    for(n=0;n<=width;n++){
        printf("_");}
    printf("score:%d",score);
}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':{
                if(cary>4){
                    cary-=10;}
                break;}
            case 'd':{
                if(cary<24){
                    cary+=10;}
                break;
            }
        }
    }
}

void random()
{
    int i,num;

    for(i=0;i<=3;i++)
    {
       num=rand()%24;
       if(num<9)
       {
           obstacleY=4;
       }
       else if(num>18)
       {
           obstacleY=24;
       }
       else
       {
           obstacleY=14;
       }
    }
}

void multi(){
    if(kbhit()){
        switch(getch()){
            case 'a':{
                if(cary>4){
                    cary-=10;}
                break;
            }
            case 'd':{
                if(cary<24){
                    cary+=10;}
                break;
            }
            case 'j':{
                if(obstacleY>4){
                    obstacleY-=10;}
                break;
            }
            case 'l':{
                if(obstacleY<24){
                    obstacleY=obstacleY+10;
                }
                break;
            }
        }
    }
}

void loop(){
    if(obstacleX>21){
        random();
        obstacleX=0;
        score+=10;
        slepn=0.99;
    }
    obstacleX++;}


void multiloop(){
    if(obstacleX>21){
        obstacleX=0;
        score+=10;
        slepn=0.9;
        if(score==200){
            gameEnd=1;}
        }
    obstacleX++;}



void end(){
    if(cary==obstacleY && carx==obstacleX){
        gameEnd=1;}
}

int endDisplay(){
    if(score>=300){
        printf("\n%d! That's a good score!\n",score);
    }
    else
    {
        printf("\nGood job!\n");
    }
    printf("Do you wish to continue the game?(Enter serial number)\n1.Retry\n2.Exit\n");
    scanf("%d",&redo);
    return redo;
}


int endDisplay2(){
    if(score>=200){
        printf("Your score:%d \nNo collision occured!Player 1, Victory is yours.\n",score);
    }
    else
    {
        printf("\nThe cars collided!Player 2, Victory is yours.\n");
    }
    printf("Do you wish to continue the game?(Insert serial number)\n1.Retry\n2.Exit\n");
    scanf("%d",&redo);
    return redo;
}

int main(){
    display();
    if(selection==1){
        while(gameEnd!=1){
        sleep(slepn);
        input();
        track();
        end();
        loop();
        if(gameEnd==1){
            endDisplay();
            if(redo==1){
                score=0;
                gameEnd=0;
                slepn=1;
            }
        }
    }
    }
    else if(selection==2){
        while(gameEnd!=1){
        sleep(slepn);
        multi();
        track();
        end();
        multiloop();
        if(gameEnd==1){
            endDisplay2();
            if(redo==1){
                score=0;
                gameEnd=0;
                slepn=1;}
        }
    }
    }
    if(gameEnd==1){
        system("cls");
        printf("Thank you for driving with us!\n");
    }
    return 0;
}
