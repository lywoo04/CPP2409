#include <iostream>
using namespace std;

int main()  {
    int floor;
    cout << "몇층을  쌓겠습니까? (5~100): ";
    cin >> floor;
    for (int i =floor; i > 0 ; i--) {
        for (int j =0; j < floor -i ; j++) {
            cout << "S";
        }
        //k의 조건문을 수정했습니다.
        for (int k = floor -2* i +1 ; k <floor; k++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
