#include "order.h"

Order::Order(QObject *parent) : QObject(parent)
{

}

int Order::getWarehouse() const
{
    return warehouse;
}

void Order::setWarehouse(int value)
{
    warehouse = value;
}

int Order::getCustomer() const
{
    return customer;
}

void Order::setCustomer(int value)
{
    customer = value;
}

QString Order::getSalesRep() const
{
    return salesRep;
}

void Order::setSalesRep(const QString &value)
{
    salesRep = value;
}

QString Order::getRoute() const
{
    return route;
}

void Order::setRoute(const QString &value)
{
    route = value;
}

int Order::getStop() const
{
    return stop;
}

void Order::setStop(int value)
{
    stop = value;
}

bool Order::getCreditOrder() const
{
    return creditOrder;
}

void Order::setCreditOrder(bool value)
{
    creditOrder = value;
}

int Order::getInvoiceNumber() const
{
    return invoiceNumber;
}

void Order::setInvoiceNumber(int value)
{
    invoiceNumber = value;
}

QDateTime Order::getInvoiceDate() const
{
    return invoiceDate;
}

void Order::setInvoiceDate(const QString &value)
{
    QDate tempDate;
    qDebug() << "WOD WOD WOD WOD WOD";
    tempDate = QDate::fromString(value,"M/d/yyyy");
    invoiceDate.setDate(tempDate);
}

double Order::getInvoiceAmount() const
{
    return invoiceAmount;
}

void Order::setInvoiceAmount(double value)
{
    invoiceAmount = value;
}

int Order::getQuantityOrdered() const
{
    return quantityOrdered;
}

void Order::setQuantityOrdered(int value)
{
    quantityOrdered = value;
}

double Order::getCaseCube() const
{
    return caseCube;
}

void Order::setCaseCube(double value)
{
    caseCube = value;
}

double Order::getCaseWeight() const
{
    return caseWeight;
}

void Order::setCaseWeight(double value)
{
    caseWeight = value;
}

QString Order::getShipDate() const
{
    return shipDate;
}

void Order::setShipDate(const QString &value)
{
    shipDate = value;
}

QString Order::getOrderDate() const
{
    return orderDate;
}

void Order::setOrderDate(const QString &value)
{
    orderDate = value;
}

int Order::getQuantityShipped() const
{
    return quantityShipped;
}

void Order::setQuantityShipped(int value)
{
    quantityShipped = value;
}

double Order::getNetSales() const
{
    return netSales;
}

void Order::setNetSales(double value)
{
    netSales = value;
}

double Order::getActualCost() const
{
    return actualCost;
}

void Order::setActualCost(double value)
{
    actualCost = value;
}

double Order::getProfitAmount() const
{
    return profitAmount;
}

void Order::setProfitAmount(double value)
{
    profitAmount = value;
}

double Order::getProfitPercet() const
{
    return profitPercet;
}

void Order::setProfitPercet(double value)
{
    profitPercet = value;
}

void Order::print(){
    qDebug() << "warehouse is:" << warehouse;
    qDebug() << "customer is:" <<  customer;
    qDebug() << "sales rep is:" <<  salesRep;
    qDebug() << "route is:" <<  route;
    qDebug() << "stop is:" <<  stop;
    qDebug() << "credit order is:" <<  creditOrder;
    qDebug() << "invoice number is:" <<  invoiceNumber;
    qDebug() << "invoice date is:" <<  invoiceDate;
    qDebug() << "invoice amount is:" <<  invoiceAmount;
    qDebug() << "quantityOrdered is:" <<  quantityOrdered;
    qDebug() << "caseCube is:" <<  caseCube;
    qDebug() << "caseWeight is:" <<  caseWeight;
    qDebug() << "shipDate is:" <<  shipDate;
    qDebug() << "orderDate is:" <<  orderDate;
    qDebug() << "quantityShipped is:" <<  quantityShipped;
    qDebug() << "netSales is:" <<  netSales;
    qDebug() << "actualCost is:" <<  actualCost;
    qDebug() << "profitAmount is:" <<  profitAmount;
    qDebug() << "profitPercet is:" <<  profitPercet;
}

QString Order::getSalesRepName() const
{
    return salesRepName;
}

void Order::setSalesRepName(const QString &value)
{
    salesRepName = value;
}

void Order::setOrderInfo(QStringList s){


    warehouse = s[1].toInt();
    customer = s[2].toInt();
    salesRep = s[3];
    route = s[5];
    stop = s[6].toInt();
    //if ()//need info on the credit column
    invoiceNumber = (s[8] + s[9] + s[10]).toInt();
    setInvoiceDate(s[11]);
    invoiceAmount = s[12].toDouble();
    quantityOrdered = s[13].toInt();
    caseCube = s[13].toDouble();
    caseWeight = s[14].toDouble();
    //have to redesign string reader to read in the string, and remove all commas between quotes.  otherwise i'm splitting up large numbers that aren't consistant.  cant dynamically plan that





}
