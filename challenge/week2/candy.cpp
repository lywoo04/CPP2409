#include <iostream>
#include <string>
using namespace std;

int main()
{
    int money = 0;
    int price = 0;


    cin >> money;
    cin >> price;

    int max = money / price;
    int margin = money % price;

    cout << "현재가지고 있는돈: " << money << endl;
    cout << "캔디의 가격: " << price << endl;
    cout << "최대로 살 수 있는 캔디: " << max << endl;
    cout << "캔디 구입 후 남는 돈: " << margin << endl;


    
    return 0;
}