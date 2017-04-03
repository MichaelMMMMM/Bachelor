#ifndef TLINHIERARCHY_H
#define TLINHIERARCHY_H
#include "TTypeList.h"

template<class TList, template<class AtomicType, class Base> class Unit, class Root = CNullType>
class TLinHierarchy;

template<class T1, class T2, template<class, class> class Unit, class Root>
class TLinHierarchy<TTypeList<T1, T2>, Unit, Root>
	: public Unit<T1, TLinHierarchy<T2, Unit, Root> >
{

};

template<class T, template<class, class> class Unit, class Root>
class TLinHierarchy<TYPELIST_1(T), Unit, Root>
	: public Unit<T, Root>
{

};

#endif
