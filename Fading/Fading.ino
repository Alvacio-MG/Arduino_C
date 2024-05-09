
int boton = 13;
int altavoz = 5; 
int led = 14;

int Si2 =1975;
int LaS2=1864;
int La2= 1760;
int SolS2=1661;
int Sol2=1567;
int FaS2=1479;
int Fa2= 1396;
int Mi2= 1318;
int ReS2=1244;
int Re2= 1174;
int DoS2=1108;
int Do2= 1046;

int Si = 987;
int LaS= 932;
int La = 880;
int SolS=830;
int Sol= 783;
int FaS= 739;
int Fa=  698;
int Mi=  659;
int ReS= 622;
int Re = 587;
int DoS =554;
int Do = 523;

int redonda=0;
int redondap=0;
int blanca= 0;
int blancap=0;
int negra=0;  
int negrap=0;
int corchea=0;
int corcheap =0;
int semicorchea=0;
int semicorcheap=0;

int bpm= 120;
void setup()
{  
  pinMode(altavoz,OUTPUT);
      negra= 60000/bpm; 
      negrap=negra*1.5;
      blanca= negra*2;
      blancap=blanca*1.5;
      redonda= negra*4;
      redondap= redonda*1.5;
      corchea= negra/2;
      corcheap=corchea*1.5;
      semicorchea= negra/4;
      semicorcheap=semicorchea*1.5;
}
 
void loop()
{
  int Eboton = digitalRead(boton);
  
  if (Eboton == HIGH)
  {
    musiquita();
  }
}

void musiquita(){
  
 tone(altavoz,Do,corchea);
 delay(corchea+50); 
 tone(altavoz,Do,corchea);
 delay(corchea+50);
  digitalWrite(led,HIGH);
 
 tone(altavoz,Re,negra);
 delay(negra+50);
 tone(altavoz,Do,negra);
 delay(negra+50);
 tone(altavoz,Fa,negra);
 delay(negra+50);
 digitalWrite(led,LOW);
 
 tone(altavoz,Mi,blanca);
 delay(blanca+50);
 tone(altavoz,Do,corchea);
 delay(corchea+50); 
 tone(altavoz,Do,corchea);
 delay(corchea+50);
  digitalWrite(led,HIGH);

 tone(altavoz,Re,negra);
 delay(negra+50);
 tone(altavoz,Do,negra);
 delay(negra+50);
 tone(altavoz,Sol,negra);
 delay(negra+50);
 digitalWrite(led,LOW);

 tone(altavoz,Fa,blanca);
 delay(blanca+50);
 tone(altavoz,Do,corchea);
 delay(corchea+50); 
 tone(altavoz,Do,corchea);
 delay(corchea+50);
  digitalWrite(led,HIGH);

  tone(altavoz,Do2,negra);
 delay(negra+50);
  tone(altavoz,La,negra);
 delay(negra+50);
 tone(altavoz,Fa,negra);
 delay(negra+50);
 digitalWrite(led,LOW);

  tone(altavoz,Mi,negra);
 delay(negra+50);
  tone(altavoz,Re,blanca);
 delay(blanca+50);
 digitalWrite(led,HIGH);

  tone(altavoz,LaS,corchea);
 delay(corchea+50);
 tone(altavoz,LaS,corchea);
 delay(corchea+50);
  tone(altavoz,La,negra);
 delay(negra+50);
  tone(altavoz,Fa,negra);
 delay(negra+50);
 digitalWrite(led,LOW);

 tone(altavoz,Sol,negra);
 delay(negra+50);
  tone(altavoz,Fa,blanca);
 delay(blanca+50); 
  digitalWrite(led,HIGH);
}
