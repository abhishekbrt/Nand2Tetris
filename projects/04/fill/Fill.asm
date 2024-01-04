// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.


//@24558
//D=A
//@last
//M=D

//@16385
//D=A
//@start
//M=D

//@SCREEN
//D=A
//@addr
//M=D

//(LOOP)
//@KBD
//D=M
//@BLACKEN
//D;JGT 
//@WHITEN
//D;JEQ

//(BLACKEN)
//@addr
//D=M
//@last
//D=D-M
//@LOOP
//D;JEQ


//@addr
//A=M
//M=-1
//@addr
//M=M+1

//@BLACKEN
//0;JMP


//(WHITEN)
//@addr
//D=M
//@start
//D=D-M
//@LOOP
//D;JEQ

//@0
//D=A
//@addr
//M=D
//@addr
//M=M-1

//@WHITEN
//0;JMP  


//code 2 

(BEGIN)
@KBD
D=M

@BLACKEN
D;JNE

@WHITEN
D;JEQ

(BLACKEN)
@counter
M=-1
(LOOP)
@counter
M=M+1
D=M
@SCREEN
A=A+D
M=-1
@8191
D=D-A
@LOOP
D;JNE

@BEGIN
0;JMP

(WHITEN)
@counter
M=-1
(LOOPWHITE)
@counter
M=M+1
D=M
@SCREEN
A=A+D
M=0
@8191
D=D-A
@LOOPWHITE
D;JNE

@BEGIN
0;JMP














































































