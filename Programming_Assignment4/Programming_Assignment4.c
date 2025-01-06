/*
Will Pond
CSC 362
The programing assignment is base off on the story of the Hare vs Tortoise Race in which they both have a fair chance of wining. In this programing it uses four function main, moveTortoise, move Hare and print.
The main function is used to delcare all the variable to setup the story in which have you the Tortoise and the Hare as character variables and the Path as a character array to setup the path to race. 
Along side that you have other variables like turn to count the number turn for the hare and tortoise to reach the finish line and collsion and nap as interger flag. Main also setup random number generate to be used in other functions and the calls the function inside the while loop until one reachs the end.
Then main print out the winner. All functions use pointer to navigate where everything is on the path and using pointer arthmetic to move. moveTortoise moves the tortoise between one and three each turn and it use pointer locate the tortoise and moves it by using pointer arithmetics. But if the tortoise lands on the hare it move back a space.
The next function moveHare moves the hare using pointers and pointer arthmetic. The hare can move between one and 8 spaces each but it has chance to nap and will not move and if it lands on the tortiose it moves back a space. Also path is filled with opening spaces, rocks, streams and carrots. if the hare lands on a rock or a space it will have to move back to the nears open space.
If the hare lands on a carrot then in the next turn it will have to remaining to eat that carrot for that duration of the turn. To calculate this you have use pointers and pointers to figure out all the loactions of hare and the path. Final the print function prints out the turn number and the path with tortosie and hare location. Along side if their being a collison or the hare is napping
Again using pointers and pointer arthimtics to figure out the path pointer location and pointers hare and tortosie then printing it out .
*/


//headers
#include <stdio.h> // This is use for I/O
#include <string.h> // This is use for manimpulating string characters
#include <stdlib.h>  // This use for random number generator to put NULL into time
#include <time.h> // use for random number generator to get the time function

// constant
#define MAX 60  // Use for setting the string length value to MAX 

// function protypes
char * moveTortoise(char*, char*, int*);  // moves the tortoise by using pointers of tortoise hare and collision to calculate the location of tortorise and return the location
char * moveHare(char*, char*, char*, int*, int*); // moves the hare by using pointers of hare tortoise hare path, nap and collision to calculate the location of hare and return the location
void print(char*, char*, char*, int, int , int); // prints out the turn number, the path including where the hare and tortoise are, the collision, napping and who wins


void main()  
{

	char* tortoise;  // declare character variable for tortoise and assign a pointer to it 
	char* hare;      // declare character variable for hare and assign a pointer to it
	int turn = 1;    // declare integer variable for turn  and set it to equal 1 count the amount turn in the program
	int collision = 0;  // declare integer variable for collision and set it to equal zero and is for a flag
	int nap = 0;  // declare integer variable for nap and set it to equal to zero and is use for a flag

	char path[] = " R  R  R  SSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R "; // delcare string variable array for the path of race

	srand(time(NULL));  // setups the random number generate to be use in the moveTortoise and moveHare functions 

	tortoise = path;  // tortoise is pointing to the first element in path
	hare = path;      // hare is pointing to the first element in path


	while (tortoise < path + MAX && hare < path + MAX)  // a while loop that uses the tortoise and hare pointers to see if their pointer is greater than the MAX length. If one of them surpass then the while loop will be exited
	{
		
		hare = moveHare(path, tortoise, hare, &collision, &nap);  // the pointer is equaling to the call function of moveHare using the arguments of the path, tortoise pointer, hare pointers, collision and nap refernces which it return location of the moved hare

		tortoise = moveTortoise(tortoise, hare, &collision);  // the pointer is equaling to the call function of moveTortoise using the arguments of pointers hare and tortoise and the collision refernces which it return the location of the method tortoise

		print(path, hare, tortoise, turn, collision, nap);  // // prints out the turn number, characters in the string path including the locations of the hare and tortoise, the collision, napping and who wins 
		
		turn = turn + 1;  // counts the amount of turns before the hare or tortoise before they reach the end

		nap = 0;   // reset the nap flag to zero regardless if a nap happen or not

		collision = 0;  // reset the collsion flag to zero regardless if a collision happen or not
			
	}

	if(tortoise < hare) // if statement to see who has the higher pointer value when one finish at the end if the hare has the higher value then excuate this block 
	{
		printf("The Hare Wins!");  // prints out that Hare Wins
	}
	else // else is when hare did not have higher pointer value when finish so excuate this block
	{
		printf("The Tortoise Wins!");  // prints out that Tortoise Wins
	}
	
	
}

char* moveHare(char* path, char* tortoise, char* hare, int * collision, int * nap) //This Function uses the parameters of the path, tortoise pointer, hare pointers, collision and nap refernces which it return location of the moved hare

