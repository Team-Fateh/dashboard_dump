// -41531 tare zero factor
//13900 cal factor

void loadcellInit() {
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");
  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
  // long zero_factor = -41531; //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
}

void loadcellCheck() {
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  load_cell_val = scale.get_units();
  // Serial.print(" kg"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  // Serial.print(" calibration_factor: ");
  // Serial.print(calibration_factor);
  // Serial.println();


}