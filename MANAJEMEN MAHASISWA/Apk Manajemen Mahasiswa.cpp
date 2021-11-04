#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//Aplikasi Manajemen Mahasiswa FINAL
//Nama = Triyono Rifan
//NPM  = 20081010003
//Kelas = PemLan B081

//Menambah Sorting Data (Sorting Nama & NPM => Ascending & Descending)

typedef struct DataFakultas{
	char fakultas[20];
	char prodi[20];
	char ThnAngkatan[31];
}Dfakultas;

struct DataMahasiswa{
	char nama[31];
	long long int npm;
	float ipk;
	char AsalKab[30];
	Dfakultas fakultas;
}Mhs[50];

int j = 0;

//Deklarasi
void MainMenu();
void TampilData();
void TambahData();
void TampilData_Baru();
void UpdateData();
void HapusData();
void TampilDataPencarian();
void MetodeCariData();
void BinarySearch();
int cariIndexData(char nama[31]);
void BubblesortAsc();
void Tutup();
void tukarsort(struct DataMahasiswa *a, struct DataMahasiswa *b);
void tampilAsc();
void TampilBubbleDesc();

//fungsi untuk full screen
void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
  //	return;
}


//Aksi menu Utama
void MainMenu(){
	system("color 3f");
	system("cls");
	printf("\t\t\t\t\t\t\t=============== MENU UTAMA ===============\n");
	printf("\t\t\t\t\t\t\t====== Aplikasi Manajemen Mahasiswa ======\n");
//	TampilData();
	TampilData_Baru();
	printf("\n\t\tPilih Aksi:\n");
	printf("\t\t\t1. Menambah Data");
	printf("\n\t\t\t2. Update/Ubah Data");
	printf("\n\t\t\t3. Hapus Data");
	printf("\n\t\t\t4. Cari Data");
	printf("\n\t\t\t5. Sorting Data");
	printf("\n\t\t\t6. Close Apk");
	int pilih;
	printf("\n\n\t\tSilahkan Pilih = ");
	scanf("%d", &pilih);
	if(pilih == 1){
		TambahData();
	}else if(pilih == 2){
		UpdateData();
	}else if(pilih == 3){
		HapusData();
	}else if(pilih == 4){
		MetodeCariData();
	}else if(pilih == 5){
		tampilAsc();
	}else if(pilih == 6){
		Tutup();
	}else{
		system("cls");
		printf("\t\t\t\t!!! PERHATIAN !!!\n");
		printf("\t\t\tMohon Masukkan Pilihan yang tersedia\n\n");
		system("Pause");
		MainMenu();
	}
}

//untuk Menambah Data Mahasiswa
void TambahData(){
	printf("\n\t\t\t===== Masukkan Data =====\n");
	printf("\t\t\tMasukkan Nama = ");
	scanf(" %[^\n]s", &Mhs[j].nama);
	printf("\t\t\tNPM = ");
	scanf(" %lld", &Mhs[j].npm);
	printf("\t\t\tNilai IPK = ");
	scanf(" %f", &Mhs[j].ipk);
	printf("\t\t\tAsal Kabupaten = ");
	scanf(" %[^\n]s", &Mhs[j].AsalKab);
	printf("\t\t\tFakultas = ");
	scanf(" %[^\n]s", &Mhs[j].fakultas.fakultas);
	printf("\t\t\tProdi = ");
	scanf(" %[^\n]s", &Mhs[j].fakultas.prodi);
	printf("\t\t\tAngkatan = ");
	scanf("%s", &Mhs[j].fakultas.ThnAngkatan);
	
	j++;
	MainMenu();
}

