                                                                                    


void Flash()  // Display pattern at once (no reveals)
{
    for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        for (byte z3 = 0; z3 < 3; z3++) {
          mainarray[z1][z2][z3] = a8x25[z1][z2][z3];
        }
      }
    }
    display();
    delay(DELAY);
}



void Animate(Direction direc, int sp, int steps) {

  if (Data_Input == Inside)
  {
      if (direc == Up)
        direc = Down;
      else if (direc == Down)
        direc = Up;
      else if (direc == LeftDown)
        direc = LeftUp;
      else if (direc == LeftUp)
        direc = LeftDown;
      else if (direc == RightDown)
        direc = RightUp;
      else if (direc == RightUp)
        direc = RightDown;
  }
  
  switch (direc){
  case Up:
    if (steps==0) steps = LED_Rows;
    for (byte hh = 0; hh < steps; hh++) {
      up(true);
      display();
      delay(sp);
    }
    break;
  
  case Down:
    if (steps==0) steps = LED_Rows;
    for (byte hh = 0; hh < steps; hh++) {
      down(true);
      display();
      delay(sp);
    }
    break;
    
  case Left:
    if (steps==0) steps = LED_Columns;
    for (byte hh = 0; hh < steps; hh++) {
      moveleft(true);
      display();
      delay(sp);
    }
    break;
  
  case Right:
    if (steps==0) steps = LED_Columns;
    for (byte hh = 0; hh < steps; hh++) {
      moveright(true);
      display();
      delay(sp);
    }
    break;
    
  case LeftUp:
    if (steps==0) steps = LED_Columns;
    for (byte hh = 0; hh < steps; hh++) {

      up(true);
      moveleft(true);
      display();
      delay(sp);
    }
    break;

  case LeftDown:
    if (steps==0) steps = LED_Columns;
    for (byte hh = 0; hh < steps; hh++) {

      down(true);
      moveleft(true);
      display();
      delay(sp);
    }
    break;

  case RightUp:
    if (steps==0) steps = LED_Columns;
    for (byte hh = 0; hh < steps; hh++) {

      up(true);
      moveright(true);
      display();
      delay(sp);
    }
    break;

  case RightDown:
    if (steps==0) steps = LED_Columns;
    for (byte hh = 0; hh < steps; hh++) {

      down(true);
      moveright(true);
      display();
      delay(sp);
    }
    break;
    
  default:
    break;
  }
}

void Reveal(Direction direc, int Delay, byte Steps) {

  //clearmainarray();
  if (Data_Input == Inside)
  {
      if (direc == Up)
        direc = Down;
      else if (direc == Down)
        direc = Up;
      else if (direc == LeftDown)
        direc = LeftUp;
      else if (direc == LeftUp)
        direc = LeftDown;
      else if (direc == RightDown)
        direc = RightUp;
      else if (direc == RightUp)
        direc = RightDown;
  }

  switch (direc){
  case Up:
    for (int j = 0; j < Steps; j++)
    {
        up(false);
        setbottomrow(j);
        display();
        delay(Delay);
    }
    break;

  case Down:
    
    for (int j = 0; j < Steps; j++)
    {
        down(false);
        settoprow(j);  //LED_Rows-1-j  - for Inverted Reveal down;
        display();
        delay(Delay);
    }
    break;

  case Left:
    for (int c=0; c < Steps; c++)
    {
        moveleft(false);
        setrightcolumn(c);
        display();
        delay(Delay);
    }
    break;
    

  case Right:
    for (int c=0; c < Steps; c++)
    {
        moveright(false);
        setleftcolumn(c);
        display();
        delay(Delay); 
    }
    break;


  case LeftUp:
    
    for (byte hh = 0; hh < Steps; hh++) {
      up(false);
      setbottomrow(hh);
      
      setrightcolumn(hh);
      moveleft(false);
      
      display();
      delay(Delay);
    }
    break;

  case LeftDown:
    
    for (byte hh = 0; hh < Steps; hh++) {

      down(false);
      settoprow(hh);

      setrightcolumn(hh);
      moveleft(false);
      
      display();
      delay(Delay);
    }
    break;

  case RightUp:
    
    for (byte hh = 0; hh < Steps; hh++) {

      up(false);
      setbottomrow(hh);
      
      setleftcolumn(hh);
      moveright(false);
      
      display();
      delay(Delay);
    }
    break;

  case RightDown:
    
    for (byte hh = 0; hh < Steps; hh++) {

      down(false);
      settoprow(hh);

      setleftcolumn(hh);
      moveright(false);
      
      display();
      delay(Delay);
    }
    break;
    
  default:
    break;
  }
  
}

