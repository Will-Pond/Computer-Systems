/*
Will Pond
CSC 362
In this program it uses two algorthims mergesort and Partition for a quicksort while using pointers. The program has 4 function the main, partition, print, and merge.
In main you have 4 declare integer arrays and a interger pointer pivot. Then you will be calling your other methods and printing them out. 
The Merge function  merges the given two sorted array as parameters into another given array as paramters and sorts again using pointers and pointer arithmetic. 
The partition function uses the given array as parameter and takes the first element as a pivot value then move down the array search for any value greater pivot and puts on the right of the array while all the number that are less than the pivot are on the left.
Then the pivot is inserted when it is sorted and is a placed between the number that is greater than pivot and a number that is less than the pivot while it using pointer and pointer arithmetics to figure out where to place it
Finally the print function prints out the given string used as parameter and the given array use as parameter while using pointers and pointer arithmetic.

*/

//header
#include <stdio.h> // use for I/O
#include <string.h> // use for manimpulating strings

// function prototypes
int partition(int*, int); // uses the given array as parameter and takes the first element as a pivot value then move down the array search for any value greater pivot to be place on the right and any value less than will be placed on the left of the pivot. Then is pivot is inserted when it is sorted and is placed between a value that is greater than and less than.
void print(char*, int*, int); // The print out the given string use as parameter and the given array use as parameter
int merge(int*, int, int*, int, int*, int); // merges the given two sorted array as parameters into another given array as paramters and sorts again 


void main() 
{

	int array1[] = { 2, 4, 6, 8, 12, 16, 22, 28, 30, 38, 40, 42, 46, 48, 50 };  // declare integer array for array1
	int array2[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29 };   // decalare integer array for array2
	int array3[30];                                                               // declare integer array for array3
	int array4[] = { 25, 22, 16, 46, 27, 4, 11, 1, 50, 19, 28, 8, 30, 38, 21, 40, 48, 2, 7, 9, 12, 42, 3, 5, 6, 15, 23, 17, 29, 13 };  // declare interger array for array4
	int array1Size = 15, array2Size = 15, array3Size = 30, array4Size = 30;  // declare integer sizes for array1, array2, array3 and array4 
	int* pivot;
	
	merge(array1, array1Size, array2, array2Size, array3, array3Size);  // calls the merge function using the array1, array1Size, array2, array2Size, array3, array3Size as argument to merge array1 and array2 into array3 and return array3

	print("The result of merge: ", array3, array3Size);  // calls the print function using the given string, array3, and array3Size as argument to print the sring and the array3

	pivot = partition(array4, array4Size);  // the pivot pointer is equaling to call function of partition using the array4 and array4size as argument to be use as a partiotion alogorthim for a quicksort

	printf("The pivot has been inserted at %d\n", (pivot -array4)); // prints out the given string and the pivot point of array4  by switch the first element where pivot is and switch with an element that is less than the pivot by doing pivot - array4 will get the location where the pivot need to be inserted.
	print("The result of partition: ", array4, array4Size);  // calls the print function using the given string array4, and array4Size as argument  to print out the given string  and array4
}

 int partition(int* array4, int array4Size) // this function uses the given array as parameter and takes the first element as a pivot value then move down the array search for any value greater than the pivot and place it on the right and any value that is less of the poivt will be place on the left. Then the pivot is  inserted when it is sorted and placed between a value that is greater than pivot and a value that is than the pivot.
{
	 int* pivot;  // a declare pointer variable for pivot
	 int* first;  // a declare pointer variable for first
	 int* second;  // a declare pointer variable for second
	 int* temp;  // a declare pointer variable for temp
	 
	 pivot = array4;  // pivot points to the first element of the array
	 first = array4;  // first points to the first element of the array


	 for (second = first + 1; second < (array4 + array4Size); second++) // a for loop to loop over the array skiping the first element beasue the first element is the pivot
	 {
		 if (*second < *pivot)  // if the current element is less than the pivot value then excute this block of code
		 {
			 first = first + 1;  // increments first by doing pointer arithmetic to get the previous element of second
			 temp = *first;   // set the temp variable to equal derefence first to get the element
			 *first = *second; // derefence first equal to the derefence second to swtich the two values
			 *second = temp;   // set the derefence second to equal to temp pointer to complete the switch
		 }
		  
	 }

	 temp = *pivot;  // temp is now equal to the pivot element of the beggining of the array
	 *pivot = *first;  // the derefence pivot is equal to the derefence first so it can switch it values
	 *first = temp;  // the derefene first is equal to the temp pointer to comple the swtich

	 return first;  // return the pivotPoint 
	
}


