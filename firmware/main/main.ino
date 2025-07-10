// include libraries
#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// init servos
Servo linear; // continuous linear servo
Servo rot; // positional rotational servo

// init LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);
lcd.init();
lcd.backlight();
lcd.cursor(0,0);

// setup keypad
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

char keys[ROWS][COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {6, 7, 8, 9}; // Connect to row pins in format {R1, R2, R3, R4}
byte colPins[COLS] = {2, 3, 4, 5}; // Connect to column pins in format {C1, C2, C3, C4}

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String PIN = "0000"; // SET YOUR PIN HERE
String attemptPIN = "";
bool lockedState = true;

// define pins
int linearPin = 11;
int rotPin = 10;

int ledPin = 12;
int buttonPin = 13; // button on the inside of the door

// variables, consts, and other states
bool lastButton = HIGH; // INPUT_PULLUP is default HIGH
bool actionDone = false; 

double msPerRev = 461.538461; // DETERMINED EMPIRICALLY

void setup() {
  Serial.begin(9600);
  
  linear.attach(linearPin);
  linear.write(90);
  rot.attach(rotPin);
  rot.write(180); // starting position to mount onto the lock

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  enterPIN(); // set LCD screen to home
}

void loop() {
  char key = keypad.getKey(); // detect key press and save the key
  if (key) { // keypad logic
    if (key == '*') { // clear attempt
      attemptPIN = "";
      updatePIN();
    } else if (key == '#') { // enter
      if (attemptPIN == PIN) {
        accessGranted(); // update LCD
        updateLED();
        (lockedState == true) ? unlock(); : lock();
        enterPIN(); // return LCD screen to home
      } else {
        accessDenied();
      }
      attemptPIN = "";
      updatePIN();
    } else { // add key pressed to the attempt
      if (attemptPIN.length() <= 4) { // only if the attempt isn't 4 digits yet
        String num = String(key);
        attemptPIN += num;
        updatePIN();
      }
    }
  }
  
  bool currentButton = digitalRead(buttonPin);

  if (currentButton == LOW && lastButton == HIGH && !actionDone) { // runs  once when pressed
    updateLED();
    (lockedState == true) ? unlock(); : lock(); // do the action
    actionDone = true; // ensure that this code runs only once when pressed
  }
  if (currentButton == HIGH) {
    actionDone = false; // reset actionDone upon release of button
  }
  
  lastButton = currentButton; // update lastButton  
}

// LED
void updateLED() {
  if (lockedState == true) { // LED logic
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}


// LCD
void enterPIN() {
  lcd.clear();
  lcd.cursor(0,0);
  lcd.write("Welcome, JAYDEN");
  lcd.cursor(0,1);
  lcd.write("____");
}

void updatePIN() {
  lcd.cursor(0,1);
  if (attemptPIN.length() > 0) { lcd.write(attemptPIN); }
  if (attemptPIN.length() < 4) {
    lcd.cursor(attemptPIN.length(),1);
    String underscores = "";
    for (int i = 0; i < (4-attemptPIN.length()); i++) {
      underscores += "_";
    }
    lcd.write(underscores);
  }
}

void accessGranted() {
  lcd.clear();
  lcd.cursor(0,0);
  lcd.write("ACCESS GRANTED")
  lcd.cursor(0,1);
  if (lockedState == true) {
    lcd.write("Unlocking...");
  } else {
    lcd.write("Locking...");
  }
}

void accessDenied() {
  lcd.clear();
  lcd.cursor(0,0);
  lcd.write("ACCESS DENIED");
  lcd.cursor(0,1);
  lcd.write("Incorrect PIN.")
  delay(3000); // wait 3s
  enterPIN(); // return LCD to home screen
}


// Servo control
void push() { // continuous linear servo
  linear.write(45); // counterclockwise
  delay(int(msPerRev*2.25)); // push 4.5mm, 2mm per rev on screw
}

void pull() { // continuous linear servo
  linear.write(135); // clockwise
  delay(int(msPerRev*2.25)); // pull 4.5mm, 2mm per rev on screw
}

void turnUnlock() {
  rot.write(0);
  delay(500); // speed of rotation
}

void turnLock() {
  rot.write(180);
  delay(1000); // slower for more torque to push the lock against the door firmly
}

void unlock() {
  push();
  turnUnlock();
  pull();
}

void lock() {
  push();
  turnLock();
  pull();
}