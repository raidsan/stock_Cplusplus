
#ifndef THREADINDEX_H
#define THREADINDEX_H

#include <QObject>

class ThreadIndex : public QObject
{
    Q_OBJECT
public:
    explicit ThreadIndex(QObject *parent = nullptr);
    void getAllIndex();
private:
    void initIndexList();
    void getEastFundFlow();
    bool isFirst=true;
    QByteArray indexData;

signals:
    void getIndexFinished();
    void getBlockFinished();
};

#endif // THREADINDEX_H
