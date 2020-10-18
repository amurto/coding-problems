// Implement two stacks in an array
// https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

import java.util.*;
import java.io.*;


class TwoStack
{
	int size;
	int top1,top2;
	int arr[] = new int[100];

	TwoStack()
	{
		size = 100;
		top1 = -1;
		top2 = size;
	}
}

class Stacks
{
    
	void push1(int x,TwoStack sq)
	{
		// pushing element to the top of first stack
		if(sq.top1 < sq.top2 - 1)
			sq.arr[sq.top1++] = x;
		
	}
	
	void push2(int x, TwoStack sq)
	{
		
		// pushing element to the top of second stop
		if(sq.top1 < sq.top2 -1)
			sq.arr[sq.top2--] = x;
		
	}
	
	int pop1(TwoStack sq)
	{
	    // removing element from the top of first stack
		if(sq.top1 == -1)
            return -1;
		return sq.arr[sq.top1--];
	}
	
	int pop2(TwoStack sq)
	{
		// removing element from the top of second stack
		if(sq.top2 == sq.size)
            return -1;
		return sq.arr[sq.top2++];
	}
}