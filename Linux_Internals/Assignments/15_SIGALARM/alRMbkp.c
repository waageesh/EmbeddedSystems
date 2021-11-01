/*
Title	: Alarm for given time from cmd, snooze or exit on user request
Author	: Vaageesh
Date	: Monday 14 January 2021 11:19:00 PM IST
*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void alarm_handler(int signum)			// signal handler for SIGALRM signal
{
	puts("Wake­up...Alarm..!!\n");
}

int main(int argc, char* argv[])
{
	struct tm tm;
	time_t my_time;
	struct tm * timeinfo;
	char buf[255];
	if (argc < 3)				// checking date format is given properly by passing in given format
	{
		printf("Insufficient arguments\n");
		printf("Usage: ./alarm <hh:mm> [dd/mm/yy]\n");
		return 0;
	}
	else					// when date is given require format from cmd( <hh:mm> [dd/mm/yy] )
	{
		int option;
		char* sp = " ";		// string having space
		
		// declaring new string for combining cmd arg into single string
		char* time_given = malloc(strlen(argv[1]) + strlen(argv[2]) + 2);
		
		// forming time from cmd arguments		
		strcpy(time_given, argv[1]);
		strcat(time_given, sp);
		strcat(time_given, argv[2]);
	
		// zero out the struct tm
		memset(&tm, 0, sizeof(struct tm));
		
		// store time string into structure 
		strptime(time_given, "%H:%M %d/%m/%Y", &tm);
		
		
		/* time behind fall validation*/
		if (mktime(&tm) > time(NULL))
		{
			printf("alarm time is greater than curr time\n");
			
		}
		else
		{
			printf("alarm time falls behind curr time\n");
			return 0;
		}
		 
		
		
		/* Register a handler */
		signal(SIGALRM, alarm_handler);
		
		/* calculating for how many minutes  alarm is set*/
		time (&my_time);				// gives current time in seconds from epoch
		timeinfo = localtime (&my_time);		// gives seconds from epoch, by alram time given in cmd 
		printf("ALARM set for %d minutes\n", tm.tm_min-timeinfo->tm_min);	// alarm duration is diff of current sec and alarm set seconds 
		printf("alarm %d, curr :%d\n", tm.tm_min, timeinfo->tm_min);
		
		//int sec = difftime(tm , my_time);
		printf("%ld %ld %ld\n", mktime(&tm), mktime(timeinfo), mktime(&tm)-mktime(timeinfo));
		
		/* Raise the ALARM, after given minutes */
		//alarm((tm.tm_min-timeinfo->tm_min)*60);
		alarm(mktime(&tm)-mktime(timeinfo));
		
		
		/* prompt user for snooze/exit after given alarm time expired  */
		do
		{	
			int time_in_min = 1;	
			pause();				// pause the process till any SIGNAL is hitting process
			printf("1. Snooze\n2. Exit\nChoose one of the option above :");	// prompt user for snooze/exit options
			scanf("%d",&option);
			if (option == 1)			// if user entered snooze option
			{
				puts("Enter snooze time in minutes: ");
				scanf("%d", &time_in_min);		// reading snooze time in min
				signal(SIGALRM, alarm_handler);	// registering SIGALRM signal to alarm handler function
				alarm(time_in_min*60);			// start alarm for given min
				printf("ALARM set for %d minutes\n",time_in_min);
			}			
		} while(option == 1);
		
		return 0;
		
	}
}


