#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
//Nama = Triyono Rifan
//NPM  = 20081010003
//Kelas = PemLan B

typedef struct jumlah_penduduk{
	float total_penduduk;
	float lansia;
	float total_vaksin;
	float total_lansia_vaksin;
}penduduk;

struct Data{
	char *provinsi;
	char *kota_kab;
	penduduk jumlah;
	long long int level;
}Data[10];


int j = 0;

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
  //	return;
}


//dekarasi
void MainMenu();
//void TambahData();
void TampilData2();
void tampil_data2();
void TampilData2_Baru();
void UrutData();
void CariData();
void TutupApk();
void hitung_Level();

void MainMenu(){
	system("color 3f");
	system("cls");
	printf("\t\t\t\t\t\t\t=============== MENU UTAMA ===============\n");
	printf("\t\t\t\t\t\t\t====== Aplikasi Informasi Level PPKM ======\n");
//	TampilData2();
	TampilData2_Baru();
	printf("\n\t\tPilih Aksi:\n");
	printf("\n\t\t\t1. Urut berdasarkan Level");
	printf("\n\t\t\t2. Cari Data");
	printf("\n\t\t\t3. Close Apk");
	int pilih;
	printf("\n\n\t\tSilahkan Pilih = ");
	scanf("%d", &pilih);
	if(pilih == 1){
		UrutData();
	}else if(pilih == 2){
		CariData();
	}else if(pilih == 3){
		TutupApk();
	}
	else{
		system("cls");
		printf("\t\t\t\t!!! PERHATIAN !!!\n");
		printf("\t\t\tMohon Masukkan Pilihan yang tersedia\n\n");
		system("Pause");
		MainMenu();
	}
}


void Tambah(char* Kab, char* provinsi, float total_penduduk, float Lansia, float vaksin_total, float lansia_vaksin){

	Data[j].kota_kab = Kab;
	Data[j].provinsi = provinsi;
	Data[j].jumlah.total_penduduk = total_penduduk;
	Data[j].jumlah.lansia = Lansia;
	Data[j].jumlah.total_vaksin = vaksin_total;
	Data[j].jumlah.total_lansia_vaksin = lansia_vaksin;
	hitung_Level();
	
	j++;
}

void tampil_data2(){
	
	Tambah("Surabaya", "Jawa Timur", 1000.0, 400.0, 600.0, 200.0);
	Tambah("Sumenep", "Jawa Timur", 1000.0, 900.0, 900.0, 700.0);
	Tambah("Sampang", "Jawa Timur", 1000.0, 200.0, 400.0, 600.0);
	Tambah("Pamekasan", "Jawa Timur", 1000.0, 400.0, 800.0, 300.0);
	Tambah("Semarang", "Jawa Tengah", 2000.0, 800.0, 1200.0, 300.0);
	Tambah("Bangkalan", "Jawa Timur", 2000.0, 800.0, 1200.0, 400.0);
	Tambah("Sidoarjo", "Jawa Timur", 2000.0, 800.0, 900.0, 300.0);
	Tambah("Pasuruan", "Jawa Timur", 3000.0, 900.0, 1200.0, 600.0);
	Tambah("Malang Kota", "Jawa Timur", 5000.0, 1200.0, 4500.0, 900.0);
	Tambah("Pacitan", "Jawa Timur", 3000.0, 1000.0, 1200.0, 400.0);
	
}

void hitung_Level(){
	float hasil_vaksin_penduduk, hasil_vaksin_lansia;
	hasil_vaksin_penduduk = Data[j].jumlah.total_vaksin / Data[j].jumlah.total_penduduk;
	hasil_vaksin_lansia = Data[j].jumlah.total_lansia_vaksin / Data[j].jumlah.lansia;
	
	if(hasil_vaksin_penduduk < 0.5 || hasil_vaksin_lansia < 0.4){
		Data[j].level = 3;
	}else if((hasil_vaksin_penduduk >= 0.5 && hasil_vaksin_penduduk < 0.7) || (hasil_vaksin_lansia >= 0.4 && hasil_vaksin_lansia < 0.6)){
		Data[j].level = 2;
	}else if(hasil_vaksin_penduduk >= 0.7 || hasil_vaksin_lansia >= 0.6 ){
		Data[j].level = 1;
	}
}


