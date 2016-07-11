#define D1 2          // Направление вращение двигателя 1
#define M1 3          // ШИМ вывод для управления двигателем 1
#define D2 4         // Направление вращение двигателя 2
#define M2 5          // ШИМ вывод для управления двигателем 2
char incomingByte;
int  LED = 13;
 
bool direction = 0;
bool direction2 ;// Текущее направление вращения       
int value ;          // Текущее значение ШИМ
  
void setup() 
{ 
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(LED, OUTPUT); 
    Serial.begin(9600); // инициализация порта
    Serial.println("Press 1 to motor start or 0 to motor off"); 
} 

void loop() 
{ 
 /* digitalWrite(13, LOW);
  delay(50);
  for(value = 0; value <= 255; value+=1) 
  { 
    digitalWrite(D1, direction);  // Задаем направление вращения
    digitalWrite(D2, direction);
    analogWrite(M1, value);       // Задаем скорость вращения
    analogWrite(M2, value);
    delay(30); 
  }  
  direction = direction ^ 1;
  digitalWrite(13, HIGH);
  delay(50);
*/
if (Serial.available() > 0){
    incomingByte = Serial.read();
    if(incomingByte == '0'){
        value = 0;
        analogWrite(M1, value);
        digitalWrite(D1, direction);
        Serial.println("motor was stoped");
    }
    if(incomingByte == '1'){
        value = 50;
        analogWrite(M1, value);
        digitalWrite(D1, HIGH); 
        Serial.println("motor was started");
    }
    if(incomingByte == '2'){
        value = 50;
        direction = direction ^ 1;
        analogWrite(M1, value);
        digitalWrite(D1, HIGH);
        Serial.println("motor was started with 50 pwm");
    }

    }
}       


