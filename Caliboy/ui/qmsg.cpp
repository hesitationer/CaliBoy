#include "qmsg.h"
#include <fstream>
#include <time.h>

const char debugModePre[] = " |-";
bool bDetailOn = true;
void detialOn()
{
    bDetailOn = true;
}
void detialOff()
{
    bDetailOn = false;
}

#ifdef _On_QtTextBrowser_

QMsgPannel *OutPannel = 0;
void setOutBrowser(QTextBrowser *browser)
{
    OutPannel = new QMsgPannel(browser);
}
void releaseOutBrowser()
{
    if (OutPannel != 0) {
        delete OutPannel;
        OutPannel = 0;
    }
}
void writeMsg(const QString &msg)
{
    if (OutPannel != 0) 
        OutPannel->Append(msg);
}
void msgOut(const QString &msg)
{
    writeMsg(msg);
}
void _msgOut(const QString &msg)
{
    if (bDetailOn) {
        QString debugMsg = QString("%1 %2").arg(debugModePre).arg(msg);
        writeMsg(debugMsg);
    }
}

#endif

void writeMsg(const char *msg)
{

#ifdef _On_QtTextBrowser_
if (OutPannel != 0)
    OutPannel->Append(msg);
#else
#ifdef _On_Console_
    printf(msg);
    printf("\n");
    fflush(stdout);
#endif
#endif
}
void msgOut(const char *msg)
{
    writeMsg(msg);
}
void _msgOut(const char *msg)
{
    if (bDetailOn) {
        char debugMsg[1024];
        sprintf_s(debugMsg, "%s %s", debugModePre, msg);
        writeMsg(debugMsg);
    }
}