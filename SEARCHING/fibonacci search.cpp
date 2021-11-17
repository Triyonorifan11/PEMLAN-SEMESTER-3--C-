#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//fibonacci search

int main(){
	int i, j, F0, F1, Fibo, n, m, N, flag;
	int FK, FK1, FK2, FK3, s, p, q, t;
	int data_A[] = {0,5,7,12,15,17,19,22,25,27,32,35,37,40,45,53, 55, 98};
	n = sizeof(data_A)/sizeof(data_A[0]);
	int FIBO[8];
	
//	clrscr();
//	n = 15;
	F0 = 1; F1 = 1; Fibo = 1;
	j = 1;
	
	while(Fibo <= n+1){
		FIBO[j] = Fibo;
		Fibo = F0+F1;
		F0 = F1;
		F1 = Fibo;
		j++;
	}
	
	s = j - 1;
	
	FK = FIBO[s];
	FK1 = FIBO[s-1]; i = FK1;
	FK2 = FIBO[s-2]; p = FK2;
	FK3 = FIBO[s-3]; q = FK3;
	
	m = (n+1) - FK;
	
	printf("Masukkan nilai : ");
	scanf("%d", &N);
	
	if(N > data_A[i]){
		i = i + m;
	}
	
	flag = 0;
	
	while(i != 0 && flag == 0){
		if(N == data_A[i]){
			flag = 1;
		}
		else{
			if(N < data_A[i]){
				if(q == 0){
					i = 0;
				}
				else{
					i = i - q;
					t = p;
					p = q;
					q = t - q;
				}
			}
			else{
				if(p == 1){
					i = 0;
				}else{
					i = i + q;
					p = p - q;
					q = q - p;
				}
			}
		}
	}
	if(flag == 1){
			printf("Data ada pada index ke %d \n", i);
		}else{
			printf("Data tidak ada !!\n");
		} 
	return 0;
}


