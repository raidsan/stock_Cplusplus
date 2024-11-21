
#ifndef THREADNEWSREPORT_H
#define THREADNEWSREPORT_H

#include <QTextToSpeech>
//#include <QRegularExpression>
//#include <QRegularExpressionMatch>

class ThreadNewsReport : public QObject
{
    Q_OBJECT
public:
    explicit ThreadNewsReport(QObject *parent = nullptr);
    void getNewsData();
    QTextToSpeech *tts=new QTextToSpeech(this);

private:
    QByteArray allData;
//    QNetworkAccessManager *naManager =new QNetworkAccessManager(this);
    QString jinShiNewsReportCurTime;
    int eastNewsReportCurTime;
    QList<QStringList> eastNewsList;
    int count=0;
    QString id;
    QString newsContent;
    void initEastNews();
    void initNewsReport();
    void sayJsNews(QJsonObject object);
    void sayEastNews(QStringList l,int time);

signals:
    void getNewsFinished(QString s);

};

#endif // THREADNEWSREPORT_H
