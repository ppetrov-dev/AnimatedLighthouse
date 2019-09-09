#include "../settings.h"
#include "../LighthouseSection/LighthouseSection.h"

class Lighthouse
{
private:
    LighthouseSection *_sections[SectionCount] = {/* &_pumpButton1, &_pumpButton2*/};
public:
    void Tick();
};
