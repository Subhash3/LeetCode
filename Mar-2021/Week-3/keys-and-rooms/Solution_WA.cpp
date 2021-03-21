#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool searchForKey(vector<int> keys, int roomNo)
    {
        for (int key : keys)
        {
            if (key == roomNo)
            {
                return true;
            }
        }

        return false;
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int N, i, roomNo;
        vector<bool> openRooms;
        bool found, roomKeyFound;

        N = rooms.size();

        for (roomNo = 1; roomNo < N; roomNo++)
        {
            roomKeyFound = false;
            for (i = 0; i < N; i++)
            {
                if (i == roomNo)
                {
                    continue;
                }
                found = searchForKey(rooms[i], roomNo);
                if (found)
                    printf("Key for room: %d, is found in room: %d\n", roomNo, i);
                else
                    printf("Key for room: %d, is NOT found in room: %d\n", roomNo, i);
                roomKeyFound |= found;
            }
            if (!roomKeyFound)
            {
                return false;
            }
        }

        return true;
    }
};