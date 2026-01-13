const int relayInputPin = 4; //digital pin  to activate relay and begin watering

const int soilMoistureSensorPin = A3; 
int moistureValue = 0; //stores the moisture level
int maxDrynessAllowed = 700; // arbitrary value max value for dryness is 1023 for 5v and around 752 experimentally for 3.3v  (exclusive moisture check)
//for maxDrynessAllowed a value closer to as dry as it can get allows more drying out between waterings while a closer to max value means more consistiently wet roots
//certain plants have prefrences for both and your soil type will also affect this (i.e. sand drys out faster than clay)

//The relay I use is a low activation relay, our pump is powered by NO not NC. (NC stands for normally closed and NO for normally open)
//if your is relay high relay swap the activate and deactivate relay functions. For this reason my relayed electricty is being connected by  the NC terminal of the relay not the NO. 
//Im using the Tongling  5VDC JQC 3FF relay (blue one)

void setup() {
  Serial.begin(9600); 
  pinMode(relayInputPin, OUTPUT);
  

  //4 seconds before relay first activates
  deactivate_relay();
  delay(4000);



  // put your setup code here, to run once:

}

void loop() {

  //reciving moisture section input section
  moistureValue = analogRead(soilMoistureSensorPin); //every loop check moisture (later maybe make one that runs every once in a while and then when spraying water check every frame again)
  Serial.print("Moister Level: ");
  Serial.println(moistureValue); // for moisture level lower number = more moist and higher number means dryer. Water conducts electricity between the two prongs, thus more water = less resitance = smaller number



  //water pump  dryness check and activation section
  if(moistureValue > maxDrynessAllowed){
    water_plant();
    delay(45000); //arbtrary wait 45 seconds to make sure sensors have time to adapt and let water settle in, adjust to your needs for the project
    Serial.println("Watering Plant");
  }
}


//turns on the water pump for 1.5 seconds and then deactivates itself. Numbers are arbitrary, since analog input seems to have large delay I only water a bit to avoid flooding
void water_plant(){ 
  activate_relay();
  delay(1500);
  deactivate_relay();
}

//the water pump is connected to the relays NO not NC terminal due to the relay being low activation (swap if yours is high activation) (or flip the activate and deactivate function your choice bro-cha-cho)
void activate_relay(){ //simple method but makes it more readable to name it
  digitalWrite(relayInputPin, LOW);
}

void deactivate_relay(){  //simple method but makes it more readable to name it
  digitalWrite(relayInputPin, HIGH);
}
