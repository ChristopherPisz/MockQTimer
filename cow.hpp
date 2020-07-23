#ifndef MOCKQTIMER_SOMECLASS_HPP
#define MOCKQTIMER_SOMECLASS_HPP

#include <QObject>
#include <QTimer>

class Cow : public QObject
{
    Q_OBJECT
public:
    Cow();
    ~Cow() override = default;

signals:
    void signalSaidMoo();

private slots:
    void onMooDue();

private:
    QTimer m_timerMoo;
};

#endif // MOCKQTIMER_SOMECLASS_HPP
