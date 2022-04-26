#define  SEG_A  7
#define  SEG_B  6
#define  SEG_C  8
#define  SEG_D  10
#define  SEG_E  11
#define  SEG_F  13
#define  SEG_G  12

byte segmento[7] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G}, cont; 
byte digito[10][7]  = { {0,0,0,0,0,0,1},    // 0
                        {1,0,0,1,1,1,1},    // 1
                        {0,0,1,0,0,1,0},    // 2
                        {0,0,0,0,1,1,0},    // 3
                        {1,0,0,1,1,0,0},    // 4
                        {0,1,0,0,1,0,0},    // 5
                        {0,1,0,0,0,0,0},    // 6
                        {0,0,0,1,1,1,1},    // 7
                        {0,0,0,0,0,0,0},    // 8
                        {0,0,0,1,1,0,0} };  // 9

void display7seg(byte estado[]) {
  for (byte i = 0; i < 7; i++)
    digitalWrite(segmento[i],estado[i]);
}

void setup() {
  for (byte i = 0; i < 7; i++)
    pinMode(segmento[i], OUTPUT);
  cont = 0;
}

void loop() {
  display7seg(digito[cont++]);
  if (cont > 9)
    cont = 0;
  delay(1000);
}
