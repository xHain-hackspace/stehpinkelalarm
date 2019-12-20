#define BUZZER_PIN 2
#define PHOTO_SENSOR_IN 3
#define BLINK_DELAY 200
#define ALARM_THRESHOLD (5000/BLINK_DELAY) //in ms



// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PHOTO_SENSOR_IN, INPUT_PULLUP);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(BUZZER_PIN, LOW); 
  
}

boolean led_state=false;
int     sensor_blocked;

// the loop function runs over and over again forever
void loop() {
  delay(BLINK_DELAY);
  
  if (digitalRead(PHOTO_SENSOR_IN)) {//sensor is blocked
    
    sensor_blocked++;//increase counter for blocked time

    //if blocked for long enough switch on buzzer
    if (sensor_blocked>=ALARM_THRESHOLD) digitalWrite(BUZZER_PIN, HIGH);
    
    //toggle led
    if (led_state==true) led_state= false;
    else led_state=true;
    digitalWrite(LED_BUILTIN,led_state);
    
    
  } else{//sensor is not blocked
    sensor_blocked=0;
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(BUZZER_PIN, LOW); 
  }
}
