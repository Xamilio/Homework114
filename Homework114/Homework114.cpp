#include <iostream>
using namespace std;

int* removeNegatives(const int* arr, int size, int& newSize) 
{
    newSize = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] >= 0) newSize++;
    }

    int* newArr = new int[newSize];
    int index = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] >= 0) newArr[index++] = arr[i];
    }
    return newArr;
}

int* appendToArray(const int* arr, int size, const int* block, int blockSize, int& newSize) 
{
    newSize = size + blockSize;
    int* newArr = new int[newSize];

    for (int i = 0; i < size; ++i) newArr[i] = arr[i];
    for (int i = 0; i < blockSize; ++i) newArr[size + i] = block[i];

    return newArr;
}

int* insertBlock(int* arr, int size, int* block, int blockSize, int index, int& newSize) 
{
    if (index < 0 || index > size) return nullptr;

    newSize = size + blockSize;
    int* newArr = new int[newSize];

    for (int i = 0; i < index; ++i) newArr[i] = arr[i];
    for (int i = 0; i < blockSize; ++i) newArr[index + i] = block[i];
    for (int i = index; i < size; ++i) newArr[i + blockSize] = arr[i];

    return newArr;
}

int* removeBlock(int* arr, int size, int index, int blockSize, int& newSize)
{
    if (index < 0 || index >= size) return nullptr;

    newSize = size - blockSize;
    if (newSize < 0) newSize = 0;

    int* newArr = new int[newSize];
    int newIdx = 0;

    for (int i = 0; i < size; ++i) 
    {
        if (i < index || i >= index + blockSize)
        {
            newArr[newIdx++] = arr[i];
        }
    }

    return newArr;
}

int main() 
{
    int arr[] = { 1, -2, 3, -4, 5, 6 };
    int block[] = { 7, 8, 9 };
    int size = 6, blockSize = 3, newSize, index = 2;

    int* newArr1 = removeNegatives(arr, size, newSize);
    cout << "Array without negatives: ";
    for (int i = 0; i < newSize; ++i) cout << newArr1[i] << " ";
    cout << endl;
    delete[] newArr1;

    int* newArr2 = appendToArray(arr, size, block, blockSize, newSize);
    cout << "Array after appending block: ";
    for (int i = 0; i < newSize; ++i) cout << newArr2[i] << " ";
    cout << endl;
    delete[] newArr2;

    int* newArr3 = insertBlock(arr, size, block, blockSize, index, newSize);
    cout << "Array after inserting block: ";
    for (int i = 0; i < newSize; ++i) cout << newArr3[i] << " ";
    cout << endl;
    delete[] newArr3;

    int* newArr4 = removeBlock(arr, size, index, blockSize, newSize);
    cout << "Array after removing block: ";
    for (int i = 0; i < newSize; ++i) cout << newArr4[i] << " ";
    cout << endl;
    delete[] newArr4;
}
