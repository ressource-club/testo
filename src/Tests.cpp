#include "../include/Tests.h"

namespace resrc
{
    namespace testo
    {
        Tests::Tests(const std::string nom, const bool arreter_sur_echec, const bool arreter_sur_erreur)
            : _nom{ nom }, _arreter_sur_echec{ arreter_sur_echec }, _arreter_sur_erreur{ arreter_sur_erreur }
        {}

        void Tests::ajouter(ITest* test)
        {
            // for (const ITest* t : this->_tests)
            //     if (t->nom() == test->nom()) throw ... // TODO Erreur TestDejaExistant
            this->_tests.push_back(test);
        }

        const size_t Tests::executer(Console* console)
        {
            const size_t n = this->_tests.size();
            const bool aff = console != nullptr;
            if (n == 0)
            {
                if (aff) console->afficher(*this, "Aucun test à exécuter.");
                return 0;
            }
            else
            {
                const std::string ns = std::to_string(n);
                size_t succes = 0, t = 0;
                if (aff) console->afficher(*this, "Exécution des tests...");
                for (t = 0; t < n; t++)
                {
                    if (aff) console->afficher("\t\t> [" + std::to_string(t + 1) + "/" + ns + "] " + this->_tests[t]->nom() + " -> ", false);
                    try
                    {
                        if (this->_tests[t]->test())
                        {
                            if (aff) console->afficher("BRAVO");
                            succes++;
                        }
                        else
                        {
                            if (aff) console->afficher("ECHEC");
                            if (this->_arreter_sur_echec)
                            {
                                t++;
                                break;
                            }
                        }
                    }
                    catch (std::exception& err)
                    {
                        if (aff)
                        {
                            console->afficher("ECHEC");
                            console->afficher(*this, "Une erreur est survenue : " + std::string(err.what()));
                        }
                        if (this->_arreter_sur_erreur)
                        {
                            t++;
                            break;
                        }
                    }
                }
                if (aff) console->afficher(*this, "Résultat : " + std::to_string(succes) + " sur " + std::to_string(t));
                return t;
            }
        }
    }
}