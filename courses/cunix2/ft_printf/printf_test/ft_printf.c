#include <io.h>
#include <stdarg.h>
#include <stdlib.h>

unsigned int ft_strlen(char *str){
	unsigned int num = 0;
	while (*str != '\0'){
		num++;
		str++;
	}
	return num;
}

char *ft_itoa(int nmb, int plus, int zero,unsigned int ati){
	int count = 0, len = 0;
	int neg = 0;
	if (nmb < 0){
		neg = 1;
		nmb = -nmb;
		count++;
	} else if (nmb == 0){
		count = 1;
	} else if (plus) {
		count++;
	}
	int num = nmb;
	while (num > 0){
		num /= 10;
		count++;
	}
	if (zero){
		len = (count > ati) ? count : ati;
	}else{
		len = count;
	}
	char *str = (char *) malloc(len+1);
	str[len] = '\0';
	if(zero){
		for(int i = 0; i < len; i++){
			str[i] = '0';
		}
	}
	for (int i = 0; i < len; i++){
		str[len-i-1] = nmb % 10 +'0';
		nmb /= 10;
	}
	if (neg){
		*str = '-';
	} else if (*plus > 0) {
		*str = '+';
	} else if (*plus < 0) {
		*str = ' ';
	}
	return str;
}

int ft_atoi(const char *nptr){
	int count = 0;
	int neg = 0;
	if(*nptr == '-'){
		neg = 1;
		nptr++;
	}
	while(*(nptr+count) >='0' && *(nptr + count) <= '9'){
		count++;
	}
	int sum = 0;

	for (int i = 0; i < count; i++){
		sum = sum*10 + (int)(nptr[i] - '0');
	}
	if(neg){
		sum *= -1;
	}
	return sum;
}

int isflag (const char *ch, int *zero, int *width, int *plus){
	if(*ch == '%'){
		*zero = 0;
		*plus = 0;
		*width = 0;
		int ind = 1;
		int i = 1;
		while(1){
			if(*(ch+i) == '%' || *(ch+i) == 'c' || *(ch+i) == 's' || *(ch+i) == 'd' || *(ch+i) == 'i'){
				return 1;
			}else if(*(ch+i) == '-'){
				*zero = 0;
				if(ind){
					*width = i;
					ind = 0;
				}
			}else if(*(ch+i) == '0' && ind){
				*zero = 1;
			}else if(*(ch+i) >= '0' && *(ch+i) <= '9'){
				if(ind){
					*width = i;
					ind = 0;
				}
			}else if(*(ch+i) == '+'){
				*plus = 1;
			}else if(*(ch+i) == ' ' && *plus != 1){
				*plus = -1;
			}else{
				return 0;
			}
			i++;
		}
	}
	return 0;
}
int ft_printf(const char *format, ... ){
	unsigned int len = 0;
	int zero, width;
	while (format[len] != '\0'){
		len++;
	}
	len++;
	
	va_list arg_list;
	
	int temp, order, ati, plus;
	char *ptr;
	va_start(arg_list, format);
	
	unsigned int i = 0, current = 0, sublen = 0;
	while(i < len && current < len){
		i = current;
		while(!isflag(format+i,&zero,&width,&plus) && i < len){
			i++;
		}
		if(write(1,format+current,i - current) != i-current){
			write(1,"OUTPUT ERROR #1.SHUTDOWN.\n",25);
			exit(1);
		}
		current = i + width;
		ati = atoi(format+current);
		current++;
		while(current < len && ((format[current] >= '0' && format[current] <= '9') || format[current] == '+' || format[current] == '-' || format[current] == ' ')){
			current++;
		}
		if(current < len){
			switch(format[current]){
				case 'c':
					temp = va_arg(arg_list, int);
					sublen = 1;
					ptr = (char *) &temp;
				break;
				case 's':
					ptr = va_arg(arg_list, char *);
					sublen = ft_strlen(ptr);
				break;
				case 'd':
					temp = va_arg(arg_list, int);
					ptr = ft_itoa(temp,plus,zero,ati);
					sublen = ft_strlen(ptr);
					free(ptr);
				break;
				case 'i':
					temp = va_arg(arg_list, int);
					ptr = ft_itoa(temp,plus,zero,ati);
					sublen = ft_strlen(ptr);
					free(ptr);
				break;
				case '%':
					sublen = 1;
					ptr = "%";
				break;
				default:
					write(1,"\nINVALID FLAG.PRINTF FAILURE SHUTDOWN\n",38);
					exit(1);
				break;
			}
			if(ati < 0){
				order = -1;
				ati = -ati;
			} else if(ati > 0){
				order = 1;
			} else{
				order = 0;
			}
			int boool = ati > suvlen ? ati - sublen : 0;
			if(order > 0 && (format[current] == 'd' || format[current] == 'i') && !zero){
				for(unsigned int i = 0; i < boool; i++){
					write(1," ",1);
				}
			} else if(order > 0 && format[current] != 'd' && format[current] != 'i'){
				for(unsigned int i = 0; i < boool; i++){
					if(zero){
						write(1,"0",1);
					} else{
						write(1," ",1);
					}
				}
			}
			write(1,ptr,sublen);
			if(order < 0){
				for(unsigned int i = 0; i < boool; i++){
					write(1," ",1);
				}
			}
		}
		current++;
	}
	va_end(arg_list);
	return 1;// temporary
}
