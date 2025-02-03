#include <iostream>
#include <vector>

int main()
{
	// vector ���� ����.
	std::vector<int> vector1;

	// ������� Ȯ��.
	// if(vector1.size() == 0)
	if(vector1.empty())
	{
		std::cout << "Vector �� �����. \n";
	}
	vector1.reserve(1000);
	// �ڷ� ����.
	for (int ix = 0; ix < 1000; ++ix)
	{
		// ������ push_back ���ε� emplace_back���� ���׷��̵� �Ǿ� ����.
		vector1.emplace_back(ix + 1);
	}

	// ��� ����.
	for (auto it = vector1.begin(); it != vector1.end();)
	{
		it = vector1.erase(it);
		if (it - vector1.begin() + 10 < vector1.size())
		{
			it += 10;
		}
		else
		{
			break;
		}
	}

	//// ��� ����.
	//for (int ix = 0; ix < 1000; ix += 10)
	//{
	//	// ������ ���ϴ� ��ġ�� �ݺ���(iterator) ����.
	//	auto iter = vector1.begin() + ix;

	//	// �տ��� ���� �ݺ��ڸ� Ȱ���� �迭 ���� ����.
	//	vector1.erase(iter);
	//}

	// ��� �Ұ�.
	// ���� ���� ������ �������� ��쿡�� delete �ؾ���.
	vector1.clear();

	if (vector1.empty())
	{
		std::cout << "Vector �� �����. \n";
	}

	// ũ�� ����.
	// vector1.resize(int size);

	// ���� Ȯ��.
	// ���Ҵ� ���� ���� / ���� ����ȭ.
	// vector1.reserve(int capacity);

	// Capacity ���� �� ���.
	vector1.shrink_to_fit();

	std::cin.get();

}