// Implementation file for the Cube class
#include "Cube.h"


bool Cube::PieceChecker(const int piece) const
{
  bool valid = false;// Tracks whether the piece is in the correct position or not
  switch (piece)
  {
    // Top layer ----------------------------------------------------------------------------
  case 0:
    // Corner 0,18,29
    if (((m_squares[0] == m_squares[4]) && (m_squares[18] == m_squares[22]) && (m_squares[29] == m_squares[31])) ||
      ((m_squares[0] == m_squares[22]) && (m_squares[18] == m_squares[31]) && (m_squares[29] == m_squares[4])) ||
      ((m_squares[0] == m_squares[31]) && (m_squares[18] == m_squares[4]) && (m_squares[29] == m_squares[22])))
      valid = true;
    break;
  case 1:
    // Edge 1,28
    if (((m_squares[1] == m_squares[4]) && (m_squares[28] == m_squares[31])) ||
      ((m_squares[1] == m_squares[31]) && (m_squares[28] == m_squares[4])))
      valid = true;
    break;
  case 2:
    // Corner 2,27,38
    if (((m_squares[2] == m_squares[4]) && (m_squares[27] == m_squares[31]) && (m_squares[38] == m_squares[40])) ||
      ((m_squares[2] == m_squares[31]) && (m_squares[27] == m_squares[40]) && (m_squares[38] == m_squares[4])) ||
      ((m_squares[2] == m_squares[40]) && (m_squares[27] == m_squares[4]) && (m_squares[38] == m_squares[31])))
      valid = true;
    break;
  case 3:
    // Edge 3,19
    if (((m_squares[3] == m_squares[4]) && (m_squares[19] == m_squares[22])) ||
      ((m_squares[3] == m_squares[22]) && (m_squares[19] == m_squares[4])))
      valid = true;
    break;
  case 4:
    // Edge 5,37
    if (((m_squares[5] == m_squares[4]) && (m_squares[37] == m_squares[40])) ||
      ((m_squares[5] == m_squares[40]) && (m_squares[37] == m_squares[4])))
      valid = true;
    break;
  case 5:
    // Corner 6,9,21
    if (((m_squares[6] == m_squares[4]) && (m_squares[9] == m_squares[13]) && (m_squares[20] == m_squares[22])) ||
      ((m_squares[6] == m_squares[13]) && (m_squares[9] == m_squares[22]) && (m_squares[20] == m_squares[4])) ||
      ((m_squares[6] == m_squares[22]) && (m_squares[9] == m_squares[4]) && (m_squares[20] == m_squares[13])))
      valid = true;
    break;
  case 6:
    // Edge 7,10
    if (((m_squares[7] == m_squares[4]) && (m_squares[10] == m_squares[13])) ||
      ((m_squares[7] == m_squares[13]) && (m_squares[10] == m_squares[4])))
      valid = true;
    break;
  case 7:
    // Corner 8,11,36
    if (((m_squares[8] == m_squares[4]) && (m_squares[11] == m_squares[13]) && (m_squares[36] == m_squares[40])) ||
      ((m_squares[8] == m_squares[13]) && (m_squares[11] == m_squares[40]) && (m_squares[36] == m_squares[4])) ||
      ((m_squares[8] == m_squares[40]) && (m_squares[11] == m_squares[4]) && (m_squares[36] == m_squares[13])))
      valid = true;
    break;

    // Middle Layer -----------------------------------------------------------
  case 8:
    // Edge 12,23
    if (((m_squares[12] == m_squares[13]) && (m_squares[23] == m_squares[22])) ||
      ((m_squares[12] == m_squares[22]) && (m_squares[23] == m_squares[13])))
      valid = true;
    break;
  case 9:
    // Edge 14,39
    if (((m_squares[14] == m_squares[13]) && (m_squares[39] == m_squares[40])) ||
      ((m_squares[14] == m_squares[40]) && (m_squares[39] == m_squares[13])))
      valid = true;
    break;
  case 10:
    // Edge 21,32
    if (((m_squares[21] == m_squares[22]) && (m_squares[32] == m_squares[31])) ||
      ((m_squares[21] == m_squares[31]) && (m_squares[32] == m_squares[22])))
      valid = true;
    break;
  case 11:
    // Edge 30,41
    if (((m_squares[30] == m_squares[31]) && (m_squares[41] == m_squares[40])) ||
      ((m_squares[30] == m_squares[40]) && (m_squares[41] == m_squares[31])))
      valid = true;
    break;

    // Bottom layer --------------------------------------------------------------------------
  case 12:
    // Corner 45,42,17
    if (((m_squares[45] == m_squares[49]) && (m_squares[42] == m_squares[40]) && (m_squares[17] == m_squares[13])) ||
      ((m_squares[45] == m_squares[13]) && (m_squares[42] == m_squares[49]) && (m_squares[17] == m_squares[40])) ||
      ((m_squares[45] == m_squares[40]) && (m_squares[42] == m_squares[13]) && (m_squares[17] == m_squares[49])))
      valid = true;
    break;
  case 13:
    // Edge 46,43
    if (((m_squares[46] == m_squares[49]) && (m_squares[43] == m_squares[40])) ||
      ((m_squares[46] == m_squares[40]) && (m_squares[43] == m_squares[49])))
      valid = true;
    break;
  case 14:
    // Corner 47,44,33
    if (((m_squares[47] == m_squares[49]) && (m_squares[44] == m_squares[40]) && (m_squares[33] == m_squares[31])) ||
      ((m_squares[47] == m_squares[31]) && (m_squares[44] == m_squares[49]) && (m_squares[33] == m_squares[40])) ||
      ((m_squares[47] == m_squares[40]) && (m_squares[44] == m_squares[31]) && (m_squares[33] == m_squares[49])))
      valid = true;
    break;
  case 15:
    // Edge 48,16
    if (((m_squares[48] == m_squares[49]) && (m_squares[16] == m_squares[13])) ||
      ((m_squares[48] == m_squares[13]) && (m_squares[16] == m_squares[49])))
      valid = true;
    break;
  case 16:
    // Edge 50,34
    if (((m_squares[50] == m_squares[49]) && (m_squares[34] == m_squares[31])) ||
      ((m_squares[50] == m_squares[31]) && (m_squares[34] == m_squares[49])))
      valid = true;
    break;
  case 17:
    // Corner 51,26,15
    if (((m_squares[51] == m_squares[49]) && (m_squares[26] == m_squares[22]) && (m_squares[15] == m_squares[13])) ||
      ((m_squares[51] == m_squares[13]) && (m_squares[26] == m_squares[49]) && (m_squares[15] == m_squares[22])) ||
      ((m_squares[51] == m_squares[22]) && (m_squares[26] == m_squares[13]) && (m_squares[15] == m_squares[49])))
      valid = true;
    break;
  case 18:
    // Edge 52,25
    if (((m_squares[52] == m_squares[49]) && (m_squares[25] == m_squares[22])) ||
      ((m_squares[52] == m_squares[22]) && (m_squares[25] == m_squares[49])))
      valid = true;
    break;
  case 19:
    // Corner 53,35,24
    if (((m_squares[53] == m_squares[49]) && (m_squares[35] == m_squares[31]) && (m_squares[24] == m_squares[22])) ||
      ((m_squares[53] == m_squares[22]) && (m_squares[35] == m_squares[49]) && (m_squares[24] == m_squares[31])) ||
      ((m_squares[53] == m_squares[31]) && (m_squares[35] == m_squares[22]) && (m_squares[24] == m_squares[49])))
      valid = true;
    break;
  default:
    cout << endl << "!!!!!!INVALID PIECE!!!!!!" <<
      endl << "Piece = " << piece << endl <<
      "m_sideLength = " << m_sideLength << endl;
    break;
  }

  return valid;
}

