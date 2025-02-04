#include <iostream>
#include <unordered_map>

class GameCharacter
{

public:
	GameCharacter() = default;
	GameCharacter(int code, int level, int money)
		: code(code), level(level), money(money)
	{

	}

	// Getter.
	const int Code() const { return code; }
	const int Level() const { return level; }
	const int Money() const { return money; }

	friend std::ostream& operator<<(std::ostream& os, const GameCharacter& character)
	{
		return os << "코드: " << character.code << " | 레벨: " << character.level << " | 돈: " << character.money << "\n";
	}

private:
	int code = 0;
	int level = 0;
	int money = 0;
};

int main()
{
	std::unordered_map<int, GameCharacter> characters;

	GameCharacter character1(10, 1, 30000);
	characters.insert(std::make_pair(character1.Code(), character1));

	GameCharacter character2(15, 3, 20000);
	characters.insert(std::make_pair(character2.Code(), character2));

	GameCharacter character3(12, 3, 20000);
	characters.insert(std::make_pair(character3.Code(), character3));

	GameCharacter character4(14, 3, 20000);
	characters.insert(std::make_pair(character4.Code(), character4));

	GameCharacter character5(11, 3, 20000);
	characters.insert(std::make_pair(character5.Code(), character5));

	for (auto& p : characters)
	{
		std::cout << p.second;
	}

	auto it = characters.find(15);
	if (it != characters.end())
	{
		std::cout << it->second;
	}
	else
	{
		std::cout << "검색에 실패\n";
	}

	std::cin.get();
}