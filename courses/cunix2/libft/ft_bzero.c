void ft_bzero(void * s, unsigned int n){
	for(unsigned int i = 0; i < n; i++){
		*((int *)s) &= ~(1 << i);
	}
}
