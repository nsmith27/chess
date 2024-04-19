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



