
byte mainarrayL1[LED_Rows][LED_Columns][3]; // Animating Frame Layer 1 arAnimLayer1
byte mainarrayL2[LED_Rows][LED_Columns][3]; // Animating Frame Layer 2 (these 2 used only when layes are in action arAnimLayer2

byte a8x25L1[LED_Rows][LED_Columns][3]; // Startup Frame Layer 1 arStartLayer1
byte a8x25L2[LED_Rows][LED_Columns][3]; // Startup Frame Layer 2 (these 2 used only when layes are in action - arStartLayer2

//byte tmpArrayL1[LED_Rows][LED_Columns][3];  // intermidiate temp frame data Layer1
//byte tmpArrayL2[LED_Rows][LED_Columns][3];  // intermidiate temp frame data Layer2

/*
byte mainarray[LED_Rows][LED_Columns][3]; // Animating Frame
byte a8x25[LED_Rows][LED_Columns][3];     // Startup Frame
byte tmpArray[LED_Rows][LED_Columns][3];  // intermidiate temp frame data
*/

const byte arTransKey[] = {0,0,0};         // Transparent Key for Layers (Not used yet)


void LYclearmainarray(byte Layer) 
{
  for (byte z1 = 0; z1 < LED_Rows; z1++) {
    for (byte z2 = 0; z2 < LED_Columns; z2++) {
      for (byte z3 = 0; z3 < 3; z3++) 
      {
        if (Layer == 1)
          mainarrayL1[z1][z2][z3] = 0;
        else
          mainarrayL2[z1][z2][z3] = 0;
      }
    }
  }
}

void LYcleara8x25(byte Layer) 
{
  for (byte z1 = 0; z1 < LED_Rows; z1++) {
    for (byte z2 = 0; z2 < LED_Columns; z2++) {
      for (byte z3 = 0; z3 < 3; z3++) 
      {
        if (Layer == 1)
          a8x25L1[z1][z2][z3] = 0;
        else
          a8x25L2[z1][z2][z3] = 0;
      }
    }
  }
}




void LYStartupFrame_FlipUpsideDown(byte Layer)
{
    // Layer 1 or 2

   for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        for (byte z3 = 0; z3 < 3; z3++) 
        {
          if (Layer == 1)
            tmpArray[z1][z2][z3] = a8x25L1[z1][z2][z3];
          else
            tmpArray[z1][z2][z3] = a8x25L2[z1][z2][z3];
        }
      }
   }

   for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        for (byte z3 = 0; z3 < 3; z3++) 
        {
          if (Layer == 1)
            a8x25L1[LED_Rows - 1 - z1][z2][z3] = tmpArray[z1][z2][z3];
          else
            a8x25L2[LED_Rows - 1 - z1][z2][z3] = tmpArray[z1][z2][z3];
        }
      }
   }
}

void LYStartupFrame_FlipLeftRight(byte Layer)
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
        for (byte z3 = 0; z3 < 3; z3++) 
        {
          if (Layer == 1)
            tmpArray[z1][z2][z3] = a8x25L1[z1][z2][z3];
          else
            tmpArray[z1][z2][z3] = a8x25L2[z1][z2][z3];
        }
      }
   }

   for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        for (byte z3 = 0; z3 < 3; z3++) 
        {
          if (Layer == 1)
            a8x25L1[z1][LED_Columns - 1 - z2][z3] = tmpArray[z1][z2][z3];
          else
            a8x25L2[z1][LED_Columns - 1 - z2][z3] = tmpArray[z1][z2][z3];
        }
      }
   }
}

void LYStartupFrame_ChangeColor(byte Layer, byte startR, byte startG, byte startB, byte endR, byte endG, byte endB )
{
  //Wrong
    for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        if (Layer == 1)
        {
          if ( a8x25L1[z1][z2][0] == startR && a8x25L1[z1][z2][1] == startG && a8x25L1[z1][z2][2] == startB)
          {
            a8x25L1[z1][z2][0] = endR;
            a8x25L1[z1][z2][1] = endG;
            a8x25L1[z1][z2][2] = endB;
          }
        }
        else
        {
          if ( a8x25L2[z1][z2][0] == startR && a8x25L2[z1][z2][1] == startG && a8x25L2[z1][z2][2] == startB)
          {
            a8x25L2[z1][z2][0] = endR;
            a8x25L2[z1][z2][1] = endG;
            a8x25L2[z1][z2][2] = endB;
          }
        }
      }
   }
}

/*
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
*/

