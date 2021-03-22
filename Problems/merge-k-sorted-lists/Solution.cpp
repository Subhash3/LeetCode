#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define MAX_HEAP_TYPE 1
#define MIN_HEAP_TYPE 0
#define LEFT_CHILD 1
#define RIGHT_CHILD -1
#define EQUAL 0

class Heap
{
public:
    vector<int> items;
    int size;
    int type;

    Heap(int type = MAX_HEAP_TYPE, vector<int> arr = {})
    {
        this->type = type;
        this->items = arr;
        this->size = arr.size();

        this->heapify();
    }

public:
    pair<int, int> getChildrenIndices(int parentIndex);
    int getParentIndex(int childIndex);
    void display();
    bool insert(int element);
    void swap(int *a, int *b);
    void heapifyUp(int index);
    bool remove();
    void heapifyDown(int elementIndex);
    int getMaxChildIndex(int parentIndex);
    int peak();
    void heapify();
    bool isEmpty();
    vector<int> heapSort(bool ascending = false);
};

bool Heap::isEmpty()
{
    return this->size <= 0;
}

pair<int, int> Heap::getChildrenIndices(int parentIndex)
{
    int left, right;

    left = 2 * parentIndex + 1;
    right = 2 * parentIndex + 2;

    left = (left >= size) ? -1 : left;
    right = (right >= size) ? -1 : right;

    return {left, right};
}

int Heap::getParentIndex(int childIndex)
{
    return ceil((double)childIndex / (double)2) - 1;
}

int Heap::getMaxChildIndex(int parentIndex)
{
    pair<int, int> children;

    children = this->getChildrenIndices(parentIndex);
    if (children.first == -1 && children.second != -1)
    {
        return children.second;
    }

    if (children.second == -1 && children.first != -1)
    {
        return children.first;
    }

    // Leaf Node
    if (children.second == -1 && children.first == -1)
    {
        return -1;
    }

    return (this->items[children.first] >= this->items[children.second]) ? children.first : children.second;
}

void Heap::display()
{
    int i;
    bool enteredLoop = false;

    printf("[");
    fflush(NULL);
    for (i = 0; i < this->size; i++)
    {
        enteredLoop = true;
        printf("%d  ", this->items[i]);
        fflush(NULL);
    }
    printf(enteredLoop ? "\b\b]\n" : "]\n");

    return;
}

void Heap::heapifyUp(int elementIndex)
{
    int parentIndex, element;

    element = this->items[elementIndex];
    while (true)
    {
        parentIndex = this->getParentIndex(elementIndex);
        // printf("parent: %d, element: %d\n", parentIndex, elementIndex);
        if ((elementIndex <= 0) || (this->items[parentIndex] >= element))
        {
            // printf("Reached root or parent > child\n");
            break;
        }
        this->swap(&this->items[parentIndex], &this->items[elementIndex]);
        elementIndex = parentIndex;
    }

    return;
}

void Heap::heapifyDown(int elementIndex)
{
    int maxChildIndex;

    while (true)
    {
        maxChildIndex = this->getMaxChildIndex(elementIndex);
        if (maxChildIndex == -1)
        {
            break;
        }
        if (this->items[maxChildIndex] <= this->items[elementIndex])
        {
            break;
        }
        swap(&this->items[maxChildIndex], &this->items[elementIndex]);
        elementIndex = maxChildIndex;
    }

    return;
}

void Heap::heapify()
{
    int i, lastInternalNodeIndex;

    lastInternalNodeIndex = ceil((double)this->size / (double)2) - 1;
    // this->display();
    for (i = lastInternalNodeIndex; i >= 0; i--)
    {
        // printf("i: %d, element: %d\n", i, this->items[i]);
        this->heapifyDown(i);
        // this->display();
    }

    return;
}

bool Heap::insert(int element)
{
    int elementIndex;

    this->items.push_back(element);
    this->size += 1;

    elementIndex = this->size - 1;
    this->heapifyUp(elementIndex);

    return true;
}

bool Heap::remove()
{
    if (this->isEmpty())
    {
        return false;
    }
    this->items[0] = this->items[this->size - 1];

    this->heapifyDown(0);
    this->items.pop_back();
    this->size -= 1;

    return true;
}

vector<int> Heap::heapSort(bool ascending)
{
    vector<int> sorted, heapCopy;
    int maxElement, sizeCopy;

    // backup items
    heapCopy = vector<int>(this->items);
    sizeCopy = this->size;

    while (!this->isEmpty())
    {
        maxElement = this->peak();
        if (ascending)
        {
            sorted.insert(sorted.begin(), maxElement);
        }
        else
        {
            sorted.push_back(maxElement);
        }
        this->remove();
    }

    // restore items
    this->items = heapCopy;
    this->size = sizeCopy;

    return sorted;
}

int Heap::peak()
{
    return this->items[0];
}

void Heap::swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return;
}

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printVector(vector<int> arr)
{
    int i, size;
    bool enteredLoop = false;

    size = arr.size();
    printf("[");
    fflush(NULL);
    for (i = 0; i < size; i++)
    {
        enteredLoop = true;
        printf("%d  ", arr[i]);
        fflush(NULL);
    }
    printf(enteredLoop ? "\b\b]\n" : "]\n");

    return;
}

class Solution
{
public:
    ListNode *vectorToList(vector<int> arr)
    {
        ListNode *head = NULL, *prev = NULL, *current = NULL;

        for (int num : arr)
        {
            current = new ListNode(num);
            if (head == NULL)
            {
                head = current;
                prev = current;
            }
            else
            {
                prev->next = current;
                prev = current;
            }
        }

        return head;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> mergedArr, sorted;
        Heap *heap = NULL;
        ListNode *ptr = NULL, *newHead = NULL;

        for (ListNode *listHead : lists)
        {
            ptr = listHead;
            while (ptr != NULL)
            {
                mergedArr.push_back(ptr->val);
                ptr = ptr->next;
            }
        }
        // printVector(mergedArr);
        heap = new Heap(1, mergedArr);
        sorted = heap->heapSort(true);
        // heap->display();
        // printVector(sorted);
        newHead = vectorToList(sorted);

        return newHead;
    }
};