                                                                                    


void LYFlash(byte Layer)  // Display pattern at once (no reveals)
{
    for (byte z1 = 0; z1 < LED_Rows; z1++) {
      for (byte z2 = 0; z2 < LED_Columns; z2++) {
        for (byte z3 = 0; z3 < 3; z3++) 
        {
          if (Layer == 1)
            mainarrayL1[z1][z2][z3] = a8x25L1[z1][z2][z3];
          else
            mainarrayL2[z1][z2][z3] = a8x25L2[z1][z2][z3];
        }
      }
    }
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(DELAY);
    }
}

void AnimateLayers(Direction direc1, Direction direc2, int Delay, int steps)
{
    for (int i = 0; i < steps; i++)
    {
        LYAnimate(1, direc1, Delay);
        LYAnimate(2, direc2, Delay);
    }
}

void LYAnimate(byte Layer, Direction direc, int sp) 
{

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
    LYup(Layer, true);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(sp);
    }
    break;
  
  case Down:
    LYdown(Layer, true);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(sp);
    }
    break;
    
  case Left:
    LYmoveleft(Layer, true);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(sp);
    }
    break;
  
  case Right:
    LYmoveright(Layer, true);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(sp);
    }
    break;
    
  case LeftUp:
    LYup(Layer, true);
    LYmoveleft(Layer, true);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(sp);
    }
    break;

  case LeftDown:
    LYdown(Layer, true);
    LYmoveleft(Layer, true);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(sp);
    }
    break;

  case RightUp:
    LYup(Layer, true);
    LYmoveright(Layer, true);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(sp);
    }
    break;

  case RightDown:
    LYdown(Layer, true);
    LYmoveright(Layer, true);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(sp);
    }
    break;
    
  default:
    break;
  }
}

void RevealLayers(Direction direc1, Direction direc2, int Delay, byte Steps)
{
    for (int j = 0; j < Steps; j++)
    {
        LYReveal(1, direc1, Delay, j);
        LYReveal(2, direc2, Delay, j);
    }
}

void LYReveal(byte Layer, Direction direc, int Delay, int Step) 
{

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
    LYup(Layer, false);
    LYsetbottomrow(Layer, Step);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(Delay);
    }
    break;

  case Down:
    LYdown(Layer, false);
    LYsettoprow(Layer, Step);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(Delay);
    }
    break;

  case Left:
    LYmoveleft(Layer, false);
    LYsetrightcolumn(Layer, Step);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(Delay);
    }
    break;
    

  case Right:
    LYmoveright(Layer, false);
    LYsetleftcolumn(Layer, Step);
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(Delay); 
    }
    break;


  case LeftUp:
    
    LYup(Layer, false);
    LYsetbottomrow(Layer, Step);

    LYmoveleft(Layer, false);
    LYsetrightcolumn(Layer, Step);
    
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(Delay);
    }
    break;

  case LeftDown:
    LYdown(Layer, false);
    LYsettoprow(Layer, Step);

    LYmoveleft(Layer, false);
    LYsetrightcolumn(Layer, Step);
    
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(Delay);
    }
    break;

  case RightUp:
    
    LYup(Layer, false);
    LYsetbottomrow(Layer, Step);
    
    LYmoveright(Layer, false);
    LYsetleftcolumn(Layer, Step);
    
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(Delay);
    }
    break;

  case RightDown:
    
    LYdown(Layer, false);
    LYsettoprow(Layer, Step);

    LYmoveright(Layer, false);
    LYsetleftcolumn(Layer, Step);
    
    if (Layer == 2)
    {
      FlattenLayers();
      display();
      delay(Delay);
    }
    break;
    
  default:
    break;
  }
  
}

void LYRevealFromCenter(byte Delay)
{
      int centerCol = floor(LED_Columns/2);
      LYclearmainarray(1);
      LYclearmainarray(2);
      
      LYDrawColumn(1, centerCol);
      LYDrawColumn(2, centerCol);

      FlattenLayers();
      display();
      delay(Delay);

      for (int st=0; st < centerCol; st++)
      {
          LYDrawColumn(1, centerCol - st);
          LYDrawColumn(1, centerCol + st);

          LYDrawColumn(2, centerCol - st);
          LYDrawColumn(2, centerCol + st);

          FlattenLayers();
          display();
          delay(Delay);
      }
}

