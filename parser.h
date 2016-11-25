#include <stdio.h>
#include <lexer.h>
/*********************** Recursive LL(1) Pareser ***********************/
/*
 * Method: assign nonterminal symbols to C-function names
 *
 * LL(1) grammars have not left recursion:
 *
 * productions like A =>* A alpha are not allowed.
 *
 * Left recursive grammars must be renormalized to Greibach normal form
 * or at least productions of kind A =>* B alpha, where B not equal to A.
 *
 * For example: E -> E + T | T could be written as
 *
 * E -> T R, R-> + T R | <>
 *
 * Thus, the mypas language becomes (using EBNF notation):
 *
 * expr -> term { addop term }
 *
 * term -> fact { mulop fact }
 *
 * fact -> variable | constant | ( expr )
 *
 * addop -> + | -
 *
 * mulop -> * | /
 *
 * variable -> ID
 *
 * constant -> DEC | OCT | HEX | FLT
 */

 #define MAXSYMTAB_ENTRIES 0x10000
 #define MAXSTACK_SIZE     0x40

/* expr -> term { addop term }
 * term -> fact { mulop fact }
 * fact -> variable | constant | ( expr )
 */
int expr(void);
int superexpr(int inherited_type);
/* addop -> + | - */
int addop (void);
/* mulop -> * | / */
int mulop (void);
/* constant -> DEC | OCT | HEX | FLT */
void constant (void);
/* variable -> ID */
void variable (void);

void arith (void);

int arithmetic_op (void);

void mypas(void);
void body(void);
void declarative(void);
void fnctype(void);
void parmdef(void);
int vartype(void);
void imperative(void);
void stmtlist(void);
void stmt(void);
void beginblock(void);
void ifstmt(void);
void whilestmt(void);
void repeatstmt(void);
int hexToInt(char hexToConvert[]);
int octalToInt(char octalToConvert[]);

/*********************** lexer-to-parser interface ***********************/

extern int lookahead; /** @ parser.c **/

extern int gettoken (FILE *); /** @ lexer.c **/

void match (int expected_token);

extern FILE *source_code;

extern char lexeme[]; /** @ lexer.c **/
