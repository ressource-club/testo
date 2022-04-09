#include "../include/Tests.h"

namespace resrc
{
    namespace testo
    {
        namespace tests
        {
            namespace Tests
            {
                const bool ArretSurEchec::test()
                {
                    testo::Tests tests{ "test", true, false };
                    tests.ajouter(new TestBravo());
                    tests.ajouter(new TestEchec());
                    tests.ajouter(new TestBravo());
                    const size_t executes = tests.executer();
                    return executes == 2;
                }

                const bool ArretSurErreur::test()
                {
                    testo::Tests tests{ "test", false, true };
                    tests.ajouter(new TestBravo());
                    tests.ajouter(new TestErreur());
                    tests.ajouter(new TestBravo());
                    const size_t executes = tests.executer();
                    return executes == 2;
                }
            }
        }
    }
}