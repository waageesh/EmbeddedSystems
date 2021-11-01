#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining macros for subject name length anf student name length
#define SUBJECT_NAME_LEN 20
#define STUDENT_NAME_LEN 20

struct student						// declaring struct for student globally
{
	int rollno;
	char *name;
	int *subject_marks;
};

int main()
{
	int student_cnt, subjects_cnt, menu, rollno;
	char name[STUDENT_NAME_LEN];
	char cont;
	do
	{
		printf("Enter no.of students :");
		scanf("%d", &student_cnt);			// reading students count
		float subject_avg[student_cnt] ;		// declaring subject_arr for storing average of all students
		printf("Enter no.of subjects :");
		scanf("%d", &subjects_cnt);			// reading subjects count

		struct student student_arr[student_cnt];	// defining array of structures
		char (*subjects)[SUBJECT_NAME_LEN] = malloc(sizeof(char) * SUBJECT_NAME_LEN * subjects_cnt);
								// defining poiner to array to store 2d array of subject names

		for(int i = 0; i < subjects_cnt; i++)		// reading subject names into above defined "pointer to array"
		{
			printf("Enter name of the subject %d :", i);
			scanf("%s",subjects[i]);
		}

		for(int i = 0; i < student_cnt ; i++ )		// reading all student details along with their subject marks
		{
			float avg = 0;
			printf("----------Enter the student datails-------------\n");
			printf("Enter the sutdent Roll no:");	
			scanf("%d", &student_arr[i].rollno);	// reading student roll no

			student_arr[i].name = malloc(sizeof(char)*STUDENT_NAME_LEN);	// memory allocation for student name pointer in 
											// defined in student struct	
			printf("Enter the student name :");
			scanf("%s", student_arr[i].name);	// reading student name after dynamic memory allocation in above line


			student_arr[i].subject_marks = (int*)malloc( sizeof(int) * subjects_cnt );	// Dynamic memory allocation for
													// double pointer(subject marks)
													// in struct
			for(int j = 0; j < subjects_cnt; j++)				// reading subject marks for all subjects
			{
				printf("Enter %s marks :", subjects[j]);
				scanf("%d", &student_arr[i].subject_marks[j]);
				avg = avg + student_arr[i].subject_marks[j] ;		// cummulative addition of subject marks
			}
			subject_avg[i] = avg / subjects_cnt ;				// storing average of all subjects in average array 

		}

		printf("----Display Menu----\n1. All student details\n2. Particular student details\nEnter you choice :");
		scanf("%d", &menu);				// asking user to print all/particular student details

		if (menu == 1)					// menu for printing all student details
		{
			printf("----Printing All student Details----");			
			
			// printing header for student details
			printf("Roll NO.\tName\t");
			for (int i = 0; i < subjects_cnt; i++)
			{
				printf("%s\t", subjects[i]);
			}
			printf("Average\tGrade\n");

			//printing all student details
			for(int i = 0; i < student_cnt ; i++ )
			{
				char grade;
				if (subject_avg[i] >= 80 )	// calcuting GRADE base on average of each student
				{
					grade = 'A';
				}
				else if (subject_avg[i] >= 60 && subject_avg[i]<80 )
				{
					grade = 'B';
				}
				else
				{
					grade = 'C';
				}
				printf("%d\t%s\t",student_arr[i].rollno, student_arr[i].name);	// printing student rollno & name
				for (int j = 0; j < subjects_cnt; j++)
				{
					printf("%d\t", student_arr[i].subject_marks[j]);	// printing all subjects
				}
				printf("%f\t%c\n", subject_avg[i], grade);			// printing average and grade

			}
		}
		else if (menu == 2)				// menu for printing particular student details based on given name/rollno
		{
			int student_menu;
			printf("----Menu for Particular student----\n1. Name.\n2. Roll no.\n");
			printf("Enter your choice :");
			scanf("%d", &student_menu);

			if ( student_menu == 1)			// student details based on name
			{
				printf("Enter the name of the student :");
				scanf("%s", name);		// reading student name

				// printing header for student details
				printf("Roll NO.\tName\t");
				for (int i = 0; i < subjects_cnt; i++)
				{
					printf("%s\t", subjects[i]);
				}
				printf("Average\tGrade\n");

				// printing all students details
				for(int i = 0; i < student_cnt ; i++ )
				{
					if ( strcmp(student_arr[i].name , name) == 0)		// checking student name across given name
					{
						char grade;				
						if (subject_avg[i] >= 80 )			// calculating grade based on average
						{
							grade = 'A';
						}
						else if (subject_avg[i] >= 60 && subject_avg[i]<80 )
						{
							grade = 'B';
						}
						else
						{
							grade = 'C';
						}
						printf("%d\t%s\t",student_arr[i].rollno, student_arr[i].name);	// printing student name&rollno
						for (int j = 0; j < subjects_cnt; j++)		
						{
							printf("%d\t", student_arr[i].subject_marks[j]);	// printing all subject marks
						}
						printf("%f\t%c\n", subject_avg[i], grade);	// printing average & grade
					}
					else
					{
						continue;					// if given name doesn't match, gofor next student
					}
				}
			}
			else if (student_menu == 2)					// student details based on rollno
			{
				printf("Enter the rollno of the student :");		
				scanf("%d", &rollno);					// reading student rollno

				// printing header for student details
				printf("Roll NO.\tName\t");
				for (int i = 0; i < subjects_cnt; i++)
				{
					printf("%s\t", subjects[i]);
				}
				printf("Average\tGrade\n");

				// printing all students details
				for(int i = 0; i < student_cnt ; i++ )
				{
					if (student_arr[i].rollno == rollno)		// checking given rollno matches across student rollno
					{
						char grade;
						if (subject_avg[i] >= 80 )		// calculating grade based on average
						{
							grade = 'A';
						}
						else if (subject_avg[i] >= 60 && subject_avg[i]<80 )
						{
							grade = 'B';
						}
						else
						{
							grade = 'C';
						}
						printf("%d\t%s\t",student_arr[i].rollno, student_arr[i].name);	// printing student rollno & name
						for (int j = 0; j < subjects_cnt; j++)
						{
							printf("%d\t", student_arr[i].subject_marks[j]);	// printing all subject marks
						}
						printf("%f\t%c\n", subject_avg[i], grade);			// printing average & grade
					}
					else
					{
						continue;				// if given roll doesn't matches, gofor next student
					}
				}
			}
		}

		printf("DO you want continue (y/Y) :");			// asking user if he want to continue or not
		scanf(" %c", &cont);
	} while (cont == 'y' || cont == 'Y');				// continue if entered y/Y

	return 0;
}

