#include <unistd.h> 
#include <stdio.h> 
 
// Main Method 
void cdb(){ 
chdir("..");

} 
int cd(char* dir) { 

	chdir(dir);

return 0; 
} 
void currentDir(){
	char cwd[1024]; // Buffer to store the current working directory

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s", cwd);
    }
}