#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*writes the IP address to a text file*/
void writeToFile(char* address) {
	FILE* f = fopen("address.txt","w");
	if(f == NULL) {
		printf("Cannot open file\n");
		exit(1);
	}	

	fprintf(f, "%s\n", address);
	fclose(f);
}

/* Inserts command on command line and reads in output. The funtion parses
the output and returns an IP address string*/
char* readOutput() {
  	char* word = malloc(100 * sizeof(char));
	char* address = malloc(39 * sizeof(char));
	int wlan0Reached = 0;
	FILE* f;	

 	/* Open the command for reading. */
  	f = popen("ifconfig", "r");
  	if (f == NULL) {
    		printf("Failed to run command\n" );
    		exit(1);
  	}

  	/* Read the output one word at a time*/
	while (fscanf(f,"%s",word) == 1) { 
		/* If wlan0 is read, set variable to 1 */
  		if(strcmp(word ,"wlan0") == 0 ) {
    			wlan0Reached = 1;
		}
		/* stores ip address in variable in format "addr:###.#.#.#" */
		if(strcmp(word , "inet") == 0 && wlan0Reached == 1) {
			fscanf(f,"%s",address);
		}
  	}

  	/* close */
  	pclose(f);
	
	return address;
}
/* returns only numeric part of address string */
char* format(char* address) {
	return address+=5;	
}

int main(int argc, char** argv){
	char* address = malloc(100 * sizeof(char));
	address = format(readOutput());
	writeToFile(address);
  	return 0;
}
