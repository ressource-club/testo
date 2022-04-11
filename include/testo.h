#ifndef H_RESRC_TESTO
#define H_RESRC_TESTO

#include "Tests.h"
#include "Test.h"

#define RESRC_TESTO_INTRO "> testo v" RESRC_TESTO_VERSION " - resrc.club"

// TODO Planifier les futures versions.

namespace resrc
{
    namespace testo
    {
        class app
        {
        private:
            static std::vector<Tests*> _series;

        public:
            inline static void ajouter(ITest* test) { _series[0]->ajouter(test); }
            // TODO Vérifier que le nom n'existe pas déjà.
            inline static void ajouter(Tests* serie) { _series.push_back(serie); }

            static const int executer(const int argc, const char** argv);
        };
    }
}
#endif