/*
Title	: Write a program to understand advanced file control system calls.
Date	: 07 - 01 - 2021
Author	: Vaageesh
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio_ext.h>
#include <string.h>


int main ( int argc , char * argv[] )
{
	char buff[1024];
	
	int fd , pid , num ;
	struct flock lock; //structure required to specify releaser or set a lock to a file 
	
	//initial all the bytes to 0
	memset( &lock , 0 ,  sizeof(lock));
	
	if ( argc == 2 ) //only if valid arguments are provided 
	{
		//assuming file is already created 
		//opening the file in write only mode 
		if ( ( fd = open ( argv[1]  , O_TRUNC | O_WRONLY ) ) == -1 ) 
		{		
			fprintf(stderr , "Error in opening file\n");
			perror("open");
			return -1;
		}

		
		printf("enter number of elements : ");
		scanf("%d" , &num );
		__fpurge(stdin);

		//create a duplicate child process 
		pid = fork();

		if ( pid )//parent process 
		{
			//set the lock to the file descriptor 
			lock.l_type = F_WRLCK;
			fcntl( fd  , F_SETLKW , &lock );
			
			//write to the file descriptor
			sprintf(buff,"\nparent process printing prime numbers upto %d\n",num);
			if ( write ( fd, buff, strlen( buff )) == -1 )
			{
				perror("write");
			}
			
			int i = 2 , j;   
			for(i = 2 ;i <= num ; i++)
			{
				int count = 0;
				for(j = 1 ; j <= i ; j++)
				{
					if(i % j == 0)
					{
						count++;
					}
				}

				if(count == 2) //if it is a prime number 
				{
					//write the prime number to the file 
					sprintf(buff, "%d ", i );
					if ( write ( fd, buff, strlen( buff )) == -1 )
					{
						perror("write");
					}
				}

			}
			
			//unlock the file descriptor
			lock.l_type = F_UNLCK;
			fcntl( fd  , F_SETLKW , &lock );
			
		}
		else if ( pid == 0) //child process
		{
			//set the lock to the file descriptor 
			lock.l_type = F_WRLCK;
			fcntl( fd  , F_SETLKW , &lock );
			
			//write to the file 
			sprintf(buff, "\nchild process printing fibonacci series upto %d\n" , num);
			
			if ( write ( fd, buff, strlen( buff )) == -1 )
			{
				perror("write");
			}
			
			int t1 = 0, t2 = 1, nextTerm = 0;
			do
			{
				//write the fibonacci series to the file 
				sprintf(buff, "%d ", nextTerm);
				if ( write ( fd, buff, strlen( buff )) == -1 )
				{
					perror("write");
				}
				
				t1 = t2;
				t2 = nextTerm;
				nextTerm = t1 + t2;
				
			}while (nextTerm <= num ) ;
			
			//unlock the file descriptor 
			lock.l_type = F_UNLCK;
			fcntl( fd  , F_SETLKW , &lock );
		}
		else //if error encountered in fork 
		{
			perror("fork");
			return -1;
		}

	}
	else //if invalid arguments are passed  
	{
		printf("Invalid arguments\n");
		printf("Usage :- ./a.out <file name>\n");
		return -1;
	}
	return 0;
}
