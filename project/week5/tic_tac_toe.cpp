#include <iostream>
using namespace std;

int main()  {
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y;

    for ( x= 0; x < numCell; x++) {
        for (y =0 ; y < numCell ; y++) {
            board[x][y] = ' ';
        }
    }

    int k = 0;
    char currentUser = 'X';

    // while 탈출을 위해 num으로 제어
    int num = 1;
    while(num) {
        //1. 누구의 차례인지 출력
        switch (k%2) {
            case 0:
                cout << "첫번째 유저(X)의 차례입니다 -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << "두번째 유저(O)의 차례입니다 -> ";
                currentUser = 'O';
                break;
        }

        //2. 좌표 입력 받기
        cout << "(x,y) 좌표를 입력하세요 : ";
        cin >> x >> y;
    
        //3. 입력 받은 좌표 유효성 체크
        if (x >= numCell || y >= numCell) {
            cout << x << ", " << y << ": " ;
            cout << "x와 y 중 하나가 칸을 벗어났습니다." << endl;
            continue;
        }
        if (board[x][y] != ' ') {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        //4. 좌표에 O/X 놓기
        board[x][y] = currentUser;

        //5. 현재 보드판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++) {
                cout << " " << board[i][j]; //표시를 중앙으로 옯김
                if (j == numCell -1) {
                    break;
                }
                cout << " |";
            }
            cout << endl;

        }
        cout << "---|---|---" << endl;
        
        //6.  빙고시 승자 출력 후 종료
            //가로 세로 빙고
        for (int l =0 ; l < numCell ; l++) {
            if (board[l][0] == board[l][1] ) {
                if (board[l][0]== board[l][2]) {
                    if (board[l][0] == currentUser) {
                        cout << "BINGO! " << currentUser << "가 승리하셨습니다." ;
                        num = 0;
                    }
                    
                }
            } 
            else if (board[0][l] == board[1][l]) {
                if (board[0][l] == board[2][l]) {
                    if (board[0][l] == currentUser) {
                        cout << "BINGO! " << currentUser << "가 승리하셨습니다." ;
                        num = 0;
                    }
                }
                
            }   
        }
            //대각선 빙고
        if (board[0][0] == board[1][1]) {
            if (board[0][0]== board[2][2]) {
                if (board[0][0] == currentUser) {
                        cout << "BINGO! " << currentUser << "가 승리하셨습니다." ;
                        num = 0;
                }
            }
        }
        if (board[0][2] == board[1][1]) {
            if (board[0][2]== board[2][0]) {
                if (board[0][2] == currentUser) {
                        cout << "BINGO! " << currentUser << "가 승리하셨습니다." ;
                        num = 0;
                    }
            }
        }
        
        k++;

        //7. 모든 칸이 찾으면 종료
        if ( k == 9) {
            cout << "둘 자리가 없습니다!" << endl << "무승부" << endl << "게임 종료" << endl;
            break;
        }
    }

    
    return 0;
}
