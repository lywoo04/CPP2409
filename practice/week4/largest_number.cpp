#include <iostream>
using namespace std;

int main()  {
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오.: ";
    cin >> a >> b >> c;

    //>= 표현을 사용해서 두 수나 세 수가 같을 경우를 추가했습니다.
    if (a >= b && a >= c)
        largest = a;
    else if (b >= a && b >= c)
        largest = b;     
    else if (c >= a && c >= b)
        largest = c;

    cout << "가장 큰 정수는" << largest << endl; 

    return 0;
}
