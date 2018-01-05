
/* 
 * File:   main.c
 * Author: ersinguven
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
/*
 * 
 */

static char* split( char* input ); 
void trim( char* str );


int main(int argc, char* argv[] ) {
   
    char* cmdargs[] = { "/bin/bash",
    "factorial=1",
    "counter=5",
    "while [ $counter -gt 0 ]",
    "do",
    "factorial=$(($factorial*$counter))",
    "counter=$(($counter - 1 ))",
    "done",
    "echo $factorial",
    NULL};
    
    
   
    char delim[2] = " ";
    printf(" Welcome To My Shell ! ");
   
    
    while( 1 ) {
        
        char line[ 1024 ];
        const char* cmd[10];
        int index = 0;
        printf("$> ");
        fgets( line , 1024 , stdin );
        
        
        char* newt ;
        
        newt = strtok( line , delim );
        
        while( newt != NULL ){
            cmd[index] = newt;
            index++;
            
            newt = strtok( NULL , delim );
        }
   
        
        
        char command[20];
        strcpy( command , cmd[0] );
        trim(command);
        printf("%s\n", command );
      
        
        
        if( command[0] != '-' ){
            printf("Error : Command argument is missing or not used properly. ( Format of commands : '--'command'') \n");
            continue;
        }
        
        
        else if( strcmp( command , "-factorial") == 0 ){
            
          
            const char* argv_t[ 3 ] ;
        
            
            argv_t[1] = cmd[1];
        
          pid_t  pid;
     int    status;

     if ((pid = fork()) < 0) { 
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) { 
          if (execvp("./factorial.sh", argv_t  ) < 0) { 
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
     }
     else { 
          while (wait(&status) != pid) 
               ;
     }
        }
        
        else if( strcmp( command , "-news") == 0 ){
            
            
            const char* argv_t[ 3 ] ;
            
            pid_t  pid;
     int    status;

     if ((pid = fork()) < 0) { 
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) { 
        
          if (execvp("./firefox.sh", argv_t  ) < 0) { 
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
     }
     else { 
          while (wait(&status) != pid) 
               ;
     }
            
        }
    }
    
    

    return (EXIT_SUCCESS);
}

static char* split( char* input ){
    
    char delim[2] = " ";
    
    return strtok( input , delim );
    
    
}

void trim(char * str)
{
    int index, i, j;

    index = 0;

   
    while(str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
    {
        index++;
    }


    if(index != 0)
    {
       
        i = 0;
        while(str[i + index] != '\0')
        {
            str[i] = str[i + index];
            i++;
        }
        str[i] = '\0'; 
    }
}

