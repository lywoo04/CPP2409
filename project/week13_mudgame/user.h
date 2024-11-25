#include<iostream>
using namespace std;

class User {
private:
    int hp;
    int item;

public:
    virtual ~User() {} 
    virtual void DecreaseHP(int dec_hp) = 0; 
    virtual void IncreaseHP(int inc_hp) = 0; 
    virtual int GetHP() const = 0; 
    virtual int ItemCnt() const = 0;
    virtual void IncreaseItemCnt(int inc_item) = 0; 
    virtual void DoAttack() const = 0; 

    friend ostream& operator<<(ostream& os, const User& user) {
        os << "현재 체력 : " << user.GetHP() << " , " << "획득 아이템 개수 : " << user.ItemCnt() << endl;
        return os;
    }
};


class Magician : public User {
private:
    int hp;
    int item;

public:
    Magician() : hp(20), item(0) {} 
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override;
    int GetHP() const override;
    int ItemCnt() const override;
    void IncreaseItemCnt(int inc_item) override;
    void DoAttack() const override;

};

class Warrior : public User {
private:
    int hp;
    int item;

public:
    Warrior() : hp(20), item(0) {}
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override;
    int GetHP() const override;
    int ItemCnt() const override;
    void IncreaseItemCnt(int inc_item) override;
    void DoAttack() const override;

};