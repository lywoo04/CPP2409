#include <iostream>
using namespace std;

class User{
protected:
    int hp;
    int itemCnt;
    int x,y;
public:
    User();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP() const;

    void Move(int dx, int dy);
    int GetX() const { return x; }
    int GetY() const { return y; }

    void IncreaseItemCnt();
    int GetItemCnt();

    friend ostream& operator<<(ostream& os, const User& player){ 
        os << "현제 HP는 {" << player.hp << "} 이고, 먹은 아이템은 총 {" << player.itemCnt << "}개 입니다";
        return os;
    }

    void DoAttack();

};

class Warrior:public User
{
public:
    void DoAttack(){
        cout << "베기 사용" << endl;
    }
};

class Magician:public User
{
public:
    void DoAttack(){
        cout << "마법 사용" << endl;
    }
};

int DecreaseLocation(int current_val, int dec_loc);
int IncreaseLocation(int current_val, int inc_loc);