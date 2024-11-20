#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int user_y);
void displayMap(vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y);

int checkMap(vector<vector<int>>& map, int user_x, int user_Y, User& player);

bool checkUser(User& player);

struct locateXY {
	int x;
	int y;
};

locateXY userMoving(int user_x, int user_y, string user_input);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
							{1, 0, 0, 2, 0},
							{0, 0, 0, 0, 0},
							{0, 2, 3, 0, 0},
							{3, 0, 0, 0, 2} };

	// 유저의 위치를 저장할 변수
	locateXY user = {0, 0};
	
	User player;

	// 게임 시작 
	while (true) { // 사용자에게 계속 입력받기 위해 무한 루프
        cout << "현재 체력은 " << player.GetHP() << "입니다" << endl;

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "명령어를 입력하세요 (up,down,left,right,map,infor,quit): ";
		cin >> user_input;
		

		if (user_input == "map") {
			displayMap(map, user.x, user.y);
			player.IncreaseHP(1);
		}
		else if (user_input == "quit") {
			cout << "종료합니다.";
			break;
		}
		else if (user_input == "infor") {
			player.IncreaseHP(1);
			cout << player << endl;
		}
		else if (user_input == "up" || user_input == "down" 
		|| user_input == "left" || user_input == "right") {
			locateXY newLocation = userMoving(user.x, user.y, user_input); // 이동 함수 호출
            
			if (checkXY(newLocation.x, newLocation.y)) {
				user = newLocation;
				displayMap(map, user.x, user.y); 
			}
			else {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다" << endl;
			}
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			player.IncreaseHP(1);
		}

		// 목적지에 도달했는지 체크
		if( checkGoal(map, user.x, user.y)) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
        
		checkMap(map, user.x, user.y, player);

		player.DecreaseHP(1);

		if (!checkUser(player)) {
            cout << "실패" << endl << "게임 종료";
            break;
        }

	}
	return 0;
}

bool checkUser(User& player) {
	return player.GetHP() > 0;
}

locateXY userMoving(int user_x, int user_y, string user_input) {
	locateXY newLocation = {user_x, user_y};

	if (user_input == "up") {
        newLocation.y -= 1;
    } else if (user_input == "down") {
        newLocation.y += 1;
    } else if (user_input == "left") {
        newLocation.x -= 1;
    } else if (user_input == "right") {
        newLocation.x += 1;
    } 

	return newLocation;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>>& map, int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
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
		cout << endl << " -------------------------------- " << endl;
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

int checkMap(vector<vector<int>>& map, int user_x, int user_y, User& player) {
    int mapState = map[user_y][user_x];
    
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    switch (mapState) {
        case 1:
			cout << "아이템을 주웠습니다" << endl;
			player.IncreaseItemCnt();
			break;
		case 2:
			cout << "적을 만났습니다" << endl << "LP 2 감소" << endl;
			player.DecreaseHP(2);
			break;
        case 3:
			cout << "포션을 마셨습니다" << endl << "LP 2 증가" << endl;
			player.IncreaseHP(2);
			break;    
    }
	return player.GetHP();
}

