#include <iostream>
#include <string>
using namespace std;

auto add(int x, int y)
{
    return x + y;
}

int main()
{
    auto sum = add(5,6);

    cout << sum << endl;
    return 0;
}