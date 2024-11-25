#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int user_y);
void displayMap(vector<vector<int>>& map, string character, int user_x, int user_y);
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y);
int checkMap(vector<vector<int>>& map,int user_x, int user_y, User& user);
bool checkUserHP(const User& user);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
								{1, 0, 0, 2, 0},
								{0, 0, 0, 0, 0},
								{0, 2, 3, 0, 0},
								{3, 0, 0, 0, 2} };

    int user_x = 0;  // 두 유저의 위치 (x 좌표)
    int user_y = 0;  // 두 유저의 위치 (y 좌표)

	int currentPlayer = 1;
	User* user = nullptr;

	Warrior warrior;
	Magician magician;

	string character = "";

	int choice;
        cout << "직업을 선택하세요 : 1. 전사 2. 마법사" << endl;
        cin >> choice;
        if(choice == 1){
        	user = new Warrior;
			character = "warrrior";
        	cout << "전사를 선택하셨습니다." << endl;
        }
        else if ( choice == 2) {
        	user = new Magician;
			character = "magician";
        	cout << "마법사를 선택하셨습니다." << endl;
        }
        else {
        	cout << "잘못된 선택입니다." << endl;
        }
	
	// 게임 시작 
	while (true) { // 사용자에게 계속 입력받기 위해 무한 루프
		
        cout << endl << "현재 캐릭터는 " << character << "입니다" << endl;
		cout << character << "의 체력은 " << user->GetHP() << "입니다" << endl;

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "명령어를 입력하세요 (up,down,left,right,map,infor,attack,quit): ";
		cin >> user_input;
		

		if (user_input == "map") {
			displayMap(map, character, user_x, user_y);
			continue;
		}
		else if (user_input == "quit") {
			cout << "종료합니다.";
			break;
		}
		else if (user_input == "infor") {
			cout << character << "의 " << *user << endl;
			continue;
		}
		else if (user_input == "attack") {
			user->DoAttack();
		}
		else if (user_input == "up" || user_input == "down" 
		|| user_input == "left" || user_input == "right") {
			
			int dx = 0;
			int dy = 0;
			
			if (user_input == "up") {
				dy = -1;
				user_y += dy;
			}
    		else if (user_input == "down") {
				dy = +1;
				user_y += dy;
			}
    		else if (user_input == "left")  {
				dx = -1;
				user_x += dx;
			}
    		else if (user_input == "right")  {
				dx = +1;
				user_x += dx;
			}

            
			if (checkXY(user_x, user_y)) {
				displayMap(map, character, user_x, user_y); 
			}
			else {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다" << endl;
				user_x -=dx;
				user_y -=dy;
			}
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		if( checkGoal(map, user_x, user_y)) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
        
		checkMap(map, user_x, user_y, *user);

		user->DecreaseHP(1);

		if (!checkUserHP(*user)) {
            cout << "실패" << endl << "게임 종료";
            break;
        }


	}
	return 0;
}

bool checkUserHP(const User& user) {
	return user.GetHP() > 0 ;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>>& map, string character, int user_x, int user_y) {
	
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				if (character == "warrior") {
					cout << "  war |";
				}
				else {
					cout << "  mag |";
				}
				
			}
			else {
				int posState = map[i][j];
				switch (posState) {
					case 0: cout << "      |"; break;
					case 1: cout << "아이템|"; break;
					case 2: cout << "  적  |"; break;
					case 3: cout << " 포션 |"; break;
					case 4: cout << "목적지|"; break;
				}
			}
		}
		cout << endl << "-----------------------------------" << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int user_y) {
	return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) ;
} 

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y) {
	// 목적지 도착하면
	return (map[user_y][user_x] == 4) ;
}

int checkMap(vector<vector<int>>& map, int user_x, int user_y, User& user) {
    int mapState = map[user_y][user_x];
    
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    switch (mapState) {
        case 1:
			cout << "아이템을 주웠습니다" << endl;
			user.IncreaseItemCnt(1);
			break;
		case 2:
			cout << "적을 만났습니다" << endl << "LP 2 감소" << endl;
			user.DecreaseHP(2);
			break;
        case 3:
			cout << "포션을 마셨습니다" << endl << "LP 2 증가" << endl;
			user.IncreaseHP(2);
			break;    
    }
	return user.GetHP();
}

