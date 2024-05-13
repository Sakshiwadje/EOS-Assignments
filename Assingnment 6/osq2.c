#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
   int retA, retB, retC, retD, s1, s2, s3, s4, i;
       retA = fork();
	   if(retA == 0) {
	      retB = fork();
		  if(retB == 0) {
		     retC = fork();
			 if(retC == 0) {
			    retD = fork();
				if(retD == 0) {
				    for(i=1; i<=5; i++) {
					    printf("childD :%d\n",i);
					}
					_exit(1);
				}  
                 for(i=1; i<=5; i++)
				 {
				    printf("childC : %d\n", i);
					sleep(1);
				 }	
				  waitpid(retD, &s4, 0);
					_exit(2);

			}	
			  for(i=1; i<=5; i++)
			  {
			     printf("childB : %d\n", i);
				 sleep(2);
			  }	 
				 waitpid(retC, &s3, 0);
				  
				 _exit(3);
			}	
			 for(i=1; i<=5; i++)
			 {
			    printf("childA : %d\n", i);
				sleep(3);
			 }	
				waitpid(retB, &s2, 0);
				
				_exit(4);
			}	
			  
  waitpid(retA, &s1, 0);
   return 0;
 }



