#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
//Kelompok 8 Perograman Lanjut B081
//Nama Anggota:

//1. TRIYONO RIFAN 					(20081010003)
//2. SALMA FATHIYATUR RIZKY MUNIR 	(20081010025)
//3. AHMAD HILMAN DANI 				(20081010057)
//4. IBET MAULANA 					(20081010067)
//5. HAFID ALFA ANAMSYAH 			(20081010189)
//6. CHANDRA IKA NUGROHO 			(20081010212)

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
void exit();


int jumlah_kos = 0;


void exit(){
	system("Color 9f");
	system("cls");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================     Terima kasih telah menggunakan aplikasi Kos sederhana      ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	puts("\n\n\t\t\t\tDibuat oleh Kelompok Final projek Pemrograman Lanjut B081");
	puts("\n\t\t\t\tFakultas Ilmu Komputer");
	puts("\n\t\t\t\tProgram Studi Informatika");
	puts("\n\t\t\t\tTerima kasih telah menggunakan Aplikasi ini\n\n\n");
}

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
  //	return;
}

void mainMenu(){
	int pilih; //deklarasi variabel pilih
	system("Color 3f");
	system("cls");
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================            Selamat datang di aplikasi Kos sederhana            ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	puts("\t\t\t =================================");
	puts("\t\t\t|| Siapa Anda? [Pemilik/Penyewa] ||");
	puts("\t\t\t =================================\n");
	puts("\t\t\t\t[1] Pemilik Kos\n");
	puts("\t\t\t\t[2] Penyewa Kos\n");
	puts("\t\t\t\t[3] Close Aplikasi\n");
	printf("\n\t\t\t\t\tMasukkan pilihan : "); scanf("%d", &pilih);
	switch(pilih){
		case 1:
			Pemilik_Kos();
			break;
		case 2:
			Penyewa_Kos();
			break;
		case 3:
			exit();
			break;
		default:
			puts("\n\n\t\t\t\t!!!! WARNING !!!!");
			printf("\n\t\t\t\tsilahkan masukkan pilihan dengan benar !!");
			system("Pause");
			mainMenu();
			break;
	}
}


void Pemilik_Kos(){
	system("cls");
	int pilih; //inisialisasi variabel pilih
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================             Laman ''Pemilik KOS'' di UMMIK KOS                 ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	puts("\t\t\t ===============================");
	puts("\t\t\t ||  Pilih Menu Pemilik Kos   ||");
	puts("\t\t\t ===============================\n");
	puts("\t\t\t\t[1] Input kamar\n");
	puts("\t\t\t\t[2] Update kamar\n");
	puts("\t\t\t\t[3] Lihat daftar kamar\n");
	puts("\t\t\t\t[4] Menu utama\n");
	puts("\t\t\t\t[5] Close\n\n");
	printf("\n\t\t\t\t\tMasukkan Pilihan : "); scanf("%d", &pilih);
	switch(pilih){
		case 1:
			input_kos();
			break;
		case 2:
			update_kos();
			break;
		case 3:
			lihat_kos();
			break;
		case 4:
			mainMenu();
			break;
		case 5:
			exit();
			break;
		default:
			puts("\t\t\t\t!!!! WARNING !!!!");
			printf("\n\t\t\t\tsilahkan masukkan pilihan dengan benar !!");
			system("Pause");
			Pemilik_Kos();
	}
}


void Penyewa_Kos(){
	system("cls");
	int pilih;
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================            Laman ''Penyewa'' KOS di UMMIK KOS                  ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	puts("\t\t\t ===============================");
	puts("\t\t\t ||  Pilih Menu Penyewa Kos   ||");
	puts("\t\t\t ===============================\n");
	puts("\n\n\t\t\t Mohon maaf!! Menu dalam Pengembangan !!\n\n\n\n");
//	printf("\t\t\t\t[1] Cari kamar\n");
//	printf("\n\t\t\t\t[2] lihat daftar kamar\n");
//	printf("\n\t\t\t\t[3] close\n");
//	printf("\n\n\t\t\t\tMasukkan Pilihan : ");
	system("Pause");
	mainMenu();
}

