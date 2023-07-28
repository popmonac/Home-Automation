  // Use TinyGSM with SIM800 modem
  #include <TinyGsmClient.h>
  #include <BlynkSimpleTinyGSM.h>
  #include <LiquidCrystal.h>
  #define TINY_GSM_MODEM_SIM800  


  // Define Blynk Template ID, Name, and Authorization Token
  #define BLYNK_TEMPLATE_ID "**************"
  #define BLYNK_TEMPLATE_NAME "HOME AUTOMATION"
  #define BLYNK_AUTH_TOKEN "******************************"

  // Set the Serial as the Blynk print output
  #define BLYNK_PRINT Serial

  // Create a HardwareSerial object for the SIM800 GSM module
  HardwareSerial sim(2);
  TinyGsm modem(sim);

      // Define Blynk authorization token, APN, username, and password
      char auth[] = "******************************";
      char apn[]  = "web.gprs.mtnnigeria.net";
      char user[] = "";
      char pass[] = "";

      // Define point index and initialize the LCD display
      int pointIndex = 1; 
      LiquidCrystal lcd(22,21,2,4,23,19);

      // Create a BlynkTimer object to handle time-related tasks
      BlynkTimer timer;

      // Define pins for four relays
      #define Relay_1      27 
      #define Relay_2      14
      #define Relay_3      12   
      #define Relay_4      13   

      // Define Virtual Pins for four buttons on the Blynk app
      #define Button_VirtualPin_1    V1 
      #define Button_VirtualPin_2    V2
      #define Button_VirtualPin_3    V3 
      #define Button_VirtualPin_4    V4

      // Initialize button condition and push button state variables for each relay
      int buttonCondition_1 = 1;
      int pushButton1State = HIGH;

      int buttonCondition_2 = 1;
      int pushButton2State = HIGH;

      int buttonCondition_3 = 1;
      int pushButton3State = HIGH;

      int buttonCondition_4 = 1;
      int pushButton4State = HIGH;

      

// Function to control relay state based on button press
void relay_state(int relay) {
    // This function controls the state of the relays based on the relay number

    // Check which relay number is passed to the function using the switch statement
    switch(relay) {
      // For relay 1
      case 1: 
             // Check if buttonCondition_1 is equal to 0 (relay is currently off)
             if(buttonCondition_1 == 0) {
                digitalWrite(Relay_1, HIGH); // Turn on relay 1 by setting its pin to HIGH
                buttonCondition_1 = 1; // Update buttonCondition_1 to indicate relay is now on
             }
             else {
                digitalWrite(Relay_1, LOW); // Turn off relay 1 by setting its pin to LOW
                buttonCondition_1 = 0; // Update buttonCondition_1 to indicate relay is now off
             }
             delay(200); // Add a delay to debounce the relay switch
      break;

      // For relay 2
      case 2: 
             // Check if buttonCondition_2 is equal to 0 (relay is currently off)
             if(buttonCondition_2 == 0) {
                digitalWrite(Relay_2, HIGH); // Turn on relay 2 by setting its pin to HIGH
                buttonCondition_2 = 1; // Update buttonCondition_2 to indicate relay is now on
             }
             else {
                digitalWrite(Relay_2, LOW); // Turn off relay 2 by setting its pin to LOW
                buttonCondition_2 = 0; // Update buttonCondition_2 to indicate relay is now off
             }
             delay(200); // Add a delay to debounce the relay switch
      break;

      // For relay 3
      case 3: 
             // Check if buttonCondition_3 is equal to 0 (relay is currently off)
             if(buttonCondition_3 == 0) {
                digitalWrite(Relay_3, HIGH); // Turn on relay 3 by setting its pin to HIGH
                buttonCondition_3 = 1; // Update buttonCondition_3 to indicate relay is now on
             }
             else {
                digitalWrite(Relay_3, LOW); // Turn off relay 3 by setting its pin to LOW
                buttonCondition_3 = 0; // Update buttonCondition_3 to indicate relay is now off
             }
             delay(200); // Add a delay to debounce the relay switch
      break;

      // For relay 4
      case 4: 
             // Check if buttonCondition_4 is equal to 0 (relay is currently off)
             if(buttonCondition_4 == 0) {
                digitalWrite(Relay_4, HIGH); // Turn on relay 4 by setting its pin to HIGH
                buttonCondition_4 = 1; // Update buttonCondition_4 to indicate relay is now on
             }
             else {
                digitalWrite(Relay_4, LOW); // Turn off relay 4 by setting its pin to LOW
                buttonCondition_4 = 0; // Update buttonCondition_4 to indicate relay is now off
             }                       
             delay(200); // Add a delay to debounce the relay switch
      break;

      // If an invalid relay number is passed, do nothing
      default : break;      
    } 
}


// Blynk function to control the state of each relay through the Blynk app

