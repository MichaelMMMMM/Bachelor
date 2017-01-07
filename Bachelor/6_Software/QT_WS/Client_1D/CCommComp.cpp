#include "CCommComp.h"

CCommComp::CCommComp()
{

}
void CCommComp::init()
{

}
void CCommComp::run()
{
    CMessage msg;
    while(true)
    {
        if(mClient.readMessage(msg))
        {
            //TODO Nachricht verarbeiten
        }
    }
}
