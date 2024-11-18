#include <iostream>
using namespace std;

class User{
private:
    int hp;
    int itemCnt;
public:
    User();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP();

    void IncreaseItemCnt();
    int GetItemCnt();

    friend ostream& operator<<(ostream& os, const User& player){ 
        os << "현제 HP는 {" << player.hp << "} 이고, 먹은 아이템은 총 {" << player.itemCnt << "}개 입니다" << endl;
        return os;
    }


};