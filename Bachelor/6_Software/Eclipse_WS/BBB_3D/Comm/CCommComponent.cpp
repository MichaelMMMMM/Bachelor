/**
 * @file	CCommComponent.cpp
 * @author	Michael Meindl
 * @date	7.10.2016
 */
#include "CCommComponent.h"
#include <iostream>

CCommComponent::CCommComponent() : mFSM()
{

}
void CCommComponent::init()
{
	std::cout << "[*] Comm-Component: Initializing" << std::endl;
	CMessage init(EEvent::INIT);
	mFSM.dispatch(init);

}
void CCommComponent::run()
{
	std::cout << "[*] Comm-Component: Running" << std::endl;
	CMessage msg;
	while(true)
	{
		if(mQueue.popFront(msg, true))
		{
			mFSM.dispatch(msg);
		}
	}
}
