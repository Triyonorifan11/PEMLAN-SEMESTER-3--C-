#include <stdio.h>
#include <stdlib.h>

struct lokasi_kos{
	char provinsi[100];
	char Kabupaten[130];
	char jalan[150];
};

struct pemilik_kos{
	long long int harga;
	lokasi_kos lokasi;
	char fasilitas[300];
	char tipe[15];
}Kos;

//inisialisasi
void Pemilik_Kos();
void Penyewa_Kos();
void input_kos();
void update_kos();
void lihat_kos();

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
		case 3:
			lihat_kos();
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
	fptr = fopen("Ummik_Kos.txt","a"); //menghasulkan pointer
	
	printf("===== Masukkan inputan dibawah ini =====\n");
	printf("Masukkan tipe rumah (LK/P) = ");
	scanf("%s", &Kos.tipe);
	printf("Masukkan alamat:");
	printf("\n\tProvinsi = ");
	scanf(" %[^\n]s", &Kos.lokasi.provinsi);
	printf("\tKabupaten = ");
	scanf(" %[^\n]s", &Kos.lokasi.Kabupaten);
	printf("\tJalan = ");
	scanf(" %[^\n]s", &Kos.lokasi.jalan);
	printf("Harga = ");
	scanf("%lld", &Kos.harga);
	printf("Fasilitas = ");
	scanf(" %[^\n]s", &Kos.fasilitas);
	
//	while(fscanf(fptr," %s %s %s %s %lld %s", &Kos.tipe, &Kos.lokasi.provinsi, &Kos.lokasi.Kabupaten, &Kos.lokasi.jalan, &Kos.harga, &Kos.fasilitas)!=EOF){
//		jumlah_kos++;
//	}
	
	fprintf(fptr,"%s %s %s %s %lld %s \n", Kos.tipe, Kos.lokasi.provinsi, Kos.lokasi.Kabupaten, Kos.lokasi.jalan, Kos.harga, Kos.fasilitas);
	fclose(fptr);
	
	system("pause");
	Pemilik_Kos();
}
void lihat_kos(){
	FILE *view;
	int hasil = 0;
	view = fopen("Ummik_Kos.txt","r");
	
	while(fscanf(view,"  %[^\n]s  %[^\n]s  %[^\n]s  %[^\n]s %lld  %[^\n]s", &Kos.tipe, &Kos.lokasi.provinsi, &Kos.lokasi.Kabupaten, &Kos.lokasi.jalan, &Kos.harga, &Kos.fasilitas)!=EOF){
		printf("%s %s %s %s %lld %s\n", Kos.tipe, Kos.lokasi.provinsi, Kos.lokasi.Kabupaten, Kos.lokasi.jalan, Kos.harga, Kos.fasilitas);
		jumlah_kos++;
	}
	
	printf("jumlah banyak kos %d\n\n", hasil);
	fclose(view);
system("pause");
}
void update_kos(){
	printf("Update Kos");
}

int main(){
	mainMenu();
	return 0;
}
