
#ifndef REQUESTSTOCSV_H
#define REQUESTSTOCSV_H

#include "qdialog.h"
#include "qpushbutton.h"
//#include "qwidget.h"
#include <QObject>
//#include <QNetworkAccessManager>
#include <QFile>
#include <QJsonArray>
#include <QTextCodec>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include "globalvar.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
#include "QDir"
#include "downloadtask.h"
#include "QThreadPool"

class RequestsToCsv : public QDialog
{
    Q_OBJECT
public:
    explicit RequestsToCsv(QDialog *parent = nullptr);
//    QNetworkAccessManager *naManager=new QNetworkAccessManager(this);
//    QStringList listJP;

    bool getIndexList();
    bool getPlateList();
    void dealWithPlateList(QList<QStringList> &list,const QByteArray &allData);
    QString getStockList();
    void dealWithAllList();
    void downStockIndexPlateInfo();
    void downloadAllStockK();
    Q_INVOKABLE void setText(int nums)
    {
        int n=GlobalVar::mTableListCopy.count();
        numLine->setText(QString::number(n-nums));
        progressBar->setValue(nums);
        if (nums==n)
        {
            stopBtn->setEnabled(false);
            stopBtn->setText("下载完成");
        }
    }
//    void baoShareStockK();
    QThreadPool threadPool;
    QDialog *progressBarWindow = new QDialog();
    QPushButton *stopBtn = new QPushButton("终止下载",progressBarWindow);
    QLabel *numLine = new QLabel(progressBarWindow);
    QProgressBar *progressBar = new QProgressBar(progressBarWindow);
    QString CNToEL(const QString &cnstr);
    bool isDownload=false;

signals:

};

#endif // REQUESTSTOCSV_H
