#include <iostream>
#include <list>

// 아이템 구조체.
struct Item
{
	Item(int code = 0, int price = 0)
		: code(code), price(price)
	{
	}

	int code = 0;
	int price = 0;
};

// 데이터 출력용 연산자 오버로딩.
std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os << "코드: " << item.code << ", 가격: " << item.price;
}

int main()
{
	std::list<Item> itemList;

	// 데이터 추가.
	itemList.emplace_front(Item(1, 200));
	itemList.emplace_front(Item(2, 1000));

	// 뒤에 추가.
	itemList.emplace_back(Item(3, 3000));
	itemList.emplace_back(Item(4, 4500));

	// 출력.
	for (std::list<Item>::iterator it = itemList.begin(); it != itemList.end(); ++it)
	{
		std::cout << *it << "\n";
	}

	//// 삭제.
	//itemList.pop_front();
	std::cout << "=========================\n";

	//itemList.pop_back();
	//std::cout << "=========================\n" << itemList.back() << "\n";

	itemList.emplace_back(Item(8, 222));
	itemList.emplace_back(Item(11, 333));
	itemList.emplace_back(Item(7, 444));
	itemList.emplace_back(Item(6, 555));

	itemList.sort([](const Item& left, const Item& right)
		{
			return left.price < right.price;
		});

	// 출력.
	for (std::list<Item>::iterator it = itemList.begin(); it != itemList.end(); ++it)
	{
		std::cout << *it << "\n";
	}

	std::cin.get();
}