/*
Will Pond
CSC 362
In this program it uses the bubble sort algorithim to sort an array but not in the normal C. Most of the code is program in assembly code block where you have to use the 4 data registers to move, decrement, increment, and multipy  variables, indexes and elements of the array.  
The assemble code start out by move variables into data register than move the data regsistrs into other variables. Then it goes into a while loop to iterate if the flag variable sort to true and if not goes into the while loop.
 Then changes the flag variable to true before it goes into the for loop to iterate the array. Inside the for loop it has if statement and if the previous element is greater than the current element then go into if statement block of code and swap the element. 
 Then change the flag variable sort to false becasue the array is not sorted. Keep doing this process until the array is sorted and it exits the while to print out the array.The only normal C code is the declare variables, the for loop to iterate the array and printf statement to print out the element.
*/


#include <stdio.h>  // header for I/O

void main()
{
  

    int array1[] = { 80, 65, 33, 45, 20, 86, 97, 22, 21, 30, 84, 66, 98, 12, 74, 89, 92, 37 };
   // int array1[] = { 30, 28, 25, 24, 22, 20, 19, 18, 16, 14, 13, 12, 11, 10, 8, 7, 6, 4, 3, 1 };
    int n = 18;        // declare integer variable n and n is equal to the length of the array
    int k = 0;         // declare integer variable k and it use later on in the assembly  
    int zero = 0;       // declare integer variable zero and it is equal to zero
    int sort = 0;        // declare integer variable sort and is use as a flag to represent is the array is sorted or not. It is equal to zero when the array is not sort and one when it is sorted
    int counter = 0;     // declare integer variable counter to count elements in the array and it is equal to zero to start at begining of the array 
    int element = 0;       // declare integer variable element and it is use to access and store the array element in this variable.  
    int four = 4;          // declare integer variable four and it is equal to 4 to be use later on in assembly
    int j;             // declare integer variable j. It is use in the for loop as counter to count the element in the array
    int index = 0;         // declare integer variable index and it is use to get the location of the array. It is equal to zero indicate it is at the begining of the array



    __asm {   // assembly block of code that contain bubble sort alorgthim to sort out array1

                mov eax, zero      // move zero into eax register to make sure that eax is zero
                mov eax, n         // move n into eax register to get length of array1 to be use later on 
                mov k, eax         // move eax register into k so that n would not be altered in any way when excuting the for loop at the bottom of the code
                dec k              // decerment k to get index of the last element in array1.
                mov edx, sort      // move the flag variable sort into edx register to make false becasue the array1 is not sorted when make comparison
        while1: cmp edx, zero      // begining of the while loop and the condition is  sort == 0 if true go into the loop  
                jne Done           // if the edx != 0 then jump out of the loop and go to Done indicating that array1 is sorted
                inc sort           // increment sort to one to indicate that it is true if it doesn't go into the for loop to sort out array1
                mov ecx, counter   // move counter into the ecx register so it can use later on to increment and make comparsion
                mov ebx, counter   // move counter into the ebx register so it can use later on to the elements of array1
         loop1: cmp ecx, k           // beginign of the loop with a comparsion of the ecx register to k and the condition is counter < k or n-1. If so go into the for loop
                jge next2               //  if counter >= k or n-1, jump out of the for loop and go to next2
                mov edx, zero           // move zero into edx register to reset back to zero to be use later on to get elements
                inc ecx                 // increment ecx register becasue it is being use as a counter for the for loop
                mov edx, array1[ebx]    // move the element located in ebx register or the counter and place it in edx
                mov index, ebx          // move ebx register into index so it can be use later on to get the previous element
                mov element, edx        // move edx register which contain the element located at the index of ebx register into element variable to store the element
                mov eax, ecx            // move the ecx register which is the counter into the eax register so it can be use later on to get next index in array1
                mul four                // multipy the eax register by four get the next index in the array1
                mov ebx, eax            // move the eax register that store the next index into ebx so it can use later on to get the next element
                mov eax, array1[ebx]    // move the element locate at the index of ebx register into the eax register to make a comparision with the previous element
                cmp element, eax           // begining of the if statement with comparsion of the eax register with element. The condition is this array1[counter] > array1[counter+ 1] and if true go into this block of code
                jle next1               // if the condition is false array1[counter] <= array1[counter + 1] then jump to next1
                mov edx, zero          // move zero into edx register to reset it back zero
                mov sort, edx          // move edx into sort because it has indicate that array1 is not sorted
                mov edx, index         // move index into the edx register so it can be use later on getting the index of the privous element
                mov array1[edx], eax   // move the eax register that contains the current element and switch in into the previous element
                mov eax, element       // move element that contains the previous element into eax register so it can be use later on to switch with current at element at that index
                mov array1[ebx], eax   // move eax register into the current element located at ebx register index
                jmp loop1              // end of if statement and for loop. jump back into the for loop iterate again
         next1: jmp loop1        // The elements do not need to switch so it jump back up into the for loop
         next2: dec k            // decrement k because at least one element in the array is in the right place 
                mov edx, sort     // move sort back into edx register to make a comparison again in the while loop condition
                jmp while1       // jump to the while loop
          Done:                  // end the of the assembly code block



    }


    for (j = 0; j < n; j++)         // for loop to iterate the array and print the element in the sorted array
    {
        printf("%d ", array1[j]);     // prints out the current element in array1
    }
  

    }

    
/*
Output
12 20 21 22 30 33 37 45 65 66 74 80 84 86 89 92 97 98

1 3 4 6 7 8 10 11 12 13 14 16 18 19 20 22 24 25 28 30

*/