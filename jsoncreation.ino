void call_json()
{
  DynamicJsonBuffer  jsonBuffer(500);

  JsonObject& root = jsonBuffer.createObject();
  root["sensor"] = "Accelerometer";
  root["time"] = 1351824120;
  root["minX"] = 123.3243;root["maxX"] = 112.3243;root["avgX"] = 132.3243;
  root["minY"] = 343.212;root["maxY"] = 333.3243;root["avgY"] = 332.3243;
  root["minZ"] = 689.212;root["maxz"] = 634.3243;root["avgZ"] = 632.3243;
  root["temp"]=55.34;
  Serial.println();
  root.printTo(Serial);
  Serial.println();

  root.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
  Serial.println(JSONmessageBuffer);
}