ostream& operator<<(ostream& out, const Cube& cube)
{
  // Output a row with all of the indices
  out << "Index:";
  for (int i = 0; i < cube.m_numSquares; i++)
    out << ((i == 0) ? " " : ((i / 10 > 0) ? "|" : "| ")) << i;
  out << endl;

  // Output a row with the colors at each index (Key: W=0,R=1,G=2,O=3,B=4,Y=5)
  out << "Color:";
  for (int i = 0; i < cube.m_numSquares; i++)
    out << ((i == 0) ? " " : "| ") << cube.m_squares[i];

  // Return the ostream
  return out;
}

void Cube::Rotate(const int move)
{
  bool skip = false;// Tracks if the move is skipped
  bool isPrime = false;// Tracks if the move is counterclockwise
  bool isTwo = (m_sideLength == 2);//      Tracks whether the cube is 2x2x2 or 3x3x3
  int squaresPerMove = (isTwo ? 12 : 20);// Tracks how many squares are are modified per move
  Package<int> moveList(2 * squaresPerMove);//  Contains the list of moves on each square in an array

  // Creating a copy of m_squares
  int* prev = new int[m_numSquares];
  for (int i = 0; i < m_numSquares; i++)
    prev[i] = m_squares[i];

  // Performing the move
  switch (move)
  {
  case 0:
    //U
    if (isTwo)
      moveList.setValues(U2);
    else
      moveList.setValues(U3);
    break;
  case 1:
    //U'
    isPrime = true;
    if (isTwo)
      moveList.setValues(U2);
    else
      moveList.setValues(U3);
    break;
  case 2:
    //F
    if (isTwo)
      moveList.setValues(F2);
    else
      moveList.setValues(F3);
    break;
  case 3:
    //F'
    isPrime = true;
    if (isTwo)
      moveList.setValues(F2);
    else
      moveList.setValues(F3);
    break;
  case 4:
    //L
    if (isTwo)
      moveList.setValues(L2);
    else
      moveList.setValues(L3);
    break;
  case 5:
    //L'
    isPrime = true;
    if (isTwo)
      moveList.setValues(L2);
    else
      moveList.setValues(L3);
    break;
  case 6:
    //B
    if (isTwo)
      moveList.setValues(B2);
    else
      moveList.setValues(B3);
    break;
  case 7:
    //B'
    isPrime = true;
    if (isTwo)
      moveList.setValues(B2);
    else
      moveList.setValues(B3);
    break;
  case 8:
    //R
    if (isTwo)
      moveList.setValues(R2);
    else
      moveList.setValues(R3);
    break;
  case 9:
    //R'
    isPrime = true;
    if (isTwo)
      moveList.setValues(R2);
    else
      moveList.setValues(R3);
    break;
  case 10:
    //D
    if (isTwo)
      moveList.setValues(D2);
    else
      moveList.setValues(D3);
    break;
  case 11:
    //D'
    isPrime = true;
    if (isTwo)
      moveList.setValues(D2);
    else
      moveList.setValues(D3);
    break;
  case 12:
    //X (Skip move)
    skip = true;
    break;
  default:
    skip = true;
    cout << "!!!!INVALID MOVE!!!!" << endl
      << "m_sideLength = " << m_sideLength << endl
      << "Move = " << move << endl
      << "Cube: " << endl << (*this) << endl << endl;
    break;
  }

  // Moving the squares or skipping the move
  if (!(skip))
  {
    for (int i = 0; i < 2 * squaresPerMove; i += 2)
    {
      if (isPrime)
        m_squares[moveList[i + 1]] = prev[moveList[i]];
      else// Not prime
        m_squares[moveList[i]] = prev[moveList[i + 1]];
    }
  }


  // Deleting the copy of m_squares
  delete[] prev;

  return;
}

