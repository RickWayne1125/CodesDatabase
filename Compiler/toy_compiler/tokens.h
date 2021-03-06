//
// Created by Ricky on 2021/4/9.
//

// Messages
#define NAME_ERROR      -1  // 命名错误
#define DOUBLE_ERROR    -2  // 浮点错误
#define CONST_ERROR     -3  // 常量错误
#define TOKEN_ERROR     -4  // 非法符号
#define LEX_ERROR   "Lexical error occurs at: "
// Reserved words
#define IDENTIFIER  0
#define CONST       1
// Variable types
#define INTEGER 2
#define DOUBLE  3
#define CHAR    4
#define STRING  5
#define HEXINT  6
#define HEXDOU  7
#define BOOLEAN 8
// Otherwords
#define FUNCT   15
#define RETURN  16
#define IF      17
#define ELSE    18
#define FOR     19
#define WHILE   20
#define TYPE    21
// Operators
#define ADD     128     // +
#define SUB     129     // -
#define MUL     130     // *
#define DIV     131     // /
#define EQUAL   132     // =
#define CEQ     133     // ==
#define CNE     134     // !=
#define CLT     135     // <
#define CLE     136     // <=
#define CGT     137     // >
#define CGE     138     // >=
#define DOT     139     // .
#define GET     140     // get
#define PUT     141     // put
#define AND     142     // &
#define OR      143     // |
#define DAND    144     // &&
#define DOR     145     // ||
#define NOT     146     // !
// Delimiter
#define LPAREN  256     // (
#define RPAREN  257     // )
#define LBRACE  258     // {
#define RBRACE  259     // }
#define LBRACK  260     // [
#define RBRACK  261     // ]
// Splits
#define COMMA   262     // ,
#define COLON   263     // :
#define SEMICOLON   264 // ;