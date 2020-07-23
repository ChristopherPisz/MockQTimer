
#include "cow.hpp"
#include <iostream>


unsigned const defaultMooIntervalMilliseconds = 1000;

Cow::Cow()
:
QObject()
{
    m_timerMoo.setInterval(defaultMooIntervalMilliseconds);
    QObject::connect(&m_timerMoo, &QTimer::timeout, this, &Cow::onMooDue);
    m_timerMoo.start();
}

void Cow::onMooDue()
{
    std::cout << "The cow says Moo" << std::endl;
    emit signalSaidMoo();
}

