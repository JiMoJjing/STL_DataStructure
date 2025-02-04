#include <iostream>
#include <deque>
#include <stack>

int main()
{
	std::deque<int> dq;

	// 데이터 추가.
	dq.emplace_back(100);
	dq.emplace_back(110);
	dq.emplace_back(120);
	dq.emplace_front(200);

	// 출력.
	for(int ix = 0; ix < (int)dq.size(); ++ix)
	{
		std::cout << dq[ix] << "\n";
	}

	std::cout << "=======================\n";
	// 데이터 추출 후 제거.
	auto data = dq.back();
	dq.pop_back();

	for (auto it = dq.begin(); it != dq.end(); ++it)
	{
		std::cout << *it << "\n";
	}

	std::cin.get();
}