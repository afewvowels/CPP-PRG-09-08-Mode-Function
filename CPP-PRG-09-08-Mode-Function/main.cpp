//
//  main.cpp
//  CPP-PRG-09-08-Mode-Function
//
//  Created by Keith Smith on 10/31/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  In statistics, the mode of a set of values is the value that occurs most often or with the
//  greatest frequency. Write a function that accepts as arguments the following:
//
//      A) An array of integers
//      B) An integer that indicates the number of elements in the array
//
//  The function should determine the mode of the array. That is, it should determine
//  which value in the array occurs most often. The mode is the value the function
//  should return. If the array has no mode (none of the values occur more than once),
//  the function should return -1. (Assum the array will always contain nonnegative
//  values.)

#include <iostream>

using namespace std;

int *sizeArray();
int *fillArray(int *, int);
int *sortArrayNumbers(int *, int *, int);
int *generateArrayTally(int *, int);
void testForNoModeCase(int *, int);
void displayArrays(const int *, const int *, int);

int main()
{
    
    int *intPtrArrIntegers = nullptr;
    int *intPtrArrNumberSorted = nullptr;
    int *intPtrArrNumberTally = nullptr;
    
    int *intSizeArray = nullptr;
    
    intSizeArray = sizeArray();
    
    intPtrArrIntegers = fillArray(intPtrArrIntegers, *intSizeArray);
    
    intPtrArrNumberTally = generateArrayTally(intPtrArrIntegers, *intSizeArray);
    
    testForNoModeCase(intPtrArrNumberTally, *intSizeArray);
    
    intPtrArrNumberSorted = sortArrayNumbers(intPtrArrNumberTally, intPtrArrIntegers, *intSizeArray);

    cout << "The mode of that set is: " << intPtrArrNumberSorted[0] << endl;
    
    cout << "Number sorted: " << endl;
    for (int i = 0 ; i < *intSizeArray ; i++)
    {
        cout << *(intPtrArrNumberSorted + i) << endl;
    }
    cout << endl;
    
//    cout << "Tally sorted: " << endl;
//    for (int i = 0 ; i < *intSizeArray ; i++)
//    {
//        cout << *(intPtrArrNumberTally + i) << endl;
//    }
//    cout << endl;
    
    return 0;
}

int *sizeArray()
{
    int *intSize =  nullptr;
    
    intSize = new int;
    
    cout << "Please enter the size of the array: ";
    cin >> *intSize;
    
    return intSize;
}

int *fillArray(int *intArrIntegers, int intArrSize)
{
    intArrIntegers = new int[intArrSize];
    
    for (int i = 0 ; i < intArrSize ; i++)
    {
        cout << "Please enter value " << (i + 1) << " of " << (intArrSize) << ": ";
        cin >> intArrIntegers[i];
    }
    
    return intArrIntegers;
}

int *generateArrayTally(int *intArrIntegers, int intArrSize)
{
    int *intArrSorted = nullptr;
    int *intArrTally = nullptr;
    
    intArrSorted = new int[intArrSize];
    intArrTally = new int[intArrSize];
    
    for (int i = 0 ; i < intArrSize ; i++)
    {
        intArrSorted[i] = intArrIntegers[i];
        intArrTally[i] = 0;
    }
    
    for (int i = 0 ; i < intArrSize ; i++)
    {
        for (int j = 0 ; j < intArrSize ; j++)
        {
            if (intArrIntegers[i] == intArrSorted[j])
            {
                intArrSorted[j] = intArrIntegers[i];
                intArrTally[j]++;
                break;
            }
        }
    }
    
    return intArrTally;
}

int *sortArrayNumbers(int *intArrTally, int *intArrIntegers, int intArrSize)
{
    int intStart;
    int intMinIndex;
    
    int *fltMinElement = nullptr;
    
    int *strMinElement = nullptr;
    
    for(intStart = 0 ; intStart < (intArrSize - 1) ; intStart++)
    {
        intMinIndex = intStart;
        fltMinElement = &intArrTally[intStart];
        
        for(int index = (intStart + 1) ; index < intArrSize ; index++)
        {
            if(intArrTally[index] > *fltMinElement)
            {
                fltMinElement = &intArrTally[index];
                strMinElement = &intArrIntegers[index];
                intMinIndex = index;
            }
        }
        swap(intArrTally[intMinIndex], intArrTally[intStart]);
        swap(intArrIntegers[intMinIndex], intArrIntegers[intStart]);
    }
    
    cout << "Tally sorted: " << endl;
    for (int i = 0 ; i < intArrSize ; i++)
    {
        cout << *(intArrTally + i) << endl;
    }
    cout << endl;
    
    return intArrIntegers;
}

void testForNoModeCase(int *intArrTally, int intArrSize)
{
    bool booAreAllSame = false;
    
    for(int i = 0 ; i < intArrSize ; i++)
    {
        if(intArrTally[i] != 1)
        {
            booAreAllSame = false;
        }
        else
        {
            booAreAllSame = true;
        }
    }
    
    if(booAreAllSame == true)
    {
        cout << "There is no mode in that set." << endl;
        exit(0);
    }
}

void displayArrays(const int *intArr1, const int *intArr2, int intArrSize)
{
    for (int i = 0 ; i < intArrSize ; i++)
    {
        
    }
}
