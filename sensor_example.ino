int moistPin = 0;
int moistVal = 0;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  moistVal = analogRead(moistPin);
  Serial.println(moistVal);
  int percent = 2.718282 * 2.718282 * (.008985 * moistVal + 0.207762); 
  Serial.print(percent);
  Serial.println("% Moisture ");
 
  }