#ifndef H_RESRC_TESTO_ITEST
#define H_RESRC_TESTO_ITEST

#include "IElement.h"

namespace resrc
{
    namespace testo
    {
        class ITest : public IElement
        {
        public:
            virtual const bool test() = 0;
        };
    }
}

#endif