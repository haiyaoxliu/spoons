#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>



int main() {
  printf("initial message\n");
  srand(time(NULL));
  int f1, f2, r;
  int status;
  if(!(f1 = fork())) {
    if(!(f2 = fork())) {
        waitpid(-1,&status,0);
	printf("pid:\t%d"
	printf("wait time:%d\n",WEXITSTATUS(status));
	return 0;
    }
    else {
      printf("haiyao:\t%d\n",getpid());
      r = rand()%16 + 5;
      sleep(r); 
      printf("YES!\n");
      exit(r);
    } //HY
  }
  else {
    printf("herman:\t%d\n",getpid());
    r = rand()%16 + 5;
    sleep(r);
    printf("herman finished his broccoli!\n");
    exit(r);
  } //HM

  //if(!f1) {
    //}
  /*
  else if(!f2) {
   }
  */
}
