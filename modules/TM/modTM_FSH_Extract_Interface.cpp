/* -*- C++ -*- */

//=============================================================================
/**
 * @file   modTM_FSH_Extract_Interface.cpp
 * @author Tad Kollar  
 *
 * $Id: modTM_FSH_Extract_Interface.cpp 1670 2012-08-28 13:25:28Z tkollar $
 * Copyright (c) 2012.
 *      NASA Glenn Research Center.  All rights reserved.
 *      See COPYING file that comes with this distribution.
 */
//=============================================================================

#include "modTM_FSH_Extract.hpp"
#include "TM_Interface_Macros.hpp"

namespace nTM_FSH_Extract {

//=============================================================================
/**
 * @class modTM_FSH_Extract_Interface
 * @author Tad Kollar  
 * @brief Provide an XML-RPC interface to the FSH Extraction module.
 */
//=============================================================================
class modTM_FSH_Extract_Interface: public nasaCE::TrafficHandler_Interface<modTM_FSH_Extract> {
public:
	modTM_FSH_Extract_Interface(xmlrpc_c::registryPtr& rpcRegistry):
		nasaCE::TrafficHandler_Interface<modTM_FSH_Extract>(rpcRegistry, "modTM_FSH_Extract") {
		ACE_TRACE("modTM_FSH_Extract_Interface::modTM_FSH_Extract_Interface");

		register_methods(rpcRegistry);
	}

	TM_PHYSICAL_CHANNEL_DEFINE_ACCESSORS();
	TM_MASTER_CHANNEL_DEFINE_ACCESSORS();

	// Export specified methods via XML-RPC.
	void register_methods(xmlrpc_c::registryPtr&);

protected:
	void get_counters_(xmlrpc_c::paramList const& paramList, modTM_FSH_Extract* handler,
		xstruct& counters) {
		ACE_TRACE("modTM_FSH_Extract_Interface::get_counters_");

		nasaCE::TrafficHandler_Interface<modTM_FSH_Extract>::get_counters_(paramList, handler, counters);

		GET_TM_PHYSICAL_CHANNEL_COUNTERS();
		GET_TM_MASTER_CHANNEL_COUNTERS();
	}

	void get_settings_(xmlrpc_c::paramList const& paramList, modTM_FSH_Extract* handler,
		xstruct& settings) {
		ACE_TRACE("modTM_FSH_Extract_Interface::get_settings_");

		nasaCE::TrafficHandler_Interface<modTM_FSH_Extract>::get_settings_(paramList, handler, settings);

		GET_TM_PHYSICAL_CHANNEL_SETTINGS();
		GET_TM_MASTER_CHANNEL_SETTINGS();
	}
};

modTM_FSH_Extract_Interface* modTM_FSH_Extract_InterfaceP;

TEMPLATE_METHOD_CLASSES(modTM_FSH_Extract_Interface, modTM_FSH_Extract_InterfaceP);

TM_PHYSICAL_CHANNEL_GENERATE_METHODS(modTM_FSH_Extract_InterfaceP);
TM_MASTER_CHANNEL_GENERATE_METHODS(modTM_FSH_Extract_InterfaceP);

void modTM_FSH_Extract_Interface::register_methods(xmlrpc_c::registryPtr& rpcRegistry) {
	ACE_TRACE("modTM_FSH_Extract_Interface::register_methods");

	TEMPLATE_REGISTER_METHODS(modTM_FSH_Extract, modTM_FSH_Extract_Interface);

	TM_PHYSICAL_CHANNEL_REGISTER_METHODS(modTM_FSH_Extract);
	TM_MASTER_CHANNEL_REGISTER_METHODS(modTM_FSH_Extract);
}

} // namespace nTM_FSH_Extract
