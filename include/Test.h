#ifndef H_RESRC_TESTO_TEST
#define H_RESRC_TESTO_TEST

#include "Composant.h"

namespace resrc
{
    namespace testo
    {
        class Test : public Composant
        {
        protected:
            Test(const std::string nom);

            virtual const bool test() = 0;

        public:
            enum class Retour
            {
                SUCCES = 0,
                ECHEC = 1,
                ERREUR = -1
            };

            const int executer(const int argc, const char** argv) override;
        };
    }
}

#endif