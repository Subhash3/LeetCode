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
    void heapifyUp(int index);
    void heapifyDown(int elementIndex);
    void heapify();
    void display();
    bool insert(double element, T data);
    bool insert(double element);
    bool remove();
    HeapElement<T> peak();
    bool isEmpty();
    vector<int> heapSort(bool reverse = false);
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
vector<int> Heap<T>::heapSort(bool reverse)
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

class Solution
{
public:
    double computeDistance(vector<int> &pointA, vector<int> &pointB)
    {
        double x1, x2, y1, y2;

        x1 = (double)pointA[0];
        y1 = (double)pointA[1];
        x2 = (double)pointB[0];
        y2 = (double)pointB[1];

        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<double> distances;
        vector<vector<int>> closestPoints;
        vector<int> origin = {0, 0};
        double dist;
        Heap<int> *minHeap = NULL;
        HeapElement<int> top;
        int index;

        for (vector<int> &point : points)
        {
            double dist = computeDistance(point, origin);
            distances.push_back(dist);
        }

        minHeap = new Heap<int>(MIN_HEAP_TYPE, distances);
        // minHeap->display();
        while (k--)
        {
            minHeap->display();
            top = minHeap->peak();
            dist = top.val;
            index = top.data;

            closestPoints.push_back(points[index]);
            minHeap->remove();
        }

        return closestPoints;
    }
};