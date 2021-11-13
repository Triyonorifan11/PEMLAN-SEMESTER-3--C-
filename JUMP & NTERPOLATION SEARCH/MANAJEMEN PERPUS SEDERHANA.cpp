#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct buku{
	long long int kode;
	char *pengarang;
	char *judul;
}buku[10];
//typedef struct buku Perpus_buku[10];


int j = 0;
int l = 0;

//deklarasi
void MainMenu();
void daftarBuku();
void tampil_buku();
void daftar_buku();
void Sorting();
void TampilSort();
void CariKode();
void CariJudul();
void close();

void MainMenu(){

	system("color 3f");
	system("cls");
	printf("\t\t\t\t\t\t\t=============== MENU UTAMA ===============\n");
	printf("\t\t\t\t\t\t\t====== Aplikasi Manajemen Buku perpustakaan ======\n");
//	TampilData2();
	if(l == 0){
		daftar_buku();
		tampil_buku();
	}else{
		Sorting();
		TampilSort();
	}
	
	printf("\n\t\tPilih Aksi:\n");
	printf("\n\t\t\t1. Cari Kode");
	printf("\n\t\t\t2. Cari Data Judul");
	printf("\n\t\t\t3. Close");
	int pilih;
	printf("\n\n\t\tSilahkan Pilih = ");
	scanf("%d", &pilih);
	if(pilih == 1){
	CariKode();
	daftarBuku(101, "Wordpress Expert", "Andrew Octa");
	daftarBuku(8812, "Web From Zero to Zero", "David Guetta");
	daftarBuku(790, "Laravel", "Hans Jackson");
	daftarBuku(66, "Master Futter", "Ozur Haskels");
	daftarBuku(111, "CodeIgniter 4 the guide", "Gantz Patrick");
	daftarBuku(678, "Raspberry Pi 4", "Tony Watts");
	daftarBuku(901, "Building Robotic AI", "Leni Imelda");
	daftarBuku(303, "Data Science with Python", "Ranya Sundar");
	daftarBuku(4089, "Go Lang Introduction", "Brian Macakzie");
}



void tampil_buku(){
	
	int i = 0;
	while(i<j){
		printf("%d  Kode Buku\t = %lld\n", i+1, buku[i].kode);
		printf("   Judul buku\t = %s\n", buku[i].judul);
		printf("   Pengarang\t = %s\n\n", buku[i].pengarang);
		i++;
	}
}


void tukar(struct buku *a, struct buku *b){
	struct buku t = *a;
	*a = *b;
	*b = t;
}

void Sorting(){
	int index = 0;
	for(int i = 0; i<j; i++){
		int Kodekecil = i;
		for(int k = i; k<j; k++){
			if(buku[Kodekecil].kode > buku[k].kode){
				Kodekecil = k;
			}
		}
		tukar(&buku[Kodekecil], &buku[index]);
		index++;
	}
}

void TampilSort(){
	int i = 0;
	//printf("===== Hasil Sorting =====\n\n");
	while(i<j){
		printf("%d  Kode Buku\t = %lld\n", i+1, buku[i].kode);
		printf("   Judul buku\t = %s\n", buku[i].judul);
		printf("   Pengarang\t = %s\n\n", buku[i].pengarang);
		i++;
	}
}

void jumpsearch(struct buku buku[], int lenght, long long int Kode){
	
	//langkah untuk jump
	int jump = sqrt(lenght);
	int jumper = jump;
	
	//mencari blok data
	int prev = 0;
	int count = 0;
	while(buku[jumper].kode <= Kode && jumper < lenght){
		
		prev = jumper;
		jumper += jump;
		
		if(jumper >= lenght){
			printf("Maaf Data tidak ditemukan\n");
			
		}
		count++;
	}
	
	int flag = 0;
	for(int i = prev; i<=jumper; i++){
		if(buku[i].kode == Kode){
			printf("\n======= Data Ditemukan =========\n");
			printf("%d  Kode Buku\t = %lld\n", i+1, buku[i].kode);
			printf("   Judul buku\t = %s\n", buku[i].judul);
			printf("   Pengarang\t = %s\n\n", buku[i].pengarang);
			flag = 1;
		}
	}
	if(count == 0 && flag == 0){
		printf("Maaf Data tidak ditemukan\n");
	}
	
	
}

void CariKode(){
	system("cls");
	long long int kodeCari;
	
	int lenght = sizeof(buku)/sizeof(buku[0]);
	
	
	printf("Masukkan kode buku = ");
	scanf("%lld", &kodeCari);
	Sorting();
	l++;
	jumpsearch(buku, lenght, kodeCari);
	system("pause");
	MainMenu();
}

int interpolationSearch(struct buku buku[], int lenght, char* key){
	int posisi, low, high;
	low = 0;
	high = lenght-1;
	
	while((strcmp(buku[low].judul, key) > 0) && (strcmp(buku[high].judul, key))){
		posisi = (key - buku[low]) / (buku[high] - buku[low]) * (high - low) + low;
		if((strcmp(buku[posisi], key) == 0)){
			return posisi;
		}
	}
	
}

void CariJudul(){
	char judulCari;
	
	int lenght = sizeof(buku)/sizeof(buku[0]);
	printf("Masukkan Judul buku = ");
	scanf("%s", &judulCari);
	fflush(stdin);
	Sorting();
	l++;
	
	interpolationSearch(buku, lenght, &judulCari);
	
	system("pause");
	MainMenu();
}

void close(){
	system("cls");
	system("color 1f");
	printf("\n\n\t\t\t=======Terima Kasih=======");
	printf("\n\t\t\tProgram Ditulis Oleh ");
	printf("\n\t\t\tNama         = Triyono Rifan\n");
	printf("\t\t\tNPM          = 20081010003\n");
	printf("\t\t\tKelas Pemlan = B081\n\n");
	printf("\t\t\tTugas Pertemuan 10 : Manajemen Pencarian Buku\n\n");
	printf("\t\t\tTekan Enter untuk keluar !!!\n\n\n\n");
	system("pause");
}

int main(){
	MainMenu();
	return 0;
}
