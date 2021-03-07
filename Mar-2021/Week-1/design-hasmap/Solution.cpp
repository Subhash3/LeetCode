#include <bits/stdc++.h>

using namespace std;

class MyHashMap
{
public:
    vector<int> arr;
    int size = 0;
    int MAX_SIZE = 10000001;

    /** Initialize your data structure here. */
    MyHashMap()
    {
        printMap();
    }

    void printMap()
    {
        int i;
        printf("[");
        fflush(NULL);
        for (i = 0; i < this->size; i++)
        {
            printf("(%d : %d)", i, this->arr[i]);
            fflush(NULL);
        }
        printf("\b\b]\n");
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        printf("put(%d, %d)\n", key, value);
        int i;

        if (key >= this->size)
        {
            printf("key: %d, >= size: %d\n", key, this->size);
            for (i = this->size; i <= key; i++)
            {
                this->arr.push_back(-1);
                size += 1;
            }
        }
        this->arr[key] = value;
        printMap();

        return;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        printf("get(%d)\n", key);
        printMap();
        if (key >= this->size)
        {
            return -1;
        }

        printf("Retuning %d\n", this->arr[key]);
        return this->arr[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        printf("remove(%d)\n", key);
        if (key >= this->size)
        {
            return;
        }
        this->arr[key] = -1;
        printMap();

        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */