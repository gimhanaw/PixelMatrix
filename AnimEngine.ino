
byte mainarray[LED_Rows][LED_Columns][3]; // Animating Frame
byte a8x25[LED_Rows][LED_Columns][3];     // Startup Frame
byte tmpArray[LED_Rows][LED_Columns][3];  // intermidiate temp frame data


byte tmpRow[LED_Columns][3]; // used when moving up or down
byte tmpColumn[LED_Rows][3]; // used when moving left or right

bool ColorGradient = false; 
 
 const byte ColorGrad_1[18][3] = {  255,   0,   0,
                                    255,  80,   0,
                                    255, 160,   0,
                                    255, 255,   0,
                                    160, 255,   0,
                                     80, 255,   0,
                                      0, 255,   0,
                                      0, 255,  80,
                                      0, 255, 160,
                                      0, 255, 255,
                                      0, 160, 255,
                                      0,  80, 255,
                                      0,   0, 255,
                                     80,   0, 255,
                                    160,   0, 255,
                                    255,   0, 255,
                                    255,   0, 160,
                                    255,   0,  80  };



void clearmainarray() {
  for (byte z1 = 0; z1 < LED_Rows; z1++) {
    for (byte z2 = 0; z2 < LED_Columns; z2++) {
      for (byte z3 = 0; z3 < 3; z3++) {
        (mainarray[z1][z2][z3]) = 0;
      }
    }
  }
}

void cleara8x25() {
  for (byte z1 = 0; z1 < LED_Rows; z1++) {
    for (byte z2 = 0; z2 < LED_Columns; z2++) {
      for (byte z3 = 0; z3 < 3; z3++) {
        a8x25[z1][z2][z3] = 0;
      }
    }
  }
}




void StartupFrame_FlipUpsideDown()
{

   for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        for (byte z3 = 0; z3 < 3; z3++) {
          tmpArray[z1][z2][z3] = a8x25[z1][z2][z3];
        }
      }
   }

   for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        for (byte z3 = 0; z3 < 3; z3++) {
          a8x25[LED_Rows - 1 - z1][z2][z3] = tmpArray[z1][z2][z3];
        }
      }
   }
}

void StartupFrame_FlipLeftRight()
{
  // a8x25 Startup Frame Data
  for (byte z1 = 0; z1 < LED_Rows; z1++) {
    for (byte z2 = 0; z2 < LED_Columns; z2++) {
      for (byte z3 = 0; z3 < 3; z3++) {
        tmpArray[z1][z2][z3] = 0;
      }
    }
  }

   for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        for (byte z3 = 0; z3 < 3; z3++) {
          tmpArray[z1][z2][z3] = a8x25[z1][z2][z3];
        }
      }
   }

   for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        for (byte z3 = 0; z3 < 3; z3++) {
          a8x25[z1][LED_Columns - 1 - z2][z3] = tmpArray[z1][z2][z3];
          //mainarray[z1][LED_Columns - 1 - z2][z3] = tmpArray[z1][z2][z3];
        }
      }
   }
}

void StartupFrame_ChangeColor(byte startR, byte startG, byte startB, byte endR, byte endG, byte endB )
{
    for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        if ( a8x25[z1][z2][0] == startR && a8x25[z1][z2][1] == startG && a8x25[z1][z2][2] == startB)
        {
            a8x25[z1][z2][0] = endR;
            a8x25[z1][z2][1] = endG;
            a8x25[z1][z2][2] = endB;
        }
      }
   }
}

void AnimatedFrame_ChangeColor(byte startR, byte startG, byte startB, byte endR, byte endG, byte endB )
{
    for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        if ( mainarray[z1][z2][0] == startR && mainarray[z1][z2][1] == startG && mainarray[z1][z2][2] == startB)
        {
            mainarray[z1][z2][0] = endR;
            mainarray[z1][z2][1] = endG;
            mainarray[z1][z2][2] = endB;
        }
      }
   }
}

