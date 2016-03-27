int RED = D1;
int GREEN = D3;
int Button = D2;
int Mode = 0;
int LED = D7;


Servo servoMotor;
const int initialAngle = 90;

void setup(){
  //Set up for LEDController
  pinMode(D7, OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  Particle.function("ToggleLED",ToggleLED);

  //Set up for ServoController
  servoMotor.attach(D0);
  servoMotor.write(initialAngle);
  delay(1000);
  Particle.function("turnServo",turnServo);
  delay(2000);
}

void loop(){

}

int ToggleLED(String color){
  if (color == "green"){
    digitalWrite(GREEN,HIGH);
    digitalWrite(RED,LOW);
    digitalWrite(LED,LOW);
    return 1;
  }else if(color == "red"){
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(LED,LOW);
    return 0;
  }else if(color == "blue"){
    digitalWrite(LED,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(RED,LOW);
  } else if(color == "none"){
    digitalWrite(LED,LOW);
    digitalWrite(GREEN,LOW);
    digitalWrite(RED,LOW);
  }
}

int turnServo(String direction){
  if (direction == "right"){
    servoMotor.write(180);
    delay(1000);
    servoMotor.write(initialAngle);
    delay(1000);
    return 1;
  }
  if (direction == "left"){
    servoMotor.write(0);
    delay(1000);
    servoMotor.write(initialAngle);
    delay(1000);
    return 2;
  }
}
