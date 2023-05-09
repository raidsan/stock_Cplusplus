
#include "threadtimesharechart.h"
#include "globalvar.h"

ThreadTimeShareChart::ThreadTimeShareChart(QObject *parent)
    : QObject{parent}
{
    naManager = new QNetworkAccessManager(this);
}

void ThreadTimeShareChart::getAllTimeShareChart()
{
    if (isRunning)
        return;
    isRunning=true;
    GlobalVar::getEastData(naManager,allData,1.5,QUrl("https://push2his.eastmoney.com/api/qt/stock/trends2/get?fields1=f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13&fields2=f51,f52,f53,f54,f55,f56,f57,f58&ut=fa5fd1943c7b386f172d6893dbfba10b&iscr=0&ndays=1&secid="+GlobalVar::getComCode()+"&_=1666401553893"),"");
    if (not GlobalVar::timeOutFlag[5])
    {
        initTimeShareChartList();
        emit getTimeShareChartFinished();
    }
    GlobalVar::timeOutFlag[5]=false;
    isRunning=false;
}

void ThreadTimeShareChart::initTimeShareChartList()
{
    GlobalVar::mTimeShareChartList.clear();
    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(allData, &jsonError);

    if (jsonError.error == QJsonParseError::NoError)
    {
        QJsonObject jsonObject = doc.object();
        GlobalVar::preClose=jsonObject.value("data").toObject().value("preClose").toDouble();
        int ph=110;
        int pl=90;
        if (GlobalVar::curCode.left(1)=="3" or GlobalVar::curCode.left(1)=="8" or GlobalVar::curCode.left(3)=="688")
        {
            ph=120;
            pl=80;
        }
        float a=int(GlobalVar::preClose*ph+0.5)/100.0;
        float b=int(GlobalVar::preClose*pl+0.5)/100.0;
        GlobalVar::timeShareHighLowPoint[3]=per(a);
        GlobalVar::timeShareHighLowPoint[4]=per(b);

        QJsonArray data=jsonObject.value("data").toObject().value("trends").toArray();
        GlobalVar::trendsTotal=jsonObject.value("data").toObject().value("trendsTotal").toInt();
        float h=0.0;
        float l=100000.0;
        GlobalVar::timeShareHighLowPoint[2]=0;
        for (int i = 0; i < data.size(); ++i)
        {
            QStringList list=data.at(i).toString().split(",");
            timeShartChartInfo info;
            info.time=list[0];
            info.price=per(list[2].toFloat());
            info.vol=list[5].toFloat();
            info.avePrice=per(list[7].toFloat());
            if (list[2].toFloat()>list[1].toFloat())
                info.direct=2;
            else if (list[2].toFloat()<list[1].toFloat())
                info.direct=1;
            else
                info.direct=3;
            if (list[3].toFloat()>h)
                h=list[3].toFloat();
            if (list[4].toFloat()<l)
                l=list[4].toFloat();
            if (list[5].toFloat()>GlobalVar::timeShareHighLowPoint[2])
                GlobalVar::timeShareHighLowPoint[2]=list[5].toFloat();
//            qDebug()<<GlobalVar::timeShareHighLowPoint[2];
            GlobalVar::mTimeShareChartList.append(info);
        }
        GlobalVar::timeShareHighLowPoint[0]=per(h);
        GlobalVar::timeShareHighLowPoint[1]=per(l);

        //        for (int i = 0; i < GlobalVar::mTimeShareChartList.size(); ++i)
        //        {
        //            qDebug()<<GlobalVar::mTimeShareChartList.at(i).time
        //                <<GlobalVar::mTimeShareChartList.at(i).price
        //                <<GlobalVar::mTimeShareChartList.at(i).vol
        //                <<GlobalVar::mTimeShareChartList.at(i).avePrice;
        //        }
    }
}

