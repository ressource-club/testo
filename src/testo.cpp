#include "../include/testo.h"

#include <iostream>

namespace resrc
{
    namespace testo
    {
        std::vector<Tests*> app::_series{ new Tests() };

        const int app::executer(const int argc, const char** argv)
        {
            Console console;            
            console.afficher(RESRC_TESTO_INTRO);
            
            const size_t n = _series.size();
            for (size_t s = 0; s < n; s++)
            {
                if (s == 0 && _series[0]->total() == 0) continue;
                _series[s]->executer(&console);
            }
            
            return n;
        }
    }
}