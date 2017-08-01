//Primeiro codigo desenvolvido para o ESP8266-12 
//utilizando a IDE do Arduino 1.8.1

//Faz a leitura analogica de um LDR conectado a porta A0 do ESP
// Quando o valor for menor que 800 ele liga o led ligado a porta digital 2 do ESP
// Caso contrario apaga o LED

/*Desenvolvido por: Stella Azevedo Marques*/

int ledPin = 2; //Led no pino 7 /define a porta 7 como saída
 Serial.begin(9600); //Inicia a comunicação serial
}
 
void loop() {
 ///ler o valor do LDR
 ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
 
 //se o valor lido for maior que 500, liga o led
 if (ldrValor>= 800) digitalWrite(ledPin,HIGH);
 // senão, apaga o led
 else digitalWrite(ledPin,LOW);
 
 //imprime o valor lido do LDR no monitor serial
 Serial.println(ldrValor);
 delay(100);
}
