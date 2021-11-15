#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct buku{
	long long int kode;
	char pengarang[25];
	char judul[25];
	int convert_string;
}buku[10];
//typedef struct buku Perpus_buku[10];


int j = 0;
int l = 0;

//deklarasi
void MainMenu();
void daftarBuku();
void tampil_buku();
void input_buku();
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

	if(l == 0){
		input_buku();
		tampil_buku();
	}else{
		tampil_buku();
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
	}
	else if(pilih == 2){
		CariJudul();
	}
	else if(pilih == 3){
		close();
	}
}
	
void daftarBuku(long long int kode, const char judul[25], const char pengarang[25]){
	buku[j].kode = kode;
	strcpy(buku[j].judul, judul);
	strcpy(buku[j].pengarang, pengarang);
	j++;
}
	
void input_buku(){
	daftarBuku(3031, "C Programing", "James Lee");
	daftarBuku(101, "Wordpress Expert", "Andrew Octa");
	daftarBuku(8812, "Web From Zero to Zero", "David Guetta");
	daftarBuku(790, "Laravel", "Hans Jackson");
	daftarBuku(66, "Master Flutter", "Ozur Haskels");
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

//Urut berdasarkan Kode
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

//Cari berdasarka Kode
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

//Urut Berdasarkan Nama
void SortNamaBubble(){
	for(int i = 0; i<j; i++){
		int k=i;
		for(int x=i+1; x<j; x++){
			int xy = strcmp(buku[k].judul, buku[x].judul);
			if(xy > 0){
				k = x;
			}
		}
		if(k != i){
			tukar(&buku[k], &buku[i]);
		}
	}
}

//Cari berdasarkan Nama
void interpolationSearch(){
	printf("Mohon maaf belum paham dengan interpolation search pada string");
//	int i,c,d,j;
//	int a = sizeof(buku)/sizeof(buku[0]);
//	int length[a];
//	
//	 for ( i = 0; i < a; i++){
//        length[i] = strlen(buku[i].judul);
//        
//        for ( j = 0; j < length[i]; j++){
//            buku[i].convert_string += buku[i].judul[j];
//        }
//        printf("%d. %d\n",i+1, buku[i].convert_string);
//    }
//	
//	char string_cari[50];
//    int convert_string = 0;
//    printf("Masukkan Judul Buku yang ingin dicari : ");
//    fflush(stdin); gets(string_cari);
//    
//    int  panjang = strlen(string_cari);
//    for ( i = 0; i < panjang; i++){
//       	convert_string += string_cari[i];
//    }
//    
//    for ( c = 0; c < 10; c++){
//        int temp;
//        temp = buku[c].convert_string;
//        d = c-1;
//            while (d>=0 && buku[d].convert_string > temp){
//                buku[d+1].convert_string = buku[d].convert_string;
//                d = d-1;
//            }
//        buku[d+1].convert_string = temp;
//    }
//	
//	
//    int low = 0;
//    int high = a - 1;
//    int position;
//
//    while (low <= high){
//
//        position = low+(((convert_string-buku[low].convert_string)/(buku[high].convert_string-buku[low].convert_string))*(high-low));
//
//        if(buku[position].convert_string == convert_string){
//          	printf("\n======= Data Ditemukan =========\n");
//			printf("%d  Kode Buku\t = %lld\n", i+1, buku[i].kode);
//			printf("   Judul buku\t = %s\n", buku[i].judul);
//			printf("   Pengarang\t = %s\n\n", buku[i].pengarang);
//            break;
//        }else if(buku[position].convert_string > convert_string){
//            high = position - 1;
//        }else{
//            low = position + 1;
//        }
//    }
//    
}
//cari Judul buku
void CariJudul(){

	SortNamaBubble();
	l++;
	
	interpolationSearch();
	
	system("pause");
	MainMenu();
}

//Tutup apk
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