//Tampil Data (untuk menampilkan data yang telah di input/edit/update/hapus/sorting)
void TampilData(){
	int i = 0;
	while (i<j){

		printf("%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
		printf("  NPM       = \t%lld\n", Mhs[i].npm);
		printf("  IPK       = \t%.1f\n", Mhs[i].ipk);
		printf("  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
		printf("  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
		printf("  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
		printf("  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
		
		printf("\n");
		i++;
	}
}

void TampilData_Baru(){
	int i = 0;
	if(j == 0){
		printf("\n\t  !!!! Silahkan Masukkan Data/Tambah data !!!\n");
	}else{
	
		printf("\n\n\t============================================================================================================================================\n");
		printf("\t|No.|");
		printf("|\t     Nama   \t|");
		printf("|\t    NPM     \t|");
		printf("|\tIPK\t|");
		printf("|\t Asal  \t|");
		printf("|\t   Fakultas\t|");
		printf("|\tProdi\t\t|");
		printf("|  Tahun ||\n");
		printf("\t============================================================================================================================================\n");
	}
	
	for(int i = 0; i<j; i++){
		printf("\t| %d |", i+1);
		printf("|\t%s\t|", Mhs[i].nama);
		printf("|\t%lld  \t|", Mhs[i].npm);
		printf("|\t%.1f\t|", Mhs[i].ipk);
		printf("|   %s \t|", Mhs[i].AsalKab);
		printf("|  %s   \t|", Mhs[i].fakultas.fakultas);
		printf("|  %s   \t|", Mhs[i].fakultas.prodi);
		printf("|  %s  ||", Mhs[i].fakultas.ThnAngkatan);
		printf("\n");
	}
	printf("\t============================================================================================================================================\n");
}

//pilihCari Nama
void cariNama(){
	system("cls");
	char inputCari[30];
	printf("\n\n\t\t\tMasukkan Nama Mahasiswa yang akan dicari = ");
	scanf(" %[^\n]s", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	for(i = 0; i<j; i++){
		//Fungsi strcmp() digunakan untuk membandingkan string dengan string yang lainnya.
		if((strcmp(Mhs[i].nama, inputCari) == 0)){
			printf("\t\t\t==== Data Telah Ditemukan =====\n");
			printf("\t\t\t%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
			printf("\t\t\t  NPM       = \t%lld\n", Mhs[i].npm);
			printf("\t\t\t  IPK       = \t%.1f\n", Mhs[i].ipk);
			printf("\t\t\t  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
			printf("\t\t\t  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
			printf("\t\t\t  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
			printf("\t\t\t  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
			
			printf("\n");
			hasilCari++;
		}
		
	}
	if(hasilCari == 1){
		printf("\t\t\tMohon maaf data tidak ditemukan\n\n");
		
	}
	printf("!!!\t\t\tTekan Enter untuk Kembali ke Menu utama\n");
	system("pause");
	MainMenu();
}

//CariIPK
void cariIPK(){
	system("cls");
	float inputCari;
	printf("\n\n\t\t\tMasukkan IPK Mahasiswa yang akan dicari = ");
	scanf(" %f", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	for(i = 0; i<j; i++){
	
		if(inputCari == Mhs[i].ipk && hasilCari == 1){
			printf("\t\t\t==== Data Telah Ditemukan =====\n");
			printf("\t\t\t%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
			printf("\t\t\t  NPM       = \t%lld\n", Mhs[i].npm);
			printf("\t\t\t  IPK       = \t%.1f\n", Mhs[i].ipk);
			printf("\t\t\t  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
			printf("\t\t\t  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
			printf("\t\t\t  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
			printf("\t\t\t  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
			
			printf("\n");
			hasilCari++;
			break;
		}
		
	}
	if(hasilCari == 1){
		printf("\t\t\tMohon maaf data tidak ditemukan\n\n");
		
	}
	printf("\t\t\t!!!Tekan Enter untuk Kembali ke Menu utama\n");
	system("pause");
	MainMenu();
}

//Cari Fakultas /Prodi
void cariFakultas_Prodi(){
	system("cls");
	char inputCari[30];
	printf("\n\n\t\t\tMasukkan Fakultas atau Prodi Mahasiswa yang akan dicari = ");
	scanf(" %[^\n]s", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	for(i = 0; i<j; i++){
		//Fungsi strcmp() digunakan untuk membandingkan string dengan string yang lainnya.
		if((strcmp(Mhs[i].fakultas.fakultas, inputCari) == 0) || (strcmp(Mhs[i].fakultas.prodi, inputCari) == 0)){
			printf("\t\t\t==== Data Telah Ditemukan =====\n");
			printf("\t\t\t%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
			printf("\t\t\t  NPM       = \t%lld\n", Mhs[i].npm);
			printf("\t\t\t  IPK       = \t%.1f\n", Mhs[i].ipk);
			printf("\t\t\t  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
			printf("\t\t\t  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
			printf("\t\t\t  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
			printf("\t\t\t  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
			
			printf("\n");
			hasilCari++;
		}
		
	}
	if(hasilCari == 1){
		printf("\t\t\tMohon maaf data tidak ditemukan\n\n");
		
	}
	printf("\t\t\t!!!Tekan Enter untuk Kembali ke Menu utama\n");
	system("pause");
	MainMenu();
}

//CariAngkatan
void cariAngkatan(){
	system("cls");
	char inputCari[30];
	printf("\n\n\t\t\tMasukkan Tahun Angkatan Mahasiswa yang akan dicari = ");
	scanf(" %[^\n]s", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	for(i = 0; i<j; i++){
		//Fungsi strcmp() digunakan untuk membandingkan string dengan string yang lainnya.
		if((strcmp(Mhs[i].fakultas.ThnAngkatan, inputCari) == 0)){
			printf("\t\t\t==== Data Telah Ditemukan =====\n");
			printf("\t\t\t%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
			printf("\t\t\t  NPM       = \t%lld\n", Mhs[i].npm);
			printf("\t\t\t  IPK       = \t%.1f\n", Mhs[i].ipk);
			printf("\t\t\t  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
			printf("\t\t\t  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
			printf("\t\t\t  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
			printf("\t\t\t  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
			
			printf("\n");
			hasilCari++;
		}
		
	}
	if(hasilCari == 1){
		printf("\t\t\tMohon maaf data tidak ditemukan\n\n");
		
	}
	printf("\t\t\t!!!Tekan Enter untuk Kembali ke Menu utama\n");
	system("pause");
	MainMenu();
}

//pilih Metode Pencarian
void MetodeCariData(){
	int pilih;
	system("cls");
	system("color 5f");
	printf("\n\n\t\t\t==== Pilih Metode Pencarian dibawah ini ====\n");
	printf("\t\t\t[1] Sequential Search\n");
	printf("\t\t\t[2] Binary Search\n\n");
	printf("\t\t\tPilih = ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1:
			TampilDataPencarian();
			break;
		case 2:
			printf("\t\t\t!!!! Metode Binary Search akan mengurutkan data terlebih dahulu\n\n");
			BinarySearch();
			break;
		default :
			printf("\t\t\tMasukkan Pilihan dengan benar ! [1] atau [2]\n");
			system("pause");
			MetodeCariData();
			break;
	}
}

//Tampil Fitur Kategori Cari Data
void TampilDataPencarian(){
	system("color 5f");
	system("cls");
	int pilihCari;
	printf("\n\n\t\t\t==== Pilih kategori pencariannya ====\n");
	printf("\t\t\t1. Nama\n");
	printf("\t\t\t2. IPK\n");
	printf("\t\t\t3. Fakultas atau prodi\n");
	printf("\t\t\t4. Tahun Angkatan\n");
	printf("\n\t\t\tPilih Kategori = ");
	scanf("%d", &pilihCari);
	
	switch(pilihCari){
		case 1 :
			cariNama();
			break;
		case 2 :
			cariIPK();
			break;
		case 3 :
			cariFakultas_Prodi();
			break;
		case 4 :
			cariAngkatan();
			break;
		default:
			printf("\t\t\tSilahkan Masukkan sesuai nomor !!!\n\n");
			printf("\t\t\tTekan enter untuk masukkan ulang");
			system("pause");
			TampilDataPencarian();
			break;
	}
}


//Input untuk Update Data
void InputUpdate(int index){
	printf("\n\t\t\t=====Masukkan Data=====\n");
	printf("\t\t\tMasukkan Nama = ");
	scanf(" %[^\n]s", &Mhs[index].nama);
	printf("\t\t\tNPM = ");
	scanf(" %lld", &Mhs[index].npm);
	printf("\t\t\tNilai IPK = ");
	scanf(" %f", &Mhs[index].ipk);
	printf("\t\t\tAsal Kabupaten = ");
	scanf(" %[^\n]s", &Mhs[index].AsalKab);
	printf("\t\t\tFakultas = ");
	scanf(" %[^\n]s", &Mhs[index].fakultas.fakultas);
	printf("\t\t\tProdi = ");
	scanf(" %[^\n]s", &Mhs[index].fakultas.prodi);
	printf("\t\t\tAngkatan = ");
	scanf("%s", &Mhs[index].fakultas.ThnAngkatan);
	
	MainMenu();
}

//Update Data
void UpdateData(){
	char nama[31];
	printf("\t\t\tMasukkan Nama yang datanya akan diubah = ");
	scanf(" %[^\n]s", &nama);
	
	int hasil = cariIndexData(nama);
	if(hasil >= 0){
		//akan mengakses void InputUpdate dengan parameter hasil
		InputUpdate(hasil);
	
	}else{
		printf("\t\t\tMaaf Data Tidak Ditemukan !!\n\n");
		printf("\t\t\ttekan enter untuk kembali ke Menu Utama\n");
		system("pause");
		MainMenu();
	}
}

//untuk Hapus Data
void Delete (int index){
	int i, posisi = 0;
	for(i = 0; i < j; i++){
		if(i != index){
			Mhs[posisi] = Mhs[i];
			posisi ++;
		}
	}
	j--;
	MainMenu();
}

//Hapus Data
void HapusData(){
	char nama[31];
	printf("\t\t\tMasukkan Nama yang datanya akan dihapus = ");
	scanf(" %[^\n]s", &nama);
	
	int hasil = cariIndexData(nama);
	if(hasil >= 0){
		//akan mengakses void InputUpdate dengan parameter hasil
		Delete(hasil);
	
	}else{
		printf("\t\t\tMaaf Data Tidak Ditemukan !!\n\n");
		printf("\t\t\ttekan enter untuk kembali ke Menu Utama\n");
		system("pause");
		MainMenu();
	}
	system("pause");
	MainMenu();
}

//mencari Index suatu data
int cariIndexData(char nama[31]){
	int i = 0;
	int index = -1;
	while (i<j && index<0){
		if(strcmp(Mhs[i].nama, nama) == 0){
			index = i;
		}
		
		i++;
	}
	return index;
}

//Proses sorting
void tukarsort(struct DataMahasiswa *a, struct DataMahasiswa *b){
	struct DataMahasiswa t = *a;
	*a = *b;
	*b = t;
}

//sorting NPM ascending
void BubblesortNpmAsc(){
		for(int i = 0; i<j-1; i++){
			for(int k = 0; k< j-i-1; k++){
				if(Mhs[k].npm > Mhs[k+1].npm){
					tukarsort(&Mhs[k], &Mhs[k+1]);
				}
			}
		}
}

//sorting NPM Descending
void BubblesortNpmDesc(){
	for(int i = 0; i<j-1; i++){
			for(int k = 0; k < j-i-1; k++){
				if(Mhs[k].npm < Mhs[k+1].npm){
					tukarsort(&Mhs[k], &Mhs[k+1]);
				}
			}
		}
}


//Sorting Nama Ascending
void BubbleSortNamaAsc(){

	for(int i = 0; i<j; i++){
		int k=i;
		for(int x = i+1; x<j; x++){
			int xy = strcmp(Mhs[k].nama, Mhs[x].nama);
			if(xy > 0){
				k = x;
			}
		}
		if(k != i){
			tukarsort(&Mhs[k], &Mhs[i]);
		}
	}
	
}

//sorting Nama Descending
void BubbleSortNamaDesc(){
	for(int i = 0; i<j; i++){
		int k=i;
		for(int x = i+1; x<j; x++){
			int xy = strcmp(Mhs[k].nama, Mhs[x].nama);
			if(xy <= 0){
				k = x;
			}
		}
		if(k != i){
			tukarsort(&Mhs[k], &Mhs[i]);
		}
	}
}

//selection Sort
void SelectionSort(){
	int index = 0;
	for(int i = 0; i<j; i++){
		int MhsKecil = i;
		for(int k = i; k<j; k++){
			if(Mhs[MhsKecil].npm > Mhs[k].npm){
				MhsKecil = k;
			}
			
		}
		tukarsort(&Mhs[MhsKecil], &Mhs[index]);
		index++;
	}
}

//Insertion Sort
void InsertionSort(){
	//looping banyak data
	for(int i = 0; i<j; i++){
		//looping selama angka ke-k (k sudah di set sebagai i di awal)
		//lebih kecil dari k-1
		for(int k = i; k>0 && Mhs[k].npm < Mhs[k-1].npm; k--){
			//melakukan tukar sort
			tukarsort(&Mhs[k], &Mhs[k-1]);
		}
	}
}

// Menampilkan Hasil Hasil Sorting
void hasilSorting(){
	printf("\t\t\t--- Setelah Disroting ----\n");
	for(int i = 0; i<j; i++){
				
		printf("\t\t\t%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
		printf("\t\t\t  NPM       = \t%lld\n", Mhs[i].npm);
		printf("\t\t\t  IPK       = \t%.1f\n", Mhs[i].ipk);
		printf("\t\t\t  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
		printf("\t\t\t  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
		printf("\t\t\t  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
		printf("\t\t\t  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
				
		printf("\n");
	}
}

//Fitur pilihan Sorting
void tampilAsc(){
	system("color 8F");
	system("cls");
	int pilih;
	printf("\n\n\t\t\t===Piih sorting===\n");
	printf("\t\t\t1. Bubble Sort Ascending NPM (terkecil >> terbesar)\n");
	printf("\t\t\t2. Bubble Sort Descending NPM (terbesar >> terkecil)\n");
	printf("\t\t\t3. Bubble Sort Ascending Nama (Aa >> Zz)\n");
	printf("\t\t\t4. Bubble Sort Descending Nama (Zz >> Aa)\n");
	printf("\t\t\t5. Selection Sort NPM\n");
	printf("\t\t\t6. Insertion Sort NPM\n\n");
	printf("\t\t\tMasukkan Pilihan = ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1:
			BubblesortNpmAsc();
			hasilSorting();
			break;
		case 2:
			BubblesortNpmDesc();
			hasilSorting();
			break;
		case 3:
			BubbleSortNamaAsc();
			hasilSorting();
			break;
		case 4:
			BubbleSortNamaDesc();
			hasilSorting();
			break;
		case 5:
			SelectionSort();
			hasilSorting();
			break;
		case 6:
			InsertionSort();
			hasilSorting();
			break;
		default:
			printf("\t\t\tPilihan Tidak Tersedia!!\n");
			system("Pause");
			break;
	}
	
	system("Pause");
	MainMenu();
}


//Metode Binary Search
void BinarySearch(){
	long long int cari;
	int awal = 0, akhir = j-1, tengah, ketemu = 0;
	
	printf("\t\t\tMasukkan NPM yang akan dicari = ");
	scanf(" %lld", &cari);
	
	InsertionSort();
	
	while(awal <= akhir && ketemu == 0){
		tengah = (awal + akhir)/2;
		
		if(Mhs[tengah].npm == cari){
			ketemu = 1;
			break;
		}
		else if(Mhs[tengah].npm < cari){
			awal = tengah + 1;
		}else{
			akhir = tengah - 1;
		}
	}
	
	if(ketemu == 1){
		printf("\t\t\t==== Data Ditemukan =====\n");
		printf("\t\t\t%d Nama      = \t%s\n", tengah+1, Mhs[tengah].nama);	
		printf("\t\t\t  NPM       = \t%lld\n", Mhs[tengah].npm);
		printf("\t\t\t  IPK       = \t%.1f\n", Mhs[tengah].ipk);
		printf("\t\t\t  Asal Kab. = \t%s\n", Mhs[tengah].AsalKab);
		printf("\t\t\t  Fakultas  = \t%s\n", Mhs[tengah].fakultas.fakultas);
		printf("\t\t\t  Prodi     = \t%s\n", Mhs[tengah].fakultas.prodi);
		printf("\t\t\t  Angkatan  = \t%s\n", Mhs[tengah].fakultas.ThnAngkatan);
		
		printf("\n");
		system("pause");
	}
	else{
		printf("\t\t\t=== Mohon Maaf Data Tidak Ditemukan ===\n\n");
		system("pause");
	}
	
	MainMenu();
}

//Tutup APK
void Tutup(){
	system("cls");
	system("color 1f");
	printf("\n\n\t\t\t=======Terima Kasih=======");
	printf("\n\t\t\tProgram Ditulis Oleh ");
	printf("\n\t\t\tNama         = Triyono Rifan\n");
	printf("\t\t\tNPM          = 20081010003\n");
	printf("\t\t\tKelas Pemlan = B081\n\n");
	printf("\t\t\tTugas Pertemuan 7 : Menambah searching (Sequential & Binary Search)\n\n");
	printf("\t\t\tTekan Enter untuk keluar !!!\n\n\n\n");
	system("pause");
	//18 Oktober 2021
}

//fungsi Utama (main)
int main(){
	fullscreen();
	MainMenu();
	return 0;
}
