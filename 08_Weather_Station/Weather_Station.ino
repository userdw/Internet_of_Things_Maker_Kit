float temp;

void setup() {
  Serial.begin(57600);
};

void loop () {
  temp = analogRead(A0)*1000/1023.0;
  temp = temp - 500;
  temp = temp / 10;
  Serial.println(temp);
  delay(500);
};