void LYup(byte Layer, bool Circulate) 
{
  //Keep 0th row (i.e. top)
  if (Circulate)
    LYKeepRow(Layer, 0);
  
  //Move Up
  for (byte i = 0; i < (LED_Rows - 1); i++) {
    for (byte j = 0; j < LED_Columns; j++) 
    {
      if (Layer == 1)
      {
        mainarrayL1[i][j][0] = mainarrayL1[i + 1][j][0];
        mainarrayL1[i][j][1] = mainarrayL1[i + 1][j][1];
        mainarrayL1[i][j][2] = mainarrayL1[i + 1][j][2];
      }
      else
      {
        mainarrayL2[i][j][0] = mainarrayL2[i + 1][j][0];
        mainarrayL2[i][j][1] = mainarrayL2[i + 1][j][1];
        mainarrayL2[i][j][2] = mainarrayL2[i + 1][j][2];
      }
    }
  }
  //Assign 0th to bottom
  if (Circulate)
    LYAssignRow(Layer, LED_Rows - 1);
}

void LYKeepRow(byte Layer, byte fromRow)
{
    for (byte j = 0; j < LED_Columns; j++) 
    {
      if (Layer == 1)
      {
        tmpRow[j][0] = mainarrayL1[fromRow][j][0];
        tmpRow[j][1] = mainarrayL1[fromRow][j][1];
        tmpRow[j][2] = mainarrayL1[fromRow][j][2];
      }
      else
      {
        tmpRow[j][0] = mainarrayL2[fromRow][j][0];
        tmpRow[j][1] = mainarrayL2[fromRow][j][1];
        tmpRow[j][2] = mainarrayL2[fromRow][j][2];
      }
    }
}

void LYAssignRow(byte Layer, byte toRow)
{
    for (byte j = 0; j < LED_Columns; j++) 
    {
      if (Layer == 1)
      {
        mainarrayL1[toRow][j][0] = tmpRow[j][0];
        mainarrayL1[toRow][j][1] = tmpRow[j][1];
        mainarrayL1[toRow][j][2] = tmpRow[j][2];
      }
      else
      {
        mainarrayL2[toRow][j][0] = tmpRow[j][0];
        mainarrayL2[toRow][j][1] = tmpRow[j][1];
        mainarrayL2[toRow][j][2] = tmpRow[j][2];
      }
    }
}

void LYKeepColumn(byte Layer, byte fromColumn)
{
    for (byte i = 0; i < LED_Rows; i++) 
    {
      if (Layer == 1)
      {
        tmpColumn[i][0] = mainarrayL1[i][fromColumn][0];
        tmpColumn[i][1] = mainarrayL1[i][fromColumn][1];
        tmpColumn[i][2] = mainarrayL1[i][fromColumn][2];
      }
      else
      {
        tmpColumn[i][0] = mainarrayL2[i][fromColumn][0];
        tmpColumn[i][1] = mainarrayL2[i][fromColumn][1];
        tmpColumn[i][2] = mainarrayL2[i][fromColumn][2];
      }
    }
}

void LYAssignColumn(byte Layer, byte toColumn)
{
    for (byte i = 0; i < LED_Rows; i++) 
    {
      if (Layer == 1)
      {
        mainarrayL1[i][toColumn][0] = tmpColumn[i][0];
        mainarrayL1[i][toColumn][1] = tmpColumn[i][1];
        mainarrayL1[i][toColumn][2] = tmpColumn[i][2];
      }
      else
      {
        mainarrayL2[i][toColumn][0] = tmpColumn[i][0];
        mainarrayL2[i][toColumn][1] = tmpColumn[i][1];
        mainarrayL2[i][toColumn][2] = tmpColumn[i][2];
      }
    }
}


void LYdown(byte Layer, bool Circulate) {
  //Keep last row (i.e. bottom)
  if (Circulate)
    LYKeepRow(Layer, LED_Rows - 1);

  for (byte i = (LED_Rows-1); i > 0; i--) {
    for (byte j = 0; j < LED_Columns; j++) 
    {
      if (Layer == 1)
      {
        mainarrayL1[i][j][0] = mainarrayL1[i - 1][j][0];
        mainarrayL1[i][j][1] = mainarrayL1[i - 1][j][1];
        mainarrayL1[i][j][2] = mainarrayL1[i - 1][j][2];
      }
      else
      {
        mainarrayL2[i][j][0] = mainarrayL2[i - 1][j][0];
        mainarrayL2[i][j][1] = mainarrayL2[i - 1][j][1];
        mainarrayL2[i][j][2] = mainarrayL2[i - 1][j][2];
      }
    }
  }

  //Assign kept row to top
  if (Circulate)
    LYAssignRow(Layer, 0);

}


void LYmoveleft(byte Layer, bool Circulate) 
{
  //keep leftmost column in memory
  if (Circulate)
    LYKeepColumn(Layer, 0);
  
  //move
  for (byte j = 0; j < (LED_Columns-1); j++) {
    for (byte i = 0; i < LED_Rows; i++) 
    {
      if (Layer == 1)
      {
        mainarrayL1[i][j][0] = mainarrayL1[i][j + 1][0];
        mainarrayL1[i][j][1] = mainarrayL1[i][j + 1][1];
        mainarrayL1[i][j][2] = mainarrayL1[i][j + 1][2];
      }
      else
      {
        mainarrayL2[i][j][0] = mainarrayL2[i][j + 1][0];
        mainarrayL2[i][j][1] = mainarrayL2[i][j + 1][1];
        mainarrayL2[i][j][2] = mainarrayL2[i][j + 1][2];
      }
    }
  }

  //replace rightmost column with memory
  if (Circulate)
    LYAssignColumn(Layer, LED_Columns - 1);
}



void LYmoveright(byte Layer, bool Circulate) 
{
  //Keep rightmost column in memory
  if (Circulate)
    LYKeepColumn(Layer, LED_Columns - 1);

  //move
  for (byte j = (LED_Columns-1); j > 0; j--) {
    for (byte i = 0; i < LED_Rows; i++) 
    {
      if (Layer == 1)
      {
        mainarrayL1[i][j][0] = mainarrayL1[i][j - 1][0];
        mainarrayL1[i][j][1] = mainarrayL1[i][j - 1][1];
        mainarrayL1[i][j][2] = mainarrayL1[i][j - 1][2];
      }
      else
      {
        mainarrayL2[i][j][0] = mainarrayL2[i][j - 1][0];
        mainarrayL2[i][j][1] = mainarrayL2[i][j - 1][1];
        mainarrayL2[i][j][2] = mainarrayL2[i][j - 1][2];
      }
    }
  }

  //restore leftmost column with memory
  if (Circulate)
    LYAssignColumn(Layer, 0);
}


void LYsetbottomrow(byte Layer, byte fromrow) 
{
  for (byte i = 0; i < LED_Columns; i++) 
  {
    if (Layer == 1)
    {
      mainarrayL1[(LED_Rows-1)][i][0] = a8x25L1[fromrow][i][0];
      mainarrayL1[(LED_Rows-1)][i][1] = a8x25L1[fromrow][i][1];
      mainarrayL1[(LED_Rows-1)][i][2] = a8x25L1[fromrow][i][2];
    }
    else
    {
      mainarrayL2[(LED_Rows-1)][i][0] = a8x25L2[fromrow][i][0];
      mainarrayL2[(LED_Rows-1)][i][1] = a8x25L2[fromrow][i][1];
      mainarrayL2[(LED_Rows-1)][i][2] = a8x25L2[fromrow][i][2];
    }
  }
}



void LYsettoprow(byte Layer, byte fromrow) 
{
  for (byte i = 0; i < LED_Columns; i++) 
  {
    if (Layer == 1)
    {
      mainarrayL1[0][i][0] = a8x25L1[LED_Rows-1-fromrow][i][0];
      mainarrayL1[0][i][1] = a8x25L1[LED_Rows-1-fromrow][i][1];
      mainarrayL1[0][i][2] = a8x25L1[LED_Rows-1-fromrow][i][2];
    }
    else
    {
      mainarrayL2[0][i][0] = a8x25L2[LED_Rows-1-fromrow][i][0];
      mainarrayL2[0][i][1] = a8x25L2[LED_Rows-1-fromrow][i][1];
      mainarrayL2[0][i][2] = a8x25L2[LED_Rows-1-fromrow][i][2];
    }
  }
}


void LYsetleftcolumn(byte Layer, byte fromcolumn) 
{
  for (byte i = 0; i < LED_Rows; i++) 
  {
    if (Layer == 1)
    {
      mainarrayL1[i][0][0] = a8x25L1[i][(LED_Columns-1) - fromcolumn][0];
      mainarrayL1[i][0][1] = a8x25L1[i][(LED_Columns-1) - fromcolumn][1];
      mainarrayL1[i][0][2] = a8x25L1[i][(LED_Columns-1) - fromcolumn][2];
    }
    else
    {
      mainarrayL2[i][0][0] = a8x25L2[i][(LED_Columns-1) - fromcolumn][0];
      mainarrayL2[i][0][1] = a8x25L2[i][(LED_Columns-1) - fromcolumn][1];
      mainarrayL2[i][0][2] = a8x25L2[i][(LED_Columns-1) - fromcolumn][2];
    }
  }
}

