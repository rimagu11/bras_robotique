#include <Servo.h>

Servo myservo1;

Servo myservo2;

Servo myservo3;

Servo myservo4;

#define servoPin1 10

#define servoPin2 9

#define servoPin3 8

#define servoPin4 7

#define motorAVPin 1

#define motorARPin 2

#define ButtonPin 0

int potpin1 = 3; // analog pin used to connect the potentiometer

   int val1; // variable to read the value from the analog pin

int potpin2 = 4; // analog pin used to connect the potentiometer

   int val2; // variable to read the value from the analog pin

int potpin3 = 5; // analog pin used to connect the potentiometer

   int val3; // variable to read the value from the analog pin

int potpin4 = 6; // analog pin used to connect the potentiometer

   int val4; // variable to read the value from the analog pin

     int Marche = 0;

  int ButtonState;

 


void setup() {

  pinMode (ButtonPin, INPUT_PULLUP);

  myservo1.attach(servoPin1);

  myservo2.attach(servoPin2);

  myservo3.attach(servoPin3);

  myservo4.attach(servoPin4);

}

void loop() {

  ButtonState = digitalRead(ButtonPin);

  if ((ButtonState == HIGH)&&(Marche == 0)){

    digitalWrite(motorAVPin, HIGH);

    delay(8000);

    digitalWrite(motorAVPin, LOW);

    Marche = 1;

  }

  ButtonState = digitalRead(ButtonPin);

    if ((ButtonState == HIGH)&&(Marche == 1)){

    digitalWrite(motorARPin, HIGH);

    delay(8000);

    digitalWrite(motorARPin, LOW);

    Marche = 0;

  }

   val1 = analogRead(potpin1);

    val1 = map(val1, 200, 823, 0, 180);

    myservo1.write(val1); // sets the servo position according to the scaled value

     val2 = analogRead(potpin2);

      val2 = map(val2, 200, 823, 0, 180);

        myservo2.write(val2); // sets the servo position according to the scaled value

          val3 = analogRead(potpin3);

            val3 = map(val3, 200, 823, 180, 0);

            myservo3.write(val3); // sets the servo position according to the scaled value

              val4 = analogRead(potpin4);

                val4 = map(val4, 200, 823, 0, 180);

                myservo4.write(val4); // sets the servo position according to the scaled value

   delay(15);

}
