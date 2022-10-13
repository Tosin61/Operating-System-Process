#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define   BUF_SIZE   100

void main(void){
  pid_t pid1, pid2, pid3;

  int stat;
  int left = 1;
  int right = 25;
  char bufSize[BUF_SIZE];
  srand(time(0));

  int first = (rand() % (right)) + left;
  int second = (rand() % (right)) + left;

  printf("first=%d, second=%d\n" ,first,second);

  pid1 = fork();
  if (pid1==0){
    int child = getpid();
    int id = getppid();
    int x;

    for(x= 1; x<= first; x++){
      printf("Child Pid: %d is going to sleep!\n", child);
      srand(time(NULL));
      int time = (rand() % (5)) + 1;
      sleep(time);
      printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n",child,id);
    }
    exit(0);
  } 
  else{
    pid2 = fork();
    if (pid2==0){
    int child = getpid();
    int id = getppid();
    int x;

    for(x= 1; x<= first; x++){
      printf("Child Pid: %d is going to sleep!\n", child);
      srand(time(NULL));
      int time = (rand() % (5)) + 1;
      sleep(time);
      printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n",child,id);
    }
    exit(0);
  }
  }

  write(1, bufSize, strlen(bufSize));
  pid3 = wait(&stat);
  sprintf(bufSize, "Child Pid: %d has completed\n", pid3);
  write(1, bufSize, strlen(bufSize));
  pid3 = wait(&stat);
  printf("Child Pid: %d has completed\n", pid3);

}