void LYsetrightcolumn(byte Layer, byte x) 
{
  for (byte i = 0; i < LED_Rows; i++) 
  {
    if (Layer == 1)
    {
      mainarrayL1[i][(LED_Columns-1)][0] = a8x25L1[i][x][0];
      mainarrayL1[i][(LED_Columns-1)][1] = a8x25L1[i][x][1];
      mainarrayL1[i][(LED_Columns-1)][2] = a8x25L1[i][x][2];
    }
    else
    {
      mainarrayL2[i][(LED_Columns-1)][0] = a8x25L2[i][x][0];
      mainarrayL2[i][(LED_Columns-1)][1] = a8x25L2[i][x][1];
      mainarrayL2[i][(LED_Columns-1)][2] = a8x25L2[i][x][2];
    }
  }
}


void LYClearRow(byte Layer, byte r)
{
  for (byte c = 0 ; c < LED_Columns; c++)
  {
    if (Layer == 1)
    {
      mainarrayL1[r][c][0] = 0;
      mainarrayL1[r][c][1] = 0;
      mainarrayL1[r][c][2] = 0;
    }
    else
    {
      mainarrayL2[r][c][0] = 0;
      mainarrayL2[r][c][1] = 0;
      mainarrayL2[r][c][2] = 0;
    }
  }
}

void LYClearColumn(byte Layer, byte c)
{
    for (byte r = 0; r < LED_Rows; r++) 
    {
      if (Layer == 1)
      {
        mainarrayL1[r][c][0] = 0;
        mainarrayL1[r][c][1] = 0;
        mainarrayL1[r][c][2] = 0;
      }
      else
      {
        mainarrayL2[r][c][0] = 0;
        mainarrayL2[r][c][1] = 0;
        mainarrayL2[r][c][2] = 0;
      }
    }  
}


void LYDrawColumn(byte Layer, byte col)
{
    for (int i = 0; i < LED_Rows; i++) 
    {
      if (Layer == 1)
      {
        mainarrayL1[i][col][0] = a8x25L1[i][col][0];
        mainarrayL1[i][col][1] = a8x25L1[i][col][1];
        mainarrayL1[i][col][2] = a8x25L1[i][col][2];
      }
      else
      {
        mainarrayL2[i][col][0] = a8x25L2[i][col][0];
        mainarrayL2[i][col][1] = a8x25L2[i][col][1];
        mainarrayL2[i][col][2] = a8x25L2[i][col][2];
      }
    }
}

void LYRead_LEDMatrixStudio_Data(byte Layer, byte ledarray[])
{
    LYcleara8x25(Layer);

    int pos = 0;
    for (byte i =  0; i < LED_Rows; i++) 
    {
        for (byte j = 0; j < LED_Columns; j++) 
        {
            pos = (i * LED_Columns + j) * 3;
            if (Layer == 1)
            {
              a8x25L1[i][j][0] = pgm_read_word_near(ledarray + pos);
              a8x25L1[i][j][1] = pgm_read_word_near(ledarray + pos+1);
              a8x25L1[i][j][2] = pgm_read_word_near(ledarray + pos+2);
            }
            else
            {
              a8x25L2[i][j][0] = pgm_read_word_near(ledarray + pos);
              a8x25L2[i][j][1] = pgm_read_word_near(ledarray + pos+1);
              a8x25L2[i][j][2] = pgm_read_word_near(ledarray + pos+2);
            }
        }
    }
    if (Data_Input == Inside)
      LYStartupFrame_FlipUpsideDown(Layer);
}

void FlattenLayers()
{
    for (byte row =  0; row < LED_Rows; row++) 
    {
        for (byte col = 0; col < LED_Columns; col++) 
        {
          if (mainarrayL2[row][col][0] == arTransKey[0] &&
              mainarrayL2[row][col][1] == arTransKey[1] &&
              mainarrayL2[row][col][2] == arTransKey[2] )   // i.e. if 2nd Layer pixel is transparent
          {
            mainarray[row][col][0] = mainarrayL1[row][col][0];
            mainarray[row][col][1] = mainarrayL1[row][col][1];
            mainarray[row][col][2] = mainarrayL1[row][col][2];
          }
          else
          {
            mainarray[row][col][0] = mainarrayL2[row][col][0];
            mainarray[row][col][1] = mainarrayL2[row][col][1];
            mainarray[row][col][2] = mainarrayL2[row][col][2];
          }

        }

    }
}
