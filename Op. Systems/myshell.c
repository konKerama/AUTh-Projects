/*
Operating Systems Project - Command Line Interpreter
AUTHOR : Konstantinos Keramaris
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_LEN 1024
#define MAX_STRING 512
#define SIZE_OF_ENTER 1

void interactive (char *argv[]);
void batch(int argc, char *argv[]);
void execute(char **args, char *argv[]);
void parse(char *buf, char **args);
void deletewhitespaces(char *token);
int hasQuit(FILE *f);

int main (int argc, char *argv[]){
  //If I have not an argument go to interactive mode
  //else to batch mode
  if (argv[1] != NULL){
    batch(argc,argv);
  }else{
    interactive(argv);
  }
}

void interactive (char *argv[]) {
  int quit=0;
  char input[BUFFER_LEN];
  char *token=malloc(512*sizeof(char*));
  char *temp_token=malloc(512*sizeof(char*));
  char *args[100];// = {"ls", "-l", NULL};
  int numOfCommands=0;

  do{
    printf("keramaris_8159> ");
    //Error in input
    if(!fgets(input, BUFFER_LEN, stdin))
      break;
    size_t length = strlen(input);
    //if length >512
    if (length > MAX_STRING){
      printf("[ERROR] --> Too big command, max size 512 characters\n");
      exit(1);
    }
    //If length =0
    if ( length== SIZE_OF_ENTER){
      printf("[ERROR] --> No input\n");
      exit(1);
    }
    //Adding null terminator at the end of the string
    if (input[length-1] == '\n'){
      input[length-1] = '\0';
    }
    temp_token = strtok(input,";");
    numOfCommands=0;
    while(temp_token!=NULL){
      strcpy(token,temp_token);
      //Delete leading and trailing Spaces
      deletewhitespaces(token);
      if (strcmp(token,"")!=0){
        //If not empty
        if ( strstr(token,"quit") !=0 || strstr(token,"QUIT")!=0 ){
          //If in my command I have a quit
          quit=1;
        }else{
          parse(token,args);
          // args is now like {"ls", "-l", NULL};
          numOfCommands++;
          execute(args,argv);
        }
      }else{
        //if empty
        //if command like ;; it wont run beacuase od strtok
        printf("[Don't insert empty commands] \n");
        printf("_________________________________________\n");
      }
      temp_token=strtok(NULL,";");
    }
    pid_t pid;
    int i;
    //printf("numOfCommands=%d\n", numOfCommands);
    //wait for the "numOfCommands" children to finish
    for (i=0;i<numOfCommands;i++){
      pid=wait(NULL);
      printf("[Child with PID %d exited.]\n", pid);
    }
    if (quit){
      //if quit has pressed
      printf("Quit \n");
      exit(0);
    }
  }while(1);
}

void batch(int argc, char *argv[]){
  printf("Batch Mode:\n");

  char *args[100];
  FILE *f = NULL;
  ssize_t line;
  size_t length;
  char *buf=NULL;
  int quit = 0;
  int size;
  f=fopen(argv[1],"r");
  int numOfCommands;

  //If file is empty
  if (f==NULL){
    //If file doesn't exist
    printf("ERROR --> File Not found. \n");
    exit(1);
  }else{
    //if file is empty
    fseek (f, 0, SEEK_END);
    size = ftell(f);
    if (size == 0) {
      printf("ERROR -->File is empty\n");
      exit(1);
    }
  }

  fclose(f);
  f = fopen(argv[1], "r");

  if(!hasQuit(f)){
    //if file has not quit then print error and exit
    printf("ERROR -->File never quits\n");
    exit(1);
  }

  fclose(f);
  f = fopen(argv[1], "r");

  //If getline =-1 then failure of reading the line
  while (line = getline(&buf,&length,f) !=-1 ){
    if (length > MAX_STRING){
      printf("ERROR --> Too big command, max size 512 characters\n");
      exit(1);
    }

    char *token=malloc(512*sizeof(char*));
    char *temp_token=malloc(512*sizeof(char*));
    numOfCommands=0;
    temp_token = strtok(buf,";");
    while(temp_token!=NULL){
      strcpy(token,temp_token);
      //Delete leading and trailing Spaces
      deletewhitespaces(token);
      if (strcmp(token,"")!=0){
        //If not empty
        if ( strstr(token,"quit") !=0 || strstr(token,"QUIT")!=0 ){
          //If in my command I have a quit
          quit=1;
        }else{
          parse(token,args);
          // args = = {"ls", "-l", NULL};
          numOfCommands++;
          execute(args,argv);
        }
      }else{
        //if empty line
        printf("\n[ERROR] --> Don't insert empty commands \n");
        printf("___________________________________________________\n");
      }
      temp_token=strtok(NULL,";");
    }
    pid_t pid;
    int i;
    for (i=0;i<numOfCommands;i++){
      pid=wait(NULL);
      printf("[Child with PID %d exited.]\n", pid);
    }
    if (quit){
      //if quit has pressed
      printf("[QUIT] \n");
      exit(0);
    }

  }
}

//If has Quit return 1 else 0
int hasQuit(FILE *f){
  char *quitStr="quit";
  char *line;
  int quitFlag=0;
  line = (char*)malloc(1024);
  while (fgets(line , sizeof(line) ,f )!= NULL){
    if (strstr(line , quitStr)!= NULL){
      quitFlag=1;
      return quitFlag;
    }
  }
  return quitFlag;
}

//Delete leading and trailing spaces
void deletewhitespaces(char *string){
  char *end;
  size_t size;

  size = strlen(string);
  //If empty command
  if (size==0) return;

  //Delete trailing space
  end =string + size -1;
  while( end >= string && isspace((unsigned char)*end) ){
    end--;
  }

  //New null terminator
  *(end+1) = '\0';

  //Delete leading space
  while (isspace((unsigned char)*string)){
    string++;
  }
}

//Convert the buffer to arguments
void parse(char *buf, char **args){
  //for all the buffer
  while (*buf != '\0') {
    //While the current character of the buffer is empty then make it the null terminator
    //and move to the next memory position
    //Until we found an actual character
    while ((*buf == ' ') || (*buf == '\t'))
      *buf++ = '\0';
    //Save that charcter in the args pointer
    *args++ = buf;
    //While we found and actual character we increment the buf
    //each argument will end in the \0 character which will be added
    while ((*buf != '\0') && (*buf != ' ') && (*buf != '\t'))
      buf++;
  }
  //The last argument must be \0
  *args = '\0';
}

//Excecute the command
void execute (char **args, char *argv[]){
  int status;
  pid_t pid;
  pid=fork();
  if (pid<0){
    //Cant create fork
    printf("Error Fork \n");
    exit(1);
  }else if(pid==0){
    //printf("\nCommand = [%s]\n",args[0] );
    if (execvp(*args,args) <0 ){
      printf( "[ERROR] --> Command invalid\n");
      exit(1);
    }
  }
}
