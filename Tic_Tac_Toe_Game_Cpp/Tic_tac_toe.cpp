#include<iostream>
#include<conio.h>
using namespace std;

//Global Declaration
char Game_array[3][3]={
    {' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '}
};
bool Game_Status=true;
int GameShell=3;
char UserInput;
char OpponentPlayer='X';
char CurrentPlayer='O';
int InputCount;//Total Valid input count

//function Declaration
void GameHelper();
void Graphics();
void GraphicsLine_Drawer();
void Backent_Process();
void GameChecker(int RowIndex,int ColumnIndex);
void GameWin();

//Main
int main(){
    
    system("cls");
    GameHelper();
    cout<<"\nEnter any key to Start Game";
    getch();
    system("cls");
    
    while(Game_Status){
        Graphics();
        cout<<"\nPlayer "<<CurrentPlayer<<" Move : ";
        UserInput=getch();  //handle input as character
        Backent_Process();
        //getch();
        system("cls");
    }
}


//Functions
void GraphicsLine_Drawer(){
    cout<<"-------------\n";
}

void Graphics(){
    for(int i=0;i<GameShell;i++){
        GraphicsLine_Drawer();
        cout<<"| ";
        for(int j=0;j<GameShell;j++){
            cout<<Game_array[i][j]<<" | ";
        }cout<<"\n";
    }
    GraphicsLine_Drawer();
}

void Backent_Process(){
    switch(UserInput){
        case '1':{
            if(Game_array[2][0]!=OpponentPlayer){
                Game_array[2][0]=CurrentPlayer;
                InputCount++;
                GameChecker(2,0);
                char TempSwapper=OpponentPlayer;
                OpponentPlayer=CurrentPlayer;
                CurrentPlayer=TempSwapper;
            }
            break;
        }
        case '2':{
            if(Game_array[2][1]!=OpponentPlayer){
                Game_array[2][1]=CurrentPlayer;
                InputCount++;
                GameChecker(2,1);
                char TempSwapper=OpponentPlayer;
                OpponentPlayer=CurrentPlayer;
                CurrentPlayer=TempSwapper;
            }
            break;
        }
        case '3':{
            if(Game_array[2][2]!=OpponentPlayer){
                Game_array[2][2]=CurrentPlayer;
                InputCount++;
                GameChecker(2,2);
                char TempSwapper=OpponentPlayer;
                OpponentPlayer=CurrentPlayer;
                CurrentPlayer=TempSwapper;
            }
            break;
        }
        case '4':{
            if(Game_array[1][0]!=OpponentPlayer){
                Game_array[1][0]=CurrentPlayer;
                InputCount++;
                GameChecker(1,0);
                char TempSwapper=OpponentPlayer;
                OpponentPlayer=CurrentPlayer;
                CurrentPlayer=TempSwapper;
            }
            break;
        }
        case '5':{
            if(Game_array[1][1]!=OpponentPlayer){
                Game_array[1][1]=CurrentPlayer;
                InputCount++;
                GameChecker(1,1);
                char TempSwapper=OpponentPlayer;
                OpponentPlayer=CurrentPlayer;
                CurrentPlayer=TempSwapper;
            }
            break;
        }
        case '6':{
            if(Game_array[1][2]!=OpponentPlayer){
                Game_array[1][2]=CurrentPlayer;
                InputCount++;
                GameChecker(1,2);
                char TempSwapper=OpponentPlayer;
                OpponentPlayer=CurrentPlayer;
                CurrentPlayer=TempSwapper;
            }
            break;
        }
        case '7':{
            if(Game_array[0][0]!=OpponentPlayer){
                Game_array[0][0]=CurrentPlayer;
                InputCount++;
                GameChecker(0,0);
                char TempSwapper=OpponentPlayer;
                OpponentPlayer=CurrentPlayer;
                CurrentPlayer=TempSwapper;
            }
            break;
        }
        case '8':{
            if(Game_array[0][1]!=OpponentPlayer){
                Game_array[0][1]=CurrentPlayer;
                InputCount++;
                GameChecker(0,1);
                char TempSwapper=OpponentPlayer;
                OpponentPlayer=CurrentPlayer;
                CurrentPlayer=TempSwapper;
            }
            break;
        }
        case '9':{
            if(Game_array[0][2]!=OpponentPlayer){
                Game_array[0][2]=CurrentPlayer;
                InputCount++;
                GameChecker(0,2);
                char TempSwapper=OpponentPlayer;
                OpponentPlayer=CurrentPlayer;
                CurrentPlayer=TempSwapper;
            }
            break;
        }
    }
}

