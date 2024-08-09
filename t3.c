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
                            int startingTwoX=rand()%lmx;
                            int startingTwoY=rand()%lmy;

                            printf("Robot 1 starting X coordinate %d\n",startingX);
                            printf("Robot 1 starting Y coordinate %d\n",startingY);
                            printf("Robot 2 starting X coordinate %d\n",startingTwoX);
                            printf("Robot 2 starting Y coordinate %d\n",startingTwoY);

                            int elements_clean=((r*c*clean_factor)/100);
                            printf("number of tiles to clean: %d\n",elements_clean);
                            int move=0;
                            int moveTwo=0;
                            int cleaned=0;
                            int collide=1;
                                while(cleaned<elements_clean){
                                    if (collide==1 || collide==2){
                                    move=rand()%limit;
                                    printf("robot 1 collided with boundary\n");
                                    }
                                    if (collide==1 || collide==3){
                                    moveTwo=rand()%limit;
                                    printf("robot 2 collided with boundary\n");    
                                    }
                                    if (collide==4){
                                    move=rand()%limit;
                                    moveTwo=rand()%limit;
                                    printf("robots collided with eachother\n");    
                                    }
                                    collide=0;
                                    //move=rand()%limit;
                                    printf("move to be played\n");
                                    while(collide==0){
                                        switch(move){
                                            case 0: 
                                            printf("R1->L\n");
                                            if (startingX+1>=r){
                                                collide=2;
                                                break;

                                            }
                                            else if (startingX+1==startingTwoX && startingY==startingTwoY){
                                                collide=4;
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
                                            printf("R1->R\n");
                                            if (startingX-1<0){
                                                collide=2;
                                                break;

                                            }
                                            else if (startingX-1==startingTwoX && startingY==startingTwoY){
                                                collide=4;
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
                                            printf("R1->U\n");
                                            if (startingY+1>=c){
                                                collide=2;
                                                break;

                                            }
                                            else if (startingX==startingTwoX && startingY+1==startingTwoY){
                                                collide=4;
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
                                            printf("R1->D\n");
                                            if (startingY-1<0){
                                                collide=2;
                                                break;

                                            }
                                            else if (startingX==startingTwoX && startingY-1==startingTwoY){
                                                collide=4;
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
                                            printf("R1->DUR\n");
                                            if (startingX-1<0 || startingY+1>=c){
                                                collide=2;
                                                break;

                                            }
                                            else if (startingX-1==startingTwoX && startingY+1==startingTwoY){
                                                collide=4;
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
                                            printf("R1->DBL\n");
                                            if (startingX+1>=r || startingY-1<0){
                                                collide=2;
                                                break;

                                            }
                                            else if (startingX+1==startingTwoX && startingY-1==startingTwoY){
                                                collide=4;
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
                                            printf("R1->DUL\n");
                                            if (startingX+1>=r || startingY+1>=c){
                                                collide=2;
                                                break;

                                            }
                                            else if (startingX+1==startingTwoX && startingY+1==startingTwoY){
                                                collide=4;
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
                                            printf("R1->DBR\n");
                                            if (startingX-1<0 || startingY-1<0){
                                                collide=2;
                                                break;

                                            }
                                            else if (startingX-1==startingTwoX && startingY-1==startingTwoY){
                                                collide=4;
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

                                    switch(moveTwo){
                                            case 0: 
                                            printf("R2->L\n");
                                            if (startingTwoX+1>=r){
                                                collide=3;
                                                break;

                                            }
                                            else if (startingX==startingTwoX+1 && startingY==startingTwoY){
                                                collide=4;
                                                break;
                                            }
                                            else{
                                                startingTwoX++;
                                                if (room[startingTwoX][startingTwoY]==1)
                                                {
                                                room[startingTwoX][startingTwoY]=0;
                                                cleaned++;
                                                }
                                                break;

                                            }
                                            case 1: 
                                            printf("R2->R\n");
                                            if (startingTwoX-1<0){
                                                collide=3;
                                                break;

                                            }
                                            else if (startingX==startingTwoX-1 && startingY==startingTwoY){
                                                collide=4;
                                                break;
                                            }
                                            else{
                                                startingTwoX--;
                                                if (room[startingTwoX][startingTwoY]==1)
                                                {
                                                room[startingTwoX][startingTwoY]=0;
                                                cleaned++;
                                                }
                                                break;

                                            }
                                            
                                            case 2: 
                                            printf("R2->U\n");
                                            if (startingTwoY+1>=c){
                                                collide=3;
                                                break;

                                            }
                                            else if (startingX==startingTwoX && startingY==startingTwoY+1){
                                                collide=4;
                                                break;
                                            }
                                            else{
                                                startingTwoY++;
                                                if (room[startingTwoX][startingTwoY]==1)
                                                {
                                                room[startingTwoX][startingTwoY]=0;
                                                cleaned++;
                                                }
                                                break;

                                            }
                                            case 3:
                                            printf("R2->D\n");
                                            if (startingTwoY-1<0){
                                                collide=3;
                                                break;

                                            }
                                            else if (startingX==startingTwoX && startingY==startingTwoY-1){
                                                collide=4;
                                                break;
                                            }
                                            else{
                                                startingTwoY--;
                                                if (room[startingTwoX][startingTwoY]==1)
                                                {
                                                room[startingTwoX][startingTwoY]=0;
                                                cleaned++;
                                                }
                                                break;

                                            } 
                                            
                                            case 4:
                                            printf("R2->DUR\n");
                                            if (startingTwoX-1<0 || startingTwoY+1>=c){
                                                collide=3;
                                                break;

                                            }
                                            else if (startingX==startingTwoX-1 && startingY==startingTwoY+1){
                                                collide=4;
                                                break;
                                            }
                                            else{
                                                startingTwoX--;
                                                startingTwoY++;
                                                if (room[startingTwoX][startingTwoY]==1)
                                                {
                                                room[startingTwoX][startingTwoY]=0;
                                                cleaned++;
                                                }
                                                break;

                                            } 
                                            
                                            case 5: 
                                            printf("R2->DBL\n");
                                            if (startingTwoX+1>=r || startingTwoY-1<0){
                                                collide=3;
                                                break;

                                            }
                                            else if (startingX==startingTwoX+1 && startingY==startingTwoY-1){
                                                collide=4;
                                                break;
                                            }
                                            else{
                                                startingTwoX++;
                                                startingTwoY--;
                                                if (room[startingTwoX][startingTwoY]==1)
                                                {
                                                room[startingTwoX][startingTwoY]=0;
                                                cleaned++;
                                                }
                                                break;

                                            } 
                                            
                                            case 6: 
                                            printf("R2->DUL\n");
                                            if (startingTwoX+1>=r || startingTwoY+1>=c){
                                                collide=3;
                                                break;

                                            }
                                            else if (startingX==startingTwoX+1 && startingY==startingTwoY+1){
                                                collide=4;
                                                break;
                                            }
                                            else{
                                                startingTwoX++;
                                                startingTwoY++;
                                                if (room[startingTwoX][startingTwoY]==1)
                                                {
                                                room[startingTwoX][startingTwoY]=0;
                                                cleaned++;
                                                }
                                                break;

                                            } 
                                            
                                            case 7: 
                                            printf("R2->DBR\n");
                                            if (startingTwoX-1<0 || startingTwoY-1<0){
                                                collide=3;
                                                break;

                                            }
                                            else if (startingX==startingTwoX-1 && startingY==startingTwoY-1){
                                                collide=4;
                                                break;
                                            }
                                            else{
                                                startingTwoX--;
                                                startingTwoY--;
                                                if (room[startingTwoX][startingTwoY]==1)
                                                {
                                                room[startingTwoX][startingTwoY]=0;
                                                cleaned++;
                                                }
                                                break;

                                            } 
                                            
                                            default: break;
                                        }

                                    }



                                }
                                printf("\ntiles cleaned: %d\n", cleaned);
                            room[startingX][startingY]=8;
                            room[startingTwoX][startingTwoY]=8;
                                for (int i=0;i<r;i++){
                                for (int j=0; j<c;j++){
                                    printf("%d  ",room[i][j]);
                                }
                                printf("\n");
                            }
                                return 0;

        }