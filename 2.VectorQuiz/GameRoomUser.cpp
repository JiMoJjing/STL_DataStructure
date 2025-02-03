#include "GameRoomUser.h"

GameRoomUser::GameRoomUser()
{
}

GameRoomUser::~GameRoomUser()
{
}

bool GameRoomUser::AddUser(UserInfo& userInfo)
{
    if (IsEmpty())
    {
        masterUserName = userInfo.userName;
    }
    else if (IsFull())
    {
        std::cout << "AddUser - 방이 꽉 찼습니다. ( 참여시도자 정보 - " << "Name: " << userInfo.userName << " / level: " << userInfo.level << "/ exp: " << userInfo.exp << " )\n";
        return false;
    }

    users.emplace_back(userInfo);

    return true;
}

bool GameRoomUser::DeleteUser(const char* userName)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        string deleteUserName = (*it).userName;

        if (deleteUserName == userName)
        {
            users.erase(it);

            if (deleteUserName == masterUserName)
            {
                if(!IsEmpty())
                {
                    masterUserName = users.front().userName;
                }
            }

            std::cout << "추방 된 유저 - " << deleteUserName << "\n";
            return true;
        }
    }
    
    return false;
}

bool GameRoomUser::IsEmpty()
{
    return users.empty();
}

bool GameRoomUser::IsFull()
{
    return users.size() == maxCount;
}

UserInfo& GameRoomUser::GetUserOfName(const char* userName)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if ((*it).userName == userName)
        {
            return *it;
        }
    }

    UserInfo* nonUser = new UserInfo("None", 0, 0);

    return *nonUser;
}

UserInfo& GameRoomUser::GetMasterUser()
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if ((*it).userName == masterUserName)
        {
            return *it;
        }
    }
}

UserInfo& GameRoomUser::GetUserOfLastOrder()
{
    return users.back();
}

bool GameRoomUser::BanUser(int orderNum)
{
    --orderNum;

    if (orderNum >= users.size())
    {
        std::cout << "BanUser - Unvalid orderNum: " << orderNum + 1 << " (UserNum: " << users.size() << ")\n";
        return false;
    }

    DeleteUser(users[orderNum].userName.c_str());
    return true;
}

void GameRoomUser::Clear()
{
    users.clear();
}

void GameRoomUser::GetAllUser()
{
    std::cout << "User List ========================== \n";
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if ((*it).userName == masterUserName)
        {
            std::cout << " " << it - users.begin() + 1 << ". "  << "Name: ** " << (*it).userName << " ** / level: " << (*it).level << "/ exp: " << (*it).exp << "\n";
        }
        else
        {
            std::cout << " " << it - users.begin() + 1 << ". " << "Name: " << (*it).userName << " / level: " << (*it).level << "/ exp: " << (*it).exp << "\n";
        }
    }
    std::cout << "==================================== \n";
}