bool Cube::isSolved() const
{
  // These track whether each side is solved or not
  bool side1, side2, side3, side4, side5, side6;
  if (m_sideLength == 2)
  {
    side1 = ((m_squares[0] == m_squares[1]) && (m_squares[1] == m_squares[2]) && (m_squares[2] == m_squares[3]));
    side2 = ((m_squares[4] == m_squares[5]) && (m_squares[5] == m_squares[6]) && (m_squares[6] == m_squares[7]));
    side3 = ((m_squares[8] == m_squares[9]) && (m_squares[9] == m_squares[10]) && (m_squares[10] == m_squares[11]));
    side4 = ((m_squares[12] == m_squares[13]) && (m_squares[13] == m_squares[14]) && (m_squares[14] == m_squares[15]));
    side5 = ((m_squares[16] == m_squares[17]) && (m_squares[17] == m_squares[18]) && (m_squares[18] == m_squares[19]));
    side6 = ((m_squares[20] == m_squares[21]) && (m_squares[21] == m_squares[22]) && (m_squares[22] == m_squares[23]));
  }
  else// m_sideLength == 3
  {
    side1 = ((m_squares[0] == m_squares[1]) && (m_squares[1] == m_squares[2]) && (m_squares[2] == m_squares[3]) &&
      (m_squares[3] == m_squares[4]) && (m_squares[4] == m_squares[5]) && (m_squares[5] == m_squares[6]) &&
      (m_squares[6] == m_squares[7]) && (m_squares[7] == m_squares[8]));
    side2 = ((m_squares[9] == m_squares[10]) && (m_squares[10] == m_squares[11]) && (m_squares[11] == m_squares[12]) &&
      (m_squares[12] == m_squares[13]) && (m_squares[13] == m_squares[14]) && (m_squares[14] == m_squares[15]) &&
      (m_squares[15] == m_squares[16]) && (m_squares[16] == m_squares[17]));
    side3 = ((m_squares[18] == m_squares[19]) && (m_squares[19] == m_squares[20]) && (m_squares[20] == m_squares[21]) &&
      (m_squares[21] == m_squares[22]) && (m_squares[22] == m_squares[23]) && (m_squares[23] == m_squares[24]) &&
      (m_squares[24] == m_squares[25]) && (m_squares[25] == m_squares[26]));
    side4 = ((m_squares[27] == m_squares[28]) && (m_squares[28] == m_squares[29]) && (m_squares[29] == m_squares[30]) &&
      (m_squares[30] == m_squares[31]) && (m_squares[31] == m_squares[32]) && (m_squares[32] == m_squares[33]) &&
      (m_squares[33] == m_squares[34]) && (m_squares[34] == m_squares[35]));
    side5 = ((m_squares[36] == m_squares[37]) && (m_squares[37] == m_squares[38]) && (m_squares[38] == m_squares[39]) &&
      (m_squares[39] == m_squares[40]) && (m_squares[40] == m_squares[41]) && (m_squares[41] == m_squares[42]) &&
      (m_squares[42] == m_squares[43]) && (m_squares[43] == m_squares[44]));
    side6 = ((m_squares[45] == m_squares[46]) && (m_squares[46] == m_squares[47]) && (m_squares[47] == m_squares[48]) &&
      (m_squares[48] == m_squares[49]) && (m_squares[49] == m_squares[50]) && (m_squares[50] == m_squares[51]) &&
      (m_squares[51] == m_squares[52]) && (m_squares[52] == m_squares[53]));
  }

  // Return true if all sides are solved, and false otherwise
  return (side1 && side2 && side3 && side4 && side5 && side6);
}

