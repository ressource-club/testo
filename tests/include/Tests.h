#ifndef H_RESRC_TESTO_TESTS_TESTS
#define H_RESRC_TESTO_TESTS_TESTS

#include "Outils.h"
#include "../../include/Tests.h"

namespace resrc
{
    namespace testo
    {
        namespace tests
        {
            namespace Tests
            {
                class ArretSurEchec : public testo::Test
                {
                public:
                    ArretSurEchec() : testo::Test("ArretSurEchec") {}
                    const bool test() override;
                };

                class ArretSurErreur : public testo::Test
                {
                public:
                    ArretSurErreur() : testo::Test("ArretSurErreur") {}
                    const bool test() override;
                };

                class Tests : public testo::Tests
                {
                public:
                    Tests() : testo::Tests("testo::Tests")
                    {
                        this->ajouter(new ArretSurEchec());
                        this->ajouter(new ArretSurErreur());
                    }
                };
            }
        }
    }
}

#endif