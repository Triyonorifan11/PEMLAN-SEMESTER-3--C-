#include <stdio.h>
#include <stdlib.h>

//Nama  = Triyono Rifan;
//NPM   = 20081010003;
//Kelas = Pemlan B081;
//Pertemuan 6 = Selection Sort & Insertion Sort;

//inisialisasi Data
int data[6] = {32,75,69,58,21,40};

void tukar (int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(){
	int index = 0;
	for(int i = 0; i<6-1; i++){
		int DataKecil = i;
		for(int j = i; j<6; j++){
			if(data[DataKecil] > data[j]){
				DataKecil = j;
				
			}
		}
		tukar(&data[DataKecil], &data[index]);
		index++;
	}
}

int main(){
	printf("Data sebelum Selection Sort\n");
	for(int i = 0; i<6; i++){
		printf("%d  ", data[i]);
	}
	
	printf("\n\nData setelah Selection Sort\n");
	SelectionSort();
		for(int i = 0; i<6; i++){
		printf("%d  ", data[i]);
	}
	system("pause");
	return 0;
}
