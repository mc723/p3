/**
 * @file      ac_tlm_mem.cpp
 * @author    Bruno de Carvalho Albertini
 *
 * @author    The ArchC Team
 *            http://www.archc.org/
 *
 *            Computer Systems Laboratory (LSC)
 *            IC-UNICAMP
 *            http://www.lsc.ic.unicamp.br/
 *
 * @version   0.1
 * @date      Sun, 02 Apr 2006 08:07:46 -0200
 *
 * @brief     Implements a ac_tlm memory.
 *
 * @attention Copyright (C) 2002-2005 --- The ArchC Team
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Lesser General Public
 *   License as published by the Free Software Foundation; either
 *   version 2.1 of the License, or (at your option) any later version.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Lesser General Public License for more details.
 *
 *
 */

//////////////////////////////////////////////////////////////////////////////
// Standard includes
// SystemC includes
// ArchC includes

#include "ac_tlm_device.h"

//////////////////////////////////////////////////////////////////////////////

/// Namespace to isolate memory from ArchC
using user::ac_tlm_device;

/// Constructor
ac_tlm_device::ac_tlm_device( sc_module_name module_name , int k ) :
  sc_module( module_name ),
  target_export("iport")
{
    /// Binds target_export to the memory
    target_export( *this );
    data1=data2=data3=data4=0;
    /// Initialize memory vector
    //memory = new uint8_t[ k ];
    //for(k=k-1;k>0;k--) memory[k]=0;

}

/// Destructor
ac_tlm_device::~ac_tlm_device() {

  //delete [] memory;
}

/** Internal Write
  * Note: Always write 32 bits
  * @param a is the address to write
  * @param d id the data being write
  * @returns A TLM response packet with SUCCESS
*/
ac_tlm_rsp_status ac_tlm_device::writem( const uint32_t &a , const uint32_t &d )
{
  //lock_data = *((uint32_t *) &d);
  int tmp = *((uint32_t *) &d);
  int tmp_sw;
  ((unsigned char*)&tmp_sw)[0]=((unsigned char*)&tmp)[3];
  ((unsigned char*)&tmp_sw)[1]=((unsigned char*)&tmp)[2];
  ((unsigned char*)&tmp_sw)[2]=((unsigned char*)&tmp)[1];
  ((unsigned char*)&tmp_sw)[3]=((unsigned char*)&tmp)[0];

  if(data1==0)
  {
	//data1= *((uint32_t *) &d);
	data1=tmp_sw;
	
  }else if(data2==0)
  {
	//data2=*((uint32_t *) &d);
	data2=tmp_sw;
  }else if(data3==0)
  {
	//data3=*((uint32_t *) &d);
	data3=tmp_sw;
  }else{
	//data4=*((uint32_t *) &d);
	data4=tmp_sw;
  }
  return SUCCESS;
}

/** Internal Read
  * Note: Always read 32 bits
  * @param a is the address to read
  * @param d id the data that will be read
  * @returns A TLM response packet with SUCCESS and a modified d
*/
ac_tlm_rsp_status ac_tlm_device::readm( const uint32_t &a , uint32_t &d )
{
 // *((uint32_t *) &d) = lock_data;
 // lock_data=1;
  int tmp = (data1+data2+data3+data4)/4;
  int tmp_sw;
  ((unsigned char*)&tmp_sw)[0]=((unsigned char*)&tmp)[3];
  ((unsigned char*)&tmp_sw)[1]=((unsigned char*)&tmp)[2];
  ((unsigned char*)&tmp_sw)[2]=((unsigned char*)&tmp)[1];
  ((unsigned char*)&tmp_sw)[3]=((unsigned char*)&tmp)[0]; 

 // *((uint32_t *) &d)=(data1+data2+data3+data4)/4;
  *((uint32_t *) &d)= tmp_sw ;  
  data1=data2=data3=data4=0;
  return SUCCESS;
}



