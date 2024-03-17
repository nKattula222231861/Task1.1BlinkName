//Creates variable to represent state of button. 0 = unpressed, 1 = pressed
int button;

void setup()
{
  //Sets up serial connection
  Serial.begin(9600);
  
  //Setts up LED pin and Digital Pin 8 to register the button state
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  
}

void loop()
{
  //Sets variable to current state of button
  button = digitalRead(8);
  
  //If statement that triggers if the button is pressed
  if (button == 1)
  {   
    
    //While statement to "Catch" the button input when it is pressed for the first time.
    while (button == 1)
    {
    	button = digitalRead(8);
    }
    
    //While statement where the morse code is placed.
    while (button == 0)
    {
      //First letter N (Long - Short). Represnted by a for loop that checks the current state of the button and which flash the program is up to.
      for (int i = 0; i <= 1; i++)
      {
        //If a button input is ever detected, breaks out of the loop.
        if (button == 1)
        {
          break;
        }
        
        if (i == 0 && button == 0)
        {
          longBlink();
        }

        else if (i == 1 && button == 0)
        {
          shortBlink();
        }

      }

      //If a button input was picked up, breaks the while loop and stops flashing the led.
      if (button == 1)
      {
        break;
      }

      delay (2000);

      //Second letter I (Short - Short)
      for (int i = 0; i <= 1; i++)
      {
        if (button == 1)
        {
          break;
        }
        
        if (button == 0)
        {
          shortBlink();
        }

      }
    
      if (button == 1)
      {
        break;
      }

      delay(2000);

      //Third letter C (Long - Short - Long - Short)
      for (int i = 0; i <= 3; i++)
      {
        if (button == 1)
        {
          break;
        }
        
        if (i == 0 && button == 0)
        {
          longBlink();
        }

        else if (i == 1 && button == 0)
        {
          shortBlink();
        }

        else if (i == 2 && button == 0)
        {
          longBlink();
        }

        else if (i == 3 && button == 0)
        {
          shortBlink();
        }

      }

      if (button == 1)
      {
        break;
      }

      delay(2000);
    
      //Fourth letter K (Long - Short - Long)
      for (int i = 0; i <= 2; i++)
      {
        if (button == 1)
        {
          break;
        }
        
        if (i == 0 && button == 0)
        {
          longBlink();
        }

        else if (i == 1 && button == 0)
        {
          shortBlink();
        }

        else if (i == 2 && button == 0)
        {
          longBlink();
        }

      }
      
      delay(2000);
      
      //Breaks the loop now that the name has been signaled.
      break;
    }   
  }
}

//Function to represent a short blink and check the button state.
void shortBlink()
{
  button = digitalRead(8);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}

//Same as above function, only for a longer blink.
void longBlink()
{
  button = digitalRead(8);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}