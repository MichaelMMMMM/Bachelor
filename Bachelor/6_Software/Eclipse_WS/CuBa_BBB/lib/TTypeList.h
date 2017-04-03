#ifndef TTYPELIST_H
#define TTYPELIST_H
#include "CNullType.h"

template<class T, class U>
struct TTypeList
{
	using Head = T;
	using Tail = U;
};

#define TYPELIST_1(T1)	TTypeList<T1, CNullType>
#define TYPELIST_2(T1, T2)  TTypeList<T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3)  TTypeList<T1, TYPELIST_2(T2, T3) >
#define TYPELIST_4(T1, T2, T3, T4)  TTypeList<T1, TYPELIST_3(T2, T3, T4) >
#define TYPELIST_5(T1, T2, T3, T4, T5) TTypeList<T1, TYPELIST_4(T2, T3, T4, T5) >
#define TYPELIST_6(T1, T2, T3, T4, T5, T6) TTypeList<T1, TYPELIST_5(T2, T3, T4, T5, T6) >
#define TYPELIST_7(T1, T2, T3, T4, T5, T6, T7) TTypeList<T1, TYPELIST_6(T2, T3, T4, T5, T6, T7) >

#endif
