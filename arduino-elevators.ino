// Elevator 1
const int LED_1 = A0;
const int BUTTON_1 = 2;
const int MAGNET_1 = 3;
const int RELAY_1 = 4;

// Elevator 2
const int LED_2 = A1;
const int BUTTON_2 = 5;
const int MAGNET_2 = 6;
const int RELAY_2 = 7;

// Elevator 3
const int LED_3 = A2;
const int BUTTON_3 = 8;
const int MAGNET_3 = 9;
const int RELAY_3 = 10;

// Elevator 4
const int LED_4 = A3;
const int BUTTON_4 = 11;
const int MAGNET_4 = 12;
const int RELAY_4 = 13;

void setup() {
  // LED
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

  // Buttons
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);

  // Magnets
  pinMode(MAGNET_1, INPUT_PULLUP);
  pinMode(MAGNET_2, INPUT_PULLUP);
  pinMode(MAGNET_3, INPUT_PULLUP);
  pinMode(MAGNET_4, INPUT_PULLUP);

  // Relays
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
}

void loop(void) {
  elevatorOne();
  elevatorTwo();
  elevatorThree();
  elevatorFour();
}

// Sensor logic for Elevator 1
void elevatorOne() {
  // IF BUTTON PRESSING
  if(digitalRead(BUTTON_1) == 0) {
    // TURN LED BUTTON ON
    digitalWrite(LED_1, 1);

    // TURN ELEVATORS
    digitalWrite(RELAY_1, LOW);
  } 
  // ELSE BUTTON NOT PRESSING
  else {
    // TURN LED BUTTON OFF
    digitalWrite(LED_1, 0);

    // NORMAL ELEVATOR LOGIC
    // read magnet state 
    int magnetState = digitalRead(MAGNET_1);
    // if magnets are not touching
    if (magnetState == HIGH) {
      // turn elevators
      digitalWrite(RELAY_1, LOW);
    }
    // else if magnets are touching
    else {
      // stop elevators
      digitalWrite(RELAY_1, HIGH);
    } 
  }
}

// Sensor logic for Elevator 2
void elevatorTwo() {
  // IF BUTTON PRESSING
  if(digitalRead(BUTTON_2) == 0) {
    // TURN LED BUTTON ON
    digitalWrite(LED_2, 1);

    // TURN ELEVATORS
    digitalWrite(RELAY_2, LOW);
  } 
  // ELSE BUTTON NOT PRESSING
  else {
    // TURN LED BUTTON OFF
    digitalWrite(LED_2, 0);

    // NORMAL ELEVATOR LOGIC
    // read magnet state 
    int magnetState = digitalRead(MAGNET_2);
    // if magnets are not touching
    if (magnetState == HIGH) {
      // turn elevators
      digitalWrite(RELAY_2, LOW);
    }
    // else if magnets are touching
    else {
      // stop elevators
      digitalWrite(RELAY_2, HIGH);
    } 
  }
}

// Sensor logic for Elevator 3
void elevatorThree() {
  // IF BUTTON PRESSING
  if(digitalRead(BUTTON_3) == 0) {
    // TURN LED BUTTON ON
    digitalWrite(LED_3, 1);

    // TURN ELEVATORS
    digitalWrite(RELAY_3, LOW);
  } 
  // ELSE BUTTON NOT PRESSING
  else {
    // TURN LED BUTTON OFF
    digitalWrite(LED_3, 0);

    // NORMAL ELEVATOR LOGIC
    // read magnet state 
    int magnetState = digitalRead(MAGNET_3);
    // if magnets are not touching
    if (magnetState == HIGH) {
      // turn elevators
      digitalWrite(RELAY_3, LOW);
    }
    // else if magnets are touching
    else {
      // stop elevators
      digitalWrite(RELAY_3, HIGH);
    } 
  }
}

// Sensor logic for Elevator 4
void elevatorFour() {
  // IF BUTTON PRESSING
  if(digitalRead(BUTTON_4) == 0) {
    // TURN LED BUTTON ON
    digitalWrite(LED_4, 1);

    // TURN ELEVATORS
    digitalWrite(RELAY_4, LOW);
  } 
  // ELSE BUTTON NOT PRESSING
  else {
    // TURN LED BUTTON OFF
    digitalWrite(LED_4, 0);

    // NORMAL ELEVATOR LOGIC
    // read magnet state 
    int magnetState = digitalRead(MAGNET_4);
    // if magnets are not touching
    if (magnetState == HIGH) {
      // turn elevators
      digitalWrite(RELAY_4, LOW);
    }
    // else if magnets are touching
    else {
      // stop elevators
      digitalWrite(RELAY_4, HIGH);
    } 
  }
}
