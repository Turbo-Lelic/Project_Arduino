const int row[8] =
{
  13, 8, 17, 10, 5, 16, 4, 14
};

const int col[8] =
{
  9, 3, 2, 12, 15, 11, 7, 6
};

int pixels[8][8];

int x = 5;
int y = 5;


void setup()
{
  for (int thisPin = 0; thisPin < 8; thisPin++)
  {
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    digitalWrite(col[thisPin], HIGH);
  }

  for (int x = 0; x < 8; x++)
  {
    for (int y = 0; y < 8; y++)
    {
      pixels[x][y] = HIGH;
    }
  }
}

void loop()
{
  pixels[0][0] = LOW;
  pixels[1][1] = LOW;
  pixels[2][2] = LOW;
  pixels[3][3] = LOW;
  pixels[4][4] = LOW;
  pixels[5][5] = LOW;
  pixels[6][6] = LOW;
  pixels[7][7] = LOW;

  refreshScreen();
}

void refreshScreen()
{
  for (int thisRow = 0; thisRow < 8; thisRow++)
  {
    digitalWrite(row[thisRow], HIGH);
    for (int thisCol = 0; thisCol < 8; thisCol++)
    {
      int thisPixel = pixels[thisRow][thisCol];
      digitalWrite(col[thisCol], thisPixel);
      if (thisPixel == LOW)
      {
        digitalWrite(col[thisCol], HIGH);
      }
    }
    digitalWrite(row[thisRow], LOW);
  }
}
