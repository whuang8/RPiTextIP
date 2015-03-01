#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

  	FILE *fp;
  	char* word = malloc(1035 * sizeof(char));
	char* address = malloc(39 * sizeof(char));
	int wlan0Reached = 0;	

 	 /* Open the command for reading. */
  	fp = popen("ifconfig", "r");
  	if (fp == NULL) {
    		printf("Failed to run command\n" );
    		exit(1);
  	}

  	/* Read the output one word at a time*/
	while (fscanf(fp,"%s",word) == 1) { 
  		if(strcmp(word ,"wlan0") == 0 ) {
    			wlan0Reached = 1;
		}
		if(strcmp(word , "inet") == 0 && wlan0Reached == 1) {
			fscanf(fp,"%s",address);
			printf("%s\n",address);
		}
  	}

  	/* close */
  	pclose(fp);
  	return 0;
}