void print(char *string, int *array, int arraySize) // This function using the given string, array3, and array3Size as parameters to print the stringand the array3

{
	int* pointer1;  // declare pointer variable pointer1
	int* pointer2;  // declare pointer variable pointer2

	
	for (pointer1 = string; *pointer1 != '\0';  string++) // a for loop to loop through the string given as a parameter using pointers and pointer arithmetic
	{
		pointer1 = string;  // pointer1 points to the next incremented string 
		printf("%c", *pointer1); // print out the character of the derefernce pointer1

	}
	
	for (pointer2 = array; pointer2 < (array + arraySize); pointer2++) // a for loop to loop through the array given as a parameter using pointers and pointer arithmetic
	{
		printf("%d ", *pointer2);  // prints out the number of the derefernce pointer2
	}

	printf("\n");  // sperates the lines for new output
}


 int merge(int* array1, int array1Size, int* array2, int array2Size, int* array3, int array3Size) // This function using the array1, array1Size, array2, array2Size, array3, array3Size as argument to merge array1 and array2 into array3 and return array3

{

	 int* pointer1;  // declare pointer variable pointer1 to point to array1
	 int* pointer2;  // declare pointer variable pointer2 to point to array2
	 int* pointer3;  // declare pointer variable pointer3 to point to array3
	 
	 pointer1 = array1; // pointer1 points to array1
	 pointer2 = array2; // pointer2 points to array2
	 pointer3 = array3; // pointer3 points to array3


	 while (pointer1 < (array1 + array1Size) && pointer2 < (array2 + array2Size)) // a while loop to loop through both array1 and array2 until one them reach end of array
	 {
		 if (*pointer1 < *pointer2) // if the derefernce pointer1 value is less then the dereference pointer2 value then excute this block of code 
		 {

			 *pointer3 = *pointer1;  // derefernce pointer3 equal to the derefence pointer1 to so that pointer3 element equal to pointer1 element

			 pointer1 = pointer1 + 1; // increments pointer1 by doing pointer arithmetic so that it can move on to the next element in the array 
			 pointer3 = pointer3 + 1; // increments pointer3 by doing pointer arithmetic so that it can move on to the next element in the array
		 }
		 else // else the derefernce pointer1 value is  not less then the dereference pointer2 value then excute this block of code 
		 {

			 *pointer3 = *pointer2; // derefernce pointer3 equal to the derefence pointer2 to so that pointer3 element equal to pointer2 element

			 pointer2 = pointer2 + 1; // increments pointer2 by doing pointer arithmetic so that it can move on to the next element in the array
			 pointer3 = pointer3 + 1; // increments pointer3 by doing pointer arithmetic so that it can move on to the next element in the array
		 }


	 }

	 while (pointer1 < (array1 + array1Size)) //  a while loop that loops through array2 if it is not finished then it add them into array3
	 {
		 *pointer3 = *pointer1;   // derefernce pointer3 equal to the derefence pointer1 to so that pointer3 element equal to pointer1 element

		 pointer1 = pointer1 + 1;  // increments pointer1 by doing pointer arithmetic so that it can move on to the next element in the array
		 pointer3 = pointer3 + 1;  // increments pointer3 by doing pointer arithmetic so that it can move on to the next element in the array

	 }

	 while (pointer2 < (array2 + array2Size)) // a while loop that loops through array2 if it is not finished then it add them into array3
	 {
		 *pointer3 = *pointer2;  // derefernce pointer3 equal to the derefence pointer2 to so that pointer3 element equal to pointer1 element

		 pointer2 = pointer2 + 1;  // increments pointer2 by doing pointer arithmetic so that it can move on to the next element in the array
		 pointer3 = pointer3 + 1;  // increments pointer3 by doing pointer arithmetic so that it can move on to the next element in the array

	 }

	 return pointer3;    // pointer3 return all the number in array3
}

 /*
 Output

 Run2
 The result of merge: 1 2 3 4 5 6 7 8 9 10 12 13 14 15 16
The pivot has been inserted at 4
The result of partition: 7 4 5 3 9 20 19 15 22 17 16 25 12 10

 Run3
The result of merge: 1 2 3 4 5 6 7 8 9 11 12 13 15 16 17 19 21 22 23 25 27 28 29 30 38 40 42 46 48 50
The pivot has been inserted at 19
The result of partition: 13 22 16 4 11 1 19 8 21 2 7 9 12 3 5 6 15 23 17 25 30 42 38 50 40 48 27 28 29 46

 */