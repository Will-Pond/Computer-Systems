
#define _CRT_SECURE_NO_WARNINGS // telling the complier to not give me an error

// constants
#define high_GPA 2225  // for 3.25 and above gpa
#define low_GPA -1500  // for 2.50 and below gpa
#define act_bonus 451  // acticity bonus for calculating bonus
#define act_thres 4    // acticity threshold for adding up all the years of work experience, number of honors courses number of extracurricular activities, number of volunteer activities
#define tech_bonus 5200 // tech bounus for people who major and minors are in tech
#define human_bonus -2500  // humanitites bouns for people who major in humanitities
#define exp_thres 2       // experience threshold for adding up all the years of work experience

#include <stdio.h>  // for I/O 
#include <string.h> //  for manimpulating strings 

// function prototypes
int input(FILE *, char *, char *, char *, char *, int *, int *, int *, int *, double * );  // gets input of one student from the text file
int compute(char *, char *,int *, int *, int *, int, int, int, int, double );    // compute the base salary, potential bonus and potential ceiling by calculating the student major, minor, years of work experience, number of honors courses, number of extracurricular activities, number of volunteer activities and gpa
int range(int *, int *, int, int, int);  // calculates the starting salary and maximum salary of the student
int output(char *, char *, int , int );    //  print out the list of firstname, lastname, starting salary and maximum salary of the students in the text file to the console in a formated way
void update(char *, int * , int *, int *,int * , int, int, int*, int*);  // Gets the total number total number of students and tech major students. Also it counts the total starting salary and maximum salary of all the the student. Also it counts the total starting salary and maximum slary of all tech major students. 
int isTech(char * ); // determines if the students major or minor is tech
int isScience(char * ); // determines if the students major or minor is science
int isHumanities(char * ); // determines if the students major or minor is humanitites
int summary(int *, int, int, int, int, int, double *, double *); //  print out total number of students and total number of tech major students along with the average salary of all students and the average salary for all tech major students
