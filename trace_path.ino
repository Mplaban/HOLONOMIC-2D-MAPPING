void path()
{
  cont=true;
  if (cx_cord == P[i][0] && cy_cord != P[i][1])
  {
    Serial.print("FD");
    x_count = 0;
    y_count = 0;
    
    m = P[i][1] - cy_cord;
    while (0 =< y_count && y_count < m * 1690)
    {
      Serial.print("M=\t");Serial.print(m);
      Serial.print("ycount= \t");
      Serial.println(y_count);
      s1 =  sf * (-0.35 * 0 + 0.35 * 150 + 0.25 * 0);
      s2 =  sf * (-0.35 * 0 + -0.35 * 150 + 0.25 * 0);
      s3 =  sf * (0.35 * 0 + -0.35 * 150 + 0.25 * 0);
      s4 =  sf * (0.35 * 0 + 0.35 * 150 + 0.25 * 0);

      dir1 = s1 >= 0 ? 0 : 1;
      dir2 = s2 >= 0 ? 0 : 1;
      dir3 = s3 >= 0 ? 1 : 0;
      dir4 = s4 >= 0 ? 0 : 1;

      digitalWrite(d1, dir1);
      digitalWrite(d2, dir2);
      digitalWrite(d3, dir3);
      digitalWrite(d4, dir4);

      analogWrite(m1, abs(s1));
      analogWrite(m2, abs(s2));
      analogWrite(m3, abs(s3));
      analogWrite(m4, abs(s4));
    }

    analogWrite(m1, 0);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, 0);
    cy_cord = P[i][1];
    m = 0;
    i++;
  }
  else if (cx_cord != P[i][0] && cy_cord == P[i][1])
  {
    x_count = 0;
    y_count = 0;
    m = P[i][0] - cx_cord;
    while (0 =< x_count && x_count< m * 1690)
    {
      Serial.print("M=\t");Serial.print(m);
      Serial.print(" xcount= \t");
      Serial.println(x_count);
      s1 =  sf * (-0.35 * 150 + 0.35 * 0 + 0.25 * 0);
      s2 =  sf * (-0.35 * 150 + -0.35 * 0 + 0.25 * 0);
      s3 =  sf * (0.35 * 150 + -0.35 * 0 + 0.25 * 0);
      s4 =  sf * (0.35 * 150 + 0.35 * 0 + 0.25 * 0);


      dir1 = s1 >= 0 ? 0 : 1;
      dir2 = s2 >= 0 ? 0 : 1;
      dir3 = s3 >= 0 ? 1 : 0;
      dir4 =  s4 >= 0 ? 0 : 1;

      digitalWrite(d1, dir1);
      digitalWrite(d2, dir2);
      digitalWrite(d3, dir3);
      digitalWrite(d4, dir4);

      analogWrite(m1, abs(s1));
      analogWrite(m2, abs(s2));
      analogWrite(m3, abs(s3));
      analogWrite(m4, abs(s4));

    }
    analogWrite(m1, 0);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, 0);
    cx_cord = P[i][1];
    m = 0;
    i++;
  }
}

