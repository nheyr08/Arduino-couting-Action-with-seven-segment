int seg_a = 13; // ##AAA##
int seg_b = 12; // F#####B
int seg_c = 11;  // F#####B
int seg_d = 10;  // ##GGG##
int seg_e = 9;  // E#####C
int seg_f = 8;  // E#####C
int seg_g = 7;  // ##DDD##

void num(int i);

int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers


int digit1 = 5;
int digit2 = 4;

int digito1 = 0;
int digito2 = 0;
int valor = 0;
bool a = true;

unsigned long previousMillis = 0;
const long interval = 1000;

const int  buttonPin = 2;
int buttonState = 0;

void setup() {
 pinMode(seg_a, OUTPUT);  
 pinMode(seg_b, OUTPUT);  
 pinMode(seg_c, OUTPUT);  
 pinMode(seg_d, OUTPUT);
 pinMode(seg_e, OUTPUT);
 pinMode(seg_f, OUTPUT);
 pinMode(seg_g, OUTPUT);
 pinMode(digit1, OUTPUT);
 pinMode(digit2, OUTPUT);

 pinMode(buttonPin, INPUT);
}

void loop() {


   if(digitalRead(buttonPin)==HIGH)
   {
    int u=0;
    while(digitalRead(buttonPin)==HIGH)
    { num(valor); u++;
        if(u>50)
        {
          valor=0;
          a=1;
        }
     }
        a=!a;
    }
//otherwise 
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;
    if(a)
    {valor++;}
    previous = reading;
  }
  num(valor);
}

void num(int i)
{
  digitalWrite(digit1, HIGH);  
  digitalWrite(digit2, LOW);
  digito1 = (valor%10);
  display(digito1);
  delay(10);
  digitalWrite(digit1, LOW);  
  digitalWrite(digit2, HIGH);
  digito2 = ((valor/10)%10);
  display(digito2);
  delay(10);
}

int display(int a) 
{
   switch(a)
   { 
   case 0: 
     digitalWrite(seg_a, LOW);  
     digitalWrite(seg_b, LOW); 
     digitalWrite(seg_c, LOW); 
     digitalWrite(seg_d, LOW);
     digitalWrite(seg_e, LOW);
     digitalWrite(seg_f, LOW); 
     digitalWrite(seg_g, HIGH); 
   break;  
   case 1: 
     digitalWrite(seg_a, HIGH);  
     digitalWrite(seg_b, LOW); 
     digitalWrite(seg_c, LOW); 
     digitalWrite(seg_d, HIGH);
     digitalWrite(seg_e, HIGH);
     digitalWrite(seg_f, HIGH); 
     digitalWrite(seg_g, HIGH); 
   break;
   case 2: 
     digitalWrite(seg_a, LOW);  
     digitalWrite(seg_b, LOW); 
     digitalWrite(seg_c, HIGH); 
     digitalWrite(seg_d, LOW);
     digitalWrite(seg_e, LOW);
     digitalWrite(seg_f, HIGH); 
     digitalWrite(seg_g, LOW); 
   break;
   case 3: 
     digitalWrite(seg_a, LOW);  
     digitalWrite(seg_b, LOW); 
     digitalWrite(seg_c, LOW); 
     digitalWrite(seg_d, LOW);
     digitalWrite(seg_e, HIGH);
     digitalWrite(seg_f, HIGH); 
     digitalWrite(seg_g, LOW); 
   break;
   case 4: 
     digitalWrite(seg_a, HIGH);  
     digitalWrite(seg_b, LOW); 
     digitalWrite(seg_c, LOW); 
     digitalWrite(seg_d, HIGH);
     digitalWrite(seg_e, HIGH);
     digitalWrite(seg_f, LOW); 
     digitalWrite(seg_g, LOW); 
   break;   
   case 5: 
     digitalWrite(seg_a, LOW);  
     digitalWrite(seg_b, HIGH); 
     digitalWrite(seg_c, LOW); 
     digitalWrite(seg_d, LOW);
     digitalWrite(seg_e, HIGH);
     digitalWrite(seg_f, LOW); 
     digitalWrite(seg_g, LOW); 
   break;
   case 6: 
     digitalWrite(seg_a, HIGH);  
     digitalWrite(seg_b, HIGH); 
     digitalWrite(seg_c, LOW); 
     digitalWrite(seg_d, LOW);
     digitalWrite(seg_e, LOW);
     digitalWrite(seg_f, LOW); 
     digitalWrite(seg_g, LOW); 
   break;
   case 7: 
     digitalWrite(seg_a, LOW);  
     digitalWrite(seg_b, LOW); 
     digitalWrite(seg_c, LOW); 
     digitalWrite(seg_d, HIGH);
     digitalWrite(seg_e, HIGH);
     digitalWrite(seg_f, HIGH); 
     digitalWrite(seg_g, HIGH); 
   break;
   case 8: 
     digitalWrite(seg_a, LOW);  
     digitalWrite(seg_b, LOW); 
     digitalWrite(seg_c, LOW); 
     digitalWrite(seg_d, LOW);
     digitalWrite(seg_e, LOW);
     digitalWrite(seg_f, LOW); 
     digitalWrite(seg_g, LOW); 
   break;
   case 9: 
     digitalWrite(seg_a, LOW);  
     digitalWrite(seg_b, LOW); 
     digitalWrite(seg_c, LOW); 
     digitalWrite(seg_d, HIGH);
     digitalWrite(seg_e, HIGH);
     digitalWrite(seg_f, LOW); 
     digitalWrite(seg_g, LOW); 
   break;      
   }
   return a;
}