Package<int> Cube::Scramble(const int maxMoves)
{
  int move;// Used to keep track of the move that will be performed
  Package<int> moveList(maxMoves);// Used to track every move performed
  for (int i = 0; i < maxMoves; i++)
  {
    move = (rand() % 13);// Picking a random move [0,12]
    Rotate(move);// Performing the move
    moveList.m_values[i] = move;// Adding the move to the list
  }
  return moveList;
}

void Cube::setScramble(const int numMoves, const int moves[])
{
  for (int i = 0; i < numMoves; i++)
    Rotate(moves[i]);
  return;
}

float Cube::getGrade() const
{
  float score = 0.0;//     Tracks the total score of the current cube (Higher the closer it is to being solved)
  float sideBonus = 0.0;// Tracks whether an entire side has been solved 

  if (m_sideLength == 2)
  {
    // Check how many pairs of colors there are
    for (int i = 0; i < NUMSIDES; i++)
    {
      if (m_squares[i * 4] == m_squares[(i * 4) + 1])
      {
        score += 0.5;
        sideBonus += 0.5;
      }
      if (m_squares[i * 4] == m_squares[(i * 4) + 2])
      {
        score += 0.5;
        sideBonus += 0.5;
      }
      if (m_squares[i * 4] == m_squares[(i * 4) + 3])
      {
        score += 0.5;
        sideBonus += 0.5;
      }
      if (m_squares[(i * 4) + 1] == m_squares[(i * 4) + 2])
      {
        score += 0.5;
        sideBonus += 0.5;
      }
      if (m_squares[(i * 4) + 1] == m_squares[(i * 4) + 3])
      {
        score += 0.5;
        sideBonus += 0.5;
      }
      if (m_squares[(i * 4) + 2] == m_squares[(i * 4) + 3])
      {
        score += 0.5;
        sideBonus += 0.5;
      }

      // Calculate the side bonus
      if (sideBonus == 3.0)
        score += 1.0;
      sideBonus = 0.0;// Reset the side bonus
    }
    //(Max for ^ that is score = 24.0)

    // Check for the layer bonus (rings of pairs around each axis)
    if ((m_squares[0] == m_squares[1]) && (m_squares[17] == m_squares[19]) &&
      (m_squares[21] == m_squares[23]) && (m_squares[8] == m_squares[10]))
      score += 1.0;
    if ((m_squares[2] == m_squares[3]) && (m_squares[16] == m_squares[18]) &&
      (m_squares[20] == m_squares[22]) && (m_squares[9] == m_squares[11]))
      score += 1.0;
    if ((m_squares[0] == m_squares[2]) && (m_squares[4] == m_squares[6]) &&
      (m_squares[22] == m_squares[23]) && (m_squares[13] == m_squares[15]))
      score += 1.0;
    if ((m_squares[1] == m_squares[3]) && (m_squares[5] == m_squares[7]) &&
      (m_squares[20] == m_squares[21]) && (m_squares[12] == m_squares[14]))
      score += 1.0;
    if ((m_squares[4] == m_squares[5]) && (m_squares[16] == m_squares[17]) &&
      (m_squares[12] == m_squares[13]) && (m_squares[8] == m_squares[9]))
      score += 1.0;
    if ((m_squares[6] == m_squares[7] && (m_squares[18] == m_squares[19]) &&
      (m_squares[14] == m_squares[15]) && (m_squares[10] == m_squares[11])))
      score += 1.0;
    //(Max for ^ that = score == 6.0)
  }
  else// m_sideLength == 3
  {
    // Check if the colors of each square match the centers of each side
    for (int i = 0; i < NUMSIDES; i++)// For each side
    {
      for (int x = (i * 9); x < ((i + 1) * 9); x++)// For every square on that side
      {
        if (x != ((i * 9) + 4))// If the square isn't the center
        {
          if (m_squares[x] == m_squares[((i * 9) + 4)])// If the square is the same color as the center
          {
            score += 0.5;// Add 0.5 to the score
            sideBonus += 0.5;// Add 0.5 to the side bonus
          }
        }
      }

      // Calculate the side bonus
      if (sideBonus == 4.0)// If the whole side has been solved
        score += 1.0;// Add 1.0 to the score
      sideBonus = 0.0;// Reset the side bonus
    }
    //(Max for ^ that is score = 30.0)


    // Check if the pieces are in the correct loctation (to give points for correct position, but wrong orientation)
    for (int i = 0; i < 20; i++)
    {
      if (PieceChecker(i))// If the piece is in the correct position
        score += 1.0;// Add 1.0 to the score
    }
    //(Max for ^ that is score = 20.0)
  }

  //Max score for m_sideLength == 2: 30.0
  //Max score for m_sideLength == 3: 50.0

  // Returns the grade as a fraction of the maximum possible score 
  if (m_sideLength == 2)
    return (score / 30.0);
  else// m_sideLength == 3
    return (score / 50.0);
}