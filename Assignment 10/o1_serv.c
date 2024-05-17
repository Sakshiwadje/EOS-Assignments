#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// p2 -- reader
int main() {
	int fd, cnt1,cnt2,num1,num2, res, sol;
	char str[32];
	fd = open("/tmp/desd_fifo", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for data...");

	cnt1 = read(fd, &num1, sizeof(int));
	printf("num1: %d\n", num1);

    cnt2 = read(fd, &num2, sizeof(int));
    printf("num2: %d\n", num2);
   
    close(fd);
    res = num1 + num2;
   
    fd = open("/tmp/desd2_fifo", O_WRONLY);
	if(fd < 0)
	{
      perror("open() failed");
	  _exit(2);
	}
	sol = write(fd, &res, sizeof(int));	
   
    printf("result send successefully: /n");

	close(fd);
	return 0;
}

