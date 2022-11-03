/*
 * HC-SR04 example sketch
 *
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 * by Isaac100
 */

/*const int trigPin1 = 9;
const int echoPin1 = 10;
*/const int trigPin2 = 5;
const int echoPin2 = 6;

float duration2, distance2, x_k_p, P_k_p, K_k, angle;
float x_k = 15;
float P_k = 1;
float Q = 1e-5;
float R = 2.92e-4;



void setup() {
  /*pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  */pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  /*digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;
  /*Serial.print("Distance 1: ");
  Serial.println(distance1);
  */

  /*delayMicroseconds(100);
*/
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*.0343)/2;
  /*Serial.print("Distance 2: ");
  Serial.println(distance2);
  */

  /*Serial.println(distance1+distance2);  
  distance = (distance1 + 28 - distance2)/2;

  for(int i = 0; i <= 4; i++){

    if((i*5.6<distance2)&&(distance2<(i+1)*5.6)){
      angle = (i+1)*30;
      break;
    }
      
  }*/

  x_k_p = x_k;
  P_k_p = P_k + Q;
  
  K_k = P_k_p/(P_k_p + R);
  x_k = x_k_p + K_k*(distance2 - x_k_p);
  P_k = (1 - K_k)*P_k_p;



String dataToSend1 = String(x_k);
Serial.println(dataToSend1);

/*String dataToSend2 = String(x_k);
Serial.println(2);
    Serial.print(30);
    Serial.print(" ");
    Serial.print(0);
    Serial.print(" ");
    Serial.print(distance2);
    Serial.print(distance2);
    Serial.print(" ");
    Serial.println(x_k);
*/  
delay(40);
  

}
