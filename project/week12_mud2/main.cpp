#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int user_y);
void displayMap(vector<vector<int>>& map, const User& warrior, const User& magician);
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y);
int checkMap(vector<vector<int>>& map,int user_x, int user_y, User& user);
bool checkUserHP(const User& warrior, const User& magician);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
								{1, 0, 0, 2, 0},
								{0, 0, 0, 0, 0},
								{0, 2, 3, 0, 0},
								{3, 0, 0, 0, 2} };

	int currentPlayer = 0;
	Warrior warrior;
	Magician magician;
	User* players[2] = {&warrior, &magician};
	string character;

	// 게임 시작 
	while (true) { // 사용자에게 계속 입력받기 위해 무한 루프
		if (currentPlayer == 0) {
			character = "warrior";
		}
		else {
			character = "magician";
		}
        cout << endl << "현재 캐릭터는 " << character << "입니다" << endl;
		cout << character << "의 체력은 " << players[currentPlayer]->GetHP() << "입니다" << endl;

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "명령어를 입력하세요 (up,down,left,right,map,infor,attack,quit): ";
		cin >> user_input;
		

		if (user_input == "map") {
			displayMap(map, warrior, magician);
			continue;
		}
		else if (user_input == "quit") {
			cout << "종료합니다.";
			break;
		}
		else if (user_input == "infor") {
			cout << character << "의 " << *players[currentPlayer] << endl;
			continue;
		}
		else if (user_input == "attack") {
			players[currentPlayer]->DoAttack();
		}
		else if (user_input == "up" || user_input == "down" 
		|| user_input == "left" || user_input == "right") {
			int dx = 0, dy = 0;
			
			if (user_input == "up") dy = -1;
    		else if (user_input == "down") dy = 1;
    		else if (user_input == "left") dx = -1;
    		else if (user_input == "right") dx = 1;

			players[currentPlayer]->Move(dx,dy); 
            
			if (checkXY(players[currentPlayer]->GetX(), players[currentPlayer]->GetY())) {
				displayMap(map, warrior, magician); 
			}
			else {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다" << endl;
				players[currentPlayer]->Move(-dx, -dy);
			}
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		if( checkGoal(map, players[currentPlayer]->GetX(), players[currentPlayer]->GetY())) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
        
		checkMap(map, players[currentPlayer]->GetX(), players[currentPlayer]->GetY(), *players[currentPlayer]);

		players[currentPlayer]->DecreaseHP(1);

		if (!checkUserHP(warrior, magician)) {
            cout << "실패" << endl << "게임 종료";
            break;
        }

		currentPlayer = (currentPlayer + 1)%2;

	}
	return 0;
}

bool checkUserHP(const User& warrior, const User& magician) {
	return warrior.GetHP() > 0 && magician.GetHP() > 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>>& map, const User& warrior, const User& magician) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == warrior.GetY() && j == warrior.GetX() &&
			i == magician.GetY() && j == magician.GetX()) {
				cout << " W&M  |";
			}
			else if (i == warrior.GetY() && j == warrior.GetX()) {
                cout << " WAR  |";
            }
			else if (i == magician.GetY() && j == magician.GetX()) {
                cout << " MAG  |";
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
			user.IncreaseItemCnt();
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

