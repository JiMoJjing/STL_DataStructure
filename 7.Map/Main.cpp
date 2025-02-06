#include <iostream>
#include <string>
#include <map>
#include <Windows.h>

// ������.
struct Item
{
	std::string name;
	unsigned int kind = 0;
	int price = 0;
	int code = 0;
};

// ������ �����ε�.

std::ostream& operator<<(std::ostream& os, Item item)
{
	return os << "�̸�: " << item.name << ", ����:" << item.price << ", �ڵ�:" << item.code << "\n";
}

int main()
{
	// �� ����.
	std::map<std::string, Item, std::greater<std::string>> items;

	// ������ �߰�.
	items.insert({ "���", {"���", 1, 200, 0} });
	items.insert({ "�ظ�", {"�ظ�", 1, 1000, 4} });
	items.insert({ "����", {"����", 2, 500, 3} });
	
	// ���� Ȯ�� �� ���.
	if (!items.empty())
	{
		std::cout << "����� ������ ��: " << items.size() << "\n";
	}
	for (auto& pair : items)
	{
		std::cout << pair.second;
	}

	// �˻�.
	auto it = items.find("�ظ�");
	if (it != items.end())
	{
		std::cout << "�ظ� �������� �ֽ��ϴ�. �ظ��� ������ " << it->second.price << " �Դϴ�.\n";
	}

	std::cin.get();
}