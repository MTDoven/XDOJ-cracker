#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char output[]="";
int exec_cmd(const char *cmd);

int main(){
	exec_cmd("for F in *.ans ; do cp $F ${F%%.ans}.out ;done");
    return 0;
}

int exec_cmd(const char *cmd){
	FILE *pipe = popen(cmd, "r");
	if(!pipe)
		return 0;
	char buffer[1024] = {0};
	while(!feof(pipe)){
		if(fgets(buffer, 1024, pipe))
			strcat(output, buffer);
	}
	pclose(pipe);
	return 0;
} // CMD(Terminal) control



