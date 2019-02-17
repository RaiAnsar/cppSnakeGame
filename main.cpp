#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
bool gameOver;
int tailX[50], tailY[50];
int nTail; 
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void settings(){
    gameOver = false;
    dir=STOP;
    x = width/2;
    y = height/2;
    fruitX = rand()%width;
    fruitY = rand()%height;
    score = 0;
}
void visual(){
    system("cls");
    for(int i=0; i<width+2; i++){
        cout<<"#";
    }
    cout<<endl;

    for (int i = 0; i <height; i++) {
        for(int j=0; j<width; j++){
            if(j==0)
                cout<<"#";
            if(i==y && j==x)
                cout<<"O";
            else if(i== fruitY && j== fruitX)
                cout<<"*";
            else{ 
                bool prinTail = false;
                
                for(int k=0; k<nTail-1; k++){
                    if(tailX[k]==j && tailY[k]==i){
                        cout<<"o";
                        prinTail = true;
                    }
                }
                if(!prinTail)
                cout<<" ";
            }
                if(j==width-1)
                cout<<"#";
        }
        cout<<endl;
    }

    for(int i=0; i<width+2; i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"\nScore: "<<(score)<< endl;

}
void logic(){
    int previousX = tailX[0];
    int previousY = tailY[0];
    int previous2X, previous2Y;
    tailX[0] =x;
    tailY[0] =y;
    for(int i=1; i<nTail; ++i){
        previous2X = tailX[i];
        previous2Y = tailY[i];
        tailX[i]= previousX;
        tailY[i] = previousY;
        previousX = previous2X;
        previousY = previous2Y;
    }
    
    switch (dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWN:
            y++;
            break;
        case UP:
            y--;
            break;
        default:
            break;

    }
    if(x>= width)
        x=0;
    else if (x<0)
        x=width-1;
    if(y>= width)
        y=0;
    else if (y<0)
        y=width-1;
        
        
    for(int i=0; i<nTail; i++){
        if (tailX[i]==x && tailY[i]==y)
            gameOver=true;
    }
    
    
    if(x==fruitX && y == fruitY){
        score+=4;
        fruitX = rand()%width;
        fruitY = rand()%height;
        nTail++;
    }

}
void input(){
    if (_kbhit()){
        switch (_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }

    }

}

int main() {
 settings();
 while (!gameOver){
     visual();
     input();
     logic();
     Sleep(100);
 }
}