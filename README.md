# PetCare Monitor – Sistema Inteligente de Bem-Estar Animal

## Descrição do funcionamento:

O projeto consiste em um sistema embarcado utilizando Arduino, desenvolvido para 
monitorar o bem-estar de animais domésticos, especialmente cães, através da 
análise de dois fatores principais: temperatura corporal e movimentação.
O sistema realiza a leitura contínua da temperatura por meio de um sensor 
analógico e detecta a presença de movimento com um sensor digital. Com base 
nesses dados, ele classifica o estado do animal em níveis

- Normal 🟢
- Alerta 🟡
- Perigo 🔴

A resposta do sistema é feita por meio de:

- Um LED RGB, que indica visualmente o estado do animal (verde, amarelo ou 
vermelho)
- Um buzzer, que emite alertas sonoros em situações críticas

Além disso, o sistema possui uma lógica inteligente que considera o tempo em que 
o animal permanece sem se movimentar, aumentando o nível de alerta caso isso 
ocorra junto com uma temperatura anormal.


# Recursos utilizados

## Componentes do projeto:

 Arduino Uno R3
 Sensor de temperatura TMP36
 Sensor de movimento PIR
 LED RGB
 Resistores (220Ω)
 Buzzer (Piezo)
 Protoboard
 Jumpers (fios de conexão

<img width="1519" height="732" alt="image" src="https://github.com/user-attachments/assets/e7bf531a-a64a-4504-b707-7fcfb35152be" />
