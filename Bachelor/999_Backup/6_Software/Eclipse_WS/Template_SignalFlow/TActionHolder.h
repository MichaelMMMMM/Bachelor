#ifndef TACTIONHOLDER_H
#define TACTIONHOLDER_H
#include "TTypeList.h"

template<class Action, class Base>
class TActionHolder: public Base, public Action
{
public:
	void calcOutput(const typename Action::InputType& input)
	{
		Action::calcOutput(input);
		Base::calcOutput(Action::getValue());
	}
public:
	TActionHolder() = default;
	TActionHolder(const TActionHolder&) = delete;
	TActionHolder& operator=(const TActionHolder&) = delete;
	~TActionHolder() = default;
};

template<class Action>
class TActionHolder<Action, CNullType> : public CNullType, public Action
{
public:
	void calcOutput(const typename Action::InputType& input)
	{
		Action::calcOutput(input);
	}
public:
	TActionHolder() = default;
	TActionHolder(const TActionHolder&) = delete;
	TActionHolder& operator=(const TActionHolder&) = delete;
	~TActionHolder() = default;
};

#endif