{

	if ((rand() % 4) == *nap)  // This if statements determines if the hare is napping by creating a random number from zero to three and see if equal nap and if so then hare is napping and the function is done. This has a probability chance of 25% of happening
	{

		hare = hare;   // hare is pointing to itself to represent that hare is not moving when napping
		*nap = 1;      // sets the napping to flag to 1 indicate that the hare is napping

		return hare;  // return the location of the hare and function is done
	}

	if (*hare == 'C')  // if condition to see if  the hare land on a C and is equal to the defernce C pointer then excutle this block of code 
	{
		hare = hare;  // hare is pointing to itself to represent that hare is not moving when eating the carrot

		path = hare;  // set the path pointer to equal the hare pointer to get the location of the hare 

		*path = ' '; // deference the pointer of path and set it to equal the deference pointer of space to the remove the C and replace with a space
	}

	else  // else the hare is not napping or eating carrots so it moves in this execute block
	{
		hare = hare + (rand() % 8) + 1;   // generate a random number between one and eight and assign it to the hare pointer to indicate the amount space it will move
		

		while(*hare == 'R' || *hare == 'S' || hare == tortoise) // a while loop that gets the location of the hare where it moves and if location is located on a S for Stream or R for Rock or the tortiose then it move back one space until it lands on a safe space including a space or a C 
		{
			if (hare == tortoise) // if statement to see if the hare lands on the tortoise and if so execute this block
			{

				*collision = 1;  // changes the flag of the collsion to 1 to signal that a collsion has happened

			}

			hare = hare - 1; // moves the hare back one space by using pointer arithmetic of decrement it 

		}
		

		if (tortoise == hare) // another if statement to check again if the hare lands of tortoise without using the while loop
		{
			hare = hare - 1; // moves the hare back one space by using pointer arithmetic of decrement it

			*collision = 1;  // changes the flag of the collsion to 1 to signal that a collision has happened
		}

	}
	
	return hare; // return the location of the hare
}



 char * moveTortoise(char *tortoise, char * hare, int * collision) // This function uses the parameters moveTortoise using the paramters of pointers hare and tortoise and the collsion refernces which it return the location of the tortoise 
{
	tortoise = tortoise + (rand() % 3) + 1; // generates a random number between one and three and set it to equal tortoise pointer to indicate the amount of spaces it will move
	 
	if (tortoise == hare)  // if statement to see if the tortosie lands of the hare and if so excute this block
	{
		tortoise = tortoise - 1; //  moves the tortoise back one space by using pointer arithmetic of decrement it

		*collision = 1; //changes the flag of the collsion to 1 to signal that a collision has happened
		
	}

	return tortoise; // return the location of the tortosie
}

void print(char* path, char* hare, char* tortoise, int turn, int collision, int nap)  // This function uses parameters path, hare, tortoise, turn, collision, and nap to out prints out the turn number, the path including where the hare and tortoise are, the collision, napping and who wins
{
		
	printf("Turn %2d:", turn); // prints out the turn number

	while(*path < (path + MAX))  // a while loop to loop of other the string path array to print out the charaters including the collison and napping
	{
		
		if (path == tortoise)    // if the pointer of the path is equal to the pointer of tortoise execute this block 
		{
			printf("T");    // print the a T in the path location to indicate where the tortoise is

			path = path + 1;  // increment path pointer by using pointer arithemtic to move on to the next element
		}
		if (path == hare)    // if the pointer of the path is equal to the pointer of hare execute this block 
		{
			printf("H");    // print the a H in the path location to indicate where the hare is

			path = path + 1;  // increment path pointer by using pointer arithemtic to move on to the next element
		}
		else              // else the poiner of the path is not equal to pointer of the tortosie or the hare so the path pointer should be printed out normaly
		{
			printf("%c", *path);  // prints out the character of the deference pointer of path in the array

			path = path + 1; // increment the path pointer by using pointer arithemtic to move on to the next element
		}
		
	}
	
	if (collision == 1)  // if statement to see if collsion is equal to one and to indicate it is true and a collision has happen if not then it is false and a collsion did not happen 
	{
		printf("   ---COLLISION---"); // prints out collision after the string has being printed out
	}

	if (nap == 1)    // if statement to see if nap is equal to one to indicate that a nap has occured and if so then excute this block of code
	{
		printf("   ---NAPING---");  // print out napping afte the string has being printed out
	}

	printf("\n");  // ends this line of output and move it to nextline for next output when called again 
	
}

