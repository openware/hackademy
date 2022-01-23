#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int my_strlen(char *str)
// have to reassign here because the function from ex01 in the first week doesnt work (type mismatch)
{
    int i = 0;
    while (str[i] != '\0')
        ++i;
    return i;
}

char *utoa(unsigned int num, int base) 
{ 
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50]; 
	char *ptr; 
	
	ptr = &buffer[49]; 
	*ptr = '\0'; 
	
	do 
	{ 
		*--ptr = Representation[num%base]; 
		num /= base; 
	}while(num != 0); 
	
	return(ptr); 
}

int myisdigit(int c)
{
        if (c >= '0' && c <= '9')
                return c;
        else
                return 0;
}

void ft_printf(char* format,...) 
{ 
	char *traverse; 
	int i,j; 
	char *s; 
	va_list arg; 
	va_start(arg, format);
    int num = 0;
	int isnum=0;
    char *res;
	for(traverse = format; *traverse != '\0'; traverse++) 
	{ 
		while( *traverse != '%' && *traverse != '\0' && *traverse != '\\') 
		{ 
			putchar(*traverse);
			traverse++; 
		} 
        int sp=-1;
        int plus = -1;
        int nul = -1;
        int min = -1;
        int kl;
        if(*traverse == '\0')break;
		traverse++; 
        while(*traverse == ' '){
            traverse++;sp=1;
        }

        if(*traverse=='+'){
            plus=1;
            traverse++;
        }
        if(*traverse=='0'){
            nul=1;
            traverse++;
        }
        while(myisdigit(*traverse)){
            num=num*10+(int)*traverse-48;
            isnum=1;
            traverse++;
        }
		switch(*traverse) 
		{ 
			case 'c' : i = va_arg(arg,int);	
            if(isnum==1){
                for(int klm=0;klm<num-1;klm++)putchar(' ');
            }
                putchar(i);
                break; 
						
			case 'd' : 
            case 'i' : i = va_arg(arg,int); 
                if(plus==1&&i>=0){
                        putchar('+');
                        plus=-1;
                        num--;
                    }
                if(i<0) 
                { 
                    min=1;
                    i = -i;
                    sp=-1;
                    if(nul==1||isnum!=1){
                        putchar('-');
                        min=-1;
                        num--;
                    }
                    //num--;
                }
                if(sp==1)putchar(' ');
                if(isnum==1){
                    char*str=utoa(i, 10);
                    if(min==1||plus==1){
                        char *strr=malloc((my_strlen(str)+1)*sizeof(char));
                        if(min==1){
                            strr[0]='-';
                        }else if(plus==1){
                            strr[0]='+';
                        }
                        for(kl=0;kl<my_strlen(str);kl++)strr[kl+1]=str[kl];
                        strr[kl+1]='\0';
                        str=strr;
                    }
                    if(my_strlen(str)<=num){
                        res=(char*)malloc((num+1)*sizeof(char));
                        for(j=0;j<num;j++){
                            if(j-num+my_strlen(str)<0){
                                if(nul==1){
                                    res[j]='0';
                                }else{
                                    res[j]=' ';
                                }
                                
                            }else{
                                res[j]=str[j-num+my_strlen(str)];
                            }
                        }
                        res[j]='\0';
                    }else{
                        res=str;
                    }
                    fputs(res, stdout);
                }else{
                    fputs(utoa(i,10), stdout);
                }
                sp=-1;
                break;        
			case 'o': i = va_arg(arg,unsigned int); 
                fputs(utoa(i,8), stdout);
                break; 
                
			case 's': s = va_arg(arg,char *); 
                if(s==NULL){
                    s="(null)";
                    //s[7]='\0';
                }
                if(isnum==1){
                    char*str=s;
                    if(my_strlen(str)<=num){
                        res=(char*)malloc((num+1)*sizeof(char));
                        for(j=0;j<num;j++){
                            if(j-num+my_strlen(str)<0){
                                res[j]=' ';
                            }else{
                                res[j]=str[j-num+my_strlen(str)];
                            }
                        }
                        res[j]='\0';
                    }else{
                        res=s;
                    }
                    fputs(res, stdout);
                }else{
                    fputs(s, stdout);
                }
                break; 
						
			case 'x': i = va_arg(arg,unsigned int); 
                fputs(utoa(i,16), stdout);
                break; 
            case 'n':
                puts("");
                break;
            case '%':
                putchar('%');
            default:
                break;
		}
        num=0;isnum=0;nul=-1;min=-1;
	} 
	va_end(arg); 
} 