int sensor_valor = 0;
int limite_som = 670; //Depois de fazer a calibração do trimpot, inserir o valor obtido de ajuste aqui
int abs_valor = 0;
int contagem_leds = 6; //quantidade de LEDs
int Pinos_Leds[] = {3, 4, 5, 6, 7, 8}; // Pinos do arduínos referente aos LEDs
  void setup(){
Serial.begin(9600); // setup serial
for (int i = 0; i <= contagem_leds; i++)
{
  pinMode(Pinos_Leds[i], OUTPUT);
}
for (int i = 0; i <= 9; i++)
{
  digitalWrite(i, LOW);
}
}
void loop() {
sensor_valor = analogRead(A0); //Intensidade do som obtido pelo sensor pelo pino analógico A0 do arduíno
Serial.println(sensor_valor);
abs_valor = abs(sensor_valor - limite_som);
int ledLevel = map(abs_valor, 0, (1024 - limite_som), 0, contagem_leds);
for (int i = 0; i < contagem_leds; i++) {
//Se o índice do elemento da matriz for menor que ledLevel, pinos dos leds em nível alto:
if (i < ledLevel) {
digitalWrite(Pinos_Leds[i], HIGH);
Serial.println(i);
}
// Se não desative todos os pinos mais altos que o ledLevel:
else {
digitalWrite(Pinos_Leds[i], LOW);
}
}}
