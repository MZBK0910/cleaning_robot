#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define r 10
#define c 10
int main (){
int limit=8;
int lmx=r;
int lmy=c;
int clean_factor=0;
printf("enter clean factor: ");
scanf("%d",&clean_factor);
printf("\n");
printf("enter perceentage for cleaning is %d %%\n",clean_factor);
int room[r][c];
for (int i=0;i<r;i++){
    for (int j=0; j<c;j++){
        room[i][j]=1;
    }
}
srand(time(0));
int startingX=rand()%lmx;
int startingY=rand()%lmy;

printf("starting X coordinate %d\n",startingX);
printf("starting Y coordinate %d\n",startingY);

int elements_clean=((r*c*clean_factor)/100);
printf("number of tiles to clean: %d\n",elements_clean);
int move=0;
int cleaned=0;
int collide=0;
    while(cleaned<elements_clean){
        collide=0;
        move=rand()%limit;
        printf("move to be played\n");
        while(collide==0){
            switch(move){
                case 0: 
                printf("L\n");
                if (startingX+1>=r){
                    collide=1;
                    break;

                }
                else{
                    startingX++;
                    if (room[startingX][startingY]==1)
                    {
                    room[startingX][startingY]=0;
                    cleaned++;
                    }
                    break;

                }
                case 1: 
                printf("R\n");
                if (startingX-1<0){
                    collide=1;
                    break;

                }
                else{
                    startingX--;
                    if (room[startingX][startingY]==1)
                    {
                    room[startingX][startingY]=0;
                    cleaned++;
                    }
                    break;

                }
                
                case 2: 
                printf("U\n");
                if (startingY+1>=c){
                    collide=1;
                    break;

                }
                else{
                    startingY++;
                    if (room[startingX][startingY]==1)
                    {
                    room[startingX][startingY]=0;
                    cleaned++;
                    }
                    break;

                }
                case 3:
                printf("D\n");
                if (startingY-1<0){
                    collide=1;
                    break;

                }
                else{
                    startingY--;
                    if (room[startingX][startingY]==1)
                    {
                    room[startingX][startingY]=0;
                    cleaned++;
                    }
                    break;

                } 
                
                case 4:
                printf("DUR\n");
                if (startingX-1<0 || startingY+1>=c){
                    collide=1;
                    break;

                }
                else{
                    startingX--;
                    startingY++;
                    if (room[startingX][startingY]==1)
                    {
                    room[startingX][startingY]=0;
                    cleaned++;
                    }
                    break;

                } 
                
                case 5: 
                printf("DBL\n");
                if (startingX+1>=r || startingY-1<0){
                    collide=1;
                    break;

                }
                else{
                    startingX++;
                    startingY--;
                    if (room[startingX][startingY]==1)
                    {
                    room[startingX][startingY]=0;
                    cleaned++;
                    }
                    break;

                } 
                
                case 6: 
                printf("DUL\n");
                if (startingX+1>=r || startingY+1>=c){
                    collide=1;
                    break;

                }
                else{
                    startingX++;
                    startingY++;
                    if (room[startingX][startingY]==1)
                    {
                    room[startingX][startingY]=0;
                    cleaned++;
                    }
                    break;

                } 
                
                case 7: 
                printf("DBR\n");
                if (startingX-1<0 || startingY-1<0){
                    collide=1;
                    break;

                }
                else{
                    startingX--;
                    startingY--;
                    if (room[startingX][startingY]==1)
                    {
                    room[startingX][startingY]=0;
                    cleaned++;
                    }
                    break;

                } 
                
                default: break;
            }

        }



    }
    printf("\ntiles cleaned: %d\n", cleaned);

    for (int i=0;i<r;i++){
    for (int j=0; j<c;j++){
        printf("%d  ",room[i][j]);
    }
    printf("\n");
}
    return 0;

}