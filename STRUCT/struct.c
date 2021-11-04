#include <stdio.h>
#include <stdlib.h>
//manajement data mahasiswa
//1. Menambah data
//2. Melihat Data
//3. Update Data
//4. Delete Data
//5. Pencarian Data
//ada nested struct nya

typedef struct input_nama{
	char nama[31];
	char npm[31];
	int umur;
}input ;

typedef struct data_jurusan{
	char jurusan[31];
	char fakultas[31];
	input mhs[31];
}Djurusan;

void pilih();

int main(){
	//input
	int i, j;
	Djurusan Dmhs[10];
	printf("=====Data Manajement Mahasiswa====\n");
	printf("ada berapa mahasiswa = ");
	scanf("%d", &j);
	
	for(i = 0; i<j; i++){
		printf("Mahasiswa ke %d\n", i+1);
		printf("Masukkan Nama = ");
		scanf(" %[^\n]s", &Dmhs[i].mhs[i].nama);
		printf("NPM = ");
		scanf(" %s", &Dmhs[i].mhs[i].npm);
		printf("Umur = ");
		scanf("%d", &Dmhs[i].mhs[i].umur);
		printf("Jurusan = ");
		scanf(" %[^\n]s", &Dmhs[i].jurusan);
		printf("Fakultas = ");
		scanf(" %[^\n]s", &Dmhs[i].fakultas);
		printf("\n\n");
	}
	
	//output
	for(i=0; i<j; i++){
		printf("=== Nama Mahasiswa ke - %i ===\n", i+1);
		printf("Nama = %s\n", Dmhs[i].mhs[i].nama);
		printf("NPM = %s\n", Dmhs[i].mhs[i].npm);
		printf("Umur = %d\n", Dmhs[i].mhs[i].umur);
		printf("Jurusan = %s\n", Dmhs[i].jurusan);
		printf("Fakultas = %s\n", Dmhs[i].fakultas);
		printf("\n\n");
	}
	int pilihan;
	printf("\n===============================\n");
	printf("Masukkan Pilihan Manajement\n");
	printf("1. Menambah data");
	printf("\n2. Melihat Data");
	printf("\n3. Update Data");
	printf("\n4. Delete Data");
	printf("\n5. Pencarian Data");
	printf("\nMasukkan Pilihan = ");
	scanf("%d", &pilihan);
	
	if(pilihan == 1){
		j = j+1;
		printf("====Masukkan banyak Data Baru===\n");
		printf("Mahasiswa ke %d\n", j);
		printf("Masukkan Nama = ");
		scanf(" %[^\n]s", &Dmhs[j].mhs[j].nama);
		printf("NPM = ");
		scanf(" %s", &Dmhs[j].mhs[j].npm);
		printf("Umur = ");
		scanf("%d", &Dmhs[j].mhs[j].umur);
		printf("Jurusan = ");
		scanf(" %[^\n]s", &Dmhs[j].jurusan);
		printf("Fakultas = ");
		scanf(" %[^\n]s", &Dmhs[j].fakultas);
		printf("\n\n");
		
		//outputnya
		for(i = 0; i<j-1; i++){
			printf("=== Nama Mahasiswa ke - %d ===\n", i+1);
			printf("Nama = %s\n", Dmhs[i].mhs[i].nama);
			printf("NPM = %s\n", Dmhs[i].mhs[i].npm);
			printf("Umur = %d\n", Dmhs[i].mhs[i].umur);
			printf("Jurusan = %s\n", Dmhs[i].jurusan);
			printf("Fakultas = %s\n", Dmhs[i].fakultas);
			printf("\n\n");
		}
		printf("=== Tambah Nama Mahasiswa ke - %d ===\n", j);
		printf("Nama = %s\n", Dmhs[j].mhs[j].nama);
		printf("NPM = %s\n", Dmhs[j].mhs[j].npm);
		printf("Umur = %d\n", Dmhs[j].mhs[j].umur);
		printf("Jurusan = %s\n", Dmhs[j].jurusan);
		printf("Fakultas = %s\n", Dmhs[j].fakultas);
		printf("\n\n");
		
	}else if(pilihan == 2){
		for(i = 0; i<j; i++){
			printf("=== Nama Mahasiswa ke - %d ===\n", i+1);
			printf("Nama = %s\n", Dmhs[i].mhs[i].nama);
			printf("NPM = %s\n", Dmhs[i].mhs[i].npm);
			printf("Umur = %d\n", Dmhs[i].mhs[i].umur);
			printf("Jurusan = %s\n", Dmhs[i].jurusan);
			printf("Fakultas = %s\n", Dmhs[i].fakultas);
			printf("\n\n");
		}
	}

	
	return 0;
}











