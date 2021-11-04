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
	char ipk[10];
	char AsalKab[30];
	Dfakultas fakultas;
}Mhs[50];

int j = 0;

//Deklarasi
void MainMenu();
void TampilData();
void TambahData();
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

//Aksi menu Utama
void MainMenu(){
	system("color 3f");
	system("cls");
	printf("=============== MENU UTAMA ===============\n");
	printf("====== Aplikasi Manajemen Mahasiswa ======\n");
	TampilData();
	printf("\nPilih Aksi:\n");
	printf("\t1. Menambah Data");
	printf("\n\t2. Update/Ubah Data");
	printf("\n\t3. Hapus Data");
	printf("\n\t4. Cari Data");
	printf("\n\t5. Sorting Data");
	printf("\n\t6. Close Apk");
	int pilih;
	printf("\n\nSilahkan Pilih = ");
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
		printf("\t!!! PERHATIAN !!!\n");
		printf("Mohon Masukkan Pilihan yang tersedia\n\n");
		system("Pause");
		MainMenu();
	}
}

//untuk Menambah Data Mahasiswa
void TambahData(){
	printf("\n===== Masukkan Data =====\n");
	printf("Masukkan Nama = ");
	scanf(" %[^\n]s", &Mhs[j].nama);
	printf("NPM = ");
	scanf(" %lld", &Mhs[j].npm);
	printf("Nilai IPK = ");
	scanf("%s", &Mhs[j].ipk);
	printf("Asal Kabupaten = ");
	scanf(" %[^\n]s", &Mhs[j].AsalKab);
	printf("Fakultas = ");
	scanf(" %[^\n]s", &Mhs[j].fakultas.fakultas);
	printf("Prodi = ");
	scanf(" %[^\n]s", &Mhs[j].fakultas.prodi);
	printf("Angkatan = ");
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
		printf("  IPK       = \t%s\n", Mhs[i].ipk);
		printf("  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
		printf("  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
		printf("  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
		printf("  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
		
		printf("\n");
		i++;
	}
	
}

//pilihCari Nama
void cariNama(){
	system("cls");
	char inputCari[30];
	printf("Masukkan Nama Mahasiswa yang akan dicari = ");
	scanf(" %[^\n]s", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	for(i = 0; i<j; i++){
		//Fungsi strcmp() digunakan untuk membandingkan string dengan string yang lainnya.
		if((strcmp(Mhs[i].nama, inputCari) == 0)){
			printf("==== Data Telah Ditemukan =====\n");
			printf("%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
			printf("  NPM       = \t%lld\n", Mhs[i].npm);
			printf("  IPK       = \t%s\n", Mhs[i].ipk);
			printf("  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
			printf("  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
			printf("  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
			printf("  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
			
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

//CariIPK
void cariIPK(){
	system("cls");
	char inputCari[30];
	printf("Masukkan IPK Mahasiswa yang akan dicari = ");
	scanf(" %[^\n]s", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	for(i = 0; i<j; i++){
		//Fungsi strcmp() digunakan untuk membandingkan string dengan string yang lainnya.
		if((strcmp(Mhs[i].ipk, inputCari) == 0)){
			printf("==== Data Telah Ditemukan =====\n");
			printf("%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
			printf("  NPM       = \t%lld\n", Mhs[i].npm);
			printf("  IPK       = \t%s\n", Mhs[i].ipk);
			printf("  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
			printf("  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
			printf("  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
			printf("  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
			
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

//Cari Fakultas /Prodi
void cariFakultas_Prodi(){
	system("cls");
	char inputCari[30];
	printf("Masukkan Fakultas atau Prodi Mahasiswa yang akan dicari = ");
	scanf(" %[^\n]s", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	for(i = 0; i<j; i++){
		//Fungsi strcmp() digunakan untuk membandingkan string dengan string yang lainnya.
		if((strcmp(Mhs[i].fakultas.fakultas, inputCari) == 0) || (strcmp(Mhs[i].fakultas.prodi, inputCari) == 0)){
			printf("==== Data Telah Ditemukan =====\n");
			printf("%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
			printf("  NPM       = \t%lld\n", Mhs[i].npm);
			printf("  IPK       = \t%s\n", Mhs[i].ipk);
			printf("  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
			printf("  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
			printf("  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
			printf("  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
			
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

//CariAngkatan
void cariAngkatan(){
	system("cls");
	char inputCari[30];
	printf("Masukkan Tahun Angkatan Mahasiswa yang akan dicari = ");
	scanf(" %[^\n]s", &inputCari);
	
	int i = 0;
	int hasilCari = 1;
	for(i = 0; i<j; i++){
		//Fungsi strcmp() digunakan untuk membandingkan string dengan string yang lainnya.
		if((strcmp(Mhs[i].fakultas.ThnAngkatan, inputCari) == 0)){
			printf("==== Data Telah Ditemukan =====\n");
			printf("%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
			printf("  NPM       = \t%lld\n", Mhs[i].npm);
			printf("  IPK       = \t%s\n", Mhs[i].ipk);
			printf("  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
			printf("  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
			printf("  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
			printf("  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
			
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

//pilih Metode Pencarian
void MetodeCariData(){
	int pilih;
	system("cls");
	system("color 5f");
	printf("==== Pilih Metode Pencarian dibawah ini ====\n");
	printf("[1] Sequential Search\n");
	printf("[2] Binary Search\n\n");
	printf("Pilih = ");
	scanf("%d", &pilih);
	switch(pilih){
		case 1:
			TampilDataPencarian();
			break;
		case 2:
			printf("!!!! Metode Binary Search akan mengurutkan data terlebih dahulu\n\n");
			BinarySearch();
			break;
		default :
			printf("Masukkan Pilihan dengan benar ! [1] atau [2]\n");
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
	printf("==== Pilih kategori pencariannya ====\n");
	printf("1. Nama\n");
	printf("2. IPK\n");
	printf("3. Fakultas atau prodi\n");
	printf("4. Tahun Angkatan\n");
	printf("\nPilih Kategori = ");
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
			printf("Silahkan Masukkan sesuai nomor !!!\n\n");
			printf("Tekan enter untuk masukkan ulang");
			system("pause");
			TampilDataPencarian();
	}
}


//Input untuk Update Data
void InputUpdate(int index){
	printf("\n=====Masukkan Data=====\n");
	printf("Masukkan Nama = ");
	scanf(" %[^\n]s", &Mhs[index].nama);
	printf("NPM = ");
	scanf(" %lld", &Mhs[index].npm);
	printf("Nilai IPK = ");
	scanf("%s", &Mhs[index].ipk);
	printf("Asal Kabupaten = ");
	scanf(" %[^\n]s", &Mhs[index].AsalKab);
	printf("Fakultas = ");
	scanf(" %[^\n]s", &Mhs[index].fakultas.fakultas);
	printf("Prodi = ");
	scanf(" %[^\n]s", &Mhs[index].fakultas.prodi);
	printf("Angkatan = ");
	scanf("%s", &Mhs[index].fakultas.ThnAngkatan);
	
	MainMenu();
}

//Update Data
void UpdateData(){
	char nama[31];
	printf("Masukkan Nama yang datanya akan diubah = ");
	scanf(" %[^\n]s", &nama);
	
	int hasil = cariIndexData(nama);
	if(hasil >= 0){
		//akan mengakses void InputUpdate dengan parameter hasil
		InputUpdate(hasil);
	
	}else{
		printf("Maaf Data Tidak Ditemukan !!\n\n");
		printf("tekan enter untuk kembali ke Menu Utama\n");
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
	printf("Masukkan Nama yang datanya akan dihapus = ");
	scanf(" %[^\n]s", &nama);
	
	int hasil = cariIndexData(nama);
	if(hasil >= 0){
		//akan mengakses void InputUpdate dengan parameter hasil
		Delete(hasil);
	
	}else{
		printf("Maaf Data Tidak Ditemukan !!\n\n");
		printf("tekan enter untuk kembali ke Menu Utama\n");
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
	printf("--- Setelah Disroting ----\n");
	for(int i = 0; i<j; i++){
				
				printf("%d Nama      = \t%s\n", i+1, Mhs[i].nama);	
				printf("  NPM       = \t%lld\n", Mhs[i].npm);
				printf("  IPK       = \t%s\n", Mhs[i].ipk);
				printf("  Asal Kab. = \t%s\n", Mhs[i].AsalKab);
				printf("  Fakultas  = \t%s\n", Mhs[i].fakultas.fakultas);
				printf("  Prodi     = \t%s\n", Mhs[i].fakultas.prodi);
				printf("  Angkatan  = \t%s\n", Mhs[i].fakultas.ThnAngkatan);
				
				printf("\n");
			}
}

//Fitur pilihan Sorting
void tampilAsc(){
	system("color 8F");
	system("cls");
	int pilih;
	printf("\n===Piih sorting===\n");
	printf("1. Bubble Sort Ascending NPM (terkecil >> terbesar)\n");
	printf("2. Bubble Sort Descending NPM (terbesar >> terkecil)\n");
	printf("3. Bubble Sort Ascending Nama (Aa >> Zz)\n");
	printf("4. Bubble Sort Descending Nama (Zz >> Aa)\n");
	printf("5. Selection Sort NPM\n");
	printf("6. Insertion Sort NPM\n\n");
	printf("Masukkan Pilihan = ");
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
			printf("Pilihan Tidak Tersedia!!\n");
			system("Pause");
			break;
	}
	
	system("Pause");
	MainMenu();
}



//Metode Binary Search

void BinarySearch(){
	long long int cari;
	int awal = 0, akhir = j-1, ketemu = 0, tengah;
	
	printf("Masukkan NPM yang akan dicari = ");
	scanf(" %lld", &cari);
	
	//melakukan pengurutan data terlebih dahulu
	InsertionSort();
	
	while(awal<=akhir && ketemu == 0){
		tengah = (awal + akhir)/2;
		
		if (Mhs[tengah].npm == cari){
			ketemu = 1;
			break;
		}
		else if(Mhs[tengah].npm < cari){
			awal = tengah + 1;
		} else{
			akhir = tengah - 1;
		}
	}
	
	if(ketemu == 1){
		printf("==== Data Ditemukan =====\n");
		printf("%d Nama      = \t%s\n", tengah+1, Mhs[tengah].nama);	
		printf("  NPM       = \t%lld\n", Mhs[tengah].npm);
		printf("  IPK       = \t%s\n", Mhs[tengah].ipk);
		printf("  Asal Kab. = \t%s\n", Mhs[tengah].AsalKab);
		printf("  Fakultas  = \t%s\n", Mhs[tengah].fakultas.fakultas);
		printf("  Prodi     = \t%s\n", Mhs[tengah].fakultas.prodi);
		printf("  Angkatan  = \t%s\n", Mhs[tengah].fakultas.ThnAngkatan);
		
		printf("\n");
		system("pause");
	} else{
		printf("==== Mohon maaf data tidak ada ====\n\n");
		system("pause");
	}
	
	MainMenu();
}


//Tutup APK
void Tutup(){
	system("cls");
	system("color 1f");
	printf("=======Terima Kasih=======");
	printf("\nProgram Ditulis Oleh ");
	printf("\nNama         = Triyono Rifan\n");
	printf("NPM          = 20081010003\n");
	printf("Kelas Pemlan = B081\n\n");
	printf("Tugas Pertemuan 7 : Menambah searching (Sequential & Binary Search)\n\n");
	printf("Tekan Enter untuk keluar !!!\n");
	system("pause");
	//17 Oktober 2021
}

//fungsi Utama (main)
int main(){
	
	MainMenu();
	return 0;
}
