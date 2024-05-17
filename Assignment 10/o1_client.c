#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// p1 -- writer
int main() {
	int fd, cnt,num1,num2,cnt3,cnt4,cnt5,sol;
	char str[32];
	fd = open("/tmp/desd_fifo", O_WRONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("enter num1:");
	scanf("%d", &num1);
  
    cnt3 = write(fd, &num1, sizeof(int));


	printf("enter num2:");
    scanf("%d", &num2);

	cnt4 = write(fd, &num2, sizeof(int));
    close(fd);

   
    fd = open("/tmp/desd2_fifo", O_RDONLY);
	if(fd < 0)
	{
     perror("open() failed");
	 _exit(3);

   }

    cnt5 = read(fd, &sol, sizeof(int));
	printf("addition of two numbers: %d + %d = %d\n", num1, num2,sol);


	close(fd);
	return 0;
}
