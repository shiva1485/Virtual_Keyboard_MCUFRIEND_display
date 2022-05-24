
void getxy (int x, int y)
{
  Serial.print("(");
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.println(")");
  Serial.println("");
}

bool touch (void)
{
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  digitalWrite(YP, HIGH);   //because TFT control pins
  digitalWrite(XM, HIGH);

  if ((p.z > MINPRESSURE ) && (p.z < MAXPRESSURE))
  {
    pixel_x = map(p.x, TS_LEFT, TS_RT, 0, 320);
    pixel_y = map(p.y, TS_TOP, TS_BOT, 0, 480);
  }

  //getxy();
  return ((p.z > MINPRESSURE ) && (p.z < MAXPRESSURE));
}


void textprint(float x , float y, int s, int c)
{
  tft.setCursor(x, y);
  tft.setTextSize(s);
  tft.setTextColor(color[c]);
}

void genkeys (int x, int y) //generate keys of keyboard.
{
  //Serial.println("started drawing the keys");
  int i, j, k, rep;//for doing the counts
  rep = 0;


  tft.fillRect(x - 8, y - 8, 308 + 5, 119 + 5, color[1]); // creating the background
  tft.drawRect(x - 8, y - 8, 308 + 5, 119 + 5, color[7]); // drawing the outline of the keyboard

  for (j = 0; j < 10; j++)//prints the rows
  {
    for (i = 0; i < 4; i++)//prints the columns
    {
      tft.drawRect(x - 5, y - 5, 20, 20, color[0]); //drawing the boxes around the letters

      //Storing the keys positions
      xco[rep] = x;
      yco[rep] = y;
      rep++;

      //drawing the keys
      textprint(x, y, 2, 3);
      tft.print(keys[i][j]);
      y = y + 33;//spacing between the keys from y-persepective.
    }
    x = x + 32;//spacing between the keys from y-persepective.
    y = k;
  }
  Serial.println("finished drawing the keys");
}


void scankeys()//scaning the touched key.
{
  if (touch())//when touched on the screen
  {
    //if (pixel_x >  layx && pixel_x < (layx + 306) && pixel_y > layy && pixel_y < (layy + 122))

    delay(200);
    int x = pixel_x, y = pixel_y, remx, remy;

    Serial.println("touch position:");
    getxy(x, y);

    for (int i = 0; i < 40; i++)//compare xy check function
    {
      if (x > xco[i] && x < (xco[i] + 20) && y > yco[i] && y < (yco[i] + 20))//checking the range of the xy positions
      {
        remx = xco[i];//returning the x positions of the cooresponding key pressed
        remy = yco[i];//same goes here

        Serial.println("remx:");
        getxy(remx, remy);

        for (int xsearch = 0; xsearch < 10; xsearch++)
        {
          if (remx == actualx[xsearch])
          {
            xindex = xsearch;
            break;
          }
        }
        for (int ysearch = 0; ysearch < 4; ysearch++)
        {
          if (remy == actualy[ysearch])
          {
            yindex = ysearch;
            break;
          }
        }
        con = true;
        break;
      }
    }
  }
}
