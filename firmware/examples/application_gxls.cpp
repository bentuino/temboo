#include "application.h"
#include "Temboo/Temboo.h"

/* 
Copy the three #define values from the TembooAccount.h file you generated on 
Teboo's web site or include the file in your Spark Cloud IDE

The same TembooAccount.h file settings can be used for all Temboo SDK sketches.  
Keeping your account information in a separate file means you can share the 
main .ino file without worrying that you forgot to delete your credentials.
*/
#define TEMBOO_ACCOUNT "<your account name>"  // Your Temboo account name 
#define TEMBOO_APP_KEY_NAME "<temboo app key name>"  // Your Temboo app key name
#define TEMBOO_APP_KEY "<temboo app key>"  // Your Temboo app key

void runAppendRow(int sensorValue);

TCPClient client;

// The number of times to trigger the action if the condition is met.
// We limit this so you won't use all of your Temboo calls while testing.
int maxCalls = 10;

// The number of times this Choreo has been run so far in this sketch.
int calls = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  
  // For debugging, wait until the serial console is connected.
  delay(4000);
  //while(!Serial.available());
  
  Serial.println("Setup started...");
  delay(5000);
  // Initialize pins
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);
  Serial.println("Setup complete.\n");
}

void loop() {
  int sensorValue = analogRead(A0);
  
  Serial.println("Sensor: " + String(sensorValue));
  
  if (sensorValue != 0) {
    if (calls < maxCalls) {
      Serial.println("\nTriggered! Calling /Library/Google/Spreadsheets/AppendRow...");
  
      runAppendRow(sensorValue);
      //digitalWrite(6, HIGH);
      calls++;
    } else {
      Serial.println("\nTriggered! Skipping the action to save Temboo calls during testing.");
      Serial.println("You can adjust or remove the calls/maxCalls if() statement to change this behavior.\n");
    }
  }
  delay(2500);
}

void runAppendRow(int sensorValue) {
  TembooChoreo AppendRowChoreo(client);

  // Set Temboo account credentials
  AppendRowChoreo.setAccountName(TEMBOO_ACCOUNT);
  AppendRowChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
  AppendRowChoreo.setAppKey(TEMBOO_APP_KEY);

  // Set profile to use for execution
  AppendRowChoreo.setProfile("GXLSSoil");

  String sensorValueStr = (String)analogRead(A0);
  Serial.println("Sensor: " + sensorValueStr);
  AppendRowChoreo.addInput("RowData", sensorValueStr);
  // Set Choreo inputs
  //AppendRowChoreo.addInput("RowData", String(sensorValue));

  
  // Identify the Choreo to run
  AppendRowChoreo.setChoreo("/Library/Google/Spreadsheets/AppendRow");

  // Run the Choreo
  unsigned int returnCode = AppendRowChoreo.run();

  // A return code of zero means everything worked
  if (returnCode == 0) {
    Serial.println("Done!\n");
  } else {
    // A non-zero return code means there was an error
    // Read and print the error message
    while (AppendRowChoreo.available()) {
      char c = AppendRowChoreo.read();
      Serial.print(c);
    }
    Serial.println();
  }
  
  AppendRowChoreo.close();
}
