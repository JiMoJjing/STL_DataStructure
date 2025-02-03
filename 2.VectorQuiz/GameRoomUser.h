#pragma once
#include <iostream>
#include <vector>
#include <string>


using namespace std;

// ���� ����
struct UserInfo
{

	UserInfo(const char* userName, int level, int exp)
		: userName(userName), level(level), exp(exp)
	{

	}

	string userName; // �̸�
	int level; // ����
	int exp; // ����ġ
};


// ���� ���� ������ �����ϴ� Ŭ����
// �濡�� �ִ� 6����� ��� �� �� �ִ�.
// �濡 ��� ���� ���� �� ���� ���� ��� �� ����� ������ �ȴ�.
class GameRoomUser
{
public:
	GameRoomUser();
	~GameRoomUser();

	// �濡 ���� �߰�
	bool AddUser(UserInfo& userInfo);

	// �濡�� ���� ����.
	// ���� ������ ������ userName�� ���ο� ������ �̸��� ���� �ؾ� �ȴ�.
	bool DeleteUser(const char* userName);

	// �濡 ������ ������ Ȯ��. ������ true ��ȯ
	bool IsEmpty();

	// �濡 ������ �� á���� Ȯ��. �� á�ٸ� true ��ȯ
	bool IsFull();

	// Ư�� ������ ����
	UserInfo& GetUserOfName(const char* userName);

	// ������ ���� ����
	UserInfo& GetMasterUser();

	// ���� �������� �濡 ��� �� ������ ����
	UserInfo& GetUserOfLastOrder();

	// Ư�� ������ ��� �� ������ �i�Ƴ���.
	bool BanUser(int orderNum);

	// ��� ������ �����Ѵ�.
	void Clear();

	// ��� ���� ���.
	void GetAllUser();

private:
	vector<UserInfo> users;
	string masterUserName; // ������ �̸�
	int maxCount = 6;
};