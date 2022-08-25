/**
 ****************************************************************************************
 *   @file          : BinarySearch.c
 *   @author        : Ahmed Ali
 *   @brief         : Write a C program to binary search.
 ****************************************************************************************
*/

/* ****************************** Includes Section Start **************************** */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* ****************************** Includes Section End **************************** */

/* ****************************** Global Variables Section Start ******************** */
int arr[1000];
unsigned int Loop_Iterator, Length = 1000, Index;
/* ****************************** Global Variables Section End ******************** */

/* ****************************** Global Declarations Section Start ***************** */
void Fill_Array(void);
void Sort_Array(void);
int CmpFunc(const void *, const void *);
void Print_Array(void);
void Binary_Search(void);
/* ****************************** Global Declarations Section End ***************** */

int main(void)
{
	Fill_Array();	
	Sort_Array();
	Print_Array();
	Binary_Search();
	
	return 0;
}
/* ****************************** Sub-Program Section Start ***************** */

/**
 ****************************************************************************************
 *  @brief          : Fill an array with random values
 *  @param          : void
 *  @return         : void
 ****************************************************************************************
*/
void Fill_Array(void)
{
	srand(time(NULL));
	
	for(Loop_Iterator = 0; Loop_Iterator < Length; Loop_Iterator++)
	{
		Index = Loop_Iterator;
		arr[Index] = rand() % 65536;
	}
}

/**
 ****************************************************************************************
 *  @brief          : Sort an array using quick sort
 *  @param          : void
 *  @return         : void
 ****************************************************************************************
*/
void Sort_Array(void)
{
	qsort(arr, Length, sizeof(int), CmpFunc);
}

/**
 ****************************************************************************************
 *  @brief          : Compare two values and return the small
 *  @param          : const void *, const void *
 *  @return         : int
 ****************************************************************************************
*/
int CmpFunc(const void *First_Value, const void *Second_Value)
{
	return ( *(int*)First_Value - *(int*)Second_Value );
}

/**
 ****************************************************************************************
 *  @brief          : Search for value in an array unsing binary dearch
 *  @param          : void
 *  @return         : void
 ****************************************************************************************
*/
void Binary_Search(void)
{
	unsigned int lower = 0, upper = Length - 1, mid = 0, key = 0, position = -1;
	
	printf("Enter Key to search for it: ");
	scanf("%d", &key);
	
	do
	{
		mid = (lower + upper) / 2;
		
		if(key == arr[mid])
		{
			position = mid;
			break;
		}
		else if (key > arr[mid])
		{
			lower = mid + 1;
		}
		else
		{
			upper = mid - 1;
		}
		
	}while(lower <= upper);
	
	if(position == -1)
	{
		printf("%d is not located in array \n", key);
	}
	else
	{
		printf("%d is located in index %d \n", key, position);
	}
}

/**
 ****************************************************************************************
 *  @brief          : Print an array.
 *  @param          : void
 *  @return         : void
 ****************************************************************************************
*/
void Print_Array(void)
{
	for(Loop_Iterator = 0; Loop_Iterator < Length; Loop_Iterator++)
	{
		Index = Loop_Iterator;
		printf("arr[%d] = %d \n",Index+1, arr[Index]);
	}
	
	printf("-------------------- \n");
}

/* ****************************** Sub-Program Section End ***************** */

/**
 *************************************************************************************************************
 User            Date                Brief
 *************************************************************************************************************
 Ahmed Ali      25-Aug-2022         Task-0.0.0 Create Fill_Array function.
 Ahmed Ali      25-Aug-2022         Task-0.0.1 Create Sort_Array function.
 Ahmed Ali      25-Aug-2022         Task-0.0.2 Create Cmp_Func function.
 Ahmed Ali      25-Aug-2022         Task-0.0.3 Create Binary_Search function.
 Ahmed Ali      25-Aug-2022         Task-0.0.4 Create Print_Array function.
 *************************************************************************************************************
*/