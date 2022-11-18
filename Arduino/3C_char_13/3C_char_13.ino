char arr[6] = {'h', 'e', 'l', 'l', 'o'};

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    Serial.print(arr[i]);
  }
}
void loop() {}