//void TambahData(){
//	printf("!!! masukkan data penduduk diikuti dengan .0");
//	printf("\n\t\t\t===== Masukkan Data =====\n");
//	printf("\t\t\tMasukkan Nama Provinsi= ");
//	scanf(" %[^\n]s", &Data[j].provinsi);
//	printf("\t\t\tMasukkan Nama Kota/Kab= ");
//	scanf(" %[^\n]s", &Data[j].kota_kab);
//	printf("\t\t\tJumlah Total Penduduk = ");
//	scanf("%f", &Data[j].jumlah.total_penduduk);
//	printf("\t\t\tJumlah Lansia = ");
//	scanf("%f", &Data[j].jumlah.lansia);
//	printf("\t\t\tJumlah Total penduduk Vaksin = ");
//	scanf("%f", &Data[j].jumlah.total_vaksin);
//	printf("\t\t\tJumlah Lansia Vaksin = ");
//	scanf("%f", &Data[j].jumlah.total_lansia_vaksin);
//	hitung_Level();
//	j++;
//	MainMenu();
//}

void TampilData2(){
	tampil_data2();
	int i = 0;
	while (i<j){
		printf("%d Provinsi\t\t= \t%s\n", i+1, Data[i].provinsi);	
		printf("  Kabupaten\t\t= \t%s\n", Data[i].kota_kab);
		printf("  Total Penduduk\t= \t%.0f\n", Data[i].jumlah.total_penduduk);
		printf("  Jumlah Lansia\t\t= \t%.0f\n", Data[i].jumlah.lansia);
		printf("  Total Tervaksin\t= \t%.0f\n", Data[i].jumlah.total_vaksin);
		printf("  Lansia Vaksin\t\t= \t%.0f\n", Data[i].jumlah.total_lansia_vaksin);
		printf("  Level\t\t\t= \t%lld\n", Data[i].level);
		
		printf("\n");
		i++;
	}
	
}

void TampilData2_Baru(){
	tampil_data2();
	int i = 0;
	printf("\n\n\t======================================================================================================================================================\n");
	printf("\t|| NO\t|");
	printf("|\tProvinsi\t|");
	printf("|\tKab/Kota\t|");
	printf("|   Total Penduduk  |");
	printf("| Jumlah Lansia\t |");
	printf("| Total ter-Vaksin |");
	printf("| Lansia Vaksin |");
	printf("| Level PPKM ||\n");
	printf("\t======================================================================================================================================================\n");
	for(i = 0; i<j; i++){
		printf("\t|| %d\t|", i+1);
		printf("|\t%s\t|", Data[i].provinsi);
		printf("|\t%s \t|", Data[i].kota_kab);
		printf("|    \t%.0f\t     |", Data[i].jumlah.total_penduduk);
		printf("| \t%.0f\t |", Data[i].jumlah.lansia);
		printf("|    \t%.0f\t      |", Data[i].jumlah.total_vaksin);
		printf("|    %.0f\t      |", Data[i].jumlah.total_lansia_vaksin);
		printf("|     %lld      ||", Data[i].level);
		printf("\n");
	}
	printf("\t======================================================================================================================================================\n");
	printf("\n\n");
}

