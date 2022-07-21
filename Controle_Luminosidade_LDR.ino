#define pinoPWM 5
#define AnalogLDR A0
#define BrilhoMax 1024
#define BrilhoMin 500
int Brilho = 0;
int Leitura = 0;
int LeituraAnterior = 0;

void setup()  
{  
  pinMode(pinoPWM, OUTPUT); //Define a porta do Led como saída  
  Serial.begin(9600);
}  
   
void loop()  
{  
  Leitura = analogRead(AnalogLDR);  //Lê o valor fornecido pelo LDR 
  
  Serial.print("Leitura sensor LDR = "); 
  Serial.println(Leitura);
  Brilho = map(Leitura, BrilhoMin, BrilhoMax, 10, 255);
  Serial.print("Duty Cycle calculado = "); 
  Serial.println(Brilho);
  
  analogWrite(pinoPWM,Brilho);

  LeituraAnterior = Leitura;
  
  delay(10);
}