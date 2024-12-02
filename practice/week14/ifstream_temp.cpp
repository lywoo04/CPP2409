#include <iostream>
#include <fstream>

using namespace std;

class TempData {
public:
    int hour;
    double temprature;
};

int main() {
    ifstream is{"temp.txt"};
    if (!is) {
        cerr << "파일 열기에 실패했습니다" << endl;
        exit(1);
    }

    int hour;
    double temperature;

    while (is >> hour >> temperature) {
        cout << hour << "시: 온도 " << temperature << endl;
    }

    return 0;
}