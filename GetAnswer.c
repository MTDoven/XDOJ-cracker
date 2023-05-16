#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#define LENGTH 1000
int exec_cmd(const char *cmd);
// CMD(Terminal) control: input terminal command
char output[LENGTH]="";



char ip[LENGTH]="10.198.67.44:8080";
/*!!! Replace the IP and port to your IP and port !!!*/
int number_of_examples = 3;
/*!!! Replace the number to that of your problem !!!*/


int main(){
    for(int i=1; i<=number_of_examples; i++){
        sprintf(output,"curl --data-binary @./%d.ans http://%s/Receiver?message=Answers",i,ip);
        exec_cmd(output);
    }
    return 0;
}/*!!! Don't change main function if not neccessary !!!*/


// One useful function below
int exec_cmd(const char *cmd){
    FILE *pipe = popen(cmd, "r");
    if(!pipe) return -1;
    char buffer[LENGTH] = {0};
    while(!feof(pipe)){
        if(fgets(buffer, LENGTH, pipe))
            strcat(output, buffer);	}
    pclose(pipe);
    return 1;
} // CMD(Terminal) control


