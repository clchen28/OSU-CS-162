/******************************************************************************
** Program name: sumArr.cpp
** Author: Charles Chen
** Date: 02/04/2017
** Description:

******************************************************************************/

int sumArr(int arr[], int arrSize)
{
    if (arrSize <= 0)
    {
        return 0;
    }

    else if (arrSize == 1)
    {
        return arr[0];
    }
    
    else
    {
        return arr[arrSize - 1] + sumArr(arr, arrSize - 1);
    }
}