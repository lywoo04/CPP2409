#include <iostream>
using namespace std;

int main()  {
    int floor;
    cout << "몇층을  쌓겠습니까? (5~100): ";
    cin >> floor;
    for (int i =0; i<floor ; i++) {
        for (int j =0; j < floor -1-i ; j++) {
            cout << "S";
        }
        //k 의 조건문을 바꾸었습니다.
        for (int k = floor-2*i -1 ; k <floor; k++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
