//////////////////////////////////////////////////////////////////////////////
// Standard includes
// SystemC includes
// ArchC includes

#include "ac_tlm_router.h"

//////////////////////////////////////////////////////////////////////////////

/// Namespace to isolate memory from ArchC
using user::ac_tlm_router;

/// Constructor
ac_tlm_router::ac_tlm_router( sc_module_name module_name ) :
  sc_module( module_name ),
  target_export("iport"),
  MEM_port("MEM_port", 5242880U),
  LOCK_port("LOCK_port",4U),
  DEV_port("DEV_port",16U)
{
    /// Binds target_export to the memory
    target_export( *this );
}

ac_tlm_rsp ac_tlm_router::transport( const ac_tlm_req &request ) {
	if(request.addr==20*1024*1024)
	{
	return DEV_port->transport(request);
	}else if(request.addr==10*1024*1024){
	return LOCK_port->transport(request);
	}else{
	return MEM_port->transport(request);
	}
}

/// Destructor
ac_tlm_router::~ac_tlm_router() {
}
