#include "cscript.h"

void cscript_version(unsigned* major, unsigned* minor)
{
  *major = CSCRIPT_VERSION_MAJOR;
  *minor = CSCRIPT_VERSION_MINOR;
}
