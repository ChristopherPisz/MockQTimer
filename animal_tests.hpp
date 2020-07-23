#ifndef MOCKQTIMER_ANIMAL_TESTS_HPP
#define MOCKQTIMER_ANIMAL_TESTS_HPP

#include "cow.hpp"
#include <QCoreApplication>
#include <QtTest>


class animal_tests : public QObject
{
Q_OBJECT

public:
    animal_tests();
    ~animal_tests() override = default;

public slots:

    /*
     * @brief Called when the Cow's Moo signal is fired
     */
    void onCowMooed();

private slots:
    void init();
    void cleanup();

    void test_moo();

private:
    Cow      m_testCow;
    unsigned m_countMoo;
};

#endif // MOCKQTIMER_ANIMAL_TESTS_HPP
