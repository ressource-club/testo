#ifndef H_RESRC_TESTO_TESTS
#define H_RESRC_TESTO_TESTS

#include "ITest.h"
#include "Console.h"

#include <vector>

namespace resrc
{
    namespace testo
    {
        class Tests : public IElement
        {
        private:
            const std::string _nom;
            std::vector<ITest*> _tests;

            const bool _arreter_sur_echec;
            const bool _arreter_sur_erreur;

        public:
            Tests(
                const std::string nom = RESRC_TESTO_TESTS_NOM_PAR_DEFAUT, 
                const bool arreter_sur_echec = RESRC_TESTO_TESTS_ARRET_ECHEC_PAR_DEFAUT,
                const bool arreter_sur_erreur = RESRC_TESTO_TESTS_ARRET_ERREUR_PAR_DEFAUT
            );

            inline const std::string& nom() const override { return this->_nom; }

            inline const size_t total() { return this->_tests.size(); }
            void ajouter(ITest* test);

            const size_t executer(Console* console = nullptr);
        };
    }
}

#endif