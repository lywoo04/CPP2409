#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "사과";
    string s2;
    //s2 = s1 + " " + 10 + "개"; 문자열과 정수끼리 직접더하지는 못하고 to_string 사용 
    s2 = s1 + " " + to_string(10) + "개";

    cout << s2 << endl;
    return 0;
}