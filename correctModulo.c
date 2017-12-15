//Program that performs modulo properly in C
#include<stdio.h>
#include<stdlib.h>

int correctModulo(int a, int b);//This function returns a % b even for negative numbers.

int main()
{
	int x = 0,y = 0;
	
	printf("\nEnter integers x,y in the form x mod y: ");
	scanf("%d mod %d",&x,&y);
	
	printf("\nanswer = %d\n",correctModulo(x,y));
	
	return 0;
}

int correctModulo(int a, int b)
{	
	/*Zero cases*/
	
	//a = 0 and b = 0
	if((a == 0) && (b == 0))
	{
		printf("\nindeterminate : 0 / 0");
		exit(0);
	}
	
	//b = 0
	if(b == 0)
	{
		printf("\nundefined : division by zero");
		exit(0);
	}
	
	// a = 0
	if(a == 0)
	{
		return 0;
	}
	
	
	/*Negative cases*/
		
	//a is negative and b is positive
	if((a < 0) && (b > 0))
	{
		while(a < 0)
		{
			a = a + b;
			
			/*Keep adding b to a until a becomes positive.
			Then return a.This gives -a mod b*/
		}
		
		/*In the cycle (0...(b-1)),we are cycling in reverse.
		We start at 0 and move back to b-1 then from b-1 back
		to 0.We do this a times(minus is for direction(backwards)).
		The number in the cycle that we land on is -a mod b.*/
		
		return a;
	}
	
	//a is positive and b is negative
	if((a > 0) && (b < 0))
	{
		while(a > 0)
		{
			a = a + b;
			
			/*Keep adding -b to a until a becomes negative.
			Then return a. This gves a mod (-b)*/
		}
		
		/*In the cycle (0...-(b-1)), we are cycling in reverse.
		we start at -(b-1) and move down to 0.We do this a times.
		The number we land on in the cycle  is a mod (-b)*/
		
		return a;
	}
	
	//a is negative and b is negative
	if((a < 0) && (b < 0))
	{
		/*C will return the correct result for this operation.It produces the
		correct result when both numbers are positive and when both numbers are
		negative.*/

		return a % b;
		
		/*It may appear strange but this is actually quite
		intuitive.What we are essentially doing is the usual
		modulo operation but with negative numbers.It seems
		as though we are counting down.
		
		In the cycle (0,-(b-1),...(-b + b-1)),we start at 0 and count up
		to (-b + b-1).Then wrapround and repeat.We do this a times.
		In fact it would be better to display the cycle
		as follows; */	
		
	}
	
	//a is positive and b is positive
	if((a > 0) && (b > 0))
	{
		return a % b;
	}
}

	/*For the negative cases in the correctModulo function,it may be better to display the cycle
	as follows ((b-1)...0).
	
	____a is negative and b is positive : -a mod b____
	
	In the cycle ((b-1)...0),we are counting down almost since the numbers are in descending order.
	We start at b-1 and iterate through the cycle a times.The number in the cycle that we land on 
	is -a mod b.
	
	Ex. -5 mod 3
	
	(2,1,0) this is the cycle for remainders of 3.
	
	i = iteration n = number
	
	_i_		_n_
	 1		 2
	 2		 1
	 3		 0
	 4		 2
	 5		 1
	
	-5 mod 3 = 1. The minus,in this case signifies the fact that I have reversed the ordering of the
	cycle.Here I changed the order but kept the direction(left to right) the same.In the function above,
	in my commments,I changed the direction but kept the order the same.
	
	
	____a is positive and b is negative : a mod -b____
	
	In the cycle (-(b-1)...0),we are counting up to 0 and wrapping round.The numbers are in ascending
	order.We start at -(b-1) and iterate through the cycle a times.The number we land on is a mod -b.
	
	Ex. 5 mod -3
	
	(-2,-1,0) this is the cycle for remainders of -3.
	
	_i_		_n_
	 1		 -2
	 2		 -1
	 3		 0
	 4		 -2
	 5		 -1	
	
	5 mod -3 = -1. The minus,in this case signifies the fact that I have reversed the ordering of the
	cycle.In the function above,in my commments,I changed the direction but kept the order the same.
	
	
	____a is negative and b is negative____
	
	In the cycle (0,-(b-1),...(-b + b-1)),we start at 0 and count up to (-b + b-1).Then wrapround and 
	repeat.We do this a times.
	
	Ex. -5 mod -3
	
	(0,-2,-1) this is the cycle for remainders of -3.
	
	_i_		_n_
	 1		 0
	 2		 -2
	 3		 -1
	 4		 0
	 5		 -2
	 
	-5 mod -3 = -2. This cycle gives -1 * (a % b).It is just -1 times the positive modulo operation.
	 
	 ____Points to note____
	 
	After reading this you may have noticed that the cases (-a mod b) and (a mod -b) are symmetric.
	So too are the cases (a mod b) and (-a mod -b). I could have merged the if-statements for
	(-a mod b) and (a mod -b) to create a single more complex if-statement but a more efficient return
	statement.I could have also done the same for (-a mod -b) and (a mod b) but I gave these conditions
	individual if-statements for the sake of simplicity.
	*/



