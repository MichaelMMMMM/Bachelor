#include "CProxy.h"
#include "CControlComp.h"
#include "CCommComponent.h"
#include "CThread.h"
#include "TObserver.h"

int main()
{
	TObserver<3U, 2U, 1U> test;
	CControlComp controlComp;
	CCommComponent commComp;

	CProxy& proxy = CProxy::getInstance();
	proxy.registerCommComponent(&commComp);
	proxy.registerControlComponent(&controlComp);

	CThread commThread(&commComp, CThread::PRIORITY_LOW);
	CThread controlThread(&controlComp, CThread::PRIORITY_CRITICAL);

	commThread.start();
	controlThread.start();

	commThread.join();
	controlThread.join();

	return 0;
}
