#include "header.h" // This include the header.h files
int compute(char * ma, char * mi, int *bs, int *pb, int *pc, int  w, int  h, int  na, int  ne, double  gpa){ // This fuction compute the base salary, potential bonus and potential ceiling by calculating the student major, minor, years of work experience, number of honors courses, number of extracurricular activities, number of volunteer activities and gpa
	//calculating base salary 
		if (isTech(ma) == 1) { // checks if is a tech major and if so add 56000 to the student's base salary
			*bs = 56000;
			if (isTech(mi) == 1) { // checks if is a tech minor and if so add 4500 to the student's base salary
				*bs = *bs + 4500;
			}
			else if (isScience(mi) == 1) { // checks if is a science minor and if so add 2500 to the student's base salary
				*bs = *bs + 2500;
			}

		}
		else if (isScience(ma) == 1) { // checks if is a science major and if so add 48000 to the student's base salary
			*bs = 48000;
			if (isTech(mi) == 1) { // checks if is a tech minor and if so add 4500 to the student's base salary
				*bs = *bs + 4500;
			}
			else if (isScience(mi) == 1) {  // checks if is a science minor and if so add 2500 to the student's base salary
				*bs = *bs + 2500;
			}
		}
		else if (isHumanities(ma) == 1) { // checks if is a humanities major and if so add 36000 to the student's base salary
			*bs = 36000;
			if (isTech(mi) == 1) { // checks if is a tech minor and if so add 4500 to the student's base salary
				*bs = *bs + 4500;
			}
			else if (isScience(mi) == 1) {  // checks if is a science minor and if so add 2500 to the student's base salary
				*bs = *bs + 2500;
			}
		}
		else {
			*bs = 40000;
			if (isTech(mi) == 1) { // checks if is a tech minor and if so add 4500 to the student's base salary
				*bs = *bs + 4500;
			}
			else if (isScience(mi) == 1) {  // checks if is a science minor and if so add 2500 to the student's base salary
				*bs = *bs + 2500;
			}
			
		}
		

	if (w > 5) {  //checks if the student's has more than 5 years of work experience if so add 4000 to the student's base salary
		*bs = *bs + 4000;
		if (gpa > 3.25) {  //checks if the student's gpa is greater than 3.25 and if so add the high_GPA constant containing 2225
			*bs = *bs + high_GPA;
		}
		else if (gpa < 2.50) { // checks if the student's gpa is lower than 2.50 and if so add the low_GPA constant containning -1500
			*bs = *bs + low_GPA;
		}
	}
	else if (w >= 4 && w <=5 ) { //checks if the student's has 4 or 5 years of work experience if so add 3200 to the student's base salary
		*bs = *bs + 3200;
		if (gpa > 3.25) { //checks if the student's gpa is greater than 3.25 and if so add the high_GPA constant containing 2225
			*bs = *bs + high_GPA;
		}
		else if (gpa < 2.50) { // checks if the student's gpa is lower than 2.50 and if so add the low_GPA constant containning -1500
			*bs = *bs + low_GPA;
		}
	}
	else if (w == 3) { //checks if the student's has 3 years of work experience if so add 2400 to the student's base salary
		*bs = *bs + 2400;
		if (gpa > 3.25) { //checks if the student's gpa is greater than 3.25 and if so add the high_GPA constant containing 2225
			*bs = *bs + high_GPA;
		}
		else if(gpa < 2.50) { // checks if the student's gpa is lower than 2.50 and if so add the low_GPA constant containning -1500
			*bs = *bs + low_GPA;
		}
	}
	else if (w >= 1 && w <= 2) { //checks if the student's has  1 or 2 years of work experience if so add 1200 to the student's base salary
		*bs = *bs + 1200;
		if (gpa > 3.25) { //checks if the student's gpa is greater than 3.25 and if so add the high_GPA constant containing 2225
			*bs = *bs + high_GPA;
		}
		else if(gpa < 2.50) { // checks if the student's gpa is lower than 2.50 and if so add the low_GPA constant containning -1500
			*bs = *bs + low_GPA;
		}
	}
	else if (w == 0) {
		if (gpa > 3.25) { //checks if the student's gpa is greater than 3.25 and if so add the high_GPA constant containing 2225
			*bs = *bs + high_GPA;
		}
		else if (gpa < 2.50) { // checks if the student's gpa is lower than 2.50 and if so add the low_GPA constant containning -1500
			*bs = *bs + low_GPA;
		}
			
		
	}

	// Calculating Potential Bonus
	*pb = 0;  // set potential bonus to 0
	if (h + na + ne > act_thres) {  // check if the students's activity is greater than the activity threshold which is 4
		*pb = (h + na + ne - 4) * act_bonus; // takes the studetns's activity  minus 4 from and multipy it by the activity boonus which is 451 and add it the the student's potential bonus
	}
	
	if ((isTech(ma) == 1) && (isScience(mi) == 1 || isTech(mi) == 1)) {  // check if the student is a tech major and a science minor and if so add the tech bonus which is 5200 and add to the student's potential bonus
		*pb = *pb + tech_bonus;
	}
	else if (isHumanities(ma) == 1) { // check if the student is a humanities major and if so add a humanities bonus which is -2500 and add it to the student's potential bonus
		*pb = *pb + human_bonus;
		if (*pb < 0) { // check if the student's potential bonus is negtive and if so rest it to 0
			*pb = 0;
		}
	}
	
	// potential ceiling
	*pc = 10000; // potential ceiling start out at 10000 for every student

	if (w > exp_thres) { // checks if the student's years of work experience is greater than expereience threshold which 2 and if so add 20000 to student's potential ceiling
		*pc = *pc + 20000;

	}
	if ((isTech(ma) == 1) && (isTech(mi) == 1)) { // checks if the student's major is tech and is a tech minor and if so add 16000 to the student's potential ceiling
		*pc = *pc + 16000;
	}
	else if ((isHumanities(ma) == 1) && (isHumanities(mi) == 1)) { // checks if the student major is humanitites and huanities minor and if so add -3800 to the potential ceiling
		*pc = *pc - 3800;

	}

	
}


