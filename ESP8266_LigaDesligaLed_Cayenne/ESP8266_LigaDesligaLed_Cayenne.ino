/*Deve se criar uma conta no https://cayenne.mydevices.com/ 
  Vai em Add new..
  Depois em Devices/widget
    Microcontrollers -> Generic ESP8266 -> Configura o controlador
  Depois em Devices/widget
    Button -> Configura o botão com canal = 1 e Digital(0/1) em choose unit, clica em Add widget
  Salva o codigo no ESP8266-12 e abre o Terminal Serial .. Pronto!
  Agora você pode ligar e desligar leds pelo Cayenne
*/
//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h>



char ssid[] = "Nome da rede";
char wifiPassword[] = "Senha da rede";


char username[] = "MQTT USERNAME";
char password[] = "MQTT PASSWORD:";
char clientID[] = "CLIENT ID:";

int led = 2; //Led no pino 2

void setup() {
  pinMode(led,OUTPUT); //define a porta 2 como saída
  Serial.begin(9600); //Inicia a comunicação serial
	Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
	Cayenne.loop();
  //Cayenne.virtualWrite(0, analogRead(ldrValor));
  //Cayenne.virtualWrite(2, analogRead(ldrValor));
  delay(500);
}

//Default function for processing actuator commands from the Cayenne Dashboard.
//You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
	CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
  int i = getValue.asInt();
  digitalWrite(led,i);
}



