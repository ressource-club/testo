#include "../include/Suite.h"

namespace resrc
{
    namespace testo
    {
        Suite::Suite(const std::string nom)
            : Composant(Composant::Type::SUITE, nom)
        {}

        inline const size_t Suite::tests(const bool suites) const
        {
            size_t tests = this->_tests.size();
            // if (suites)
            // {
            //     for (Composant* suite : this->_suites)
            //         tests += suite->uint64_t(this);
            // }
            return tests;
        }

        inline const size_t Suite::suites() const
        { return this->_suites.size(); }

        void Suite::ajouter(Composant* composant)
        {
            switch (composant->type())
            {
            case Composant::Type::TEST:
                // TODO Verifier si le nom existe déjà.
                this->_tests.push_back(composant);
                break;
            
            case Composant::Type::SUITE:
                // TODO Verifier si le nom existe déjà.
                this->_suites.push_back(composant);
                break;

            default:
                // TODO Erreur ComposantInconnu.
                break;
            }
        }

        const size_t Suite::executer_tests(const int argc, const char** argv)
        {
            const size_t n = this->_tests.size();
            const std::string ns = std::to_string(n);
            size_t succes = 0, t = 0;
            Test::Retour retour;
            Console::afficher(this, "TESTS > " + ns + " tests.");
            if (n > 0)
            {
                Console::saut();
                for (t = 0; t < n; t++)
                {
                    Console::afficher(this, "[" + std::to_string(t + 1) + "/" + ns + "] " + this->_tests[t]->nom() + " -> ", false, false);
                    retour = (Test::Retour) this->_tests[t]->executer(argc, argv);
                    if (retour == Test::Retour::SUCCES)
                    {
                        Console::afficher(RESRC_TESTO_MESSAGE_SUCCES);
                        succes++;
                    }
                    else if (retour == Test::Retour::ECHEC)
                    {
                        Console::afficher(RESRC_TESTO_MESSAGE_ECHEC);
                        // TODO Arrêter sur echec.
                    }
                    else if (retour == Test::Retour::ERREUR)
                    {
                        Console::afficher(RESRC_TESTO_MESSAGE_ERREUR);
                        // TODO Arrêter sur erreur.
                    }
                }
                Console::saut();
                Console::afficher(this, "TESTS > " + std::to_string(succes) + " succès sur " + std::to_string(t) + " tests exécutés.");
            }
            return t;
        }

        const size_t Suite::executer_suites(const int argc, const char** argv)
        {
            const size_t n = this->_suites.size();
            const std::string ns = std::to_string(n);
            size_t tests = 0, s = 0;
            Console::afficher(this, "SUITES > " + ns + " suites.");//(" + std::to_string(this->tests(true) - this->tests()) + " tests).");
            if (n > 0)
            {
                Console::saut();
                Console::augmenter_indentation();
                for (s = 0; s < n; s++)
                {
                    tests += this->_suites[s]->executer(argc, argv);
                    Console::saut();
                }
                Console::reduire_indentation();
                Console::afficher(this, "SUITES > " + std::to_string(tests) + " tests exécutés.");
            }
            return tests;
        }

        const int Suite::executer(const int argc, const char** argv)
        {
            size_t tests = this->executer_tests(argc, argv);
            Console::saut();
            tests += this->executer_suites(argc, argv);
            return tests;
        }
    }
}