#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

const String phrases[] = {"Boom!",
                        "Para nuestro CTO Roi-Greydon del \"Club de la Comidia\" Feb 2018",
                        "Wisuuu", 
                        "Ojala te mueras(en el gusano)",
                        "Todos a por el verde",
                        "Justicia gusanistica",
                        "Ha hecho un Juan",
                        "Pixeleando",
                        "Ya va ganando Roi.Es lo que queriais,no?",
                        "Jorge trampas",
                        "Juan huecos",
                        "Vamos Greenly!",
                        "Ya esta desmo",
                        "Alvaro parcelas",
                        "Yo antes era bueno",
                        "Mira los coleguitas",
                        "Gordaco",
                        "Patri suicidios",
                        "Rascote",
                        "Ah!Me duele el brazo",
                        "El puntero!!!",
                        "Jorge y su pedal",
                        "Morid todos!",
                        "Muerte inutil",
                        "Azul y Gris,no lo olvideis",
                        "Capaz de lo mejor y lo peor",
                        "Alguien me ha tocado las teclas",
                        "Ya estan los de siempre",
                        "Finitorrrr",
                        "Cereeeebroooo",
                        "Si quedan dos,no se limpia",
                        "Jorge,te pego un puno",
                        "Cacahuete",
                        "Encierrale por debajo!",
                        "La codicia te pudo Marti",
                        "Antonio,suicidate",
                        "Estamos todos en la final",
                        "Sonrisitas Abraham",
                        "A ver si das alguna en el aro",
                        "Dartman",
                        "Patri Comaneci",
                        "Goooobiii!",
                        "Donde esta la verde?"};
const int xBall[] = { 7,6,5,4,3,2,1,2,3,4,5,6,7,8,9,9,9,9,9,9,9,9,9,9,9,
                      9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
                      7,7,6,6,5,5,4,4,3,3,2,2,2,2,9,9,9,9,9,9,9,9,9,9,9,
                      9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
                      7,7,6,6,5,5,4,4,3,3,2,2,3,3,4,4,5,5,6,6,9,9,9,9,9,
                      9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
                      7,7,6,6,5,5,4,4,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
                      9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
                      5,5,5,5,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9};
const int yBall[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,
                      9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
                      4,4,4,4,4,4,4,4,5,5,6,6,7,7,9,9,9,9,9,9,9,9,9,9,9,
                      9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
                      0,0,0,0,1,1,1,1,2,2,3,3,4,4,5,5,6,6,7,7,9,9,9,9,9,
                      9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
                      3,3,2,2,1,1,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
                      9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
                      0,0,0,0,1,1,1,1,2,2,2,2,3,3,4,4,5,5,6,6,7,7,9,9,9};

const int androidios[] {
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,1,0,0,
  0,1,1,0,1,1,1,0,
  1,0,1,0,1,1,1,1,
  1,1,1,0,1,1,1,0,
  1,0,1,0,1,1,1,1,
  0,1,1,0,1,1,1,0,
  0,0,0,0,0,1,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,1,1,1,1,1,1,1,
  0,1,0,0,1,0,0,0,
  0,1,0,0,1,1,0,0,
  0,1,0,0,1,0,1,0,
  0,0,1,1,0,0,0,1,
  0,0,0,0,0,0,0,0,
  0,0,0,0,1,1,1,0,
  0,0,0,1,0,0,0,1,
  0,0,0,1,0,0,0,1,
  0,0,0,1,0,0,0,1,
  0,0,0,0,1,1,1,0,
  0,0,0,0,0,0,0,0,
  0,0,0,1,0,0,0,1,
  0,1,0,1,1,1,1,1,
  0,0,0,0,0,0,0,1,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,1,1,1,0,0,
  0,0,1,1,1,1,1,1,
  0,0,1,1,1,1,1,1,
  0,1,1,1,1,1,1,0,
  1,0,1,1,1,1,1,1,
  0,0,1,1,1,1,1,1,
  0,0,0,1,0,0,1,0,
  0,0,0,0,0,0,0,0
};

const int wait = 100;
const int waitChar = 50;
const int waitBasket = 3;
const unsigned long messageWait = 60000;
const int spacer = 1;
const int width = 5 + spacer;
const int pinRandom = A0;
const int length = 8;

Max72xxPanel matrix = Max72xxPanel(D6, 1, 1);

int x[length], y[length];
int ptr, nextPtr;
unsigned long previousMillis = 0; 
int phrasesShowed = 0;
boolean flip = false;

void setup() {
  //configure matrix
  matrix.setIntensity(4);
  matrix.setRotation(1);
  
  // reset all variables
  for ( ptr = 0; ptr < length; ptr++ ) {
    x[ptr] =  8 / 2;
    y[ptr] =  8 / 2;
  }
  nextPtr = 0;

  randomSeed(analogRead(pinRandom)); // initialize random generator

  //animation intro
  showAndroidios();

}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > messageWait) {
    //show random message every messageWait miliseconds
    previousMillis = currentMillis;   
    if (phrasesShowed < waitBasket) {    
      scrollText(random(1, sizeof(phrases) / sizeof(String)));
      phrasesShowed++;
    } else {
      if (flip) {
        showBasketAnimation();
      } else {
        showAndroidios();
      }
      flip = !flip;
      phrasesShowed = 0;
    }
  } else {
    //snake animation
    showSnake();
  }
}

