#include <iostream>
#include <string>
#include <set>
#include <memory>

using namespace std;

class Player
{
public:
	Player(int level = 0) : level(level)
	{
	}

	~Player()
	{
	}

	int level = 0;
};

// 레벨이 높은 순으로 정렬
struct LevelCompare
{
	bool operator() (shared_ptr<Player> player1, shared_ptr<Player> player2) const
	{
		return player1->level > player2->level;
	}
};

int main()
{
	shared_ptr<Player> player1 = make_shared<Player>(10);
	shared_ptr<Player> player2 = make_shared<Player>(45);
	shared_ptr<Player> player3 = make_shared<Player>(5);
	shared_ptr<Player> player4 = make_shared<Player>(16);

	set<shared_ptr<Player>, LevelCompare> playerList = { player1, player2, player3, player4 };

	// 정 방향으로 출력( 레벨이 높은 순으로).
	for (auto it = playerList.begin(); it != playerList.end(); ++it)
	{
		cout << (*it)->level << endl;
	}

	cout << endl;

	// 역 방향으로 출력( 레벨이 낮은 순으로)
	for (auto it = playerList.rbegin(); it != playerList.rend(); ++it)
	{
		cout << (*it)->level << endl;
	}

	cout << endl;

	// player4를검색
	auto search = playerList.find(player4);
	if (search != playerList.end())
	{
		cout << "player4를 찾았습니다" << endl;
		cout << "player4 삭제" << endl;
		playerList.erase(search);
	}
	else
	{
		cout << "player4를 못찾았습니다" << endl;
	}

	cout << endl;

	cout << "전체 Player 수 : " << playerList.size() << endl;

	cout << endl;

	playerList.clear();
	if (playerList.empty())
	{
		cout << "Player가 없습니다." << endl;
	}

	cin.get();
}