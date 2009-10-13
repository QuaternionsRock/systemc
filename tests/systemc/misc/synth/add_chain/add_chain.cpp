/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2005 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License Version 2.4 (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.systemc.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  add_chain.cpp -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

// $Log: add_chain.cpp,v $
// Revision 1.4  2006/01/24 21:05:23  acg
//  Andy Goodrich: replacement of deprecated features with their non-deprecated
//  counterparts.
//
// Revision 1.3  2006/01/20 00:43:19  acg
// Andy Goodrich: Changed over to use putenv() instead of setenv() to accommodate old versions of Solaris.
//
// Revision 1.2  2006/01/19 00:47:26  acg
// Andy Goodrich: Changes for the fact signal write checking is enabled.
//

#include "systemc.h"
#include "define.h"
#include "display.h"
#include "data_gen.h"
#include "reset_stim.h"
#include "add_chain.h"
#include "tb.h" 	

int
sc_main(int ac, char *av[])
{
  // turn off multiwrite check for signals.
  putenv("SC_SIGNAL_WRITE_CHECK=DISABLE");
  sc_get_curr_simcontext()->reset();

  sc_clock clk( "CLOCK", 20, SC_NS, 0.5, 0, SC_NS, false);  // Clock function
  testbench tb1("TB1", clk );	// Testbench Instance

  sc_start();   
  return 0;
}
