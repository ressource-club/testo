#ifndef H_RESRC_TESTO_TESTS_OUTILS
#define H_RESRC_TESTO_TESTS_OUTILS

#include "../../include/Test.h"

namespace resrc
{
    namespace testo
    {
        namespace tests
        {
            class TestBravo : public testo::Test
            {
            public:
                TestBravo() : testo::Test("Bravo ?") {}
                const bool test() override { return true; }
            };

            class TestEchec : public testo::Test
            {
            public:
                TestEchec() : testo::Test("Echec ?") {}
                const bool test() override { return false; }
            };

            class TestErreur : public testo::Test
            {
            public:
                TestErreur() : testo::Test("Erreur ?") {}
                const bool test() override { throw std::exception(); }
            };
        }
    }
}

#endif