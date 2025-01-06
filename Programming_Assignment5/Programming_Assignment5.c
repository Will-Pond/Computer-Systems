/*
Will Pond
CSC 362
In this program it finds the maximum distance between two prime in a given range but it is not code in normal C. Most of the code is programed in assembly code block to find the prime numbers and the distance between them.
In the assembly code block it uses 4 data register to move, increment, decrement, divid, and subtract from other data registers and variables. the program begins by moving varaibles into the data registers to set the range before going into a for loop1 to find out if number1 has pass the given range of number2. 
Then it going into for loop2 to find if that particular number is prime or not. If not then it moves on to next number in the range but if the number is prime then it is store the prime number in variable to be use later to find the distance between two prime numbers. 
Then it going into for loop3 and loop4 to find another particular number is prime or not. If not then it moves on to the next number in the range but if th number is prime then it is store in another variable to be use later to find the distance between two prime numbers.
Then it takes the two variable that stores the two prime numbers and subtracts them to find the distance and if the distance is greater than current maximum distance it replaces the distance and the two prime numbers that have given the current maximum distance. It repeat this process until number1 or number2 goes belong the given range  
Finally after exhasting the for loops it exits the assembly block code to be print out the maximum distance between the two prime numbers in the given range include the prime numbers itself that uses a printf statement in C code.
*/



#include <stdio.h> // header for I/O

