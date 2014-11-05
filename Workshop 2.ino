int switchPin = 8; 
int ledPin = 13; 
boolean lastButton = LOW; 
boolean currentButton = LOW; 
boolean ledOn = false; // boolean values store either 1 or 0, HIGH or LOW, true or false

void setup()
{
  pinMode(switchPin,INPUT); 
  pinMode(ledPin,OUTPUT);
}

boolean debounce (boolean last)
{
  boolean current = digitalRead(switchPin);
  if(last != current) // Only bother changing if the button state has changed different to the state of the light
  {
    delay(5); // delaying here accounts for the bouncing by making sure the button is fully stable before updating
    current = digitalRead(switchPin); 
  }
  return current; 
}

void loop()
{
  currentButton = debounce(lastButton);  // add debounce to our loop
  if(lastButton == LOW && currentButton == HIGH) // if difference, shift LED state variable
  {
    ledOn = !ledOn;
  }

    lastButton = currentButton;
    digitalWrite(ledPin,ledOn); // write LED state variable to the LED pin.
}
