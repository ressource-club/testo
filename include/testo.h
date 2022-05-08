#ifndef H_RESRC_TESTO
#define H_RESRC_TESTO

#include "Suite.h"

#define RESRC_TESTO_INTRO "testo v" RESRC_TESTO_VERSION " - resrc.club"

// TODO Planifier les futures versions.

namespace resrc
{
    namespace testo
    {
        class App : public Suite
        {
        public:
            App(const std::string nom);

            const int executer(const int argc, const char** argv) override;
        };
    }
}
#endif