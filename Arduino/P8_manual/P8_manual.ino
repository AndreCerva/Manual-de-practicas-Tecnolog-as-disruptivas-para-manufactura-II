int speakerPin = 12;// Introducimos la variable por donde saldrá nuestra señal digital hasta el zumbador
int numTones = 10;// Definimos una variable con el número de tonos que va a reproducir
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};// mid C C# D D# E F F# G G# A //Entre mas bajo más grave y entre más grande más agudo
// Arriba se muestran las equivalencias entre frecuencias y Notas de la escala natural, no están todas declaradas pero existen.
void setup()
{
// Generamos un bucle que recorra nuestro vector. Este será el encargado de introducir una determinada frecuencia al zumbador cada vez, conforme hayamos declarado el vector de tonos.
for (int i = 0; i < numTones; i++)
{
tone(speakerPin, tones[i]);//Mandar al pin que tenemos conectado el zumbador la frecuencia a la que queremos que zumbe
delay(500);//Tiempo de espera de medio segundo
}
noTone(speakerPin);//deja de generar la onda cuadrada que en principio estaba emitiéndose por una ejecución previa de tone()
}
void loop()
{
}
