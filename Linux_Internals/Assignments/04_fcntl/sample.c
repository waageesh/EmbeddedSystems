#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    struct flock lock;
    char* buff = malloc(sizeof(int));
    int fd = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	lock.l_type = F_WRLCK;
	
 	if (fcntl(fd, F_SETLKW, &lock) == -1)
 	{
 		if (errno == EINTR)
 			printf("file is already locked by other process\n");
 	}
 	
 	int k=12;
 	snprintf(buff, sizeof(int), "%d", k);
 	printf("buff %s, len %d\n", buff, strlen(buff));
 	if ( write(fd, &buff, strlen(buff)) == -1)
 	    perror("write");
 	
 	// unlock write lock on file
	lock.l_type = F_UNLCK;
	fcntl (fd, F_SETLKW, &lock);

    return 0;
}

