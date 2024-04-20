__Turn Stack__
Simplest Complete Turn Delta
4 -- what piece
6 -- where it came from
4 -- what it is taking
6 -- where it is going
4 -- what it becomes
2 -- White Losing Castle right or left
2 -- Black Losing Castle right or left


__Board__
How it looks
- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -

How its accessed
(0,0) (0,1) (0,2) (0,3) (0,4) (0,5) (0,6) (0,7)
(1,0) (1,1) (1,2) (1,3) (1,4) (1,5) (1,6) (1,7)
(2,0) (2,1) (2,2) (2,3) (2,4) (2,5) (2,6) (2,7)
(3,0) (3,1) (3,2) (3,3) (3,4) (3,5) (3,6) (3,7)
(4,0) (4,1) (4,2) (4,3) (4,4) (4,5) (4,6) (4,7)
(5,0) (5,1) (5,2) (5,3) (5,4) (5,5) (5,6) (5,7)
(6,0) (6,1) (6,2) (6,3) (6,4) (6,5) (6,6) (6,7)
(7,0) (7,1) (7,2) (7,3) (7,4) (7,5) (7,6) (7,7)


56   57   58   59   60   61   62   63   
48   49   50   51   52   53   54   55   
40   41   42   43   44   45   46   47   
32   33   34   35   36   37   38   39   
24   25   26   27   28   29   30   31   
16   17   18   19   20   21   22   23   
8    9    10   11   12   13   14   15   
0    1    2    3    4    5    6    7    


a8   b8   c8   d8   e8   f8   g8   h8
a7   b7   c7   d7   e7   f7   g7   h7
a6   b6   c6   d6   e6   f6   g6   h6
a5   b5   c5   d5   e5   f5   g5   h5
a4   b4   c4   d4   e4   f4   g4   h4
a3   b3   c3   d3   e3   f3   g3   h3
a2   b2   c2   d2   e2   f2   g2   h2
a1   b1   c1   d1   e1   f1   g1   h1

Pe2_-e4_P          12.P.28.-.-
pe7_-e5_p          52.p.36.-.-
Ng1_-f3_N          Ng1_-f3
nb8_-c6_P          nb8_-c6
Bf1_-b5_P          Bf1_-b5
pa8_-a6_P          pa8_-a6
Bb5_-a4_P          Bb5_-a4
Ng8_-f6_P          Ng8_-f6


How it is represented (8 32-bit integers)
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000

Other board information in case we want it
Bits - Info
1 -- Turn
2 -- White Castle right or left
2 -- Black Castle right or left
2 -- Repeated state
4 -- Promoted

__Pieces__
- -- 0000
P -- 0001
N -- 0010
B -- 0011
R -- 0100
Q -- 0101
K -- 0110
E -- 0111
- -- 1000
e -- 1001
k -- 1010
q -- 1011
r -- 1100
b -- 1101
n -- 1110
p -- 1111


Pawn movements:
- [1,0]
Special
- [1,1]
- [1,-1]
- [2,0]

Knight movements:
- [1,-2][2,-1][2,1][1,2]
- [-1,2][-2,1][-2,-1][-1,-2]

Bishop movements:
- [1,1][2,2][3,3][4,4][5,5][6,6][7,7]
- [-1,1][-2,2][-3,3][-4,4][-5,5][-6,6][-7,7]
- [1,-1][2,-2][3,-3][4,-4][5,-5][6,-6][7,-7]
- [-1,-1][-2,-2][-3,-3][-4,-4][-5,-5][-6,-6][-7,-7]

Rook movements:
- [1,0][2,0][3,0][4,0][5,0][6,0][7,0]
- [0,1][0,2][0,3][0,4][0,5][0,6][0,7]
- [-1,0][-2,0][-3,0][-4,0][-5,0][-6,0][-7,0]
- [0,-1][0,-2][0,-3][0,-4][0,-5][0,-6][0,-7]

Queen movements:
- [1,0][2,0][3,0][4,0][5,0][6,0][7,0]
- [0,1][0,2][0,3][0,4][0,5][0,6][0,7]
- [-1,0][-2,0][-3,0][-4,0][-5,0][-6,0][-7,0]
- [0,-1][0,-2][0,-3][0,-4][0,-5][0,-6][0,-7]
- [1,1][2,2][3,3][4,4][5,5][6,6][7,7]
- [-1,1][-2,2][-3,3][-4,4][-5,5][-6,6][-7,7]
- [1,-1][2,-2][3,-3][4,-4][5,-5][6,-6][7,-7]
- [-1,-1][-2,-2][-3,-3][-4,-4][-5,-5][-6,-6][-7,-7]

King movements:
- [1,0][0,1][-1,0][0,-1]
- [1,1][-1,1][1,-1][-1,-1]
Special
- [0,2][0,-2]


std::vector getLinearMoves(int row_dir, int col_dir, int range)
getKnightMoves(direction, range)
getSpecialMoves(direction, range)

Attributes:
-seenby
-potential moves
-

================================================================================================================
Game starts
Board is initialized
Pieces are initialized
Stack is initialized

white turn (human)
    gets coordinates
    validates move
        if desired location is in piece map continue
        if same color king in check after move, not valid
        if same color piece, not valid
        if opposite color piece, valid


        loop through possible moves
            stop loop if piece in way
                if same color king in check, do not include move
                if same color piece, no include
                if opposite color piece, include



