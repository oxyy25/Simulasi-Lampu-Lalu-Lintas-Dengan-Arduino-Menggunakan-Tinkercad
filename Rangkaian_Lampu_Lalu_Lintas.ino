// mendefinisikan LED dari semua bagian dan Waktu
#define HIJAU_Utara   13
#define KUNING_Utara  12
#define MERAH_Utara   11

#define HIJAU_Timur   4
#define KUNING_Timur  3
#define MERAH_Timur   2

#define HIJAU_Selatan   7
#define KUNING_Selatan  6
#define MERAH_Selatan   5

#define HIJAU_Barat   10
#define KUNING_Barat  9
#define MERAH_Barat   8

#define WAKTU_HIJAU        5000
#define WAKTU_KEDIP        300
#define JUMLAH_KEDIP       3

//fungsi untuk mematikan LED
void matikanSimpang(int pinHijau, int pinKuning, int pinMerah) {
  digitalWrite(pinHijau,  LOW);
  digitalWrite(pinKuning, LOW);
  digitalWrite(pinMerah,  LOW);
}

// fungsi untuk menyalakan LED merah
void merahSimpang(int pinHijau, int pinKuning, int pinMerah) {
  digitalWrite(pinHijau,  LOW);
  digitalWrite(pinKuning, LOW);
  digitalWrite(pinMerah,  HIGH);
}

// Fungsi untuk menyeting kedip pada LED kuning
void kedipKuning(int pinKuning, int jumlah) {
  for (int i = 0; i < jumlah; i++) {
    digitalWrite(pinKuning, HIGH);
    delay(WAKTU_KEDIP);
    digitalWrite(pinKuning, LOW);
    delay(WAKTU_KEDIP);
  }
}

// Fungsi untuk menyalakan LED Hijau
void aktifkanSimpang(int pinHijau, int pinKuning, int pinMerah) {
  
  digitalWrite(pinMerah,  LOW);
  digitalWrite(pinKuning, LOW);
  digitalWrite(pinHijau,  HIGH);
  delay(WAKTU_HIJAU);

  
  digitalWrite(pinHijau, LOW);
  kedipKuning(pinKuning, JUMLAH_KEDIP);

  digitalWrite(pinKuning, LOW);
  digitalWrite(pinMerah,  HIGH);
}

void setup()
{
  pinMode(HIJAU_Utara,OUTPUT);
  pinMode(KUNING_Utara,OUTPUT);
  pinMode(MERAH_Utara,OUTPUT);

  pinMode(HIJAU_Timur,OUTPUT);
  pinMode(KUNING_Timur,OUTPUT);
  pinMode(MERAH_Timur,OUTPUT);

  pinMode(HIJAU_Selatan,OUTPUT);
  pinMode(KUNING_Selatan,OUTPUT);
  pinMode(MERAH_Selatan,OUTPUT);

  pinMode(HIJAU_Barat,OUTPUT);
  pinMode(KUNING_Barat,OUTPUT);
  pinMode(MERAH_Barat,OUTPUT);
  
  //menyalakan lampu merah saat mulai
  merahSimpang(HIJAU_Utara,KUNING_Utara,   MERAH_Utara);
  merahSimpang(HIJAU_Timur,   KUNING_Timur,   MERAH_Timur);
  merahSimpang(HIJAU_Selatan, KUNING_Selatan, MERAH_Selatan);
  merahSimpang(HIJAU_Barat,   KUNING_Barat,   MERAH_Barat);

  delay(1000); 
}


void loop()//menyalakan LED searah jarum jam
{
  merahSimpang(HIJAU_Timur,   KUNING_Timur,   MERAH_Timur);
  merahSimpang(HIJAU_Selatan, KUNING_Selatan, MERAH_Selatan);
  merahSimpang(HIJAU_Barat,   KUNING_Barat,   MERAH_Barat);
  aktifkanSimpang(HIJAU_Utara, KUNING_Utara, MERAH_Utara);
  
  merahSimpang(HIJAU_Utara,   KUNING_Utara,   MERAH_Utara);
  merahSimpang(HIJAU_Selatan, KUNING_Selatan, MERAH_Selatan);
  merahSimpang(HIJAU_Barat,   KUNING_Barat,   MERAH_Barat);
  aktifkanSimpang(HIJAU_Timur, KUNING_Timur, MERAH_Timur);

  merahSimpang(HIJAU_Utara,   KUNING_Utara,   MERAH_Utara);
  merahSimpang(HIJAU_Timur,   KUNING_Timur,   MERAH_Timur);
  merahSimpang(HIJAU_Barat,   KUNING_Barat,   MERAH_Barat);
  aktifkanSimpang(HIJAU_Selatan, KUNING_Selatan, MERAH_Selatan);

  merahSimpang(HIJAU_Utara,   KUNING_Utara,   MERAH_Utara);
  merahSimpang(HIJAU_Timur,   KUNING_Timur,   MERAH_Timur);
  merahSimpang(HIJAU_Selatan, KUNING_Selatan, MERAH_Selatan);
  aktifkanSimpang(HIJAU_Barat, KUNING_Barat, MERAH_Barat); 
}
