#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v;
    int score;
    int total = 0;
    int count= 0;

    while (true) {
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> score;
        if (score == -1) {
            break;
        }

        v.push_back(score);
        count += 1;
    }
    
    while (v.empty() !=true) {
        total += v.back();
        v.pop_back();
    }
    
    cout << "성적 평균 = " << total/count ;
}