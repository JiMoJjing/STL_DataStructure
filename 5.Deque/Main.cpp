#include <iostream>
#include <deque>
#include <stack>

int main()
{
	std::deque<int> dq;

	// ������ �߰�.
	dq.emplace_back(100);
	dq.emplace_back(110);
	dq.emplace_back(120);
	dq.emplace_front(200);

	// ���.
	for(int ix = 0; ix < (int)dq.size(); ++ix)
	{
		std::cout << dq[ix] << "\n";
	}

	std::cout << "=======================\n";
	// ������ ���� �� ����.
	auto data = dq.back();
	dq.pop_back();

	for (auto it = dq.begin(); it != dq.end(); ++it)
	{
		std::cout << *it << "\n";
	}

	std::cin.get();
}