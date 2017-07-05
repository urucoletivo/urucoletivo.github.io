#define Red 9
#define Blue 10
#define Green 11
//int vermelho=20, verde=200, azul=180;
//int flow=0;
int prevR = 0, prevG = 0, prevB = 0; // all of the previous RGB values

//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);

  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}

void loop() {
  //if (flow<70) { vermelho=0, verde=255, azul=255; }
  //if (flow>=70, flow<140) { vermelho=255, verde=0, azul=255; }
  //if (flow>=140, flow<=210) { vermelho=255, verde=255, azul=0; }
  //if (flow>210) { flow=0; }
  //flow = flow+1;
  //delay(1);  
  //analogWrite(blue, azul);
  //analogWrite(red, vermelho);
  //analogWrite(green, verde);

   //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  delay(1000);

  RGB(0, 0, 255); 
    delay(10*cmMsec);
  RGB(0,255,0);
    delay(10*cmMsec);
  RGB(255, 0, 0);
    delay(10*cmMsec);
 
}


void RGB(int R, int G, int B) {

for (int i = 0; i <= 255; i++){
  
  if (i >=  prevR - R && prevR < R) { 
   analogWrite(Red, prevR + i);
  }
  
  if (i >= prevG - G && prevG < G) {
    analogWrite(Green, prevG + i); 
  }

  if (i >= prevB - B && prevB < B) {
    analogWrite(Blue, prevB + i);
  }

  if (i >= R - prevR && prevR > R) {
    analogWrite(Red, prevR - i);
  }
  
  if (i >= G - prevG && prevG > G) { 
    analogWrite(Green, prevG - i); 
  }

  if (i >= B - prevB && prevB > B) {
    analogWrite(Blue, prevB - i);
  }
  
delay(10);
}
delay(10);
analogWrite(Red, R);
analogWrite(Green, G);
analogWrite(Blue, B);
prevR = R;
prevG = G;
prevB = B;
}
 
  
  