int range(int* ss, int * ms, int bs, int pb, int pc) { // This function calculates the starting salary and maximum salary of the student by using the base salary, potential bonus and potential ceiling
	*ss = bs + (pb / 3);  // base salary + (potential bonus / 3)
	*ms = bs + pb + pc;  // base salary + potential bonus + potential ceiling
}

void update(char *ma, int * tsss, int * tsms, int *ttss, int *ttms, int ss, int ms, int* total, int* tech) { // This function  Gets the total number total number of students and tech major students. Also it counts the total starting salary and maximum salary of all the the student. Also it counts the total starting salary and maximum slary of all tech major students. 
	*total = *total + 1; // counts the total number of students in the text file
	if (isTech(ma) == 1) { // checks if the student is a tech major and if so counts total tech majors in the text file
		*tech = *tech + 1; 

		*ttss = *ttss + ss;   // gets the total tech starting salary by add the starting salary of all tech majors
		*ttms = *ttms + ms;   // gets the total tech maximum salary by add the maximum salary of all tech majors

	}

	*tsss = *tsss + ss; // gets the total starting salary of all the students in the text file by adding the starting salary of each student
	*tsms = *tsms + ms; // gets the total maximum salary of all the students in the text file by adding the maximum salary of each student


}

int isTech(char * str) { // this fuction determines if the student's major or minor is tech by match to it to another string and if it does match return 1 for true and if  not return 0 for false 
	if (strcmp(str, "ASE") == 0 || strcmp(str, "CIT") == 0 || strcmp(str, "CSC") == 0 || strcmp(str, "CYS") == 0 || strcmp(str, "DFX") == 0 || strcmp(str, "DSC") == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int isScience(char * str) { // this fuction determines if the student's major or minor is science by match to it to another string and if it does match return 1 for true and if  not return 0 for false 
	if (strcmp(str, "BIO") == 0 || strcmp(str, "CHE") == 0 || strcmp(str, "PHY") == 0 || strcmp(str, "MAT") == 0) {
		return 1;
	}
	else {
		return 0;
	}

}

isHumanities(char * str) { // this fuction determines if the student's major or minor is humanities by match to it to another string and if it does match return 1 for true and if  not return 0 for false 
	if (strcmp(str, "ANT") == 0 || strcmp(str, "ART") == 0 || strcmp(str, "ENG") == 0 || strcmp(str, "HIS") == 0 || strcmp(str, "MUS") == 0 || strcmp(str, "PHI") == 0 || strcmp(str, "SOC") == 0) {
		return 1;
	}
	else {
		return 0;
	}
}