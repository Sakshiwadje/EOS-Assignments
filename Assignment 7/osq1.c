#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
int main()
{ 
 int ret, signo, pid;
 printf("signo\n");
 scanf("%d",&signo);

 printf("pid\n");
 scanf("%d",&pid);

 ret = kill(pid,signo);
 if(ret == 0)
 {
   printf("success\n");
 }
 else
 {
   printf("failure\n");
 }
return 0;
}
