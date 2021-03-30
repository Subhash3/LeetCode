#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// All constant definitions
#define MAX_HEAP_TYPE 1
#define MIN_HEAP_TYPE -1

// Heap Element
template <typename X>
struct HeapElement
{
    double val;
    X data;
};

template <class T>
class Heap
{
private:
    vector<HeapElement<T>> items;

public:
    int type;
    int size;

    // Vector of heap elements
    Heap(int type = MAX_HEAP_TYPE, vector<HeapElement<T>> arr = {})
    {
        this->type = type;
        this->size = arr.size();
        for (HeapElement<T> he : arr)
        {
            this->items.push_back(he);
        }

        this->heapify();
    }

    // Indices will be used as data if double array is passed
    Heap(int type = MAX_HEAP_TYPE, vector<double> arr = {})
    {
        int i;

        this->type = type;
        this->size = arr.size();

        for (i = 0; i < this->size; i++)
        {
            HeapElement<T> he = {arr[i], i};
            this->items.push_back(he);
        }

        this->heapify();
    }

private:
    bool comparator(double a, double b, bool strict = true);
    pair<int, int> getChildrenIndices(int parentIndex);
    int getParentIndex(int childIndex);
    int getPrioritizedChildIndex(int parentIndex);
    void swap(HeapElement<T> *a, HeapElement<T> *b);

public:
    /*********** Methods *************/
    // Converts an array into heap
    void heapify();

    // Prints the heap, (Only val not data)
    void display();

    // Inserts a new element to the heap along with data
    bool insert(double element, T data);

    // Overloaded method of the above method. If no data is passed, its index will be used a data
    bool insert(double element);

    // Removes the top/prioritized element of the heap
    bool remove();

    // Returns the top/prioritized element of the heap. This doesn't affect the heap.
    HeapElement<T> peak();

    // Returns true if the heap is empty and false otherwise.
    bool isEmpty();

    // Returns the sorted arr of the heapElements.val. This doesn't affect the heap.
    vector<double> heapSort(bool reverse = false);

    // Utility functions.
    void heapifyUp(int index);
    void heapifyDown(int elementIndex);
};

template <class T>
bool Heap<T>::comparator(double a, double b, bool strict)
{
    if (this->type == MAX_HEAP_TYPE)
    {
        if (strict)
        {
            return a > b;
        }
        return a >= b;
    }
    if (strict)
    {
        return a < b;
    }
    return a <= b;
}

template <class T>
bool Heap<T>::isEmpty()
{
    return this->size <= 0;
}

template <class T>
pair<int, int> Heap<T>::getChildrenIndices(int parentIndex)
{
    int left, right;

    left = 2 * parentIndex + 1;
    right = 2 * parentIndex + 2;

    left = (left >= size) ? -1 : left;
    right = (right >= size) ? -1 : right;

    return {left, right};
}

template <class T>
int Heap<T>::getParentIndex(int childIndex)
{
    return ceil((double)childIndex / (double)2) - 1;
}

template <class T>
int Heap<T>::getPrioritizedChildIndex(int parentIndex)
{
    pair<int, int> children;
    double a, b;

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

    // return (this->items[children.first].val >= this->items[children.second].val) ? children.first : children.second;
    a = this->items[children.first].val;
    b = this->items[children.second].val;
    return this->comparator(a, b, false) ? children.first : children.second;
}

template <class T>
void Heap<T>::display()
{
    int i;
    bool enteredLoop = false;

    printf("[");
    fflush(NULL);
    for (i = 0; i < this->size; i++)
    {
        enteredLoop = true;
        printf("%f  ", this->items[i].val);
        fflush(NULL);
    }
    printf(enteredLoop ? "\b\b]\n" : "]\n");

    return;
}

template <class T>
void Heap<T>::heapifyUp(int elementIndex)
{
    int parentIndex;
    double element;

    element = this->items[elementIndex].val;
    while (true)
    {
        parentIndex = this->getParentIndex(elementIndex);
        // printf("parent: %d, element: %d\n", parentIndex, elementIndex);
        if ((elementIndex <= 0) || this->comparator(this->items[parentIndex].val, element, false))
        {
            // printf("Reached root or parent > child\n");
            break;
        }
        this->swap(&this->items[parentIndex], &this->items[elementIndex]);
        elementIndex = parentIndex;
    }

    return;
}

template <class T>
void Heap<T>::heapifyDown(int elementIndex)
{
    int maxChildIndex;

    while (true)
    {
        maxChildIndex = this->getPrioritizedChildIndex(elementIndex);
        if (maxChildIndex == -1)
        {
            break;
        }
        if (!this->comparator(this->items[maxChildIndex].val, this->items[elementIndex].val))
        {
            break;
        }
        this->swap(&this->items[maxChildIndex], &this->items[elementIndex]);
        elementIndex = maxChildIndex;
    }

    return;
}

template <class T>
void Heap<T>::heapify()
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

template <class T>
bool Heap<T>::insert(double element, T data)
{
    int elementIndex;
    HeapElement<T> heapElement;

    heapElement.val = element;
    heapElement.data = data;

    this->items.push_back(heapElement);
    this->size += 1;

    elementIndex = this->size - 1;
    this->heapifyUp(elementIndex);

    return true;
}

template <class T>
bool Heap<T>::insert(double element)
{
    // If no data is provided, index is used!
    return this->insert(element, this->size);
}

template <class T>
bool Heap<T>::remove()
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

template <class T>
vector<double> Heap<T>::heapSort(bool reverse)
{
    vector<HeapElement<T>> heapCopy;
    vector<double> sorted;
    HeapElement<T> maxElement;
    int sizeCopy;

    // backup items
    for (HeapElement<T> he : this->items)
    {
        heapCopy.push_back(he);
    }
    sizeCopy = this->size;

    while (!this->isEmpty())
    {
        maxElement = this->peak();
        if (reverse)
        {
            sorted.insert(sorted.begin(), maxElement.val);
        }
        else
        {
            sorted.push_back(maxElement.val);
        }
        this->remove();
    }

    // restore items
    this->items = heapCopy;
    this->size = sizeCopy;

    return sorted;
}

template <class T>
HeapElement<T> Heap<T>::peak()
{
    if (this->isEmpty())
    {
        return {};
    }
    return this->items[0];
}

template <class T>
void Heap<T>::swap(HeapElement<T> *a, HeapElement<T> *b)
{
    HeapElement<T> temp;

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

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<Heap<int> *> minHeaps;
        Heap<int> *heap = NULL;
        ListNode *newHead = NULL, *current = NULL, *prev = NULL;

        int k, i, minNum, num, minIndex;

        k = 0;
        for (ListNode *ptr : lists)
        {
            vector<double> list;
            while (ptr != NULL)
            {
                list.push_back(ptr->val);
                ptr = ptr->next;
            };
            heap = new Heap<int>(MIN_HEAP_TYPE, list);
            minHeaps.push_back(heap);
            k += 1;
        }

        while (true)
        {
            minNum = INT32_MAX;
            minIndex = -1;
            for (i = 0; i < k; i++)
            {
                if (minHeaps[i]->isEmpty())
                {
                    continue;
                }
                num = (minHeaps[i]->peak()).val;
                if (num < minNum)
                {
                    minNum = num;
                    minIndex = i;
                }
            }
            if (minIndex == -1)
            {
                break;
            }

            minHeaps[minIndex]->remove();
            current = new ListNode(minNum);
            if (newHead == NULL)
            {
                newHead = current;
                prev = current;
            }
            else
            {
                prev->next = current;
                prev = current;
            }
        }

        return newHead;
    }
};