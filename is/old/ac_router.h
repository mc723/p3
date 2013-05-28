//////////////////////////////////////////////////////////////////////////////

#ifndef AC_ROUTER_H_
#define AC_ROUTER_H_

//////////////////////////////////////////////////////////////////////////////

// Standard includes
// SystemC includes
#include <systemc>
// ArchC includes
#include "ac_tlm_protocol.H"
#include <ac_tlm_port.H>

//////////////////////////////////////////////////////////////////////////////

// using statements
using tlm::tlm_transport_if;

//////////////////////////////////////////////////////////////////////////////

//#define DEBUG

/// Namespace to isolate memory from ArchC
namespace user
{

/// A TLM memory
class ac_router :
  public sc_module,
  public ac_tlm_transport_if // Using ArchC TLM protocol
  {
  public:
    /// Exposed port with ArchC interface
    sc_export< ac_tlm_transport_if > target_export;
    ac_tlm_port MEM_port;

    /**
     * Default constructor.
     *
     */
    ac_router( sc_module_name module_name );

    /**
     * Default destructor.
     */
    ~ac_router();

  private:
  };

};

#endif //AC_ROUTER_H_
