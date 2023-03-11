
void Run_GBPattern()
{
    GBPattern();
    for (int rep = 0; rep < 3; rep++)
    {
        Reveal(Up, DELAY, 20);
        Wipe(Up, DELAY, 20);

        Reveal(Down, DELAY, 20);
        Wipe(Down, DELAY, 20);

    }
}

void GBPattern()
{
    cleara8x25();
    clearmainarray();
    for (int row = 0; row < 20; row++)   //scanning from Bottom to Top
    {
        for (int col = 0; col < 60; col++)  // scanning from Left to Right
        {
            if (row%2 == 0 && col%2 == 0)   // if row number and column number is even
                 a8x25[row][col][2] = 255;    // making the pixel Blue

            else if (row%2 != 0 && col%2 != 0)  //if both row and column numbers are odd
                a8x25[row][col][1] = 255;    // making the pixel Green
        }
    }
    if (Data_Input == Inside)
      StartupFrame_FlipUpsideDown();
}