void main() {
		

	int number1 = 3;    // declare integer variable number1 for the first number for the range 
	int number2 = 999;   // declare integer variable number2 for the second number for the range
	int number3 = 0;    // declare integer variable number3 for the third number to replace number1 for the range 
	int start = 2;      // declare integer variable start and it equals to two because when it is use in a for loop to find factors that would number1 composite. To find those factors we start at two and not one.
	int prime1 = 0;     // declare integer variable prime1 is the current prime number in the range of number1 and number2
	int half1 = 0;      // declare integer variable half1 is the half number of number1 in the first for loop when find factors of number1
	int zero = 0;       // declare integer variable zero that equal zero
	int half2 = 0;      // declare integer variable half2 is the half nubmer of number1 in the third for loop when find factors of number1
	int prime2 = 0;     // declare integer variable prime2 is the current prime number in the range fo number1 and number3
	int distance = 0;   // declare integer variable distance is the distance between prime1 and prime2
	int low_prime = 0;    // declare integer variable low_prime is the store value of prime1 that makes up the maximum distance
	int high_prime = 0;   // declare integer variable high_prime is the store value of prime2 that makes up the maximum distance


	__asm {  // begining the assembly code block

			mov ebx, number2     // move number2 into ebx register to be later on use to compare number1
			mov ecx, start       // move start into ecx register to later use in the second loop as a counter
	 loop1: mov edx, zero             // move zero into edx register to make sure edx is zero but also to reset back to zero
			mov eax, number1     // move number1 number into eax register to perform divison
			div start             // divid number1 by start which is two so number1 / 2  to get the number into a simply form of finding factors
			mov half1, eax            // move eax register which contain number1 / 2 into half1 to be later used in a comparison in loop2
			cmp number1, ebx     //  make a comparsion between number1 and eax register which is this  number1 < number2
			jg Done               // jump to Done if number1 > number2 to exit the first for loop
	 loop2: cmp ecx, half1        // make a comparison between the start value of 2 and eax register that = number1 / 2      start < number 1 / 2
			jg L2                 //  if start value is greater than number1 / 2  jump to L2
			mov edx, zero            // move zero into edx register again to reset when prepare to do another divison
			mov eax, number1      // move number1 into eax register to make the numerator when divding it by ecx
			div ecx               // divid by ecx register to get reminder of eax and see if it is a zero
	   if1: cmp edx, zero               // comparing the reminder from eax register and zero and to see if they equal and if they do jump to L3
			je L3                 // jump L3 when edx register == zero meaning the number is composite
			inc ecx             // if ecx regsiter that contians the start value and is less than number1 / 2  increment ecx and jump back up to loop2 to do the process again
			jmp loop2             // jump to loop2 to start the process again of finding a prime number
	    L2: mov ecx, start          // reset ecx register by moving the orginal start value back to two for next incremented number of number1
			mov edx, number1        // move number1 into edx register to be later move into prime1
			mov prime1, edx              // move edx register to prime1 to store the current highest prime number in the giving range
			inc number1                  // increment number1 to help find the second prime number greater than the current prime number
			mov edx, number1             // move number1 into the edx register to be use later on to be store in number3
			mov number3, edx             // move the edx register into number3 in which number3 will help us store the second prime number
	 loop3: mov edx, zero             // move zero into edx register to make sure edx is zero but also to reset back to zero
			mov eax, number3     // move number3 number into eax register to perform divison
			div start             // divid number1 by start which is two so number3 / 2  to get the number into a simply form of finding factors
			mov half2, eax            // move eax register which contain number3 / 2 into half2 to be later used in a comparison in loop4
			cmp number3, ebx     //  make a comparsion between number1 and eax register which is this  number3 <= number2
			jg Done                // if number3 > number2 than jump to Done becasue their are no more prime number in the given range
	 loop4: cmp ecx, half2        // make a comparison between the start value of 2 and eax register that = number3 / 2      start < number 3 / 2
			jg L4                //  if start value is greater than number3 / 2  jump to L4
			mov edx, zero            // move zero into edx register again to reset when prepare to do another divison
			mov eax, number3      // move number3 into eax register to make the numerator when divding it by ecx
			div ecx                   // divid by ecx register to get reminder of eaxand see if it is a zero
	   if2: cmp edx, zero               // comparing the reminder from eax register and zero and to see if they equal and if they do jump to L5
			je L5                 // jump L5 when edx register == zero meaning the number is composite
			inc ecx             // if ecx regsiter that contians the start value and is less than number3 / 2  increment ecx and jump back up to loop4 to do the process again
			jmp loop4           // jump to loop4 to repeat the process again of finding a prime number
		L3: mov ecx, start    // reset ecx register by moving the orginal start value back to two for next incremented number of number1
			inc number1       // increment number1 to get to the next number to make comparison of number2
			jmp loop1          // jmp into first loop to do the process again of finding new set of prime numbers
		L4: mov ecx, start          // reset ecx register by moving the orginal start value back to two for next incremented number of number1
			mov edx, number3        // move number1 into edx register to be later move into prime1
			mov prime2, edx              // move edx register to prime2 to store the current highest prime number in the giving range
			jmp test1               // jump to test1 to test if the distance between the two prime are greater than the current maximum distance 
		L5: mov ecx, start    // reset ecx register by moving the orginal start value back to two for next incremented number of number1
			inc number3       // increment number1 to get to the next number to make comparison of number2
			jmp loop3          // jump to loop3 to repeat the process again of trying to find a prime number
	 test1: mov edx, prime2     // move prime2 into the edx register to perform a subtraction from prime1 
			sub edx, prime1     // subtact prime2 from prime1 to fined the maximum distance prime2 -prime1 = distance
			cmp edx, distance   // if statement to see if the edx register distance is greater than the current maximum distance
			jg Final            // if the edx register distnace is greater than the current maximum distance than jump to Final to switch the current lowprime and highprime
			jmp loop1           // if the edx register distance is not greater than the current maximum distance than jump to loop1 to start the process again of find new prime numbers
	 Final: mov distance, edx   // move the edx register distance into distance to change out the current maximum distance with the new one
			mov edx, prime1     // move prime1 into the edx register so it can be use to move into the low_prime varaible to switch it out
			mov low_prime, edx  // move edx register into low_prime to switch out the current low_prime with the new one
			mov edx, prime2     // move prime2 into the edx register so it can be use to move into the high_prime varaible to switch it out
			mov high_prime, edx  // move edx register into high_prime to switch out the current low_prime with the new one
			jmp loop1            // jump into loop1 again to find new prime numbers that have a better maximum distance
	 Done:			            // ends the assembly code block		



	}

	printf("The maximum distance is %d found between %d and %d", distance, low_prime, high_prime);  //print statement to print out the maximum distance and the two prime to make that difference
	
}


/*
Output
The maximum distance is 20 found between 887 and 907
The maximum distance is 72 found between 31397 and 31469
The maximum distance is 114 found between 492113 and 492227

*/