void input_kos(){
	FILE *fptr;
	fptr = fopen("Ummik_Kos.txt","a"); //menghasilkan pointer
	
	printf("\n\n\t\t\t\t\t===== Masukkan inputan dibawah ini =====\n");
	printf("\n\t\t\t\t\tMasukkan tipe rumah (LK/P) = ");
	scanf("%s", &Kos.tipe);
	printf("\n\t\t\t\t\tMasukkan alamat:");
	printf("\n\t\t\t\t\t\tProvinsi = ");
	scanf(" %[^\n]s", &Kos.lokasi.provinsi);
	printf("\t\t\t\t\t\tKabupaten = ");
	scanf(" %[^\n]s", &Kos.lokasi.Kabupaten);
	printf("\t\t\t\t\t\tJalan = ");
	scanf(" %[^\n]s", &Kos.lokasi.jalan);
	printf("\n\t\t\t\t\tHarga = ");
	scanf("%lld", &Kos.harga);
	printf("\n\t\t\t\t\tFasilitas = ");
	scanf(" %[^\n]s", &Kos.fasilitas);
	
	fprintf(fptr,"%s %s %s %s %lld %s \n", Kos.tipe, Kos.lokasi.provinsi, Kos.lokasi.Kabupaten, Kos.lokasi.jalan, Kos.harga, Kos.fasilitas);
	fclose(fptr);
	
	puts("\t\t\t ===============================");
	puts("\t\t\t ||    Data telah tersimpan   ||");
	puts("\t\t\t ===============================\n");
	system("pause");
	Pemilik_Kos();
}


void lihat_kos(){
	system("cls");
	printf("........................................................................................................................................................................\n");
	printf("========================================================================================================================================================================\n");
	printf("================================================                          UMMIK.KOS                             ========================================================\n");
	printf("================================================                 Lihat Daftar KOS di UMMIK KOS                  ========================================================\n");
	printf("========================================================================================================================================================================\n");
	printf("........................................................................................................................................................................\n\n");
	int pilih;
	FILE *view;
	
	view = fopen("Ummik_Kos.txt","r");
	
	if(view==NULL){
		puts("\t\t\t ===============================");
		puts("\t\t\t ||     Belum ada data KOS    ||");
		puts("\t\t\t ===============================\n");
	}
	else{
		while(fscanf(view, " %s %s %s %s %lld %s", &Kos.tipe, &Kos.lokasi.provinsi, &Kos.lokasi.Kabupaten, &Kos.lokasi.jalan, &Kos.harga, &Kos.fasilitas)!=EOF){
	        printf("%s %s %s %s %lld %s \n", Kos.tipe, Kos.lokasi.provinsi, Kos.lokasi.Kabupaten, Kos.lokasi.jalan, Kos.harga, Kos.fasilitas);
	        jumlah_kos++;
   		}
	}
	printf("\t\t\t\tjumlah banyak kos %d\n", jumlah_kos);
	fclose(view);
	
	ulang_disini:
	printf("\n\t\t\t\t[1]Menu Utama\n\n\t\t\t\t[2]Laman Pemilik Kos\n\n\t\t\t\t[3]Keluar\n\n\t\t\t\t\t\tPilih salah satu  : ");
	switch(getch()){
		case '1':
			mainMenu();
		break;
		case '2':
			Pemilik_Kos();
		break;
		case '3':
			exit();
		break;
		default:
			printf("\ntolong inputkan angka antara [1]/[2]/[3]\n");
			system("pause");
			goto ulang_disini;
	}
}


void update_kos(){
	system("cls");
	printf("\n\n\n\n\t\t\t\t\tUpdate Kos dalam progress yaa ...\n\n\n\n\n");
	system("Pause");
	Pemilik_Kos();
}


int main(){
	fullscreen();
	mainMenu();
	return 0;
}
