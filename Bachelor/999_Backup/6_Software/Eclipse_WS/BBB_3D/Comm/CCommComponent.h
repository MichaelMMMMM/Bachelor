/**
 * @file	CCommComponent.h
 * @author	Michael Meindl
 * @date	7.10.2016
 */
#ifndef CCOMMCOMPONENT_H
#define CCOMMCOMPONENT_H
#include "AComponentBase.h"
#include "CCommFSM.h"

class CCommComponent : public AComponentBase
{
public:
	void init() override;
	void run() override;
public:
	CCommComponent();
	CCommComponent(const CCommComponent&) = delete;
	CCommComponent& operator=(const CCommComponent&) = delete;
	~CCommComponent() = default;
private:
	CCommFSM mFSM;
};

#endif
