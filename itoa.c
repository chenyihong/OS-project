#include "/usr/include/uarm/libuarm.h"
#include "itoa.h"

void u_reverse(char str[], int in, int fin){


	if (in < fin){
		str[in] ^= str[fin] ; //xor swap algorithm
		str[fin] ^= str[in] ;
		str[in] ^= str[fin] ;
		u_reverse(str, ++in, --fin);
	}
}

int u_cifre(int num){


	if (num != 0){
		int cifre = u_cifre(num/10) + 1 ;
		return cifre ;
	}
	else 
		return 0 ;


}


void u_itoa(char str[], int num, int i){ 
	

	if (num != 0){
		int cifra = num % 10 ;
		str[i] = (char)cifra +'0' ; //tabella ascii assegna cifre decimali da 48 a 57 compresi
		u_itoa(str,num/10,++i);
	}

}

//per provare funzioni
int main(int argc, char* argv[]){

	char stringa[5] = {'m','i','n','k'};
	int n = 67857 ;
	int m = u_cifre(n);
	char stringa_di_cifre[m+1] ;
	u_reverse(stringa,0,3);
	u_itoa(stringa_di_cifre,n,0);
	tprint(stringa);
	tprint("\n");
	tprint(stringa_di_cifre);
	return 0 ;
}