#include <stdio.h>

int data[] = {22,10,15,3,8,2};

void BubbleSortAsc(){
	int i, j, t;
		for (i=0; i<=6-1; i++){
			for (j=5; j>=(i+1); j--){
				if (data[j]<data[j-1]){
					t = data [j-1];
					data [j-1] = data [j];
					data [j] = t;
				}
			}
	}
}

int main(){
	printf("Data Sebelum sorting : \n");
	for (int i = 0; i<6; i++){
		printf("%d ", data[i]);
	}
	BubbleSortAsc();
	printf("\n\nSetelah Proses sorting : \n");
	for(int i = 0; i<6; i++){
		printf("%d ", data[i]);
	}
	return 0;
}
