#include <iostream>
using namespace std;

int main()  {
    int userInput;

    cout << "정수를 10번 입력하세요 (0을 입력하면 종료)";
    int i = 0;

    for ( int j = 1; j <= 10; j++)  {
        cin >> userInput;
        if (userInput == 0) {
            break;
        }

        cout << "입력값: " << userInput << "횟수 :" << i++ << endl;

    

    }
    cout << "종료 되었습니다.";
        
    return 0;

}