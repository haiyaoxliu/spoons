#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
	
	srand(time(NULL));
	
	printf("initial message\n");
	int f = fork();
	if (f) {
		f = 1;
		f = fork();
	}
	
	if (!f) {
		printf("Child PID: %d\n", getpid());
		int snore = (rand() % 16) + 5;
		sleep(snore);
		printf("Child finished its broccoli");
		return snore;
	}
	if (f) {
		int status;
		f = wait(&status);
		printf("Child %d completed after %d seconds\n", f, WEXITSTATUS(status));
		printf("Parent process complete: %d\n", getpid());
	}
	
	return 0;
}