#ifndef ORDER_H
#define ORDER_H

#include <QTime>
#include <QObject>
#include <QtCore>
#include <QDateTime>


class Order : public QObject
{
    Q_OBJECT
public:
    explicit Order(QObject *parent = 0);

    int getWarehouse() const;
    void setWarehouse(int value);

    int getCustomer() const;
    void setCustomer(int value);

    QString getSalesRep() const;
    void setSalesRep(const QString &value);

    QString getRoute() const;
    void setRoute(const QString &value);

    int getStop() const;
    void setStop(int value);

    bool getCreditOrder() const;
    void setCreditOrder(bool value);

    int getInvoiceNumber() const;
    void setInvoiceNumber(int value);

    QDateTime getInvoiceDate() const;
    void setInvoiceDate(const QString &value);

    double getInvoiceAmount() const;
    void setInvoiceAmount(double value);

    int getQuantityOrdered() const;
    void setQuantityOrdered(int value);

    double getCaseCube() const;
    void setCaseCube(double value);

    double getCaseWeight() const;
    void setCaseWeight(double value);

    QString getShipDate() const;
    void setShipDate(const QString &value);

    QString getOrderDate() const;
    void setOrderDate(const QString &value);

    int getQuantityShipped() const;
    void setQuantityShipped(int value);

    double getNetSales() const;
    void setNetSales(double value);

    double getActualCost() const;
    void setActualCost(double value);

    double getProfitAmount() const;
    void setProfitAmount(double value);

    double getProfitPercet() const;
    void setProfitPercet(double value);

    QString getSalesRepName() const;
    void setSalesRepName(const QString &value);

    void print();

    void setOrderInfo(QStringList s);

signals:

public slots:

private:
    int warehouse;
    int customer;
    QString salesRep;
    QString route;
    int stop;
    bool creditOrder;
    int invoiceNumber;
    //"invoice date" and "time of order" is the date and time that the orderwas placed in system.
    //further, time is written as a 24h format, without leading zeros... fun stuff to read in.  (prepent with zeros to get to 6 digits, convert to HH:mm:ss?)
    QDateTime invoiceDate;
    double invoiceAmount;
    int quantityOrdered;
    double caseCube;
    double caseWeight;
    QString shipDate;
    QString orderDate;
    int quantityShipped;
    double netSales;
    double actualCost;
    double profitAmount;
    double profitPercet;
    QString salesRepName;
    //I wish we could use calcualted fields, but there is some accounting fuckery so we have to use profit data as writ even if the numbers don't add up <cough>
    //<cough> bullshit! <cough>





};

#endif // ORDER_H
