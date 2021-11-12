#define SSEG_CA 1
#define inp A0
#define inn A1
uint8_t num = 0;
uint8_t seven_seg_lut[10][7] = {
 //LSB to HSB
 //a, b, c, d, e, f, g
  {1, 1, 1, 1, 1, 1, 0}, //0
  {0, 1, 1, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1}, //2
  {1, 1, 1, 1, 0, 0, 1}, //3
  {0, 1, 1, 0, 0, 1, 1}, //4
  {1, 0, 1, 1, 0, 1, 1}, //5
  {1, 0, 1, 1, 1, 1, 1}, //6
  {1, 1, 1, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1}, //8
  {1, 1, 1, 1, 0, 1, 1}  //9
};
void init_sseg_ca()//Initialization for common cathod 7-seg
{
  for(uint8_t i = 0; i < 7; ++i) pinMode(i, OUTPUT);
}
void data_sseg_ca(uint8_t num)
{
  for(uint8_t j = 0; j < 7; ++j)
  {
    if(seven_seg_lut[num][j]) digitalWrite(j, LOW);
    else digitalWrite(j, HIGH);
  }
}
void setup() {
  delay(1000);
  if(SSEG_CA) init_sseg_ca();
  pinMode(inp, INPUT_PULLUP);
  pinMode(inn, INPUT_PULLUP);
}

void loop() {
  delay(100);
  if(!digitalRead(inp))
  {
    if(num == 9) num = 0;
    else num++;
  }
  else if(!digitalRead(inn))
  {
    if(num == 0) num = 9;
    else num--;
  }
  data_sseg_ca(num);
}
