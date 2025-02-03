#include <iostream>
#include <vector>

int main()
{
	// vector 변수 선언.
	std::vector<int> vector1;

	// 비었는지 확인.
	// if(vector1.size() == 0)
	if(vector1.empty())
	{
		std::cout << "Vector 가 비었음. \n";
	}
	vector1.reserve(1000);
	// 자료 삽입.
	for (int ix = 0; ix < 1000; ++ix)
	{
		// 지금은 push_back 내부도 emplace_back으로 업그레이드 되어 있음.
		vector1.emplace_back(ix + 1);
	}

	// 요소 삭제.
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

	//// 요소 삭제.
	//for (int ix = 0; ix < 1000; ix += 10)
	//{
	//	// 삭제를 원하는 위치의 반복자(iterator) 저장.
	//	auto iter = vector1.begin() + ix;

	//	// 앞에서 구한 반복자를 활용해 배열 원소 삭제.
	//	vector1.erase(iter);
	//}

	// 모두 소거.
	// 내부 저장 변수가 포인터인 경우에는 delete 해야함.
	vector1.clear();

	if (vector1.empty())
	{
		std::cout << "Vector 가 비었음. \n";
	}

	// 크기 조정.
	// vector1.resize(int size);

	// 공간 확보.
	// 재할당 방지 목적 / 공간 최적화.
	// vector1.reserve(int capacity);

	// Capacity 줄일 때 사용.
	vector1.shrink_to_fit();

	std::cin.get();

}