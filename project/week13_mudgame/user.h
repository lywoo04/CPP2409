#include <iostream>
using namespace std;

class User{
protected:
    int hp;
    int itemCnt;
    int x,y;
public:
    User();
    virtual void DecreaseHP(int dec_hp);
    virtual void IncreaseHP(int inc_hp);
    virtual int GetHP() const;

    virtual void Move(int dx, int dy);
    virtual int GetX() const { return x; }
    virtual int GetY() const { return y; }

    virtual void IncreaseItemCnt();
    virtual int GetItemCnt();

    friend ostream& operator<<(ostream& os, const User& player){ 
        os << "현제 HP는 {" << player.hp << "} 이고, 먹은 아이템은 총 {" << player.itemCnt << "}개 입니다";
        return os;
    }

    void DoAttack();

};

