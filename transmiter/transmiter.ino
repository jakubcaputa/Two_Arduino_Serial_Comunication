
#define cr_pin 9

void setup() {
  Serial.begin(1200);  /* Define baud rate for serial communication */
  tone(cr_pin, 38000);  /* For modulation at 38kHz */
  
  
  
}


void loop() {
    
    int counter=0;
    bool err = 0;
    String data_str = "";
    bool data[8] = {1,1,1,1,1,1,0,0};
    for (int i=0; i<8;i++)
    {
        if (data[i]==true)
            counter++;
    }
    if (counter %2 ==0)
        err = 0;
    else
        err = 1;
    
    //cout << err << endl;
    bool packet[9] = {data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],err};
    
    for (int i=0;i<9;i++)
    {
        if (packet[i] == true)
            data_str = data_str +"1";
        else
            data_str = data_str +"0";
    
    }
    
    //char mystr[5]= "Hello";
    //Serial.write(mystr,5);
    Serial.println(data_str);
    delay(1000);
 
}
