#include <stdio.h> // importing
#include <stdlib.h>            // import
#include <stdint.h>                      //files

int main(int argc, char *argv[])
{
    //check command line if user added file or no
 if(argc != 2)
 {
     printf("Usage: ./recover IMAGE \n"); //if line N 11 not, print error message
     return 1; //stop all
 }

FILE *fl = fopen(argv[1], "r"); // read argument [1] wich is  a pointer to the first command line argument supplied with FILE function

if(fl == NULL) //if no file
{
    printf("File not found \n"); //print error
    return 1;
}
char f[8]; //create char f with 8


FILE *result = NULL; //
unsigned char buf[512]; //creat buf with 512 bytes


int rasm = 0; //integer variable rasm declared as 0
int name = 0; //integer variable name declared as 0


while (fread(buf, 512,1, fl)) //read buf data
{
    if(buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0) //if conditions above are satisfied
    {
         if(rasm != 0) //if result = 0
        {
            printf("oops, somthing is wrong \n"); //print error
            fclose(result); //pint error and close result
        }
        sprintf(f, "%03i.jpg", name); //printf names of the images with decreasing by 1 each time
        result = fopen (f,"w"); name+=1; //rewwrite


    }
    if(result != 0)
    {

        fwrite(buf, 512, 1, result);
    }
  }
  return 0;
}