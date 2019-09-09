#include "Lighthouse.h"

void Lighthouse::Tick()
{
    for (auto i = 0; i < SectionCount; i++)
        _sections[i]->Tick();
}
