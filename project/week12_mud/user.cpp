#include "user.h"

User::User() {
    hp = 20 ;
    itemCnt = 0;
}
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) {
        hp = 0;
    }
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int User::GetHP() {
    return hp;
}

void User::IncreaseItemCnt(){
    itemCnt += 1;

}

int User::GetItemCnt() {
    return itemCnt;
}