#include <unordered_map>
#include <stack>

using namespace std;

class FreqStack
{
public:
    unordered_map<int, int> numsToFreqMap;
    unordered_map<int, stack<int>> freqToStackMap;
    int maxFreq = -1;

    FreqStack()
    {
    }

    void printMap()
    {
        for (auto i : this->numsToFreqMap)
        {
            printf("%d : %d\n", i.first, i.second);
        }
        printf("MAXFREQ: %d\n\n", this->maxFreq);
        return;
    }

    void push(int x)
    {
        // printf("PUSH(%d)\n", x);
        if (this->numsToFreqMap.find(x) != this->numsToFreqMap.end())
        {
            this->numsToFreqMap[x] += 1;
        }
        else
        {
            this->numsToFreqMap[x] = 1;
        }

        if (this->maxFreq < this->numsToFreqMap[x])
        {
            this->maxFreq = this->numsToFreqMap[x];
        }

        this->freqToStackMap[this->numsToFreqMap[x]].push(x);
        // printMap();

        return;
    }

    int pop()
    {
        // printf("POP\n");
        int numWithMaxFreq;

        numWithMaxFreq = this->freqToStackMap[this->maxFreq].top();
        // printf("Num with max freq: %d\n", numWithMaxFreq);
        this->numsToFreqMap[numWithMaxFreq] -= 1;
        this->freqToStackMap[this->maxFreq].pop();

        if (this->freqToStackMap[this->maxFreq].size() == 0)
        {
            this->maxFreq -= 1;
        }

        // printMap();
        return numWithMaxFreq;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */