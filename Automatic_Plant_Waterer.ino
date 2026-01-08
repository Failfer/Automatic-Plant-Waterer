const int relayInputPin = 4; //digital pin  to activate relay and begin watering

//The relay I use is a low activation relay, our pump is powered by NO not NC. (NC stands for normally closed and NO for normally open)
//if your is relay high relay swap the activate and deactivate relay functions. For this reason my relayed electricty is being connected by  the NC terminal of the relay not the NO. 
//Im using the Tongling  5VDC JQC 3FF relay (blue one)

void setup() {
  pinMode(relayInputPin, OUTPUT);

  //4 seconds before relay first activates
  deactivate_relay();
  delay(4000);



  // put your setup code here, to run once:

}

void loop() {

  
  deactivate_relay();
  delay(15000);
  activate_relay();
  delay(500);



  // put your main code here, to run repeatedly:

}


//the water pump is connected to the relays NO not NC terminal due to the relay being low activation (swap if yours is high activation) (or flip the activate and deactivate function your choice bro-cha-cho)
void activate_relay(){ //simple method but makes it more readable to name it
  digitalWrite(relayInputPin, LOW);
}

void deactivate_relay(){  //simple method but makes it more readable to name it
  digitalWrite(relayInputPin, HIGH);
}
