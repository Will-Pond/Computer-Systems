/*
* Will Pond
* CSC 362 Programming Assignment 1
* In this program it asks the user for a input file, a output file and two letter seperated by a space in whcih the first letter must be less than the second letter. The program open the input file and read it character by character until it reach the end of the file.
* While reading the input file the program also, opens the output file and writes the characters from the input file depending on the user input for the two letters.  
* For example if the user choose b and p for the two letter input any letter that fall in the range would be outputed to the output file along with punctuation and whitespaces. If the letter did not fall between the two input letter or it was digit would be discard. 
* additionally the program keep count the amount of charaters that are contain in the input file, the output file and the charaters that were discarded. Finally the program calculate the size difference between the two files and print out the size of the first file, the second file, the charaters that were not outputed and the difference in size as a precentage.
* 
* The program also uses header files like stdio.h for I/O Functions and ctype.h for testing characters and numbers 
*/

#include <stdio.h>    // for I/O Functions
#include <ctype.h>    // for testing character and numbers

void main()
{
    FILE *input, *output;   // File pointer for input and output
    int chars_in = 0, chars_out = 0,  digit = 0, total = 0;  // Counter variables
    char input_file[20], output_file[20], first, second, c;  // file names, first = first letter, second = second letter and c = current charater for input file 
    double difference;    // Delcare variable
    

    printf("Enter the input file name: ");     // Asks the user for a input file
    scanf("%[^\n]%*c", input_file);             // Get the input from the user and stores it in input_file
 
    printf("Enter the output file name: ");     // Asks the user for a output file
    scanf("%[^\n]%*c", output_file);            // Gets input from the user and stores it in output_file
    

  printf("Enter two letter separated by a blank space: ");     // Asks the user to input two letter with a space    
    
    do {
        scanf(" %c %c", &first, &second);         // Gets input from the user and stores it in first and second
    } while (!isalpha(first) || !isalpha(second) || tolower(first) > tolower(second));  // A while loop that checks for the two letters that the user inputed to actual letters and to see if the first letter is less than the second letter.  

    input = fopen(input_file, "r");   // Opens the input_file for read only
    output = fopen(output_file, "w");  // Opens the output_file for write only
    
    if (input != NULL) {        // Checking if the input file opend up successfully 
        while ((c = getc(input)) != EOF) {        // A while loop that keeps going with c reading each character until it reach end of file 
            if(tolower(c) >= tolower(first) && tolower(c) <= tolower(second) || ispunct(c) || isspace(c)) {      // if statement checks the character if it is between the two letter that the user inputed and checks for punction or whitespace. If this is true execute this if block. 
                
                chars_in++;    // Counts the number of character that going to be added into the the output file 
                total++;          // Counts the total number of characters of the input file
                fprintf(output, "%c", c);   // Write the character in the output file

            } else if(isdigit(c)) {      // Checks if the character is a digit. If this is true execute this else if block.  
               
                digit++;  // Counts the character as digit
                total++;  // Counts the total number of character of the input file.
            }
            else {    
                
                chars_out++;   // Count the character to not be outputed to the output file.
                total++;     // Counts the total number of character of the input file.
            }

        }
 
        fclose(input);     // Closes the input file when while loop is done
        fclose(output);    // Closes the output file when while loop is done
        
    }
    
    difference = (double)chars_in / total;    // Calculates the difference as a decimal
    difference = difference * 100;      // Multiply by 100 to get the percentage of the difference


    printf("\n Size of %s is: %d", input_file, total);     //prints out the amount of charater containing in the input file
    printf("\n Size of %s is: %d", output_file, chars_in);   // prints out the amount of charters containg in the output file 
    printf("\n Letters not output is: %d", chars_out);       // prints out the amount of letters not outputed in the output file 
    printf("\n Differenece in size is: %.2f%%", difference);  // prints out the perecentage of difference between the two file by two decimal places
    printf("\n Digits not output is: %d", digit);             // prints out the amount digits not output to the output file
  
    /*
    * INPUT:
    * Enter the input file name: p1in2.txt
    * Enter the output file name: p1out2.txt
    * Enter two letter separated by a blank space: e x

    * OUTPUT:
    * Size of p1in2.txt is: 728
    * Size of p1out2.txt is: 603
    * Letters not output is: 108
    * Differenece in size is: 82.83%
    * Digits not output is: 17
    * 
    * OUTPUT TEXT FILE:
    * ution is efine s "inferene to the est explntion," 
    *  tsk of generting n explntion to ount for the 
    * pperne of  given set of finings or t [].  Within 
    * the ontext of hnwritten hrter reognition, the tsk 
    * is one of hpothesiing the hrters (or smols/wors) 
    * responsile for the fetures foun in snne itmps; 
    * the tsk ttempts to fin the est olletion of hrters to 
    * explin these fetures.  ution hs previousl een 
    * pplie to  wie rnge of interprettion prolems inluing 
    * speeh reognition [], ignosis [, , ], meil test 
    * interprettion [], stor unerstning [], nturl 
    * lnguge unerstning [, ], theor formtion n legl 
    * resoning [].
    * 
    */
}