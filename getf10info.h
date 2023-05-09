
#ifndef GETF10INFO_H
#define GETF10INFO_H

#include <QNetworkAccessManager>
#include <QJsonArray>
#include <QTextCodec>

class GetF10Info : public QObject
{
    Q_OBJECT
public:
    GetF10Info(QObject *parent = nullptr);
    QNetworkAccessManager *naManager;
    QByteArray allData;
    QList<QStringList> f10QList;
    QStringList colList;
    QStringList period={};
    void getStockHotRank();
    void getMainIndex();
    void mainBusinessComposition();
    void assetLiability();
    void getIncome();
    void getCashFlow();
    void getData(QStringList key,QStringList value,QStringList &col,QList<QStringList> &l);
    void getAllData(QStringList key,QStringList value,QStringList &col,QList<QStringList> &l,QString url);
    void calcPeriod();
};

#endif // GETF10INFO_H
