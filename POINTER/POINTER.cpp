#include <stdio.h>


 void pangkat (int *m, int n){
 	int i, hasil = 1;
 	for(i = 0; i<n; i++){
 		hasil = hasil * *m;
	 }
	 *m = hasil;
 }
int main(){
	
	int m = 9, n = 6;
	pangkat(&m,n);
	printf("Hasil perpangkatan  = %d", m);
	
	return 0;
}