void LYRevealToCenter(byte Delay)
{
      int centerCol = floor(LED_Columns/2);
      LYclearmainarray(1);
      LYclearmainarray(2);
      
      for (int st=0; st < centerCol; st++)
      {
          LYDrawColumn(1, LED_Columns - 1 - st);
          LYDrawColumn(1, st);

          LYDrawColumn(2, LED_Columns - 1 - st);
          LYDrawColumn(2, st);

          FlattenLayers();
          display();
          delay(Delay);
      }
      LYDrawColumn(1, centerCol);
      LYDrawColumn(2, centerCol);

      FlattenLayers();
      display();
      delay(Delay);
}

void WipeLayers(Direction direc1, Direction direc2, int Delay, byte Steps)
{
    for (int j = 0; j < Steps; j++)
    {
        LYWipe(1, direc1, Delay);
        LYWipe(2, direc2, Delay);
    }
}

void LYWipe(byte Layer, Direction direc, int Delay) {

  if (Data_Input == Inside)
  {
      if (direc == Up)
        direc = Down;
      else if (direc == Down)
        direc = Up;
  }

  switch (direc){
  case Up:
      LYup(Layer, false);
      LYClearRow(Layer, LED_Rows-1);
      if (Layer == 2)
      {
        FlattenLayers();
        display();
        delay(Delay);
      }
      break;
      
  case Down:
      LYdown(Layer, false);
      LYClearRow(Layer, 0);
      if (Layer == 2)
      {
        FlattenLayers();
        display();
        delay(Delay);
      }
    break;
    
  case Left:
      LYmoveleft(Layer, false);
      LYClearColumn(Layer, LED_Columns-1);
      if (Layer == 2)
      {
        FlattenLayers();
        display();
        delay(Delay);
      }
    break;
    
  case Right:
        LYmoveright(Layer, false);
        LYClearColumn(Layer, 0);
        if (Layer == 2)
        {
          FlattenLayers();
          display();
          delay(Delay);
        }
      break;
  default:
    break;
  }
  
}


void LYWipeToCenter(int Delay)
{
      int centerCol = floor(LED_Columns/2);
      
      for (int st=0; st < centerCol; st++)
      {
        //Layer 1
          LYmoveRightHalf(1, Left);
          LYmoveLeftHalf(1, Right);
          LYClearColumn(1, 0);            // Clear left most
          LYClearColumn(1, LED_Columns-1);  // Clear right most
        //Layer 2
          LYmoveRightHalf(2, Left);
          LYmoveLeftHalf(2, Right);
          LYClearColumn(2, 0);            // Clear left most
          LYClearColumn(2, LED_Columns-1);  // Clear right most

          FlattenLayers();
          display();
          delay(Delay);
      }
      LYClearColumn(1, centerCol);
      LYClearColumn(2, centerCol);
      FlattenLayers();
      display();
      //delay(Delay);
}

void LYWipeFromCenter(int Delay)
{
      int centerCol = floor(LED_Columns/2);

      for (int st=0; st < centerCol; st++)
      {
          LYmoveRightHalf(1, Right);
          LYmoveLeftHalf(1, Left);
          LYClearColumn(1, centerCol);

          LYmoveRightHalf(1, Right);
          LYmoveLeftHalf(1, Left);
          LYClearColumn(1, centerCol);
          
          display();
          delay(Delay);
      }
}

void LYmoveRightHalf(byte Layer, Direction dir)
{
  int centerCol = floor(LED_Columns/2);
  
  switch (dir){
    
  case Left:
    for (int j = centerCol; j < LED_Columns; j++) {
      for (int i = 0; i < LED_Rows; i++) {
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
    break;
  case Right:
    for (int j = LED_Columns -1; j > centerCol; j--) {
      for (int i = 0; i < LED_Rows; i++) {
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
    break;
  default:
    break;
  }
}

void LYmoveLeftHalf(byte Layer, Direction dir) 
{
    int centerCol = floor(LED_Columns/2);
    switch (dir){

    case Left :
      for (int j = 0; j < centerCol; j++) {
        for (int i = 0; i < LED_Rows; i++) {
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
      break;
      
    case Right :
      for (int j = centerCol; j > 0; j--) {
        for (int i = 0; i < LED_Rows; i++) {
          if (Layer == 1)
          {
            mainarrayL1[i][j][0] = mainarrayL1[i][j-1][0];
            mainarrayL1[i][j][1] = mainarrayL1[i][j-1][1];
            mainarrayL1[i][j][2] = mainarrayL1[i][j-1][2];
          }
          else
          {
            mainarrayL2[i][j][0] = mainarrayL2[i][j-1][0];
            mainarrayL2[i][j][1] = mainarrayL2[i][j-1][1];
            mainarrayL2[i][j][2] = mainarrayL2[i][j-1][2];
          }
        }
      }
      break;
    default:
      break;
    }
}
