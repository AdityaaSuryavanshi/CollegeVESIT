// Car Game
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

int height=21,width=28;
int x=21,y=14,multiplayer=0,randomizer=0,obstacleX=3,obstacleY=10,flag=0,score=0,gameEnd=0,flag2;
float slepn=1;

char car(coord){
    int m,n,p,q;
    printf("A\n");
    for(m=0;m<=coord+1;m++){
       if(m==coord-1){
            printf("/");
        }
        else if(m==coord+1){
             printf("\\ \n");
        }
        else{
         printf(" ");
        }
    }
    for(n=0;n<=coord+2;n++){
       if(n==coord-2){
          printf("|");
        }
        else if(n==coord){
          printf("o");
        }
        else if(n==coord+2){
         printf("| \n");
        }
        else{
          printf(" ");
        }
        }
    for(p=0;p<=coord+1;p++){
        if(p==coord-1){
            printf("\\");
            }
        else if(p==coord+1){
           printf("/\n");
        }
        else{
            printf(" ");
        }
        }
    for(q=0;q<=coord;q++){
        if(q==coord){
        printf("v");
        }
        else{
         printf(" ");
        }
    }
    return 0;
}

void multi()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'j':
            {
                obstacleY=4;
                break;
            }
            case 'k':
            {
                obstacleY=14;
                break;
            }
            case 'l':
            {
                obstacleY=24;
                break;
            }
        }
    }
}

int select(a)
{
        switch(a)
        {
            case 1:
            {
                multiplayer=1;
                return multiplayer;
                break;
            }
            case 2:
            {
                randomizer=1;
                return randomizer;
                break;
            }
        }
}

void display()
{
    int a;
    printf("Hello!\nPlease select which mode you would like to play the game in\n1.Multiplayer\n2.Randomizer\n");
    scanf("%d",&a);
    select(a);
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

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':
            {
                y=4;
                break;
            }
            case 's':
            {
                y=14;
                break;
            }
            case 'd':
            {
                y=24;
                break;
            }

        }
    }
}

void track()
{
    system("cls");
    int i,j;
    for(i=0;i<=height;i++)
    {
        for(j=0;j<=width;j++)
        {
            if(j==0 || j==width)
            {
                printf("|");
            }
            else
            {
                if(i==x && j==y)
                {
                    car(y);
                }
                else if(i==obstacleX && j==obstacleY)
                {
                    car(obstacleY);
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void end()
{
    if(y==obstacleY && x==obstacleX)
    {
        gameEnd=1;
    }
}

void loop()
{
    if(obstacleX>21)
    {
        random();
        obstacleX=0;
        score=score+10;
        slepn=1;
    }
    obstacleX++;

}

void multiloop()
{
    if(obstacleX>21)
    {
        obstacleX=0;
        score=score+10;
        slepn=1;
    }
    obstacleX++;

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

        printf("score: %d",score);
    }
    }
    else if(multiplayer==1)
    {
        while(gameEnd!=1)
    {
        sleep(slepn);
        multi();
        input();
        track();
        end();
        multiloop();

        printf("score: %d\n",score);
    }
    }
    if(gameEnd==1)
    {
        printf("Your score is %d\n",score);
    }
    return 0;
}
