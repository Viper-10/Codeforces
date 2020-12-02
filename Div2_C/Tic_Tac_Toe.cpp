#include<cstdio>
using namespace std; 
int HasPlayerWon(char arr[][3], char CurrPlayer){

    int LeftDans = 1, RightDans = 1, RowsAns = 1, ColsAns = 1; 

    for(int i = 0;i < 3; i++){
        LeftDans = (arr[i][i] == CurrPlayer && LeftDans == 1) ? 1 : 0; 
        RightDans = (arr[i][3-i-1] == CurrPlayer && RightDans == 1) ? 1 : 0; 
    }

    for(int i = 0;i < 3; ++i){
        RowsAns = 1, ColsAns = 1; 
        for(int j= 0; j < 3; ++j){
            RowsAns = (arr[i][j] == CurrPlayer && RowsAns == 1) ? 1 : 0;
            ColsAns = (arr[j][i] == CurrPlayer && ColsAns == 1) ? 1 : 0; 
        }

        if(RowsAns == 1 || ColsAns == 1) break; 
    }

    return (RowsAns || ColsAns || LeftDans || RightDans); 
}
int main(){

    char arr[3][3]; 

    int Xcount = 0, Ocount = 0; 

    for(int i = 0;i < 9; ++i){
        scanf(" %c", &arr[i/3][i%3]); 
        if(arr[i/3][i%3] == 'X') Xcount++; 
        else if(arr[i/3][i%3] == '0') Ocount++;  
    }


    if(Ocount > Xcount || Xcount-Ocount > 1 || Xcount > 5 || Ocount > 4){
        puts("illegal"); 
    }    

    else if(Xcount < 3){
        if(Xcount ==  Ocount){
            puts("first"); 
        }

        else puts("second"); 

    }

    else if(Xcount >= 3){
        int SaveX = Xcount; 
        int SaveO = Ocount; 

        int ansX = HasPlayerWon(arr, 'X');
        int ansO = HasPlayerWon(arr, '0'); 

        Xcount = SaveX; 
        Ocount = SaveO; 

        if(ansO == 1 && ansX == 1 || (ansO == 1 && Xcount == Ocount+1) || (ansX == 1 && Xcount == Ocount)){
            puts("illegal"); 
        }
        else if(ansO == 1){
            puts("the second player won"); 
        }

        else if(ansX == 1){
            puts("the first player won"); 
        }

        else if(Xcount == 5 && Ocount == 4){
            puts("draw"); 
        }

        else if(Xcount == Ocount){
            puts("first"); 
        }

        else{
            puts("second"); 
        }
    }



    return 0; 
}