void showSnake() {
    ptr = nextPtr;
    nextPtr = next(ptr);
  
    matrix.drawPixel(x[ptr], y[ptr], HIGH); // draw the head of the snake
    matrix.write(); // send bitmap to display
  
    delay(wait);
  
    if ( ! occupied(nextPtr) ) {
      matrix.drawPixel(x[nextPtr], y[nextPtr], LOW); // remove the tail of the snake
    }
  
    for ( int attempt = 0; attempt < 10; attempt++ ) {
  
      // jump at random one step up, down, left, or right
      switch ( random(4) ) {
      case 0: x[nextPtr] = constrain(x[ptr] + 1, 0, matrix.width() - 1); y[nextPtr] = y[ptr]; break;
      case 1: x[nextPtr] = constrain(x[ptr] - 1, 0, matrix.width() - 1); y[nextPtr] = y[ptr]; break;
      case 2: y[nextPtr] = constrain(y[ptr] + 1, 0, matrix.height() - 1); x[nextPtr] = x[ptr]; break;
      case 3: y[nextPtr] = constrain(y[ptr] - 1, 0, matrix.height() - 1); x[nextPtr] = x[ptr]; break;
      }
  
      if ( ! occupied(nextPtr) ) {
        break; // the spot is empty, break out the for loop
      }
    }
}

boolean occupied(int ptrA) {
  for ( int ptrB = 0 ; ptrB < length; ptrB++ ) {
    if ( ptrA != ptrB ) {
      if ( equal(ptrA, ptrB) ) {
        return true;
      }
    }
  }

  return false;
}

int next(int ptr) {
  return (ptr + 1) % length;
}

boolean equal(int ptrA, int ptrB) {
  return x[ptrA] == x[ptrB] && y[ptrA] == y[ptrB];
}

void scrollText(int phrase) {
  String tape = phrases[phrase];
  
  for (int i = 0; i < width * tape.length() + matrix.width() - 1 - spacer; i++) {
 
      matrix.fillScreen(LOW);
 
      int letter = i / width;
      int x = (matrix.width() - 1) - i % width;
      int y = (matrix.height() - 8) / 2; // center the text vertically
 
      while (x + width - spacer >= 0 && letter >= 0) {
         if (letter < tape.length()) {
            matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);
         }
 
         letter--;
         x -= width;
      }
      matrix.write(); // send bitmap to display
 
      delay(waitChar);
   }
   matrix.fillScreen(LOW);

}

void showBasketAnimation() {
  showBallAnimation();
  scrollText(0);
  showPlayerAnimation();
}

void showBallAnimation() {
  for (int i = 0; i < 225; i++) {
      matrix.fillScreen(LOW);  
          
      //basket
      matrix.drawLine(0,0,0,4,HIGH);
      matrix.drawLine(0,3,2,3,HIGH);   
         
      if (i<200) {
        //small ball
        matrix.drawPixel(xBall[i],yBall[i],HIGH);
      } else {
        //big ball
        matrix.drawRect(xBall[i],yBall[i],2,2,HIGH);
      }
      
      matrix.write();
      delay(40);
   }
   matrix.fillScreen(LOW);
}

void showPlayerAnimation() {
  for (int i = 0; i<2; i++) {
    for (int j = 0; j<4; j++) {
      matrix.fillScreen(LOW);  
          
      //head and body
      matrix.drawRect(2,0,4,2,HIGH);
      matrix.drawRect(3,0,2,6,HIGH);
        
      for (int k = 0; k < 16; k++) {
        if (j==0 || j==2) {
          //arms
          matrix.drawLine(1,2,2,3,HIGH);
          matrix.drawLine(5,3,6,2,HIGH);        
          //legs
          matrix.drawLine(2,6,2,7,HIGH);
          matrix.drawLine(5,6,5,7,HIGH);
        } else {
          //arms
          matrix.drawLine(1,4,2,3,HIGH);
          matrix.drawLine(5,3,6,4,HIGH);
          //legs
          if (j==1) {
            matrix.drawLine(2,5,2,6,HIGH);
            matrix.drawLine(5,6,5,7,HIGH);
          } else {
            matrix.drawLine(2,6,2,7,HIGH);
            matrix.drawLine(5,5,5,6,HIGH);
          }        
        }
        
        matrix.write();
        delay(40); 
        
      }
    }
  }
  matrix.fillScreen(LOW);
}

void showAndroidios() {
  int mLength = (sizeof(androidios) / sizeof(int))/8;
  for (int i = 0; i<=(mLength-8); i++) {
    matrix.fillScreen(LOW);
    int temp[64];
    for (int j = 0; j<64; j++) {      
        temp[j] = androidios[(i*8)+j];      
    }    
    for (int m = 0; m<8; m++) {
      for (int n = 0; n<8; n++) {
        if(temp[(8*m)+n] == 1) {
          matrix.drawPixel(m,n, HIGH);  
        }
      }
    }
    matrix.write();
    if (i == 0) {
      delay(2000);
    } else {
      delay(250);
    }
  } 
  delay(2000);   
  scrollText(1);
}

