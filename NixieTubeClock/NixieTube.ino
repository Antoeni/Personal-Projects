#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>  

#define NT1A 2
#define NT1B 3
#define NT1C 4
#define NT1D 5

#define NT2A 14
#define NT2B 15
#define NT2C 16 
#define NT2D 17

#define NT3A 10
#define NT3B 11
#define NT3C 12
#define NT3D 13

#define NT4A 6
#define NT4B 7
#define NT4C 8
#define NT4D 9

int hrLft;
int hrRght;
int minLft;
int minRght;
int hrs;
int mins;


int A[4] = {NT1A, NT2A, NT3A, NT4A};
int B[4] = {NT1B, NT2B, NT3B, NT4B};
int C[4] = {NT1C, NT2C, NT3C, NT4C};
int D[4] = {NT1D, NT2D, NT3D, NT4D};
void TimeSet(int digit, int time){//This portion of the code is coming from GreatScott's youtube video
  switch(time){//The switch statement will check for the number that we got from the RTC module 
    case 0:
    digitalWrite(A[digit], LOW);
    digitalWrite(B[digit], LOW);
    digitalWrite(C[digit], LOW);
    digitalWrite(D[digit], LOW);
    break;
    case 1:
    digitalWrite(A[digit], HIGH);
    digitalWrite(B[digit], LOW);
    digitalWrite(C[digit], LOW);
    digitalWrite(D[digit], LOW);
    break;
    case 2:
    digitalWrite(A[digit], LOW);
    digitalWrite(B[digit], HIGH);
    digitalWrite(C[digit], LOW);
    digitalWrite(D[digit], LOW);
    break;
    case 3:
    digitalWrite(A[digit], HIGH);
    digitalWrite(B[digit], HIGH);
    digitalWrite(C[digit], LOW);
    digitalWrite(D[digit], LOW);
    break;
    case 4:
    digitalWrite(A[digit], LOW);
    digitalWrite(B[digit], LOW);
    digitalWrite(C[digit], HIGH);
    digitalWrite(D[digit], LOW);
    break;
    case 5:
    digitalWrite(A[digit], HIGH);
    digitalWrite(B[digit], LOW);
    digitalWrite(C[digit], HIGH);
    digitalWrite(D[digit], LOW);
    break;
    case 6:
    digitalWrite(A[digit], LOW);
    digitalWrite(B[digit], HIGH);
    digitalWrite(C[digit], HIGH);
    digitalWrite(D[digit], LOW);
    break;
    case 7:
    digitalWrite(A[digit], HIGH);
    digitalWrite(B[digit], HIGH);
    digitalWrite(C[digit], HIGH);
    digitalWrite(D[digit], LOW);
    break;
    case 8:
    digitalWrite(A[digit], LOW);
    digitalWrite(B[digit], LOW);
    digitalWrite(C[digit], LOW);
    digitalWrite(D[digit], HIGH);
    break;
    case 9:
    digitalWrite(A[digit], HIGH);
    digitalWrite(B[digit], LOW);
    digitalWrite(C[digit], LOW);
    digitalWrite(D[digit], HIGH);
    break;
  }

}

void setup() {
  //Nixie Tube 1
  pinMode(NT1A, OUTPUT);
  pinMode(NT1B, OUTPUT);
  pinMode(NT1C, OUTPUT);
  pinMode(NT1D, OUTPUT);

  //Nixie Tube 2
  pinMode(NT2A, OUTPUT);
  pinMode(NT2B, OUTPUT);
  pinMode(NT2C, OUTPUT);
  pinMode(NT2D, OUTPUT);

  //Nixie Tube 3
  pinMode(NT3A, OUTPUT);
  pinMode(NT3B, OUTPUT);
  pinMode(NT3C, OUTPUT);
  pinMode(NT3D, OUTPUT);

  //Nixie Tube 4
  pinMode(NT4A, OUTPUT);
  pinMode(NT4B, OUTPUT);
  pinMode(NT4C, OUTPUT);
  pinMode(NT4D, OUTPUT);
}

void loop() {
  tmElements_t tm;
  if (RTC.read(tm)) {
    hrs = tm.Hour%12; //Changes 24 hour formatting to 12 hour formatting
    
    //In the event that 24(12Am) or 12(12PM) is modulated by 12, it would display zero 
    //so I added in a condition to change it to 12
    if(hrs == 0){
      hrs = 12;
    }
    mins = tm.Minute;
    //This will get the individual numbers of the hours and the minutes, which is again from GreatScott!
    hrLft = (hrs/10)%10;
    hrRght = hrs%10;
    minLft = (mins/10)%10;
    minRght = mins%10;
    //Then we will just set the number we want to the nixie tube
    TimeSet(3, hrLft);
    TimeSet(2, hrRght);
    TimeSet(1, minLft);
    TimeSet(0, minRght);
  } 
  delay(1000);
}
