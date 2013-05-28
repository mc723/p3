//////////////////////////////////////////////////////////////////////////////
// Standard includes
// SystemC includes
// ArchC includes

#include "ac_router.h"

//////////////////////////////////////////////////////////////////////////////

/// Namespace to isolate memory from ArchC
using user::ac_router;

/// Constructor
ac_router::ac_router( sc_module_name module_name ) :
  sc_module( module_name ),
  target_export("iport"),
  MEM_port("MEM_port", 5242880U)
{
    /// Binds target_export to the memory
    target_export( *this );
}

/// Destructor
ac_router::~ac_router() {
}


