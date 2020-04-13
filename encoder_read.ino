
void Count_X ()
{
  int A1state = digitalRead(enc1pinA);
  int B1state = digitalRead(enc1pinB);
  if (B1state == A1state)
    x_count--;
  else
    x_count++;
}
void Count_Y () {
  int A2state = digitalRead(enc2pinA);
  int B2state = digitalRead(enc2pinB);
  if (B2state == A2state)
    y_count--;
  else
    y_count++;
}
void Path_process () {
  if (x_count - lastx_count == val) {
    last_x = x_cord;
    x_cord++;
    lastx_count = x_count;
  }
  else if (x_count - lastx_count == -val) {
    last_x = x_cord;
    x_cord--;
    lastx_count = x_count;
  }
  if (y_count - lasty_count == val) {
    last_y = y_cord;
    y_cord++;
    lasty_count = y_count;
  }

  else if (y_count - lasty_count == -val) {
    last_y = y_cord;
    y_cord--;
    lasty_count = y_count;
  }

}
void Fill_matrix() {

  if ((x_cord != last_x && y_cord == last_y) || (x_cord == last_x && y_cord != last_y) || (x_cord != last_x && y_cord != last_y)) {
    P[k][0] = x_cord;
    P[k][1] = y_cord;
    if ( ((check_x != P[k][0]) && (check_y != P[k][1])) || ((check_x != P[k][0]) && (check_y == P[k][1])) || ((check_x == P[k][0]) && (check_y != P[k][1]))) {
      Serial.print("x-");
      //Serial.print('\t');
      Serial.print(P[k][0]);
      Serial.print('\t');
      Serial.print("y-");
      Serial.print(P[k][1]);
      Serial.println();
      flag = k;
      k++;
    }
    if(PS4.getButtonClick(TRIANGLE))
    Map[abs(y_cord)][abs(x_cord)] = 1;
    else {
    if (Map[abs(y_cord)][abs(x_cord)] == 7) {
    Map[abs(y_cord)][abs(x_cord)]=0;
    }
    check_x = P[flag][0]; 
    check_y = P[flag][1];
  }

}
}

void show_matrix () {
  Serial.println();
  Serial.print("path-map:");
  Serial.println();
  for ( int i = 0; i < 7; i++) {
    for ( int j = 0; j < 9; j++) {
      Serial.print(Map[i][j]);
      Serial.print('\t');
    }
    Serial.println();
  }
}