// This function is triggered whenever the state of Button_VirtualPin_1 in the Blynk app changes
    BLYNK_WRITE(Button_VirtualPin_1) {
        // Store the state of Button_VirtualPin_1 in the variable buttonCondition_1
        buttonCondition_1 = param.asInt();
        
        // Set the Relay_1 pin HIGH or LOW based on the value of buttonCondition_1
        digitalWrite(Relay_1, buttonCondition_1);
        
        // Update the LCD display with the current state of Relay_1
        lcd.setCursor (0,0);
        lcd.print("PORT1=");
        lcd.setCursor (6,0);
        lcd.print(buttonCondition_1);             
    }

// This function is triggered whenever the state of Button_VirtualPin_2 in the Blynk app changes
    BLYNK_WRITE(Button_VirtualPin_2) {
        // Store the state of Button_VirtualPin_2 in the variable buttonCondition_2
        buttonCondition_2 = param.asInt();
        
        // Set the Relay_2 pin HIGH or LOW based on the value of buttonCondition_2
        digitalWrite(Relay_2, buttonCondition_2);
        
        // Update the LCD display with the current state of Relay_2
        lcd.setCursor (9,0);
        lcd.print("PORT2=");
        lcd.setCursor (15,0);
        lcd.print(buttonCondition_2); 
    }

// This function is triggered whenever the state of Button_VirtualPin_3 in the Blynk app changes
    BLYNK_WRITE(Button_VirtualPin_3) {
        // Store the state of Button_VirtualPin_3 in the variable buttonCondition_3
        buttonCondition_3 = param.asInt();
        
        // Set the Relay_3 pin HIGH or LOW based on the value of buttonCondition_3
        digitalWrite(Relay_3, buttonCondition_3);
        
        // Update the LCD display with the current state of Relay_3
        lcd.setCursor (0,1);
        lcd.print("PORT3=");
        lcd.setCursor (6,1);
        lcd.print(buttonCondition_3); 
    }

// This function is triggered whenever the state of Button_VirtualPin_4 in the Blynk app changes
    BLYNK_WRITE(Button_VirtualPin_4) {
        // Store the state of Button_VirtualPin_4 in the variable buttonCondition_4
        buttonCondition_4 = param.asInt();
        
        // Set the Relay_4 pin HIGH or LOW based on the value of buttonCondition_4
        digitalWrite(Relay_4, buttonCondition_4);
        
        // Update the LCD display with the current state of Relay_4
        lcd.setCursor (9,1);
        lcd.print("PORT4=");
        lcd.setCursor (15,1);
        lcd.print(buttonCondition_4); 
    }     


void checkBlynkStatus() { // This function is called every 3 seconds by SimpleTimer

        // Check if the Blynk app is currently connected to the server and store the result in 'isconnected'
        bool isconnected = Blynk.connected();

        // If the Blynk app is not connected to the server (isconnected == false), attempt to reconnect
        if (isconnected == false) {
          Blynk.begin(auth, modem, apn, user, pass); // Reconnect to the Blynk server using the provided authentication credentials
        }

        // If the Blynk app is connected to the server (isconnected == true), print "Connected" to the serial monitor
        if (isconnected == true) {
          Serial.println("Connected"); // Print "Connected" to the serial monitor
        }
    }


    void setup() { 
      // Initialize serial communication at a baud rate of 9600 for debugging purposes
      Serial.begin(9600);
      
      // Initialize the LCD with 16 columns and 2 rows
      lcd.begin(16, 2); 
      
      // Print the welcome message on the LCD display
      lcd.setCursor (0,0);
      lcd.print(" HOME AUTOMATION  ");
      lcd.setCursor (5,1);
      lcd.print("SYSTEM");  
      
      // Wait for 2 seconds to display the welcome message
      delay(2000);
      
      // Set relay pins as output and initialize them with buttonCondition variables
      pinMode(Relay_1, OUTPUT);
      digitalWrite(Relay_1, buttonCondition_1);

      pinMode(Relay_2, OUTPUT);
      digitalWrite(Relay_2, buttonCondition_2);

      pinMode(Relay_3, OUTPUT);
      digitalWrite(Relay_3, buttonCondition_3);

      pinMode(Relay_4, OUTPUT);
      digitalWrite(Relay_4, buttonCondition_4);

      // Initialize the SIM800 GSM module with a baud rate of 9600, data bits: 8, parity: None, stop bits: 1
      sim.begin(9600, SERIAL_8N1, 16, 17);
      
      // Begin Blynk with specified parameters (authentication, modem, APN, username, and password)
      Blynk.begin(auth, modem, apn, user, pass);
      
      // Set BlynkTimer interval to check Blynk server connection every 3 seconds
      timer.setInterval(3000L, checkBlynkStatus);
      
      // Wait for 2 seconds
      delay(2000);
      
      // Clear the LCD display to prepare for displaying real-time data
      lcd.clear(); 
      
      // Wait for 1 second
      delay(1000);
    }


void loop() {  
    // Run Blynk to oversee the communication and transmission with the Blynk server
       Blynk.run();
} 