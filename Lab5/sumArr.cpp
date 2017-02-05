/******************************************************************************
** Program name: sumArr.cpp
** Author: Charles Chen
** Date: 02/04/2017
** Description:
sumArr takes an array of integers, as well as an integer containing the size of
this array, and returns an intger containing the  sum of all elements in the
array.
******************************************************************************/

int sumArr(int arr[], int arrSize)
{
    // Error protection - if array size is less than 0, just return sum as 0
    if (arrSize <= 0)
    {
        return 0;
    }

    // Base case - If array size is 1, the sum of the array is itself
    else if (arrSize == 1)
    {
        return arr[0];
    }
    
    // Recursive step - The sum of all elements of an array is the value of the
    // last element of the array, plus the sum of the rest of the array
    else
    {
        return arr[arrSize - 1] + sumArr(arr, arrSize - 1);
    }
}