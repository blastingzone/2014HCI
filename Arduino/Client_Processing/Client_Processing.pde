import processing.serial.*;     // import the Processing serial library
Serial myArduinoPort;
Serial XBeePort;
char val;

int previousTime;

boolean isReady = true;

PImage img_on;
PImage img_off;
int red = 153;
int green = 151;
int blue = 125;
int speed = 5;

void setup() {
  size(640, 360);
  
  img_on = loadImage("on_image.jpg");
  img_off = loadImage("off_image.jpg");
  
  println(Serial.list());

  //Choose usb adapter
  // warning!! must check portNumber of Xbee and Arduino are correct
  String XbeeName = Serial.list()[0];
  String ArduinoName = Serial.list()[1];
  println("Xbee portName:" + XbeeName);
  println("Arduino portName:" + ArduinoName);
  //myPort = new Serial(this, portName, 9600);
 
  myArduinoPort = new Serial(this, ArduinoName, 9600);
  XBeePort = new Serial(this, XbeeName, 9600);
}

void draw() {
  
  background(red, green, blue);
  
  if ( mousePressed )
  {
    println("Remote Fire!");
    // fire!
    XBeePort.write('F');
    isReady = false;
    previousTime = millis();
  } 
  
  // true == catapult on
  if (isReady)
  {
    image(img_off, 50, 50);
  }
  else
  {
    image(img_on, 50, 50);
  }
  
  // if arduino send signal
  if ( myArduinoPort.available() > 0 && isReady) {
    String buffer = myArduinoPort.readStringUntil('\n');
    println("Sensor Data : " + buffer);    
    if (buffer != null) 
    {
     String [] values = split(buffer,'\n');
     int value = parseInt(values[0].trim());
     println("Sensor Value : " + value);
     if (value == 1)
     {
       red = 255;
       green = 213;
       blue = 106;     
     }
     // fire!!
    XBeePort.write('F');
    isReady = false;
    previousTime = millis();
    }
  } 
  
  // wait for initialize
  if (isReady == false)
  {
    int passedTime = millis() - previousTime;
    if (passedTime > 4000)
    {
      isReady = true;
      println("Ready");
    }
  }
}

