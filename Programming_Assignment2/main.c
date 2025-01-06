/*
Will Pond
CSC 362 Programing Assignment 2
In this program it calculates a earning potential for students by uses 4 files the io.c, compute.c, header.h and main.c. In the main file it calls many methods that contain in both in the io.c and compute.c
while passing paramters through copy or by address. the header.h contain the header files for the protypes and constants to be use in the program. Each file has header.h at very top of the file. There 10 fuctions in this program that will help predict earning potential for students
In the main fuction it declare many variable and call most of the fuction. first what it does it takes in a input file and reads it then in a while loops call the input function while passing in parameters to get each line of the text file and then it calls the compute fuction.
Where the compute fuction compute base salary, potential bonus and potential ceiling from given parameters pass by copy or by address. Then inside compute fuction there are more fuction called inside of that fuction called isTech, IsScience and isHumanities.  
They deterimine the students major and minor is tech, science or humanites. Then after the compute fuction gets excuted it goes the range fuction to calculate the student's expected starting salary and maximum salary.
Then the main fuction calls the output fuction in io.c to output the Calls the ouput function with parameters passed by copy to print out the list of firstname, lastname, starting salary and maximum salary of the students from the text file into the console
Then in main fuction it calls the update in the compute.c to to count the number of all students in the text and number of tech major and calculates the total starting salary and maximum salary of all students and calculates the toal staring salary and maximum salary of all tech major students
Finally the main calls the summary fuction to print out a summary of all students names starting, maximum, the number of all student, the number all tech major students, the averages salary of all the students and the average salary all tech major students 
*/




#include "header.h"  // This include the header.h files
void main(){
	
	char first_name[20], last_name[20], major[20], minor[20];  //declare string values for firstname lastname major and minor
	
	int years_of_work_exp = 0; // declare inetger variable for the years of work expericene of the student
	int num_of_honors = 0;   // declare integer variable for the number of honors the student has 
	int	num_of_extra = 0;    // declare integer variable for the number of extracurricular activiites that the student is part of
	int	num_of_vol = 0;     // declare integer variable for number of volunteer activities
	int base_sal = 0;       // declare integer variable for the base salary of the student
	int pot_bonus = 0;      // declare integer variable for the potiental bonus of the student
	int pot_ceiling = 0;    // delcare integer variable for the potiental ceiling of the student
	int start_sal = 0;      // delcare integer variable for the starting salary of the student
	int max_sal = 0;        // delcare integer variable for the maximum salary of the student
	int total_num_stud = 0;  // delcare integer variable for the total number of student in the text file
	int total_num_tech = 0;  // delcare integer variable for the total number of tech majors in the text file 
	int total_start_sal = 0;  // delcare integer variable for the total starting salary of all the students in the text file
	int total_max_sal = 0;    // delcare integer variable for the total maximum salary of all the students in the text file
	int total_num_tech_start_sal = 0;  // delcare integer variable for the total number of all tech majors starting salary in the text file
	int total_num_tech_max_sal = 0;    // delcare integer variable for the total number of all tech majors maximum salary in the text file
	
	double GPA = 0;   // delcare double variable for student GPA
	double total_avg = 0;   // delcare double variable for the total average salary for all students in the text file
	double tech_avg = 0;   // delcare double variable for the total average salary for all tech majors students in the text file
	FILE *input_file;    // delcare file variable name input_file 


	input_file = fopen("C:\\Users\\wpond\\OneDrive\\Desktop\\CSC 362\\Programming_Assignment2\\p2in3-2.txt", "r");   // input_file  opens the target file and reads it

	printf("First     \t\tLast    \t\tStarting   \t\tMaximum\n"); // print out header for the list of columns

	while(input(input_file, first_name, last_name, major, minor, &years_of_work_exp, &num_of_honors, &num_of_extra, &num_of_vol, &GPA) != EOF)  // a while that calls the input fuction with parameters to keep loop through the file by each line until it reach the end of the file 
	{
		compute(major, minor, &base_sal, &pot_bonus, &pot_ceiling, years_of_work_exp, num_of_honors, num_of_extra, num_of_vol, GPA);  // Calls the compute function with parameters passed by address and compute the base salary, potential bonus and potential ceiling for the student

		range(&start_sal, &max_sal, base_sal, pot_bonus, pot_ceiling); // Calls the range function with parameters passed by address to compute the starting salary and maximum salary of the student

		output(first_name, last_name, start_sal, max_sal);  // Calls the ouput function with parameters passed by copy to print out the list of firstname, lastname, starting salary and maximum salary of the students from the text file to the console 

		update(major, &total_start_sal, &total_max_sal, &total_num_tech_start_sal, &total_num_tech_max_sal, start_sal, max_sal, &total_num_stud, &total_num_tech);  // Calls the update function with parameters some passed by address some passed by copy to count the total number of students and tech major students. Also it counts the total starting salary and maximum salary of all the the student. Also it counts the total starting salary and maximum slary of all tech major students. 

	}

	summary(&total_num_stud, total_num_tech, total_start_sal, total_max_sal, total_num_tech_start_sal, total_num_tech_max_sal, &total_avg, &tech_avg);  // Calls the summary function with parameter some passed by address other passed by copy to print out total number of students and total number of tech major students along with the average salary of all students and the average salary for all tech major students

	fclose(input_file);    // closes the input file 

	}

/*
Output_1
First                   Last                    Starting                Maximum
Stan                    Marsh                   $43425                  $53425
Wendy                   Testaburger             $38895                  $46435
Eric                    Cartman                 $38500                  $48500
Lisa                    Simpson                 $44627                  $57033
Kenny                   Jones                   $41425                  $67625
Sherri                  Mackleberry             $51850                  $62151
Terri                   Macklberry              $51850                  $62151
Rod                     Flanders                $50252                  $62357
Kyle                    Broflovski              $65059                  $95729
Theresa                 Gray                    $59575                  $69876
Bart                    Simpsons                $38500                  $68500
Tolkien                 Black                   $59725                  $70327
Allison                 Taylor                  $43244                  $54284
Ralph                   Wiggum                  $38500                  $48500
Bebe                    Stevens                 $56526                  $67729
Butter                  Scotch                  $56300                  $66902

16 students processed and 4 tech students processed
average salary for all students:   $55618.03
average salary for tech students:  $67936.62


Output_2
First                   Last                    Starting                Maximum
Marvin                  Harrison                $55025                  $65627
Jacy                    Sheldon                 $42400                  $72400
Trey                    Henderson               $43350                  $73651
Taylor                  Thierry                 $42225                  $52225
Jack                    Sawyer                  $46151                  $57053
Carson                  Hinzman                 $40000                  $50000
Cotie                   McMahon                 $43876                  $54778
Celeste                 Taylor                  $56676                  $68180
Cade                    Stover                  $43425                  $53425
Tommy                   Eichenberg              $37200                  $47200
Madison                 Greene                  $38400                  $64600
Josh                    Proctor                 $51425                  $61425

12 students processed and 0 tech students processed
average salary for all students:   $52529.88
*/