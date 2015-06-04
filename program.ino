
void setup() {

  Serial.begin(9600); //Iniciar serial

}

void loop() {

  if(Serial.available()>=21){//Si han llegado datos
    for(int i=0;i<22;i++){//Muéstralos
      Serial.print(Serial.read(),HEX);
      Serial.print(",");
    }
    Serial.println();
   }
   else{
     Serial.println("aqui no hay na");//Dime que no ha llegado nada
   
   }
}


