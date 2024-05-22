#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
  int ret, s, err,fd;
  ret = fork();
  if(ret == 0)
  {
    fd = open("int.txt", O_RDONLY);
	close(0);
	dup(fd);
	close(fd);
	err = execlp("wc", "wc", NULL);

  }

  else
   waitpid(-1, &s, 0);

 return 0;
}
