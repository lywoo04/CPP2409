#include <iostream>
#include <string>
using namespace std;

int main()  {
     const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요. " << endl;

    for (int i = 0; i < maxPeople ; i++) {
        cout <<"사람 " << i + 1 << "의 이름 :";
        cin >> names[i];
        cout << "사람 " << i +1 << "의 나이 :";
        cin >> ages[i];
    }
    int oldest =0 ;
    int youngest =0 ;

    for (int i =0 ; i < maxPeople ; i++){
        if (oldest <= ages[i]) {
            oldest = i;
        }
    }
    
    for (int i =0 ; i < maxPeople ; i++){
        if (youngest >= ages[i]) {
            youngest = i;
        }
    }


    while(1) {
        int num ;
        cout << "메뉴를 선택하세요: "<< endl << "1.가장 나이가 많은 사람 출력" << endl << "2.가장 나이가 적은 사람 출력" << endl << "3. 종료";
        cin >> num;
        
        switch (num) {
            case 1:
                cout << names[oldest] << endl;
                break;
            case 2:
                cout << names[youngest] << endl;
                break;
            default:
                num = 0;
                break;
        }
        
        if (num == 0) {
            cout << "종료"; 
            break;
        }
    }
    






}
