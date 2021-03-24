#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define MAX_HEAP_TYPE 1
#define MIN_HEAP_TYPE -1
#define LEFT_CHILD 1
#define RIGHT_CHILD -1
#define EQUAL 0

template <typename X>
struct HeapElement
{
    int val;
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

    // Indices will be used as data if integer array is passed
    Heap(int type = MAX_HEAP_TYPE, vector<int> arr = {})
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
    bool comparator(int a, int b, bool strict = true)
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

public:
    pair<int, int> getChildrenIndices(int parentIndex);
    int getParentIndex(int childIndex);
    void display();
    bool insert(int element, T data);
    bool insert(int element);
    void swap(HeapElement<T> *a, HeapElement<T> *b);
    void heapifyUp(int index);
    bool remove();
    void heapifyDown(int elementIndex);
    int getPrioritizedChildIndex(int parentIndex);
    HeapElement<T> peak();
    void heapify();
    bool isEmpty();
    vector<int> heapSort(bool ascending = false);
};

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
    int a, b;

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
        printf("%d  ", this->items[i].val);
        fflush(NULL);
    }
    printf(enteredLoop ? "\b\b]\n" : "]\n");

    return;
}

template <class T>
void Heap<T>::heapifyUp(int elementIndex)
{
    int parentIndex, element;

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
bool Heap<T>::insert(int element, T data)
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
bool Heap<T>::insert(int element)
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
vector<int> Heap<T>::heapSort(bool ascending)
{
    vector<HeapElement<T>> heapCopy;
    vector<int> sorted;
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
        if (ascending)
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

class Solution
{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        Heap<int> *heapA = NULL, *heapB = NULL;
        vector<int> ans, useless;
        int n, i, j, index, uselessCount;
        HeapElement<int> elementA, elementB;

        n = A.size();
        heapA = new Heap<int>(MIN_HEAP_TYPE, A);
        heapB = new Heap<int>(MIN_HEAP_TYPE, B);
        ans = vector<int>(n);
        fill(ans.begin(), ans.end(), -1);
        uselessCount = 0;

        heapA->display();
        heapB->display();

        while (heapA->size > 0)
        {
            elementA = heapA->peak();
            elementB = heapB->peak();

            printf("a: %d, b: %d\n", elementA.val, elementB.val);
            index = elementB.data;
            if (elementA.val > elementB.val)
            {
                ans[index] = elementA.val;
                heapB->remove();
            }
            else
            {
                useless.push_back(elementA.val);
                uselessCount += 1;
            }
            heapA->remove();
        }

        j = 0;
        for (i = 0; i < n; i++)
        {
            if (ans[i] == -1)
            {
                ans[i] = useless[j];
                j += 1;
            }
        }

        return ans;
    }
};