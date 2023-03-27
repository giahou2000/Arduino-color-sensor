// Define some keywords so that we make our life easier (connect the sensor pins with the arduino's pins)
#define S0 8
#define S1 9
#define S2 12
#define S3 11
#define sensorOut 10

// Initialize the sensor's output values
int red = 0;
int green = 0;
int blue = 0;

// setup the arduino before running
void setup()
{
  // Begins serial communication
  // set data rate to 9600 bps for the communication between arduino board and pc
  Serial.begin(9600);

  // Setting the outputs and inputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 100%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
}

// the main function
void loop()
{
  // Let's read the red component using the red filters
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  red = pulseIn(sensorOut, digitalRead(sensorOut) == HIGH ? LOW : HIGH);
  // Let's read the blue component using the blue filters
  digitalWrite(S3, HIGH);
  blue = pulseIn(sensorOut, digitalRead(sensorOut) == HIGH ? LOW : HIGH);
  // Let's read the green component using the green filters
  digitalWrite(S2, HIGH);
  green = pulseIn(sensorOut, digitalRead(sensorOut) == HIGH ? LOW : HIGH);
 
  // Check at what color range we are in (RGB)
  if (red < blue && red < green && red < 20)
  {
   Serial.println(" Red Color");
  }

  else if (blue < red && blue < green)
  {
   Serial.println(" Blue Color");
  }

  else if (green < red && green < blue)
  {
   Serial.println(" Green Color");
  }
  delay(500);
 }