#include <iostream>
#include <string>
using namespace std;

int main()
{
    int f = 0;

    cin >> f;
 

    int c = (5.0 / 9.0)*(f -32);

    cout << "화씨 온도: " << f << endl;
    cout << "섭씨 온도: " << c << endl;
    
    return 0;
}