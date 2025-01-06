#include "header.h" // This include the header.h files
int input(FILE *data, char *f, char *l, char *ma, char *mi, int *w, int *h, int *na, int * ne, double * gpa){  // This function gets input of one student from the text file

	return fscanf(data, "%s %s %s %s %d %d %d %d %lf", f, l, ma, mi, w, h, na, ne, gpa);
}

int output(char * f, char * l, int ss, int sm) { // This function print out the list of firstname, lastname, starting salary and maximum salary of the students in the text file to the console in a formated way

	printf("%s     \t\t%s    \t\t$%d   \t\t$%d\n", f, l, ss, sm);
}

int summary(int* tns, int tnt, int tss, int tms, int tsst, int tmst, double* sa, double* ta) { // This fuction  print out total number of students and total number of tech major students along with the average salary of all students and the average salary for all tech major students


	*sa = *sa + (double)(tss + tms)/(2 * *tns); // calculating the total student average
	
	printf("\n%d students processed and %d tech students processed", *tns, tnt);
	printf("\naverage salary for all students:   $%.2lf", *sa);
	
	if (tnt != 0) { // check if there is a tech major in the text file
		*ta = *ta + (double)(tsst + tmst) / (2 * tnt); // calculating the total tech major average
		printf("\naverage salary for tech students:  $%.2lf", *ta); // print out the average salary for tech students
	}
	
}