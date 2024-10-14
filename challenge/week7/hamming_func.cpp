#include <iostream>
#include <string>
using namespace std;;

string toLowerStr(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}


int calcHammingDist(string a, string b) {
    int count =0;
    for (int i = 0; i < a.length() ; i++){
            if (a[i] != b[i]) {
                count += 1;
            }
        }
    return count;    
}

int main(){
    string s1, s2;


    cout << "DNA1: ";
    cin >> s1;

    cout << "DNA2: ";
    cin >> s2;

    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);

    int num = 1;
    do {
        if (s1.length() != s2.length()){
            cout << "오류: 길이가 다름" <<endl;
            
            cout << "DNA1: ";
            cin >> s1;

            cout << "DNA2: ";
            cin >> s2;
        }
        else {
            int distance = calcHammingDist(s1, s2);
            
            cout << "해밍 거리는 " << distance << endl;
            num = 0;
        }

    } while(num);

    return 0;
    
}
