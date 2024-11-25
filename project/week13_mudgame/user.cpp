#include "user.h"

class Warrior:public User
{
public:
    void DoAttack(){
        cout << "베기 사용" << endl;
    }
    Warrior() {
        hp = 20 ;
        itemCnt = 0;
        x = 0;
        y = 0;
    }
    void DecreaseHP(int dec_hp) {
        hp -= dec_hp;
        if (hp < 0) {
            hp = 0;
        }
    }

    void IncreaseHP(int inc_hp) {
        hp += inc_hp;
    }

    int GetHP() const{
        return hp;
    }

    void IncreaseItemCnt(){
        itemCnt += 1;
    }
    
    int GetItemCnt() {
        return itemCnt;
    }

    void Move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};


class Magician:public User
{
public:
    void DoAttack(){
        cout << "마법 사용" << endl;
    }
    Magician() {
        hp = 20 ;
        itemCnt = 0;
        x = 0;
        y = 0;
    }
    void DecreaseHP(int dec_hp) {
        hp -= dec_hp;
        if (hp < 0) {
            hp = 0;
        }
    }

    void IncreaseHP(int inc_hp) {
        hp += inc_hp;
    }

    int GetHP() const{
        return hp;
    }

    void IncreaseItemCnt(){
        itemCnt += 1;
    }

    int GetItemCnt() {
        return itemCnt;
    }

    void Move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};