void GameChecker(int RowIndex,int ColumnIndex){
    //cout<<CurrentPlayer;getch();
    //checking for win if last clic in center
    if(RowIndex==1&&ColumnIndex==1){
        if((Game_array[0][1]==CurrentPlayer&&Game_array[2][1]==CurrentPlayer)||(Game_array[1][0]==CurrentPlayer&&Game_array[1][2]==CurrentPlayer)||(Game_array[0][0]==CurrentPlayer&&Game_array[2][2]==CurrentPlayer)||(Game_array[0][2]==CurrentPlayer&&Game_array[2][0]==CurrentPlayer)){
            GameWin();
        }
    }else if(RowIndex==0&&ColumnIndex==0){                                        //cheking for last input in corner
        if(Game_array[1][1]==CurrentPlayer&&Game_array[2][2]==CurrentPlayer){
            GameWin();
        }else if(Game_array[1][0]==CurrentPlayer&&Game_array[2][0]==CurrentPlayer){
            GameWin();
        }else if(Game_array[0][1]==CurrentPlayer&&Game_array[0][2]==CurrentPlayer){
            GameWin();
        }
    }else if(RowIndex==0&&ColumnIndex==2){
        if(Game_array[1][1]==CurrentPlayer&&Game_array[2][0]==CurrentPlayer){
            GameWin();
        }else if(Game_array[0][1]==CurrentPlayer&&Game_array[0][0]==CurrentPlayer){
            GameWin();
        }else if(Game_array[1][2]==CurrentPlayer&&Game_array[2][2]==CurrentPlayer){
            GameWin();
        }
    }else if(RowIndex==2&&ColumnIndex==0){
        if(Game_array[1][1]==CurrentPlayer&&Game_array[0][2]==CurrentPlayer){
            GameWin();
        }else if(Game_array[1][0]==CurrentPlayer&&Game_array[0][0]==CurrentPlayer){
            GameWin();
        }else if(Game_array[2][1]==CurrentPlayer&&Game_array[2][2]==CurrentPlayer){
            GameWin();
        }
    }else if(RowIndex==2&&ColumnIndex==2){
        if(Game_array[1][1]==CurrentPlayer&&Game_array[0][0]==CurrentPlayer){
            GameWin();
        }else if(Game_array[1][2]==CurrentPlayer&&Game_array[0][2]==CurrentPlayer){
            GameWin();
        }else if(Game_array[2][1]==CurrentPlayer&&Game_array[2][0]==CurrentPlayer){
            GameWin();
        }
    }else if(RowIndex==0&&ColumnIndex==1){                                        //cheking for last input in border line center
        if(Game_array[0][0]==CurrentPlayer&&Game_array[0][2]==CurrentPlayer){
            GameWin();
        }
    }else if(RowIndex==1&&ColumnIndex==2){
        if(Game_array[0][2]==CurrentPlayer&&Game_array[2][2]==CurrentPlayer){
            GameWin();
        }
    }else if(RowIndex==2&&ColumnIndex==1){
        if(Game_array[2][0]==CurrentPlayer&&Game_array[2][2]==CurrentPlayer){
            GameWin();
        }
    }else if(RowIndex==1&&ColumnIndex==0){
        if(Game_array[0][0]==CurrentPlayer&&Game_array[2][0]==CurrentPlayer){
            GameWin();
        }
    }
    if(InputCount==9){
        Game_Status=false;
        system("cls");
        Graphics();
        cout<<"\n\n   Game Draw      ";
        getch();
    }
    
}


void GameWin(){
    Game_Status=false;
    system("cls");
    Graphics();
    cout<<"\n\n   Game Win      ";
    cout<<"\n    Winner\n   >> "<<CurrentPlayer<<" <<";
    getch();
}

void GameHelper(){
    cout<<"Press a number to make markings \n\n";
    GraphicsLine_Drawer();
    cout<<"| 7 | 8 | 9 |\n";
    GraphicsLine_Drawer();
    cout<<"| 4 | 5 | 6 |\n";
    GraphicsLine_Drawer();
    cout<<"| 1 | 2 | 3 |\n";
    GraphicsLine_Drawer();
}