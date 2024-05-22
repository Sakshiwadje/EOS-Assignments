#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/msg.h>

#define MQ_KEY 0x1234


typedef struct msg
{
  long type;
  int a, b ,c;

}msg_t;

int main()
{
 int mqid, ret1,ret2,s;

 mqid = msgget(MQ_KEY , IPC_CREAT | 0600);
 if(mqid < 0)
 {
   perror("msgget() failed");
   _exit(1);

 }

 ret1 = fork();
 if (ret1 == 0)
 {
  msg_t m1;
  m1.type = 1;
  printf("child : send two numbers : ");
  scanf("%d%d", &m1.a , &m1.b);
  ret1 = msgsnd(mqid, &m1 , sizeof(m1) - sizeof(m1.type), 0);
  printf("child : send to numbers : %d\n", ret1);



  msg_t m2;
  printf("receive addition from parent:...\n");
  ret2 = msgrcv(mqid, &m2 , sizeof(m2) - sizeof(m2.type),2,0);
  if(ret2 >  0)
  {
   printf("chlid result is received : %d + %d = %d\n",m1.a,m1.b,m2.c);
  }
  else
  {
   printf("child: failed to receive results....\n");
  }
  _exit(0);
} 

else
{
  msg_t m1, m2;
  printf("waiting for two numbers :........\n");
  ret1 = msgrcv(mqid , &m1 , sizeof(m1) - sizeof(m1.type), 1, 0);
  printf("parent : two numbers receive : %d, %d\n", m1.a,m1.b);

  m2.type = 2;
  printf("Adding two numbers...\n");
  m2.c = m1.a + m1.b;
  ret1 = msgsnd(mqid, &m2, sizeof(m2) - sizeof(m2.type), 0);
  printf("message send : %d\n", ret1);

}

wait(&s);

return 0;
}
