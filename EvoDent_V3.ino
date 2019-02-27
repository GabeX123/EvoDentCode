int vals[4] = {170,512,853,1024};
int motor_asiento_up = 2;
int motor_asiento_down = 3;
int motor_respaldo_up = 5;
int motor_respaldo_down = 4;

//int temp = 3;
int llenavaso = 4;
int lavabachas = 5;
int negatoscopio = 6;
int foco = 7;

int test = 7;

int ADC0 = A0;
int ADC1 = A1;
int ADC2 = A2;
int ADC3 = A3;

int asiento_fin = 8;
int respaldo_fin = 9;
int asiento_inicio = 10;
int respaldo_inicio = 11;

int buttonPushCounter = 1;
int buttonState = 0;         
int lastButtonState = 0;     
void setup() {
  

  Serial.begin(9600);
  Serial.println("Evodent v0.1");
  // put your setup code here, to run once:
  pinMode(test, OUTPUT);
  pinMode(motor_asiento_up,OUTPUT);
  pinMode(motor_asiento_down,OUTPUT);
  pinMode(motor_respaldo_up,OUTPUT);
  pinMode(motor_respaldo_down,OUTPUT);

  pinMode(negatoscopio,OUTPUT);
  pinMode(foco,OUTPUT);
  //pinMode(temp,OUTPUT);
  pinMode(llenavaso,OUTPUT);
  pinMode(lavabachas,OUTPUT);

  pinMode(asiento_fin,INPUT);
  pinMode(respaldo_fin,INPUT);

  pinMode(asiento_inicio,INPUT);
  pinMode(respaldo_inicio,INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  int ADC0 = analogRead(A0);
  int ADC1 = analogRead(A1);
  int ADC2 = analogRead(A2);
  int ADC3 = analogRead(A3);

//Botonera ADC0

  if((ADC0 > vals[0]) && (ADC0 < vals[1])){
    Negatoscopio();
  }
  if((ADC0 > vals[1]) && (ADC0 < vals[2])){
    SubeRespaldo();
  }
  else{
    DetenerMotores();
  }
  if((ADC0 > vals[2]) && (ADC0 < vals[3])){
    SubeAsiento();
  }
  else{
    DetenerMotores();
  }

//Botonera ADC1

  if((ADC1 > vals[0]) && (ADC1 < vals[1])){
    DetenerTodo();
  }
  if((ADC1 > vals[1]) && (ADC1 < vals[2])){
    Foco();
  }
  if((ADC1 > vals[2]) && (ADC1 < vals[3])){
    Lavabachas();
  }

//Botonera ADC2

  if((ADC2 > vals[0]) && (ADC2 < vals[1])){
    Zero();
  }
  if((ADC2 > vals[1]) && (ADC2 < vals[2])){
    Llenavasos();
  }
  if((ADC2 > vals[2]) && (ADC2 < vals[3])){
    Temperatura();
  }
//Botonera ADC3

  if((ADC3 > vals[0]) && (ADC3 < vals[1])){
    BajaAsiento();
  }
  else{
    DetenerMotores();
  }
  if((ADC3 > vals[1]) && (ADC3 < vals[2])){
    BajaRespaldo();
  }
  else{
    DetenerMotores();
  }
  if((ADC3 > vals[2]) && (ADC3 < vals[3])){
    MemoriaSalivar();
  }

  /*Serial.print("ADC 0:");Serial.print(ADC0);
  Serial.print(" ADC 1:");Serial.print(ADC1);
  Serial.print(" ADC 2:");Serial.print(ADC2);
  Serial.print(" ADC 3:");Serial.println(ADC3);
  */
  digitalWrite(test, HIGH);
  delay(200);
  digitalWrite(test, LOW);
  delay(200);
}

void SubeAsiento(){
    Serial.println("Sube Asiento");
    digitalWrite(motor_asiento_up,HIGH);
    digitalWrite(motor_asiento_down,LOW);
    digitalWrite(motor_respaldo_up,LOW);
    digitalWrite(motor_respaldo_down,LOW);
    
    delay(10);
  }

void BajaAsiento(){
    Serial.println("Baja Asiento");
    digitalWrite(motor_asiento_up,LOW);
    digitalWrite(motor_asiento_down,HIGH);
    digitalWrite(motor_respaldo_up,LOW);
    digitalWrite(motor_respaldo_down,LOW);
    
    delay(10);
  }

void SubeRespaldo(){
    Serial.println("Sube Respaldo");
    digitalWrite(motor_respaldo_up,HIGH);
    digitalWrite(motor_respaldo_down,LOW);
    digitalWrite(motor_asiento_up,LOW);
    digitalWrite(motor_asiento_down,LOW);
    
    delay(10);
  }

void BajaRespaldo(){
    Serial.println("Baja Respaldo");
    digitalWrite(motor_respaldo_up,LOW);
    digitalWrite(motor_respaldo_down,HIGH);
    digitalWrite(motor_asiento_up,LOW);
    digitalWrite(motor_asiento_down,LOW);
    
    delay(10);
  }
void Zero(){
    while((digitalRead(asiento_fin)==HIGH) && (digitalRead(respaldo_fin)==HIGH)){
        SubeAsiento();
        SubeRespaldo();
        
      }
    //digitalWrite()
  }
void DetenerTodo(){
  digitalWrite(motor_asiento_up,LOW);
  digitalWrite(motor_asiento_down,LOW);
  digitalWrite(motor_respaldo_up,LOW);
  digitalWrite(motor_respaldo_down,LOW);
  digitalWrite(lavabachas,LOW);
  digitalWrite(llenavaso,LOW);
  digitalWrite(negatoscopio,LOW);
  digitalWrite(foco,LOW);
  delay(10);
  }
void Memoria1(){
  
  }
void Memoria2(){
  
  }
void MEmoria3(){
  
  }
void MemoriaSalivar(){
  
  }
void Retorno(){
  
  }

void Foco(){
  
  buttonState = ADC1;

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState > 100) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println(buttonState);
      }
    // Delay a little bit to avoid bouncing
    delay(50);
    }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  if (buttonPushCounter % 2 == 0) {
    digitalWrite(foco, HIGH);
    } else {
    digitalWrite(foco, LOW);
    }
  if (buttonPushCounter == 6){
    buttonPushCounter == 1;
    }    
  }
void Temperatura(){
  
  }

void Negatoscopio(){
  
  buttonState = ADC0;
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState > 100) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println(buttonState);
      }
    // Delay a little bit to avoid bouncing
    delay(50);
    }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  if (buttonPushCounter % 2 == 0) {
    digitalWrite(negatoscopio, HIGH);
    } else {
    digitalWrite(negatoscopio, LOW);
    }
  if (buttonPushCounter == 6){
    buttonPushCounter == 1;
    }
  }

void Lavabachas(){
  Serial.println("lavabachas");
  
  buttonState = ADC1;
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState > 100) {
    // turn LED on:
    digitalWrite(lavabachas, HIGH);
  } else {
    // turn LED off:
    digitalWrite(lavabachas, LOW);
  }
  }
  
void Llenavasos(){
  Serial.println("lavabachas");
  
  buttonState = ADC2;
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState > 100) {
    // turn LED on:
    digitalWrite(llenavaso, HIGH);
  } else {
    // turn LED off:
    digitalWrite(llenavaso, LOW);
  }
  }
  
void DetenerMotores(){
  digitalWrite(motor_asiento_up,LOW);
  digitalWrite(motor_asiento_down,LOW);
  digitalWrite(motor_respaldo_up,LOW);
  digitalWrite(motor_respaldo_down,LOW);
  delay(10);
}
