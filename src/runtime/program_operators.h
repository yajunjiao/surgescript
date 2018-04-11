/*
 * SurgeScript
 * A lightweight programming language for computer games and interactive apps
 * Copyright (C) 2016-2017  Alexandre Martins <alemartf(at)gmail(dot)com>
 *
 * runtime/program_operators.h
 * SurgeScript program operators table
 */

#ifndef _SURGESCRIPT_RUNTIME_PROGRAM_OPERATORS_H
#define _SURGESCRIPT_RUNTIME_PROGRAM_OPERATORS_H

/*
    conventions:
        let 'a' and 'b' be the arguments of each operation
        and t[0 .. 3] be temporary values (aka "registers")

    now,
        a, b are constants
        t[0], t[1] are temps holding different values throughout the program
        t[2] holds the results of comparisons
        t[3] holds other calculations
*/
#define SURGESCRIPT_PROGRAM_OPERATORS(F) \
    F( SSOP_NOP, "nop" )                                 /* no-operation */ \
    F( SSOP_SELF, "self" )             /* t[a] = handle to caller object */ \
    F( SSOP_STATE, "state" )   /* t[a] = get/set the state of the object */ \
                                                                            \
    F( SSOP_MOV, "mov" )                                  /* t[a] = t[b] */ \
    F( SSOP_MOVN, "movn" )                                /* t[a] = null */ \
    F( SSOP_MOVB, "movb" )                             /* t[a] = (bool)b */ \
    F( SSOP_MOVF, "movf" )                           /* t[a] = (number)b */ \
    F( SSOP_MOVS, "movs" )                             /* t[a] = text[b] */ \
    F( SSOP_MOVO, "movo" )                           /* t[a] = (object)b */ \
    F( SSOP_MOVU, "movu" )                              /* t[a] = (u32)b */ \
    F( SSOP_XCHG, "xchg" )                           /* swap(t[a], t[b]) */ \
                                                                            \
    F( SSOP_ALLOC, "alloc" )              /* t[a] = allocate memory cell */ \
    F( SSOP_LOAD, "load" )                             /* t[a] = *(t[b]) */ \
    F( SSOP_STORE, "store" )                           /* *(t[b]) = t[a] */ \
    F( SSOP_PEEK, "peek" )                                /* t[a] = (*b) */ \
    F( SSOP_POKE, "poke" )                                /* (*b) = t[a] */ \
                                                                            \
    F( SSOP_PUSH, "push" )                                  /* push t[a] */ \
    F( SSOP_POP, "pop" )                                     /* pop t[a] */ \
    F( SSOP_SPEEK, "speek" )                   /* t[a] = stack[base + b] */ \
    F( SSOP_SPOKE, "spoke" )                   /* stack[base + b] = t[a] */ \
    F( SSOP_PUSHN, "pushn" )                             /* push a cells */ \
    F( SSOP_POPN, "popn" )                                /* pop a cells */ \
                                                                            \
    F( SSOP_INC, "inc" )                                       /* t[a]++ */ \
    F( SSOP_DEC, "dec" )                                       /* t[a]-- */ \
    F( SSOP_ADD, "add" )                                 /* t[a] += t[b] */ \
    F( SSOP_SUB, "sub" )                                 /* t[a] -= t[b] */ \
    F( SSOP_MUL, "mul" )                                 /* t[a] *= t[b] */ \
    F( SSOP_DIV, "div" )                                 /* t[a] /= t[b] */ \
    F( SSOP_NEG, "neg" )                                 /* t[a] = -t[b] */ \
    F( SSOP_LNOT, "lnot" )                               /* t[a] = !t[b] */ \
    F( SSOP_NOT, "not" )                                 /* t[a] = ~t[b] */ \
    F( SSOP_AND, "and" )                           /* t[a] = t[a] & t[b] */ \
    F( SSOP_OR, "or" )                             /* t[a] = t[a] | t[b] */ \
    F( SSOP_XOR, "xor" )                           /* t[a] = t[a] ^ t[b] */ \
                                                                            \
    F( SSOP_TEST, "test" )                         /* t[2] = t[a] & t[b] */ \
    F( SSOP_TCHK, "tchk" )                  /* t[2] = typecheck(t[a], b) */ \
    F( SSOP_TC01, "tc01" )       /* t[2] = tchk(t[0], a) | tchk(t[1], a) */ \
    F( SSOP_TCMP, "tcmp" )             /* t[2] = typecompare(t[a], t[b]) */ \
    F( SSOP_CMP, "cmp" )                   /* t[2] = compare(t[a], t[b]) */ \
                                                                            \
    F( SSOP_JMP, "jmp" )                               /* jump to line a */ \
    F( SSOP_JE, "je" )                    /* jump to line a if t[2] == 0 */ \
    F( SSOP_JNE, "jne" )                  /* jump to line a if t[2] != 0 */ \
    F( SSOP_JG, "jg" )                     /* jump to line a if t[2] > 0 */ \
    F( SSOP_JGE, "jge" )                  /* jump to line a if t[2] >= 0 */ \
    F( SSOP_JL, "jl" )                     /* jump to line a if t[2] < 0 */ \
    F( SSOP_JLE, "jle" )                  /* jump to line a if t[2] <= 0 */ \
                                                                            \
    F( SSOP_CALL, "call" )                /* call program named text[a], */ \
                                         /* with b parameters, of object */ \
                                       /* stack[top-b] and store in t[0] */ \
                                      /* the return value of the program */ \
    F( SSOP_RET, "ret" )                 /* returns, halting the program */

#endif