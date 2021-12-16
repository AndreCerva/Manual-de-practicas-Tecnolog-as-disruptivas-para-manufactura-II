import processing.serial.*;
//lf es el caracter de retorno de carro, que en ASCII es 10
int lf = 10;
// El puerto serie 
Serial myPort;
void setup() {
// Lista todos los puertos serie
println(Serial.list());
// OJO: Elige el puerto donde tengas conectado Arduino.
// Cambia el "0" de Serial.list()[0] por el orden que
// tu puerto ocupe en la lista (0, 1, 2,...).
// Si no lo tienes claro qué puerto ocupa Arduino mira
// en el IDE Arduino en "Herramientas" mira el puerto que esté seleccionado.
//Fíjate que tenemos la velocidad del puerto a la misma que pusimos en Arduino
myPort = new Serial(this, Serial.list()[0], 9600);
}
void draw() {
while (myPort.available() > 0) {
String lectura = myPort.readStringUntil(lf);
if (lectura != null) {
println(lectura);
//IMPORTANTE! cambia andres por tu nombre o lo que utilizases anteriormente
loadStrings("https://dweet.io/dweet/for/andresce?"+lectura);

}

}
}
