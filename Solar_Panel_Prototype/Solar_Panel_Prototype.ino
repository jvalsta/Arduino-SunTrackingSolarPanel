// Arduino Uno sun tracking solar panel
// Done as a course work for a prototype course at Haaga-Helia University of Applied Sciences
// Prototype course site: www.terokarvinen.com
// GNU General Public License v2.0

// pin locations
int servoHorizontalPin= 2;
int servoVerticalPin= 3;
int topLeftldrPin = A0; //red orange
int topRightldrPin = A1; // yellow green
int bottomLeftldrPin = A2; // purple blue
int bottomRightldrPin = A3; // gray white

// global servo angle pulse values
int horizontalAnglePulse = 1425;
int verticalAnglePulse = 450;

// pulsing servos by Tero Karvinen @ www.botbook.com
void pulseServo(int servoPin, int pulseLenUs) {
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseLenUs);
  digitalWrite(servoPin, LOW);
  delay(1);
}

int readLdrTopLeft() {
  int topLeft = 1023 - analogRead(topLeftldrPin);
  return topLeft;
}

int readLdrTopRight() {
  int topRight = 1023 - analogRead(topRightldrPin);
  return topRight;
}

int readLdrBottomLeft() {
  int BottomLeft = 1023 - analogRead(bottomLeftldrPin);
  return BottomLeft;
}

int readLdrBottomRight() {
  int BottomRight = 1023 - analogRead(bottomRightldrPin);
  return BottomRight;
}

int averageTop(int topLeft, int topRight) {
  int avgTop = (topLeft + topRight) / 2;
  return avgTop;
}

int averageBottom(int bottomLeft, int bottomRight) {
  int avgBottom = (bottomLeft + bottomRight) / 2;
  return avgBottom;
}

int averageLeft(int topLeft, int bottomLeft) {
  int avgLeft = (topLeft + bottomLeft) / 2;
  return avgLeft;
}

int averageRight(int topRight, int bottomRight) {
  int avgRight = (topRight + bottomRight) / 2;
  return avgRight;
}

int checkHorizontalDifference(int avgLeft, int avgRight) {
  int differenceHorizontal = avgLeft - avgRight; 
  return differenceHorizontal;
}

int checkVerticalDifference(int avgTop, int avgBottom) { 
  int differenceVertical = avgTop - avgBottom;
  return differenceVertical;
}

void printLdrValues(int topLeft, int topRight, int bottomLeft, int bottomRight) {
  Serial.println("");
  Serial.print("Top Left: ");
  Serial.print(topLeft);
  Serial.println("");
  
  Serial.print("Top Right: ");
  Serial.print(topRight);
  Serial.println("");
  
  Serial.print("Bottom Left: ");
  Serial.print(bottomLeft);
  Serial.println("");
  
  Serial.print("Bottom Right: ");
  Serial.print(bottomRight);
  Serial.println("");
}

void printAvgValues(int avgTop, int avgBottom, int avgLeft, int avgRight)
{
  Serial.println("");
  Serial.print("Average Top: ");
  Serial.print(avgTop);
  Serial.println("");
  
  Serial.print("Average Bottom: ");
  Serial.print(avgBottom);
  Serial.println("");
  
  Serial.print("Average Left: ");
  Serial.print(avgLeft);
  Serial.println("");
  
  Serial.print("Average Right: ");
  Serial.print(avgRight);
  Serial.println("");
}

void printDifferenceValues(int differenceHorizontal,int differenceVertical)
{
  Serial.println("");
  Serial.print("Horizontal difference: ");
  Serial.print(differenceHorizontal);
  Serial.println("");
  
  Serial.print("Vertical difference: ");
  Serial.print(differenceVertical);
  Serial.println("");
}

int moveHorizontal(int differenceHorizontal, int avgLeft, int avgRight, int horizontalAnglePulse) {
  if (differenceHorizontal > 10 || differenceHorizontal < -10) {
    if (avgLeft < avgRight) {
      if (horizontalAnglePulse < 2350) {
        horizontalAnglePulse = ++horizontalAnglePulse;
        pulseServo(servoHorizontalPin, horizontalAnglePulse);
      }
      if (horizontalAnglePulse >= 2350) {
        horizontalAnglePulse = 2350;
      }
    }
    else if (avgLeft > avgRight) {
      if (horizontalAnglePulse > 500) {
        horizontalAnglePulse = --horizontalAnglePulse;
        pulseServo(servoHorizontalPin, horizontalAnglePulse);
      }
      if (horizontalAnglePulse <= 500) {
        horizontalAnglePulse = 500;
      }
    }
  }
  return horizontalAnglePulse;
}

int moveVertical(int differenceVertical, int avgTop, int avgBottom, int verticalAnglePulse) {
  if (differenceVertical > 10 || differenceVertical < -10) {
    if (avgTop > avgBottom) {
      if (verticalAnglePulse < 1150) {
        verticalAnglePulse = ++verticalAnglePulse;
        pulseServo(servoVerticalPin, verticalAnglePulse);
      }
      if (verticalAnglePulse >= 1150) {
        verticalAnglePulse = 1150;
        }
    }
    else if (avgTop < avgBottom) {
      if (verticalAnglePulse > 450) {
        verticalAnglePulse = --verticalAnglePulse;
        pulseServo(servoVerticalPin, verticalAnglePulse);
      }
      if (verticalAnglePulse <= 450) {
        verticalAnglePulse = 450;
      }
    }
  }
  return verticalAnglePulse;
}

void printPulseAngleValues(int horizontalAnglePulse, int verticalAnglePulse)
{
  Serial.println("");
  Serial.print("Horizontal pulse angle: ");
  Serial.print(horizontalAnglePulse);
  Serial.println("");
  
  Serial.print("Vertical pulse angle: ");
  Serial.print(verticalAnglePulse);
  Serial.println("");
}

void setup()
{
  pinMode(servoHorizontalPin, OUTPUT);
  pinMode(servoVerticalPin, OUTPUT);
  
  pinMode(topLeftldrPin, INPUT_PULLUP);
  pinMode(topRightldrPin, INPUT_PULLUP);
  pinMode(bottomLeftldrPin, INPUT_PULLUP);
  pinMode(bottomRightldrPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop()
{
  // get ldr values
  int topLeft = readLdrTopLeft();
  int topRight = readLdrTopRight();
  int bottomLeft = readLdrBottomLeft();
  int bottomRight = readLdrBottomRight();

  // get average values
  int avgTop = averageTop(topLeft, topRight);
  int avgBottom = averageBottom(bottomLeft, bottomRight);
  int avgLeft = averageLeft(topLeft, bottomLeft);
  int avgRight = averageRight(topRight, bottomRight);

  // get difference values
  int differenceHorizontal = checkHorizontalDifference(avgLeft, avgRight);
  int differenceVertical = checkVerticalDifference(avgTop, avgBottom);

  // servo angle pulse values and moving servos
  horizontalAnglePulse = moveHorizontal(differenceHorizontal, avgLeft, avgRight, horizontalAnglePulse);
  verticalAnglePulse = moveVertical(differenceVertical, avgTop, avgBottom, verticalAnglePulse);
  
  // debugging with serial monitor
  printLdrValues(topLeft, topRight, bottomLeft, bottomRight); // used for debug from serial monitor
  printAvgValues(avgTop, avgBottom, avgLeft, avgRight); // used for debug from serial monitor
  printDifferenceValues(differenceHorizontal, differenceVertical); // used for debug from serial monitor
  printPulseAngleValues(horizontalAnglePulse, verticalAnglePulse); // used for debug from serial monitor
  delay(5);

}

