const int led=13;
const int reed=7;

float radius=20; // 자전거 반지름
float circle=(2*radius*3.14)/100; // 바퀴둘레
float velocity=0; // 자전거 속도
float ontime=0; // 스위치 켜질 때 시간
float offtime=0; // 스위치 꺼질 때 시간
float cycletime=0; // 리드스위치가 인식이 안될때~될때 시간
int count=0;
boolean temp=0;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(reed, INPUT);
}

void loop(){
  boolean check = digitalRead(reed);
  
  if(check == 1 && temp == 0){  
    ontime = micros();  
    temp = 1;  
  }
  
  else if(check == 0 && temp == 1 && count > 5){
     
    offtime = micros();  
      
    cycletime = (offtime - ontime)/100000;
    Serial.println(cycletime,4);
   
    velocity = (circle / cycletime) * 3.6; 
    temp = 0; 
    count = 0; 
  }

  
  if(check == 1){  
    count++;
    if(count > 150){
      velocity = 0;
    }
  }
}


