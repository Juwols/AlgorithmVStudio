#pragma once
//#define INT_MIN (1<<31)
//#define INT_MAX (((unsignd int)INT_MIN)-1)
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))
#define SET_BIT(a,b) ((a) |= (1<<(b)))
#define GET_BIT(a,b) (((a) & (1<<(b)))>0?1:0)
#define CLEAR_BIT(a,b) ((a) &= ~(1<<(b)))
#define TOGGLE_BIT(a,b) if (GET_BIT(a,b) == 1) CLEAR_BIT(a,b); \
                        else SET_BIT(a,b);