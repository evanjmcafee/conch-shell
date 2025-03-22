#include "headers.h"
#include "calls.c"
#include "colors.c"
char ERRTXT[] = "\x1b[38;5;160m";
char VOLUMETXT[] = "\x1b[38;5;27m";
char DIRTXT[] = "\x1b[38;5;46m";
char ENTERTXT[] = "\x1b[38;5;46m";
char NORMTXT[] = "\x1b[38;5;231m";
#define MAX_LINE 80 // Maximum length of command
void error(){
	printf("%s", ERRTXT);
}

void volume(){
	printf("%s", ERRTXT);
}

int terminal(){
  	char *args[MAX_LINE/2 + 1]; 
  	char line[MAX_LINE];
  	int status;
	int ran;

	printf("%s",NORMTXT);
		while(1){
				ran=0;
		printf("%s",NORMTXT);
  		fflush(stdout);
		printf("\x1b[38;5;10m");
		currentDir();
		printf("\x1b[38;5;220m");
		printf("/> ");
  		fflush(stdout);
		printf("%s", NORMTXT);
		fflush(stdout);
    	if (fgets(line, MAX_LINE, stdin) == NULL) {
      			break; 
    		}

    		int i = 0;
    		char *token = strtok(line, " \n");
    		while (token != NULL) {
      		args[i++] = token;
      		token = strtok(NULL, " \n");
    		}
    		args[i] = NULL; 

    	if (strcmp(args[0], "exit") == 0) {
      		break;
			
    	}
    	if (strcmp(args[0], "cd..") == 0) {
      		cdb();
			ran =1;
		}
		if (strcmp(args[0], "cd") == 0) {
      		cd(args[1]);
			ran = 1;
		}

    		pid_t pid = fork();
			if (pid == 0) {
				execvp(args[0], args); 
				error();
				if (ran==0){perror("execvp failed");}
				exit(1);
			} else if (pid < 0) {
				perror("fork failed");
				exit(1);
			} else { 
				wait(&status); 

}
}
}