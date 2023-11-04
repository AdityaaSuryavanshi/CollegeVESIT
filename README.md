//car game!
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

int height=21,width=28;
int x=21,y=14,redo,multiplayer=0,randomizer=0,obstacleX=3,obstacleY=14,flag=0,score=0,gameEnd=0,flag2,n;
float slepn=0.99;

char car(int coord)
{
    int m,n,p,q;
    printf("_\n");
    for(m=0;m<=coord+1;m++)
    {
        if(m==coord-1)
        {
            printf("/");
        }
        else if(m==coord+1)
        {
            printf("\\ \n");
        }
        else
        {
            printf(" ");
        }
    }
    for(n=0;n<=coord+2;n++)
    {
        if(n==coord-2)
        {
            printf("|");
        }
        else if(n==coord)
        {
            printf("o");
        }
        else if(n==coord+2)
        {
            printf("| \n");
        }
        else
        {
            printf(" ");
        }
        }
    for(p=0;p<=coord+1;p++)
    {
        if(p==coord-1)
        {
            printf("\\");
            }
        else if(p==coord+1)
        {
            printf("/\n");
        }
        else
        {
            printf(" ");
        }
        }
    for(q=0;q<=coord;q++)
    {
        if(q==coord)
        {
        printf("v");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}

int select(int a)
{
        switch(a)
        {
            case 2:
            {
                multiplayer=1;
                return multiplayer;
                break;
            }
            case 1:
            {
                randomizer=1;
                return randomizer;
                break;
            }
        }
}

void display()
{
    printf("Hello! Welcome to SPEED FOR NEED.\nWe hope you enjoy it!\n\n");
    sleep(1);
    int a;
    printf("Please select which mode you would like to play the game in\n1.Single Player\n2.Multiplayer\n");
    scanf("%d",&a);
    select(a);
    sleep(1);
    if(randomizer==1)
    {
        system("cls");
        printf("The controls of the game are \n Player control:-\n A = Left \n D = Right\n\nWARNING:- GAME SPEED INCREASES AFTER THE FIRST LOOP\n");
        sleep(2);
    }
    else if(multiplayer==1)
    {
        system("cls");
        printf("The controls of the game are \n Player 1:-\n A = Left \n D = Right  \n\n\n FOR MULTIPLAYER \n J = Left  \n L = Right \n\nWARNING:- GAME SPEED INCREASES AFTER THE FIRST LOOP\n");
        sleep(2);
    }
}

void track()
{
    system("cls");
    int i,j;
    for(i=0;i<=height;i++){
        for(j=0;j<=width;j++){
            if(j==0 || j==width){
                printf("|");
            }
            else{
                if(i==x && j==y){
                    car(y);
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
        printf("_");
    }
}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':{
                if(y>4){
                    y-=10;
                    }
                break;}
            case 'd':{
                if(y<24){
                    y+=10;
                }
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
                if(y>4){
                    y-=10;}
                break;
            }
            case 'd':{
                if(y<24){
                    y+=10;}
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

void loop()
{
    if(obstacleX>21)
    {
        random();
        obstacleX=0;
        score+=10;
        slepn=0.9;
    }
    obstacleX++;
}

void multiloop(){
    if(obstacleX>21)
        {
        obstacleX=0;
        score+=10;
        slepn=0.9;
        if(score==200)
        {
            gameEnd=1;
        }
        }
    obstacleX++;
}

void end(){
    if(y==obstacleY && x==obstacleX){
        gameEnd=1;}
}

int endDisplay()
{
    if(score>=300)
    {
        printf("\nYour score is %d!\n\nYou have achieved one of the highest scores!Congrats!!\n",score);
    }
    else
    {
        printf("Your score %d!\n\nYou did great!\n",score);
    }
    printf("Do you wish to continue the game?\n1.Retry\n2.Exit\n");
    scanf("%d",&redo);
    return redo;
}


int endDisplay2(){
    if(score>=200)
    {
        printf("Your score:%d\n No collision occured! Player 1,victory is yours.\n",score);
    }
    else
    {
        printf("The cars collided!Player 2,victory is yours.\n");
    }
    printf("Do you wish to continue the game?\n1.Retry\n2.Exit\n");
    scanf("%d",&redo);
    return redo;
}

int main()
{
    display();
    if(randomizer==1)
    {
        while(gameEnd!=1)
    {

        sleep(slepn);
        input();
        track();
        end();
        loop();
        if(gameEnd==1)
        {
            endDisplay();
            if(redo==1)
            {
                score=0;
                gameEnd=0;
            }
        }
    }
    }
    else if(multiplayer==1){
        while(gameEnd!=1){
        sleep(slepn);
        multi();
        track();
        end();
        multiloop();
        if(gameEnd==1)
        {
            endDisplay2();
            if(redo==1)
            {
                score=0;
                gameEnd=0;
            }
        }
    }
    }
    if(gameEnd==1)
    {
        system("cls");
        printf("Thank you for playing\n");
    }
    return 0;
}
