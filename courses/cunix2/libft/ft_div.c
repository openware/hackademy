#include <stdlib.h>
/*typedef struct divid {
	int quot;
	int rem;
}	div_t;*/

div_t ft_div(int num, int denom) {
	div_t result;
	result.quot = num / denom;
	while (num >= denom){
		num -= denom;
	}
	result.rem = num;
	return result;
}
