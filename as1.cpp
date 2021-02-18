//PROBLEM 1 ASSIGNMENT 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
int counter = 0,pid,i;
char buffer[100];
char *args[10];
char *point;

while(1)
{
counter = 0;
printf("cmd>");

fgets(buffer,sizeof(buffer),stdin); // reads the string (string, value, pointer to file obj)

buffer[strlen(buffer)-1]='\0'; //strlen returns length of given string

if(strcmp(buffer,"exit") == 0) // to exit
{
break; //stops if statement
}

for(i = 0; i < 10; i++) //10 array of strings
{
args[i] = (char*) malloc(30*sizeof(char));
}

point = strtok(buffer," ");


strcpy(args[counter++],point); // copies one string to another

while(point!=NULL)
{
point = strtok(NULL," ");

if(point == NULL)
break;

strcpy(args[counter++],point);
}

//execvp to execute cmd,create child process
args[counter] = NULL;
pid = fork();

if(pid == 0) //child process
{
execvp(*args,args);
}

else //parent process
{
wait(0); //wait for child to finish
}

} // while loop

return 0;

}
