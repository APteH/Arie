/*
I am almost 76 years old and started with Arduino about a 0.5 year ago.
So, if you think I made mistakes, please report them to me via prins.arie@gmail.com.
Any (positive) suggestion is very welcome

  
  This small piece of software serves a remote control and opens or closes your Somfy shutters at programmed times.
  The used remote control is a universal model that must first be programmed for use as a Sompy control.
  The circuit further consists of a timer clock and a processor ATMega386P-PU with a 16Mhz x-tal.
  Make sure that the contacts of the built-in switch of the clock are free of mains voltage. If not, then Pfffft!

  The timer clock contacts are connected to the input pin 11 with a pull-up resistor, and -3.2V (Gnd).
  The two outputs, 12 and 13 respectively, are directly connected to the pushbutton contacts of the remote control.
  Pull-up resistors are not required because they are already installed in the remote control at the factory.
  The timer, switches the outputs at the programmed times, with a pulse of 1 second to -3.2V (Gnd), to simulate the pressing of a button.
  
  Arie Prins 01-10-2018
*/
const int ClockPin = 11;
const int OutputPin1 = 12;
const int OutputPin2 = 13;
int ClockState = LOW;
int OldClockState = LOW;

void setup()
{
  pinMode(ClockPin, INPUT);
  pinMode(OutputPin1, OUTPUT);
  pinMode(OutputPin2, OUTPUT);
 }
void loop()
{
  ClockState = digitalRead(ClockPin);
  if (ClockState != OldClockState)
  {
    if (ClockState == HIGH)
    {
      digitalWrite(OutputPin1, LOW);
      delay (1000);
      digitalWrite(OutputPin1, HIGH);
    }
    else
    {
      digitalWrite(OutputPin2, LOW);
      delay (1000);
      digitalWrite(OutputPin2, HIGH);
    }
  }
  OldClockState = ClockState;
  delay(10);
}
