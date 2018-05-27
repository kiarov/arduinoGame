int myStr[6] = {1,2,3,4,5,6};
int i;

void setup(){
  Serial.begin(9600);
}

void loop() {
  for (i = 0; i < myStr; i++){
    Serial.print(i, DEC);
    Serial.print(" = ");
    Serial.print(myStr[i]);
    Serial.println();
  }
  delay(5000); // slow down the program
}
