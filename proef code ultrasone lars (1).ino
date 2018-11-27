/*
 * PIN AANSLUITINGEN
 *
 * Vcc  --> 5V 4 als spranningsbron
 * Trig --> 5
 * Echo --> 6
 * GND  --> GND in 7
 */
int spanningsBron = 4;    // zet 4 als spanningsbron 
const int trigPin = 5;   // trigger pin
const int echoPin = 6;    // echo pin

float tijd;           // variabele voor tijdsduur als continue getal
float afstand;           // variabele voor afstand als continue getal  

void setup() {
  Serial.begin(9600);               // stel de seriële monitor in (plotten) 
  pinMode(trigPin, OUTPUT);         // stel de trigger pin in als uitvoer
  pinMode(echoPin, INPUT);          // stel de echo pin in als invoer
  pinMode(spanningsBron, OUTPUT);    // stel de spannning bron in als uitvoer. 
  digitalWrite(spanningsBron, HIGH); // zet spanningsbron aan 
}

void loop() {
  digitalWrite(trigPin, LOW);       // zet de trigPin op uit
  delayMicroseconds(2);             // wacht 2 microseconden zodat de trigPin ook daadwerkelijk uit is

  digitalWrite(trigPin, HIGH);      // zet de trigPin aan om ultrasoon geluid te zenden
  delayMicroseconds(10);            // wacht 10 microseconden
  digitalWrite(trigPin, LOW);       // set de trigPin uit om het zenden te stoppen

  tijd = pulseIn(echoPin, HIGH);     // vraag de tijdsduur op hoe lang het duurde voor er geluid werd ontvangen
                                         // Let op dat pulseIn het programma pauseert totdat er een signaal is ontvangen
                                         // standaard is de timeout 1 seconden. Dus het programma staat maximaal 1 seconde stil en geeft dus maximaal 1 seconde geen afstandswaardes
  afstand = (tijd * 0.0343) / 2;    // bereken de afstand aan de hand van de snelheid van het geluid
                                         
  Serial.print("Afstand: ");             // Toon het resultaat op de seriële monitor
  Serial.println(afstand);

  delay(100);                            // wacht 100ms tot een volgende meting
}
