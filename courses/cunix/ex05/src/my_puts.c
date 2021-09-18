#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "test.h"
//#include "syscalls.h"

int my_puts(const char *s){
    //int k=-2;
    /*int fg=null;
    char  buf [ 128 ]; 
    int a=open (s,fg, mode_t mode);

    write(a,s,strlen(s));

    close(fg);*/
    /*int n;
    while ((n = read(0, s)) > 0)
        {write(1,s, n); }
   // write(1,s);*/
   //************************
  // int l=strlen(s);
   //fwrite(1,s,l);
  // write(1,s,l);
  // int x = printf("%s\n", s);
  
  // write(1, s, strlen(s));
    

   /* int i = 0;
   while(s[i])  
    {
        if( putchar(s[i]) == EOF)  
        {return EOF;}
        i++;
    }*/
    /*
    write(k,s,strlen(s));
    if(putchar(*s)==EOF){
        return EOF;
    }
    if(putchar('\n') == EOF)  
   {
       return EOF;
   }
    return 1;

*/
       //return 0;
   //*************************************************
    /*int filedesc = open("testfile.txt", O_WRONLY | O_APPEND);
 
    if (filedesc < 0) {
        return -1;
    }
    write(filedesc, s, strlen(s));
    int x = printf("%s\n", s);
   //return (s > 0) ? s : EOF;
    return 0; */
    //*************************************************
    int i = 0;
   while(s[i])  
    {
        if( putchar(s[i]) == EOF)  
        {return EOF;}
        i++;
    }
   if(putchar('\n') == EOF)  //this will occur right after we quit due to the null terminated character.
   {
       return EOF;
   }
   return 1; 
   /*
   int fd1;
   char * arg = (char*) malloc(10); 
   //char arg[]="aaaaaaa";
    fd1 = open(&arg, O_WRONLY | O_CREAT);
    if (fd1 == -1) {
        perror("File cannot be opened");
        return EOF;
    }


     Enter the data to be written into the file 
    //scanf("%127s", buf);
   
    write(fd1, s, strlen(s));  fd1 is the file descriptor, buf is the character array used to 
    hold the data, strlen(buf) informs the function that the number of bytes equal to the length of the 
    string in the buffer need to be copied 
    close(fd1);
    return 0;
    */

}