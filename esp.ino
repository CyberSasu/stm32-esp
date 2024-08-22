void setup() {
  Serial.begin(115200);  // Initialize hardware serial with the same baud rate as STM32
  Serial.println("ESP Ready");
}

void loop() {
  // Check if data is available from STM32
  if (Serial.available()) {
    String data = Serial.readString();  // Read the incoming data
    Serial.println("Received: " + data);

    // Echo back to STM32
    Serial.println("Acknowledged: " + data);
  }
  delay(1000);  // Add some delay for stability
}
