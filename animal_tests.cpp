
#include "animal_tests.hpp"


animal_tests::animal_tests()
    :
    m_countMoo(0)
{}

void animal_tests::onCowMooed()
{
    ++m_countMoo;
}

void animal_tests::init()
{
    m_countMoo = 0;
    connect(&m_testCow, &Cow::signalSaidMoo, this, &animal_tests::onCowMooed);
}

void animal_tests::cleanup()
{
}

void animal_tests::test_moo()
{
    // We want to test that the cow moos once a second
    //
    // This is terrible to actually wait a second using timers and non deterministic results! We had to add an extra 500 ms to make it pass
    // and that is completely dependant on cpu speed and accuracy of timer. We also don't want to wait eons for the unit tests to complete.
    // We need dependency injection and a mock timer, so we can control when the timer fires!
    QVERIFY(QTest::qWaitFor([this] () { return m_countMoo >= 3; }, 3500));
}

QTEST_MAIN(animal_tests)



