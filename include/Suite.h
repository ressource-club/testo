#ifndef H_RESRC_TESTO_SUITE
#define H_RESRC_TESTO_SUITE

#include "Test.h"
#include "Console.h"

#include <vector>

namespace resrc
{
    namespace testo
    {
        class Suite : public Composant
        {
        private:
            std::vector<Composant*> _tests;
            std::vector<Composant*> _suites;

            const size_t executer_tests(const int argc, const char** argv);
            const size_t executer_suites(const int argc, const char** argv);

        public:
            Suite(const std::string nom);

            inline const size_t tests(const bool suite = false) const;
            inline const size_t suites() const;

            void ajouter(Composant* composant);

            const int executer(const int argc, const char** argv) override;
        };
    }
}

#endif