void Cari_Level_PPKM(){
	system("cls");
	int inputCari;
	printf("Masukkan Level [1/2/3] = ");
	scanf("%d", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	
	for(i = 0; i<j; i++){
		if(inputCari == Data[i].level && hasilCari == 1){
			printf("%d Provinsi\t\t= \t%s\n", i+1, Data[i].provinsi);	
			printf("  Kabupaten\t\t= \t%s\n", Data[i].kota_kab);
			printf("  Total Penduduk\t= \t%.0f\n", Data[i].jumlah.total_penduduk);
			printf("  Jumlah Lansia\t\t= \t%.0f\n", Data[i].jumlah.lansia);
			printf("  Total Tervaksin\t= \t%.0f\n", Data[i].jumlah.total_vaksin);
			printf("  Lansia Vaksin\t\t= \t%.0f\n", Data[i].jumlah.total_lansia_vaksin);
			printf("  Level\t\t\t= \t%lld\n", Data[i].level);
		
			printf("\n");
		
			printf("\n");
			hasilCari++;
			break;
		}
	}
	
	if(hasilCari == 1){
	printf("Mohon maaf data tidak ditemukan\n\n");
		
	}
	printf("!!!Tekan Enter untuk Kembali ke Menu utama\n");
	system("pause");
	MainMenu();
}

void Cari_provinsi(){
	system("cls");
	char inputCari[30];
	printf("Masukkan Nama Provinsi yang akan dicari = ");
	scanf(" %[^\n]s", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	
	for(i = 0; i<j; i++){
		if(strcmp(Data[i].provinsi, inputCari) == 0){
			printf("%d Provinsi\t\t= \t%s\n", i+1, Data[i].provinsi);	
			printf("  Kabupaten\t\t= \t%s\n", Data[i].kota_kab);
			printf("  Total Penduduk\t= \t%.0f\n", Data[i].jumlah.total_penduduk);
			printf("  Jumlah Lansia\t\t= \t%.0f\n", Data[i].jumlah.lansia);
			printf("  Total Tervaksin\t= \t%.0f\n", Data[i].jumlah.total_vaksin);
			printf("  Lansia Vaksin\t\t= \t%.0f\n", Data[i].jumlah.total_lansia_vaksin);
			printf("  Level\t\t\t= \t%lld\n", Data[i].level);
		
			printf("\n");
		
			printf("\n");
			hasilCari++;
		}
	}
	if(hasilCari == 1){
	printf("Mohon maaf data tidak ditemukan\n\n");
		
	}
	printf("!!!Tekan Enter untuk Kembali ke Menu utama\n");
	system("pause");
	MainMenu();
}


void Cari_Kab(){
	system("cls");
	char inputCari[30];
	printf("Masukkan Nama Kabupaten yang akan dicari = ");
	scanf(" %[^\n]s", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	
	for(i = 0; i<j; i++){
		if(strcmp(Data[i].kota_kab, inputCari) == 0){
			printf("%d Provinsi\t\t= \t%s\n", i+1, Data[i].provinsi);	
			printf("  Kabupaten\t\t= \t%s\n", Data[i].kota_kab);
			printf("  Total Penduduk\t= \t%.0f\n", Data[i].jumlah.total_penduduk);
			printf("  Jumlah Lansia\t\t= \t%.0f\n", Data[i].jumlah.lansia);
			printf("  Total Tervaksin\t= \t%.0f\n", Data[i].jumlah.total_vaksin);
			printf("  Lansia Vaksin\t\t= \t%.0f\n", Data[i].jumlah.total_lansia_vaksin);
			printf("  Level\t\t\t= \t%lld\n", Data[i].level);
		
		printf("\n");
		
			printf("\n");
			hasilCari++;
		}
	}
	
	if(hasilCari == 1){
	printf("Mohon maaf data tidak ditemukan\n\n");
		
	}
	printf("!!!Tekan Enter untuk Kembali ke Menu utama\n");
	system("pause");
	MainMenu();
}


//Cari Data
void CariData(){
	int pilih;
	printf("Pilih untuk pencarian\n");
	printf("1. Level PPKM\n");
	printf("2. Provinsi\n");
	printf("3. Kabupaten/kota\n");
	printf("Masukkan Pilihan = ");
	scanf("%d", &pilih);
	if(pilih == 1){
		Cari_Level_PPKM();
	}else if(pilih == 2){
		Cari_provinsi();
	}else if(pilih == 3){
		Cari_Kab();
	}else{
		printf("masukkan pilihan diatas\n");
		system("pause");
		CariData();
	}
	MainMenu();
}


void tukarsort(struct Data *a, struct Data *b){
	struct Data t = *a;
	*a = *b;
	*b = t;
}


//selection Sort Asc
void SelectionSortAsc(){
	int index = 0;
	for(int i = 0; i<j; i++){
		int DataKecil = i;
		for(int k = i; k<j; k++){
			if(Data[DataKecil].level > Data[k].level){
				DataKecil = k;
			}
			
		}
		tukarsort(&Data[DataKecil], &Data[index]);
		index++;
	}
}

//selection Sort Desc
void SelectionSortDesc(){
	int index = 0;
	for(int i = 0; i<j; i++){
		int DataKecil = i;
		for(int k = i; k<j; k++){
			if(Data[DataKecil].level < Data[k].level){
				DataKecil = k;
			}
			
		}
		tukarsort(&Data[DataKecil], &Data[index]);
		index++;
	}
}

void TampilSort(){
	printf("\t\t\t--- Setelah Disroting ----\n");
	int i = 0;
	while (i<j){
		printf("%d Provinsi\t\t= \t%s\n", i+1, Data[i].provinsi);	
		printf("  Kabupaten\t\t= \t%s\n", Data[i].kota_kab);
		printf("  Total Penduduk\t= \t%.0f\n", Data[i].jumlah.total_penduduk);
		printf("  Jumlah Lansia\t\t= \t%.0f\n", Data[i].jumlah.lansia);
		printf("  Total Tervaksin\t= \t%.0f\n", Data[i].jumlah.total_vaksin);
		printf("  Lansia Vaksin\t\t= \t%.0f\n", Data[i].jumlah.total_lansia_vaksin);
		printf("  Level\t\t\t= \t%lld\n", Data[i].level);
		
		printf("\n");
		i++;
	}
	
}

void TampilSort2(){
	printf("\t\t\t\t\t\t\t\t--- Setelah Disroting ----\n");
	int i = 0;
	printf("\n\n\t======================================================================================================================================================\n");
	printf("\t|| NO\t|");
	printf("|\tProvinsi\t|");
	printf("|\tKab/Kota\t|");
	printf("|   Total Penduduk  |");
	printf("| Jumlah Lansia\t |");
	printf("| Total ter-Vaksin |");
	printf("| Lansia Vaksin |");
	printf("| Level PPKM ||\n");
	printf("\t======================================================================================================================================================\n");
	for(i = 0; i<j; i++){
		printf("\t|| %d\t|", i+1);
		printf("|\t%s\t|", Data[i].provinsi);
		printf("|\t%s \t|", Data[i].kota_kab);
		printf("|    \t%.0f\t     |", Data[i].jumlah.total_penduduk);
		printf("| \t%.0f\t |", Data[i].jumlah.lansia);
		printf("|    \t%.0f\t      |", Data[i].jumlah.total_vaksin);
		printf("|    %.0f\t      |", Data[i].jumlah.total_lansia_vaksin);
		printf("|     %lld      ||", Data[i].level);
		printf("\n");
	}
	printf("\t======================================================================================================================================================\n");
	printf("\n\n");
}

void UrutData(){
	int pilih;
	printf("\t\t\tPilih Metode [1/2]\n");
	printf("\t\t\t1. Asc\n");
	printf("\t\t\t2. Desc\n");
	printf("\t\t\tPilih = ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1: 
			SelectionSortAsc();
			TampilSort2();
			break;
		case 2:
			SelectionSortDesc();
			TampilSort2();
			break;
		default:
			printf("Pilih 2 Metode diatas ! ! !\n");
			system("pause");
//			UrutData();
			break;
	}
	
	system("pause");
	MainMenu();
}

void TutupApk(){
	system("cls");
	system("color 1f");
	printf("\n\n\t\t\t=======Terima Kasih=======");
	printf("\n\t\t\tProgram Ditulis Oleh ");
	printf("\n\t\t\tNama         = Triyono Rifan\n");
	printf("\t\t\tNPM          = 20081010003\n");
	printf("\t\t\tKelas Pemlan = B081\n\n");
	printf("\t\t\tTugas Pertemuan 8 : UTS Ganjil Fix\n\n");
	printf("\t\t\tTekan Enter untuk keluar !!!\n\n\n\n");
	system("pause");
	//18 Oktober 2021
}

int main(){
	fullscreen();
	MainMenu();
	
	return 0;
}
