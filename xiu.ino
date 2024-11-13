//Define os pinos digitais 7 e 8 para o sensor e a lâmpada, respectivamente
#define pinoSensor A0
#define pinoLampGreen1 13
#define pinoLampGreen2 12
#define pinoLampYellow1 11
#define pinoLampYellow2 10
#define pinoLampRed1 9
#define pinoLampRed2 8
//bool lampada = false; //variável que armazena o estado da lâmpada (true = ligada e false = desligada)
void setup() {
  //Define os pinos do sensor e da lâmpada como entrada e saída respectivamente
  Serial.begin(9600);
  pinMode(pinoSensor,INPUT);
  pinMode(pinoLampGreen1,OUTPUT);
  pinMode(pinoLampGreen2,OUTPUT);
  pinMode(pinoLampYellow1,OUTPUT);
  pinMode(pinoLampYellow2,OUTPUT);
  pinMode(pinoLampRed1,OUTPUT);
  pinMode(pinoLampRed2,OUTPUT);
}

void loop() {
  int entrada = analogRead(pinoSensor);
  Serial.println(entrada);

  if(entrada <= 500) {
    Serial.println("entrada <= 600");
    digitalWrite(pinoLampGreen1, LOW);
    digitalWrite(pinoLampGreen2, LOW);
    digitalWrite(pinoLampYellow1, LOW);
    digitalWrite(pinoLampYellow2, LOW);
    digitalWrite(pinoLampRed1, LOW);
    digitalWrite(pinoLampRed2, LOW);

  }else if (entrada > 600 && entrada <700) {
    // Se o valor de entrada for maior que 800, acende as lâmpadas verdes
    Serial.println("entrada > 700 && entrada <800");
    digitalWrite(pinoLampGreen1, HIGH);
    digitalWrite(pinoLampGreen2, HIGH);
    digitalWrite(pinoLampYellow1, LOW);
    digitalWrite(pinoLampYellow2, LOW);
    digitalWrite(pinoLampRed1, LOW);
    digitalWrite(pinoLampRed2, LOW);
  }
   else if (entrada > 810 && entrada <1000) {
    // Se o valor de entrada for entre 500 e 800, acende as lâmpadas amarelas
    Serial.println("entrada > 810 && entrada <1000");
    digitalWrite(pinoLampGreen1, HIGH);
    digitalWrite(pinoLampGreen2,  HIGH);
    digitalWrite(pinoLampYellow1, HIGH);
    digitalWrite(pinoLampYellow2, HIGH);
    digitalWrite(pinoLampRed1, LOW);
    digitalWrite(pinoLampRed2, LOW);
  }
  else if (entrada > 1010) {
    // Se o valor de entrada for menor que 500, acende as lâmpadas vermelhas
    Serial.println("entrada > 1010");
    digitalWrite(pinoLampGreen1,  HIGH);
    digitalWrite(pinoLampGreen2,  HIGH);
    digitalWrite(pinoLampYellow1,  HIGH);
    digitalWrite(pinoLampYellow2,  HIGH);
    digitalWrite(pinoLampRed1, HIGH);
    digitalWrite(pinoLampRed2, HIGH);
  }
  
  // Você pode adicionar um pequeno atraso para estabilizar as leituras
  delay(200);

}
