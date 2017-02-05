/******************************************************************************
** Program name: triNum.cpp
** Author: Charles Chen
** Date: 02/04/2017
** Description:

******************************************************************************/

int triNum(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        return n + triNum(n-1);
    }
}