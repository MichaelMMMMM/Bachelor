#include "CProxy.h"
#include "CControlComp.h"
#include "CCommComponent.h"
#include "CThread.h"

int main()
{
	CControlComp controlComp;
	CCommComponent commComp;

	CProxy& proxy = CProxy::getInstance();
	proxy.registerCommComponent(&commComp);
	proxy.registerControlComponent(&controlComp);

	CThread commThread(&commComp, CThread::PRIORITY_LOW);
	CThread controlThread(&controlComp, CThread::PRIORITY_HIGH);

	commThread.start();
	controlThread.start();

	commThread.join();
	controlThread.join();

	return 0;
}
