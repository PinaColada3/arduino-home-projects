#include <Keyboard.h>

int sleep_counter = 0;
const int start_up_delay = 3000;
const int wake_up = 1;

void setup() {
  // put your setup code here, to run once:
  delay(start_up_delay);
  Keyboard.begin();
}

void loop() {
  Keyboard.write(' ');
  bool run = true;
  while(run)
  {
    delay(8000);
    long randomNumber = random(5);
    switch(randomNumber)
    {
      case 0:
        Keyboard.press('w');
        break;
      case 1:
        Keyboard.press('a');
        break;
      case 2:
        Keyboard.press('s');
        break;
      case 3:
        Keyboard.press('d');
        break;
      case 4:
        Keyboard.write(' ');
        break;
    }
    delay(500);
    Keyboard.releaseAll();
  }
}