void RevealFromCenter(int Delay)
{
      int centerCol = floor(LED_Columns/2);
      clearmainarray();
      
      DrawColumn(centerCol);
      display();
      delay(Delay);
      for (int st=0; st < centerCol; st++)
      {
          DrawColumn(centerCol - st);
          DrawColumn(centerCol + st);
          display();
          delay(Delay);
      }
}


void Wipe(Direction direc, int sp, byte steps) {

  if (Data_Input == Inside)
  {
      if (direc == Up)
        direc = Down;
      else if (direc == Down)
        direc = Up;
  }

  switch (direc){
  case Up:
      for (int hh = 0; hh < steps; hh++) {
        up(false);
        ClearRow(LED_Rows-1);
        display();
        delay(sp);
      }
      break;
      
  case Down:
    for (int hh = 0; hh < steps; hh++)
    {
      down(false);
      ClearRow(0);
      display();
      delay(sp);
    }
    break;
    
  case Left:
    for (int hh = 0; hh < steps; hh++) 
    {
      moveleft(false);
      ClearColumn(LED_Columns-1);
      display();
      delay(sp);
    }
    break;
    
  case Right:
      for (int hh = 0; hh < steps; hh++) 
      {
        moveright(false);
        ClearColumn(0);
        display();
        delay(sp);
      }
      break;
  default:
    break;
  }
  
}

void WipeToCenter(int Delay)
{
      int centerCol = floor(LED_Columns/2);
      
      for (int st=0; st < centerCol; st++)
      {
          moveRightHalf(Left);
          moveLeftHalf(Right);
          ClearColumn(0);            // Clear left most
          ClearColumn(LED_Columns-1);  // Clear right most
          display();
          delay(Delay);
      }
      ClearColumn(centerCol);
      display();
      //delay(Delay);
}

void WipeFromCenter(int Delay)
{
      int centerCol = floor(LED_Columns/2);

      for (int st=0; st < centerCol; st++)
      {
          moveRightHalf(Right);
          moveLeftHalf(Left);
          ClearColumn(centerCol);
          display();
          delay(Delay);
      }
}

void moveRightHalf(Direction dir)
{
  int centerCol = floor(LED_Columns/2);
  
  switch (dir){
    
  case Left:
    for (int j = centerCol; j < LED_Columns; j++) {
      for (int i = 0; i < LED_Rows; i++) {
        mainarray[i][j][0] = mainarray[i][j + 1][0];
        mainarray[i][j][1] = mainarray[i][j + 1][1];
        mainarray[i][j][2] = mainarray[i][j + 1][2];
      }
    }
    break;
  case Right:
    for (int j = LED_Columns -1; j > centerCol; j--) {
      for (int i = 0; i < LED_Rows; i++) {
        mainarray[i][j][0] = mainarray[i][j - 1][0];
        mainarray[i][j][1] = mainarray[i][j - 1][1];
        mainarray[i][j][2] = mainarray[i][j - 1][2];
      }
    }
    break;
  default:
    break;
  }
}

void moveLeftHalf(Direction dir) 
{
    int centerCol = floor(LED_Columns/2);
    switch (dir){

    case Left :
      for (int j = 0; j < centerCol; j++) {
        for (int i = 0; i < LED_Rows; i++) {
          mainarray[i][j][0] = mainarray[i][j + 1][0];
          mainarray[i][j][1] = mainarray[i][j + 1][1];
          mainarray[i][j][2] = mainarray[i][j + 1][2];
        }
      }
      break;
      
    case Right :
      for (int j = centerCol; j > 0; j--) {
        for (int i = 0; i < LED_Rows; i++) {
          mainarray[i][j][0] = mainarray[i][j-1][0];
          mainarray[i][j][1] = mainarray[i][j-1][1];
          mainarray[i][j][2] = mainarray[i][j-1][2];
        }
      }
      break;
    default:
      break;
    }
}