void display() 
{
  int r, g, b;
  
    // Input Offset will be considered here
  int col;
  for (byte j = 0; j < LED_Columns; j++) 
  {
    col = j + DATA_IN_OFFSET;
    if (col >= LED_Columns)
        col = col - LED_Columns;
    if (j % 2 == 0) {
      for (byte i = 0; i < LED_Rows; i++) 
      {
        r = mainarray[i][col][0];
        g = mainarray[i][col][1];
        b = mainarray[i][col][2];
        leds[i + (j * LED_Rows)] = CRGB(r, g, b);
        
        /*if (leds[i + (j * LED_Rows)])
        {
           
          
          if (r>=0 && b<255)
          {
            g = 0;
            b++; 
            r--;
          }
          else if ( b>=0 && g<255 )
          {
            r = 0;
            g++;
            b--;
          }
          else if (g>=0 && r<255 )
          {
            b = 0;
            r++;
            g--;
          }
          mainarray[i][col][0] = r;
          mainarray[i][col][1] = g;
          mainarray[i][col][2] = b;
        }*/
      }
    }
    else {
      for (byte i = 0; i < LED_Rows; i++) 
      {
        r = mainarray[(LED_Rows-1) - i][col][0];
        g = mainarray[(LED_Rows-1) - i][col][1];
        b = mainarray[(LED_Rows-1) - i][col][2];
        leds[i + (j * LED_Rows)] = CRGB(r, g, b);
        /*if (leds[i + (j * LED_Rows)])
        {
          r++; g++; b++;
          if (r > 255) r = 0;
          if (g > 255) g = 0;
          if (b > 255) b = 0;
          if (r>=0 && b<255)
          {
            //g = 0;
            b++; 
            r--;
          }
          else if ( b>=0 && g<255 )
          {
            //r = 0;
            g++;
            b--;
          }
          else if (g>=0 && r<255 )
          {
            //b = 0;
            r++;
            g--;
          }
          mainarray[(LED_Rows-1) - i][col][0] = r;
          mainarray[(LED_Rows-1) - i][col][1] = g;
          mainarray[(LED_Rows-1) - i][col][2] = b;
        }*/
      }
    }
  }
  FastLED.show();
}


void SetNextColor(byte r, byte g, byte b)
{
    if (r == 0)
    {
        if (g == 0)
        {
            b = b - 20;
        }
        else
        {
            b = b - 20;
            if (b < 0) b = 0;
            g = g + 20;
            if (g > 255) g = 255;
        }
    }
    else if (g == 0)
    {
      
    }
    else if (b == 0)
    {
      
    }
}

void up(bool Circulate) {
  //Keep 0th row (i.e. top)
  if (Circulate)
    KeepRow(0);
  
  //Move Up
  for (byte i = 0; i < (LED_Rows - 1); i++) {
    for (byte j = 0; j < LED_Columns; j++) {
      mainarray[i][j][0] = mainarray[i + 1][j][0];
      mainarray[i][j][1] = mainarray[i + 1][j][1];
      mainarray[i][j][2] = mainarray[i + 1][j][2];
    }
  }
  //Assign 0th to bottom
  if (Circulate)
    AssignRow(LED_Rows - 1);
}

void KeepRow(byte fromRow)
{
    for (byte j = 0; j < LED_Columns; j++) {
      tmpRow[j][0] = mainarray[fromRow][j][0];
      tmpRow[j][1] = mainarray[fromRow][j][1];
      tmpRow[j][2] = mainarray[fromRow][j][2];
    }
}

void AssignRow(byte toRow)
{
    for (byte j = 0; j < LED_Columns; j++) {
      mainarray[toRow][j][0] = tmpRow[j][0];
      mainarray[toRow][j][1] = tmpRow[j][1];
      mainarray[toRow][j][2] = tmpRow[j][2];
    }
}

void KeepColumn(byte fromColumn)
{
    for (byte i = 0; i < LED_Rows; i++) {
      tmpColumn[i][0] = mainarray[i][fromColumn][0];
      tmpColumn[i][1] = mainarray[i][fromColumn][1];
      tmpColumn[i][2] = mainarray[i][fromColumn][2];
    }
}

void AssignColumn(byte toColumn)
{
    for (byte i = 0; i < LED_Rows; i++) {
      mainarray[i][toColumn][0] = tmpColumn[i][0];
      mainarray[i][toColumn][1] = tmpColumn[i][1];
      mainarray[i][toColumn][2] = tmpColumn[i][2];
    }
}


void down(bool Circulate) {
  //Keep last row (i.e. bottom)
  if (Circulate)
    KeepRow(LED_Rows - 1);

  for (byte i = (LED_Rows-1); i > 0; i--) {
    for (byte j = 0; j < LED_Columns; j++) {
      mainarray[i][j][0] = mainarray[i - 1][j][0];
      mainarray[i][j][1] = mainarray[i - 1][j][1];
      mainarray[i][j][2] = mainarray[i - 1][j][2];
    }
  }

  //Assign kept row to top
  if (Circulate)
    AssignRow(0);

}


