String command;
int stime;
int repeat;
int i;
int rot;
int ele;

#define a1 2
#define a2 3
#define a3 4
#define a4 5
#define b1 6
#define b2 7
#define b3 8
#define b4 9


void setup() {
  Serial.begin(9600);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(a4, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(b4, OUTPUT);

  delay(1000);

  stime = 10;
  repeat = 1;
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();
    if (command.toInt() > 0) {
      repeat = command.toInt();
    }
    if (command.equals("reset")) {
      rot=0;
      ele=0;
      Serial.println("OK");
    }
    if (command.equals("rot")) {
      Serial.println(rot);
    }
    if (command.equals("ele")) {
      Serial.println(ele);
    }
    if (command.equals("r")) {
      for (i=0; i < repeat; i++) { 
        right();
      }
    }
    if (command.equals("l")) {
      for (i=0; i < repeat; i++) {
        left();
      }
    }
    if (command.equals("u")) {
      for (i=0; i < repeat; i++) {
        up();
      }
    }
    if (command.equals("d")) {
      for (i=0; i < repeat; i++) {
        down();
      }
    }
  }
}


void right() {
  digitalWrite(a1, HIGH);
      delay (stime);
      digitalWrite(a1, LOW);
      digitalWrite(a2, HIGH);
      delay (stime);
      digitalWrite(a2, LOW);
      digitalWrite(a3, HIGH);
      delay (stime);
      digitalWrite(a3, LOW);
      digitalWrite(a4, HIGH);
      delay (stime);
      digitalWrite(a4, LOW);
      rot++;
}

void left() {
  digitalWrite(a4, HIGH);
      delay (stime);
      digitalWrite(a4, LOW);
      digitalWrite(a3, HIGH);
      delay (stime);
      digitalWrite(a3, LOW);
      digitalWrite(a2, HIGH);
      delay (stime);
      digitalWrite(a2, LOW);
      digitalWrite(a1, HIGH);
      delay (stime);
      digitalWrite(a1, LOW);
      rot--;
}

void up() {
  digitalWrite(b1, HIGH);
      delay (stime);
      digitalWrite(b1, LOW);
      digitalWrite(b2, HIGH);
      delay (stime);
      digitalWrite(b2, LOW);
      digitalWrite(b3, HIGH);
      delay (stime);
      digitalWrite(b3, LOW);
      digitalWrite(b4, HIGH);
      delay (stime);
      digitalWrite(b4, LOW);
      ele++;
}

void down() {
  digitalWrite(b4, HIGH);
      delay (stime);
      digitalWrite(b4, LOW);
      digitalWrite(b3, HIGH);
      delay (stime);
      digitalWrite(b3, LOW);
      digitalWrite(b2, HIGH);
      delay (stime);
      digitalWrite(b2, LOW);
      digitalWrite(b1, HIGH);
      delay (stime);
      digitalWrite(b1, LOW);
      ele--;
}
