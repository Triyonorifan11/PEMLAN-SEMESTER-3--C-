#include <stdio.h>
#include <stdlib.h>

struct lokasi_kos{
	char provinsi[30];
	char Kabupaten[30];
	char jalan[50];
};

struct pemilik_kos{
	long long int harga;
	lokasi_kos lokasi;
	char fasilitas[300];
	char tipe[15];
}Kos[100];

//inisialisasi
void Pemilik_Kos();
void Penyewa_Kos();
void input_kos();
void update_kos();

int jumlah_kos = 0;

void mainMenu(){
	int pilih;
	system("cls");
	printf("======UMMIK.KOSS=======\n");
	printf("Selamat datang di aplikasi Kos sederhana\n");
	printf("Masukkan pilihan user\n");
	printf("[1] Pemilik Kos\n");
	printf("[2] Penyewa Kos");
	printf("\nMasukkan pilihan : ");
	scanf("%d", &pilih);
	if(pilih == 1){
		Pemilik_Kos();
	}else if(pilih == 2){
		Penyewa_Kos();
	}else{
		printf("\nMasukkan Pilihan yang benar !!");
		system("Pause");
		mainMenu();
	}
}


void Pemilik_Kos(){
	system("cls");
	int pilih;
	printf("===== Laman Pemilik Kos UMMIK.KOS =====\n");
	printf("====Menu====\n");
	printf("[1] input kamar\n");
	printf("[2] update kamar\n");
	printf("[3] lihat daftar kamar\n");
	printf("[4] close\n");
	printf("Masukkan Pilihan : ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1:
			input_kos();
			break;
		case 2:
			update_kos();
			break;
	}
	
}
void Penyewa_Kos(){
	system("cls");
	int pilih;
	printf("===== Laman Penyewa Kos UMMIK.KOS =====\n");
	printf("====Menu====\n");
	printf("[1] Cari kamar\n");
	printf("[2] lihat daftar kamar\n");
	printf("[3] close\n");
	printf("Masukkan Pilihan : ");
}

void input_kos(){
	FILE *fptr;
	fptr = fopen("Ummik_Kos.txt","a");
	
	printf("===== Masukkan inputan dibawah ini =====\n");
	printf("Masukkan tipe rumah (LK/P) = ");
	scanf("%s", &Kos[jumlah_kos].tipe);
	printf("Masukkan alamat:");
	printf("\n\tProvinsi = ");
	scanf(" %[^\n]s", &Kos[jumlah_kos].lokasi.provinsi);
	printf("\tKabupaten = ");
	scanf(" %[^\n]s", &Kos[jumlah_kos].lokasi.Kabupaten);
	printf("\tJalan = ");
	scanf(" %[^\n]s", &Kos[jumlah_kos].lokasi.jalan);
	printf("Harga = ");
	scanf("%lld", &Kos[jumlah_kos].harga);
	printf("Fasilitas = ");
	scanf(" %[^\n]s", &Kos[jumlah_kos].fasilitas);
	
	fprintf(fptr,"%s %s %s %s %lld %s", Kos[jumlah_kos].tipe, Kos[jumlah_kos].lokasi.provinsi, Kos[jumlah_kos].lokasi.Kabupaten, Kos[jumlah_kos].lokasi.jalan, Kos[jumlah_kos].harga, Kos[jumlah_kos].fasilitas);
	fclose(fptr);
	
	jumlah_kos++;
	mainMenu();
}

void update_kos(){
	printf("Update Kos");
}

int main(){
	mainMenu();
	return 0;
}