void moveleft(bool Circulate) 
{
  //keep leftmost column in memory
  if (Circulate)
    KeepColumn(0);
  
  //move
  for (byte j = 0; j < (LED_Columns-1); j++) {
    for (byte i = 0; i < LED_Rows; i++) {
      mainarray[i][j][0] = mainarray[i][j + 1][0];
      mainarray[i][j][1] = mainarray[i][j + 1][1];
      mainarray[i][j][2] = mainarray[i][j + 1][2];
    }
  }

  //replace rightmost column with memory
  if (Circulate)
    AssignColumn(LED_Columns - 1);
}



void moveright(bool Circulate) 
{
  //Keep rightmost column in memory
  if (Circulate)
    KeepColumn(LED_Columns - 1);

  //move
  for (byte j = (LED_Columns-1); j > 0; j--) {
    for (byte i = 0; i < LED_Rows; i++) {
      mainarray[i][j][0] = mainarray[i][j - 1][0];
      mainarray[i][j][1] = mainarray[i][j - 1][1];
      mainarray[i][j][2] = mainarray[i][j - 1][2];
    }
  }

  //restore leftmost column with memory
  if (Circulate)
    AssignColumn(0);
}


void setbottomrow(byte x) {
  for (byte i = 0; i < LED_Columns; i++) {
    mainarray[(LED_Rows-1)][i][0] = a8x25[x][i][0];
    mainarray[(LED_Rows-1)][i][1] = a8x25[x][i][1];
    mainarray[(LED_Rows-1)][i][2] = a8x25[x][i][2];
  }
}



void settoprow(byte x) {
  for (byte i = 0; i < LED_Columns; i++) {
    mainarray[0][i][0] = a8x25[LED_Rows-1-x][i][0];
    mainarray[0][i][1] = a8x25[LED_Rows-1-x][i][1];
    mainarray[0][i][2] = a8x25[LED_Rows-1-x][i][2];
  }
}


void setleftcolumn(byte x) {
  for (byte i = 0; i < LED_Rows; i++) {
    mainarray[i][0][0] = a8x25[i][(LED_Columns-1) - x][0];
    mainarray[i][0][1] = a8x25[i][(LED_Columns-1) - x][1];
    mainarray[i][0][2] = a8x25[i][(LED_Columns-1) - x][2];
  }
}

void setrightcolumn(byte x) {
  for (byte i = 0; i < LED_Rows; i++) {
    mainarray[i][(LED_Columns-1)][0] = a8x25[i][x][0];
    mainarray[i][(LED_Columns-1)][1] = a8x25[i][x][1];
    mainarray[i][(LED_Columns-1)][2] = a8x25[i][x][2];
  }
}


void ClearRow(int r)
{
  for (byte c = 0 ; c < LED_Columns; c++)
  {
    mainarray[r][c][0] = 0;
    mainarray[r][c][1] = 0;
    mainarray[r][c][2] = 0;
  }
}

void ClearColumn(int c)
{
    for (byte r = 0; r < LED_Rows; r++) 
    {
      mainarray[r][c][0] = 0;
      mainarray[r][c][1] = 0;
      mainarray[r][c][2] = 0;
    }  
}


void DrawColumn(int col)
{
    for (int i = 0; i < LED_Rows; i++) {
      mainarray[i][col][0] = a8x25[i][col][0];
      mainarray[i][col][1] = a8x25[i][col][1];
      mainarray[i][col][2] = a8x25[i][col][2];
    }
}

void Read_LEDMatrixStudio_Data(byte ledarray[])
{
    cleara8x25();

    int pos = 0;
    for (byte i =  0; i < LED_Rows; i++) 
    {
        for (byte j = 0; j < LED_Columns; j++) 
        {
            pos = (i * LED_Columns + j) * 3;
            a8x25[i][j][0] = pgm_read_word_near(ledarray + pos);
            a8x25[i][j][1] = pgm_read_word_near(ledarray + pos+1);
            a8x25[i][j][2] = pgm_read_word_near(ledarray + pos+2);
        }
    }
    if (Data_Input == Inside)
      StartupFrame_FlipUpsideDown();
}
