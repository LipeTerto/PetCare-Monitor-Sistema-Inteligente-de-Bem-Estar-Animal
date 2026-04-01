int sensorTemp = A0;
int sensorMov = 2;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int buzzer = 8;

float temperatura = 0;

unsigned long tempoSemMovimento = 0;
unsigned long limiteTempo = 10000;

void setup()
{
  pinMode(sensorMov, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int leitura = analogRead(sensorTemp);
  float tensao = leitura * (5.0 / 1024.0);
  temperatura = (tensao - 0.5) * 100.0;

  int movimento = digitalRead(sensorMov);

  if (movimento == LOW) {
    tempoSemMovimento += 1000;
  } else {
    tempoSemMovimento = 0;
  }


  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" | Movimento: ");
  Serial.println(movimento);


  if (temperatura > 41 || temperatura < 37.5) {
    setColor(255, 0, 0);
    tone(buzzer, 3000);

    Serial.println("🚨 PERIGO: TEMPERATURA CRITICA!");

  }

  else if (temperatura > 39.5) {
    setColor(255, 255, 0);
    noTone(buzzer);

    Serial.println("⚠️ ALERTA: POSSIVEL FEBRE");
  }

  else {
    setColor(0, 255, 0);
    noTone(buzzer);

    Serial.println("✅ NORMAL");
  }

  if ((temperatura > 39.5 || temperatura < 37.5) && tempoSemMovimento > limiteTempo) {
    tone(buzzer, 4000);
    Serial.println("🚨 ALERTA CRITICO: PET PARADO E COM TEMPERATURA ANORMAL!");
  }

  delay(1000);
}

void setColor(int r, int g, int b)
{
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}
