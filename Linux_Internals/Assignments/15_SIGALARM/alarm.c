/*
Title	: BlockSignal for sometime for registered signals
Author	: Vaageesh
Date	: Monday 14 January 2021 11:19:00 PM IST
*/

#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <features.h>

void alarm_handler(int signum)
{
    puts("Alarm expired");
}
	
int main(int argc, char **argv)
{
	struct tm tm;
	struct tm *localtime(const time_t *timer);
	struct tm *localtime_r(const time_t *restrict timer, struct tm *restrict result);
	time_t t;
	time_t now;
	int minutes_to_event;


	if(argc < 2)
	{
		printf("\nPlease pass sufficient arguments through command line");
		return 1;
	}



	/*local time to get*/
	time(&now);
	printf("The time is ");
	fputs(asctime(localtime(&now)), stdout);
	printf("There are still %d minutes to the event.\n", minutes_to_event);
	/*strptime function to convert string from command line*/
	if (strptime(argv[1] && argv[2], "%d %b %Y %H:%M:%S", &tm) == NULL)
	    /* Handle error */;

	printf("year: %d; month: %d; day: %d;\n", tm.tm_year, tm.tm_mon, tm.tm_mday);
	printf("hour: %d; minute: %d; second: %d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("week day: %d; year day: %d\n", tm.tm_wday, tm.tm_yday);

	tm.tm_isdst = -1;      /* Not set by strptime(); tells mktime()
		                  to determine whether daylight saving time
		                  is in effect */
	t = mktime(&tm);
	if (t == -1)
	    /* Handle error */;
	printf("seconds since the Epoch: %ld\n", (long) t);

	/*/*//*Alarm prg*//*/*/


	/* Register a handler */
	signal(SIGALRM, alarm_handler);

	/* Raise the ALARM, after 5 seconds */
	alarm(10);
	printf("ALARM set for 10 seconds\n");

#if 0
    /* Infinite loop */
    while(1);
#else
    pause(); //wait for any signal to occur
    puts("Quitting now...");
#endif

    return 0;
}
