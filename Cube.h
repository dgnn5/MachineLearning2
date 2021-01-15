// Header file for the Cube class
#ifndef CUBE_H
#define CUBE_H

#include "Header.h"


const int NUMSIDES = 6;//      The number of sides on a Rubik's cube
const int DEFSIDELENGTH = 2;// The default side length for the Cube class


// Rubik's Cube
class Cube
{
private:
  int m_sideLength;// The side length of the cube
  int m_numSquares;// The total number of squares on the cube = ((m_sideLength)^2) * NUMSIDES(=6)
  int* m_squares;//  An array of every square on the cube (W=0,R=1,G=2,O=3,B=4,Y=5)

  // Checks if the piece is in the correct position, regardless of orientation (NOTE: Only works if m_sideLength == 3)
  bool PieceChecker(const int piece) const;
public:
  // Default Constructor
  Cube() : m_sideLength(DEFSIDELENGTH), m_numSquares(m_sideLength* m_sideLength* NUMSIDES), m_squares(new int[m_numSquares])
  {
    // Creates an unscrambled cube
    for (int i = 0; i < m_numSquares; i++)
      m_squares[i] = i / (m_sideLength * m_sideLength);
  }

  // Constructor (unscrambled)
  Cube(const int sideLength) : m_sideLength(sideLength), m_numSquares(m_sideLength* m_sideLength* NUMSIDES), m_squares(new int[m_numSquares])
  {
    // Creates an unscrambled cube
    for (int i = 0; i < m_numSquares; i++)
      m_squares[i] = i / (m_sideLength * m_sideLength);
  }

  // Constructor (random scramble)
  Cube(const int sideLength, const int maxMoves) : m_sideLength(sideLength), m_numSquares(m_sideLength* m_sideLength* NUMSIDES), m_squares(new int[m_numSquares])
  {
    // Creates an unscrambled cube
    for (int i = 0; i < m_numSquares; i++)
      m_squares[i] = i / (m_sideLength * m_sideLength);
    // Scrambles the cube
    Scramble(maxMoves);
  }

  // Constructor (set scramble)
  Cube(const int sideLength, const int numMoves, const int moves[]) :
    m_sideLength(sideLength), m_numSquares(m_sideLength* m_sideLength* NUMSIDES), m_squares(new int[m_numSquares])
  {
    // Creates an unscrambled cube
    for (int i = 0; i < m_numSquares; i++)
      m_squares[i] = i / (m_sideLength * m_sideLength);
    // Sets the scramble
    setScramble(numMoves, moves);
  }

  // Copy constructor
  Cube(const Cube& source) : m_sideLength(source.m_sideLength), m_numSquares(m_sideLength* m_sideLength* NUMSIDES), m_squares(new int[m_numSquares])
  {
    for (int i = 0; i < m_numSquares; i++)
      m_squares[i] = source.m_squares[i];
  }

  // Destructor
  ~Cube() { delete[] m_squares; }

  // Insertion operator overload (for easier visualization)
  friend ostream& operator<<(ostream& out, const Cube& cube);

  // Rotate function (NOTE: ASSUMES m_sideLength==2 or m_sideLength==3)
  void Rotate(const int move);

  // Returned true if the cube is in a valid solved state (NOTE: ASSUMES m_sideLength==2 or m_sideLength==3)
  bool isSolved() const;

  // Scrambles the cube between 0 and maxMoves random moves and returns a package of the moves used to scramble it
  Package<int> Scramble(const int maxMoves);

  // Scrambles the cube with the moves within the moves[] parameter (length = numMoves)
  void setScramble(const int numMoves, const int moves[]);

  // Returns a grade depending on how solved it is (NOTE: ASSUMES m_sideLength==2 or m_sideLength==3)
  // getGrade() * 100.0 = the percentage score out of 100%
  float getGrade() const;
};

#endif