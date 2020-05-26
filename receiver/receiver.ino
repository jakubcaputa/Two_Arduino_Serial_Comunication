// przarzysta liczba dwojek xor daje o
int counter = 0;
char data_str[9];
String napis ="qwertyyut";
void setup() {
  Serial.begin(1200);/* Define baud rate for serial communication */
  
}

void loop() {
  
  
if(Serial.available())  /* If data is available on serial port */
  {
    
    //Serial.readBytes(data_str,5);
    //Serial.println(data_str);
    //Serial.print(char(Serial.read()));
    data_str[counter] = char(Serial.read());
    napis[counter]= data_str[counter];
    
    //String data_str = String(Serial.read());
    //Serial.print("Read data");
    //Serial.print(data_str);
    //Serial.println(data);
    counter++;
    
    if(counter == 9)
  {
    Serial.println(napis);
    String data_str = napis;
    counter = 0;
    char err='0';
    
    for (int i=0;i<sizeof(data_str);i++)
    {
        char temp = data_str[i];
        if (temp == '1')
            counter++;
    }
    if (counter %2 ==0)
        err = '0';
    else
        err = '1';
    
    if (data_str[8] == err)        
        Serial.println("Correct transimsion");
    if (data_str[8] != err)   
        Serial.println("Error transimsion");
  }
  }
  
  
  //Serial.print(data_str);
  
    
}
