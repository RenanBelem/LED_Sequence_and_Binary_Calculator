
const int ledVerde = 4;
const int ledVermelho = 3;
const int ledAmarelo = 2;
int A = 0;
int B = 0;
int resultado = 0;
char operador = '?';
 
void setup()
{
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  Serial.begin(9600);
}
 
void loop()
{
  Serial.println("Digite o primeiro número: ");
  while (Serial.available()== 0){} // loop de espera
  A = Serial.parseInt();

  Serial.println("Digite o operador (- ou +): ");
  while (Serial.available()== 0){} // loop de espera
  operador = Serial.read();

  Serial.println("Digite o segundo número: ");
  while (Serial.available()== 0){} // loop de espera
  B = Serial.parseInt();

  if(operador == '-' && A >= B && A - B <= 7){
    Serial.println("Dados válidos!!!");
    resultado = A - B;
  } else if(operador == '+' && A + B <= 7){
    Serial.println("Dados válidos!!!");
    resultado = A + B;
  }else{
    Serial.println("Dados inválidos!!!");
  }

  Serial.println(A);
  Serial.println(B);
  Serial.println(operador);
  
  digitalWrite(ledAmarelo, bitRead(resultado, 0));
  digitalWrite(ledVermelho, bitRead(resultado, 1));
  digitalWrite(ledVerde, bitRead(resultado, 2));
  
}
