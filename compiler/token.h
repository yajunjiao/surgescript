/*
 * SurgeScript
 * A lightweight programming language for computer games and interactive apps
 * Copyright (C) 2017  Alexandre Martins <alemartf(at)gmail(dot)com>
 *
 * compiler/token.h
 * SurgeScript compiler: tokens
 */

#ifndef _SURGESCRIPT_COMPILER_TOKEN_H
#define _SURGESCRIPT_COMPILER_TOKEN_H

#define SURGESCRIPT_TOKEN_TYPES(F)                                              \
    F( SSTOK_IDENTIFIER, "identifier" )                                         \
    F( SSTOK_NUMBER, "number" )                                                 \
    F( SSTOK_STRING, "string" )                                                 \
    F( SSTOK_BOOL, "boolean" )                                                  \
    F( SSTOK_NULL, "null" )                                                     \
    F( SSTOK_SEMICOLON, ";" )                                                   \
    F( SSTOK_COMMA, "," )                                                       \
    F( SSTOK_DOT, "." )                                                         \
    F( SSTOK_LPAREN, "(" )                                                      \
    F( SSTOK_RPAREN, ")" )                                                      \
    F( SSTOK_LBRACKET, "[" )                                                    \
    F( SSTOK_RBRACKET, "]" )                                                    \
    F( SSTOK_LCURLY, "{" )                                                      \
    F( SSTOK_RCURLY, "}" )                                                      \
    F( SSTOK_UNARYOP, "unary operator" )                                        \
    F( SSTOK_BINARYOP, "binary operator" )                                      \
    F( SSTOK_ASSIGNOP, "assignment operator" )                                  \
    F( SSTOK_OBJECT, "object" )                                                 \
    F( SSTOK_FUN, "fun" )                                                       \
    F( SSTOK_RETURN, "return" )                                                 \
    F( SSTOK_IF, "if" )                                                         \
    F( SSTOK_ELSE, "else" )                                                     \
    F( SSTOK_WHILE, "while" )                                                   \
    F( SSTOK_FOR, "for" )                                                       \
    F( SSTOK_IN, "in" )                                                         \
    F( SSTOK_BREAK, "break" )                                                   \
    F( SSTOK_CONTINUE, "continue" )                                             \
    F( SSTOK_EOF, "end-of-file" )                                               \
    F( SSTOK_UNKNOWN, "unknown" )

typedef struct surgescript_token_t surgescript_token_t;
typedef enum surgescript_tokentype_t {
    #define TOKEN_CODE(x, y) x,
    SURGESCRIPT_TOKEN_TYPES(TOKEN_CODE)
} surgescript_tokentype_t;

surgescript_token_t* surgescript_token_create(surgescript_tokentype_t type, const char* lexeme);
surgescript_token_t* surgescript_token_destroy(surgescript_token_t* token);
surgescript_tokentype_t surgescript_token_type(const surgescript_token_t* token);
const char* surgescript_token_lexeme(const surgescript_token_t* token);
const char* surgescript_tokentype_name(surgescript_tokentype_t type);

#endif