/*
Output1
Turn  1: R TRH R  SSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R
Turn  2: R  RT RH SSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R
Turn  3: R  R TRH SSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R    ---NAPING---
Turn  4: R  R  RTHSSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R    ---COLLISION---
Turn  5: R  R  R  TSSSS H R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R
Turn  6: R  R  R  SSSTS   R HR CCCC  R   R   CCCCCCCCCC  R  SSSS  R
Turn  7: R  R  R  SSSSS T R  R CCCCH R   R   CCCCCCCCCC  R  SSSS  R
Turn  8: R  R  R  SSSSS  TR  R CCCC  R   R H CCCCCCCCCC  R  SSSS  R
Turn  9: R  R  R  SSSSS   RT R CCCC  R   R   HCCCCCCCCC  R  SSSS  R
Turn 10: R  R  R  SSSSS   R  RTCCCC  R   R   HCCCCCCCCC  R  SSSS  R    ---NAPING---
Turn 11: R  R  R  SSSSS   R  R TCCC  R   R    CCCCCCCHC  R  SSSS  R
Turn 12: R  R  R  SSSSS   R  R CCCT  R   R    CCCCCCCHC  R  SSSS  R
Turn 13: R  R  R  SSSSS   R  R CCCC  T   R    CCCCCCC C  R HSSSS  R
Turn 14: R  R  R  SSSSS   R  R CCCC  RT  R    CCCCCCC C  R  SSSSH R
Turn 15: R  R  R  SSSSS   R  R CCCC  R T R    CCCCCCC C  R  SSSS  R
The Hare Wins!

Output2
Turn  1: RTHR  R  SSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R    ---COLLISION---
Turn  2: R TR  RH SSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R
Turn  3: R  R TR HSSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R
Turn  4: R  R  RTHSSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R
Turn  5: R  R  R HTSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R    ---NAPING---
Turn  6: R  R  R  SSSTS H R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R
Turn  7: R  R  R  SSSSST  RH R CCCC  R   R   CCCCCCCCCC  R  SSSS  R
Turn  8: R  R  R  SSSSS T R HR CCCC  R   R   CCCCCCCCCC  R  SSSS  R
Turn  9: R  R  R  SSSSS   RTHR CCCC  R   R   CCCCCCCCCC  R  SSSS  R    ---NAPING---
Turn 10: R  R  R  SSSSS   R  RTCCHC  R   R   CCCCCCCCCC  R  SSSS  R
Turn 11: R  R  R  SSSSS   R  R CTHC  R   R   CCCCCCCCCC  R  SSSS  R    ---NAPING---
Turn 12: R  R  R  SSSSS   R  R CTHC  R   R   CCCCCCCCCC  R  SSSS  R    ---COLLISION---   ---NAPING---
Turn 13: R  R  R  SSSSS   R  R CC TH R   R   CCCCCCCCCC  R  SSSS  R
Turn 14: R  R  R  SSSSS   R  R CC CT R  HR   CCCCCCCCCC  R  SSSS  R
Turn 15: R  R  R  SSSSS   R  R CC C  RT HR   CCCCCCCCCC  R  SSSS  R    ---NAPING---
Turn 16: R  R  R  SSSSS   R  R CC C  R   T   HCCCCCCCCC  R  SSSS  R
Turn 17: R  R  R  SSSSS   R  R CC C  R   R  THCCCCCCCCC  R  SSSS  R    ---NAPING---
Turn 18: R  R  R  SSSSS   R  R CC C  R   R    HTCCCCCCC  R  SSSS  R
Turn 19: R  R  R  SSSSS   R  R CC C  R   R    HCTCCCCCC  R  SSSS  R
Turn 20: R  R  R  SSSSS   R  R CC C  R   R    HCCCCTCCC  R  SSSS  R    ---NAPING---
Turn 21: R  R  R  SSSSS   R  R CC C  R   R    HCCCCCCTC  R  SSSS  R    ---NAPING---
Turn 22: R  R  R  SSSSS   R  R CC C  R   R    HCCCCCCCT  R  SSSS  R    ---NAPING---
Turn 23: R  R  R  SSSSS   R  R CC C  R   R    HCCCCCCCCT R  SSSS  R    ---NAPING---
Turn 24: R  R  R  SSSSS   R  R CC C  R   R    HCCCCCCCC  T  SSSS  R    ---NAPING---
Turn 25: R  R  R  SSSSS   R  R CC C  R   R     CCCCCCHC  R TSSSS  R
Turn 26: R  R  R  SSSSS   R  R CC C  R   R     CCCCCCHC  R  TSSS  R
Turn 27: R  R  R  SSSSS   R  R CC C  R   R     CCCCCC C HR  SSTS  R
Turn 28: R  R  R  SSSSS   R  R CC C  R   R     CCCCCC C HR  SSSST R
Turn 29: R  R  R  SSSSS   R  R CC C  R   R     CCCCCC C  R HSSSS  RT
Turn 30: R  R  R  SSSSS   R  R CC C  R   R     CCCCCC C  R  SSSS HR
The Tortoise Wins!

*/