
#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#include <QDateTime>
#include <QTimeZone>
#include <QSettings>
#include <QPalette>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>
#include <QTimer>
#include <QCoreApplication>
#include "stockinfo.h"

class GlobalVar
{
public:
    GlobalVar();
    static bool isWorkDay(QDateTime curTime);
    static bool isZhWorkDay(QDateTime curTime,int select);
    static QDateTime curRecentWorkDay(int select);
    static bool isZhMarketDay(QDateTime curTime);
    static bool isUSMarketDay(QDateTime curTime);
    static bool isUKMarketDay(QDateTime curTime);
    static bool isHKMarketDay(QDateTime curTime);
    static bool getVacation();
    static QString getComCode();
    static QString getStockSymbol();
    static void sortByColumn(QList<StockInfo> *mList,int column,bool is_asc);
    static QString getCookies(QString url);
    static void getData(QByteArray &allData,float timeOut,QNetworkRequest requests);
    static void getData(QByteArray &allData,float timeOut,const QUrl &url);
    static void postData(const QByteArray &postArray,QByteArray &allData, float timeOut, const QUrl &url);
    static QString format_conversion(float data);
//    static QString format_conversion(int data);
    static QString peelStr(const QString &s,QString begin,QString end);
    static QPair<QString, QString> cutStr(const QString &s,QString begin,QString end);
    static QString getContent(const QString &s);
    static QString getAttributeContent(const QString &s,QString attribute,QString symbol);
    static void getAllContent(QString &content,QStringList &strList,QString begin);
    static bool isInt(QString s);
    static StockInfo findStock(QString code);
    static int setRound();

    static QString curCode;
    static bool isBoard;
    static QString curBoard;
    static QString curName;
    static QString EPSReportDate;
    static QString PEName;
//    static QStringList tableHeader;
    static float preClose;
    static float hisPreClose;
    static int WhichInterface;
    static bool isKState;
    static bool isUsZhStock;
    static QString circle_green_SheetStyle;
    static QString circle_red_SheetStyle;
    static QSettings *settings;
//    static ModelTableStock *m_tableModel;
//    static ModelTableStock *m_risingSpeedModel;
//    static ModelTableStock *m_myStockModel;
//    static ModelTimeShare *m_timeShareTickModel;
    static QList<StockInfo> mTableList;
    static QList<StockInfo> mTableListCopy;
    static QList<StockInfo> mRisingSpeedList;
    static QList<StockInfo> mMyStockList;
    static QList<QStringList> mFundFlowList;
    static QStringList mMyStockCode;
    static QList<IndexInfo> mIndexList;
    static QList<timeShareTickInfo> mTimeShareTickList;
    static QList<timeShareChartInfo> mTimeShareChartList;
    static QList<timeShareChartInfo> mHisTimeShareChartList;
    static QList<candleChartInfo> mCandleChartList;
    static bool timeOutFlag[10];
    static int KRange;
    static float timeShareHighLowPoint[5];
//    static float candleHighLowPoint[5];
    static float buySellPrice[10];
    static float buySellNum[10];
    static float baseInfoData[14];
    static int curSortNum;
    static QString columns[17];
    static bool is_asc;
    static QPalette pRed;
    static QPalette pGreen;
    static QPalette pBlack;
    static QPalette pBlue;
    static QPalette pWhite;
    static int upNums[3];
    static int downNums[3];
    static int trendsTotal;
    static bool isSayNews;
    static int curBlock;
    static QString currentPath;
    static int offsetEnd;
    static int offsetLocal;
    static bool areaFlag[5];
    static QString formulaContent;
    static int mTableListNum;
    static QString mCandleListCode;
    static QList<QStringList> formula;
    static QList<QStringList> annoucementList;
};

inline int GlobalVar::setRound()
{
    int p=2;
    QString s=GlobalVar::curCode.left(3);
    if (s=="133")
        p=4;
    else if (GlobalVar::curCode.size()==5 or s=="155")
        p=3;
    return p;
}

#endif // GLOBALVAR_H
