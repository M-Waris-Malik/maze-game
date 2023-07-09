#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

const int Width = 50;
const int Height = 30;

struct Position {
    int x;
    int y;
};

void gotoxy(int x, int y){
	COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

 void screen(){
 	 for (int i = 0; i < Width; i++) {
        gotoxy(i, 0);
        cout << "#";
        gotoxy(i, Height - 1);
        cout << "#";
    }
    
    for (int i = 1; i < Height - 1; i++) {
        gotoxy(0, i);
        cout << "#";
        gotoxy(Width - 1, i);
        cout << "#";
    }
 }
 
 void maze(){
  for (int i = 0; i < Width - 4; i++) {
        gotoxy(i + 1, 3);
        cout << "*";
    }
	
	 for (int i = 0; i < Width - 4; i++) {
        gotoxy(i + 3, 6);
        cout << "*";
    }
		
 	  gotoxy(Width / 2, 7);
    cout << "#";
    gotoxy(Width / 2, 8);
    cout << "#";
    
       for (int i = 0; i < Width / 2 - 3; i++) {
        gotoxy(i + 1, 9);
        cout << "*";
    }

    for (int i = 0; i < Width - 4; i++) {
        gotoxy(i + 1, 12);
        cout << "*";
    }

    for (int i = 0; i < Width / 2; i++) {
        gotoxy(i + 1, 15);
        cout << "*";
    }

    for (int i = 0; i < Width / 2 - 4; i++) {
        gotoxy(i + Width / 2 + 3, 15);
        cout << "*";
    }

    for (int i = 0; i < Width - 4; i++) {
        gotoxy(i + 1, 18);
        cout << "*";
    }

    gotoxy(0 + Width / 2 - 2, 19);
    cout << "#";
    gotoxy(0 + Width / 2 - 2, 20);
    cout << "#";

    for (int i = 0; i < Width - 4; i++) {
        gotoxy(i + 1, 21);
        cout << "*";
    }

    for (int i = 0; i < Width - 4; i++) {
        gotoxy(i + 3, 24);
        cout << "*";
    }

    for (int i = 0; i < Width / 2 + 8; i++) {
        gotoxy(i + 1, 27);
        cout << "*";
    }

    for (int i = 0; i < Width / 2 - 11; i++) {
        gotoxy(i + Width / 2 + 10, 27);
        cout << "*";
    }
 	
 }
 
 void drawPositions(const Position& playerPos, const Position& destPos){
 	 gotoxy(playerPos.x, playerPos.y);
    cout << "@";
    
       gotoxy(destPos.x,destPos.y);
    cout<<"()";
 }
 
 bool checkCollision(const Position& newPos) {
    if (newPos.x <= 0 || newPos.x >= Width - 1 
   || newPos.y <= 0 || newPos.y >= Height - 1)
	
        return true;

    return false;   
}

bool checkWin(const Position& playerPos, const Position& destPos) {
    if (playerPos.x == destPos.x && playerPos.y == destPos.y)
        return true;
    return false;
    
    
}
 
 int main(){
 	system("mode con: lines=40 cols=70");
 	Position playerPos = {2,2};
 	Position destPos = {2, Height-2};
 	
 
 	
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Hide the cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    
    	gotoxy(0,Height/2-3);
 	
 	cout<<"<<<<< Instruction >>>>>:"<<endl;
    cout<<"************************"<<endl;
    cout<<"Use Arrow keys (Left,Right,Up,Down) for move:"<<endl;
    cout<<endl;
    
     system("pause");
     
     system("cls");
 	screen();
 	maze();
 	
 	drawPositions(playerPos, destPos);
 	while(true){
 		
 	Position newPos = playerPos;
 	
 	if(_kbhit()){
 		char key = _getch();
 		
 		if(key==80){
 			newPos.y++;
		 }
		else if(key==72){
			newPos.y--;
		} 
		
		else if(key==77){
		newPos.x++;
		}
		
	else if(key==75){
		newPos.x--;
		}	
		
	 }
	 
	 if(!checkCollision(newPos)){
	  gotoxy(playerPos.x, playerPos.y);
        cout << " ";
        
        playerPos = newPos;
        
       drawPositions(playerPos, destPos); 
        	
	 }
	 
	 if (checkWin(playerPos, destPos))
    break;
 		
	 }//while
	
	 gotoxy(2, Height+1);
	 cout << "Congratulations! You reached the destination!" << endl;
	 
	 return 0;	
 }//main
