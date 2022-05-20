#define s Serial1
#define LED 3
#define BUT 9

void setup() {
  s.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUT, INPUT_PULLUP);

}


void loop() {
  static bool flag, butFlag = true;
  if (s.available()) {
    char ch = s.read();

    if (ch == '1') {
      flag = !flag;


    }
    digitalWrite(LED, flag);

    while (s.available()) {
      s.read();
    }

  }

  if (!digitalRead(BUT) && butFlag) {
    butFlag = false;
    s.print("1");
  }

  if (digitalRead(BUT) && !butFlag) {
    butFlag = true;

  }



}
