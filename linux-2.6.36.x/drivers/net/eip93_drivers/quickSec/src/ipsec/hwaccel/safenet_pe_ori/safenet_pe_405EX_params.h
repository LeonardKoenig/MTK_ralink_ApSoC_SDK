/*
  safenet_pe_405EX_params.h

  Copyright:
  Copyright (c) 2007 SFNT Finland Oy.
  All rights reserved.

  Tunable configuration parameters for safenet_la.c and safenet_pe_slad.c
*/

#ifndef SAFENET_PE_405EX_PARAMS_H
#define SAFENET_PE_405EX_PARAMS_H


#define SAFENET_PE_PLATFORM_PE_REQUIRES_SWAP
#define SAFENET_PE_PLATFORM_SSH_SAFENET_MAX_QUEUED_OPERATIONS 390
#define SAFENET_PE_PLATFORM_SSH_SAFENET_POLLING
/*#define SAFENET_PE_PLATFORM_SSH_SAFENET_OCM_SA*/
#define SAFENET_PE_PLATFORM_SSH_SAFENET_NOT_COHERENT_CACHE 
#define SAFENET_PE_PLATFORM_SSH_SAFENET_MIN_BYTE_SWAP
/*#define SAFENET_PE_PLATFORM_SSH_SAFENET_PE_SA_CACHING*/
#define SAFENET_PE_PLATFORM_SSH_SAFENET_PDR_ENTRIES_PER_INTERRUPT 32
#ifdef SAFENET_PE_PLATFORM_SSH_SAFENET_POLLING
#define SAFENET_PE_PLATFORM_SSH_SAFENET_PDR_GET_COUNT		\
  (SAFENET_PE_PLATFORM_SSH_SAFENET_MAX_QUEUED_OPERATIONS + 9)
#else
#define SAFENET_PE_PLATFORM_SSH_SAFENET_PDR_GET_COUNT		\
  (SAFENET_PE_PLATFORM_SSH_SAFENET_PDR_ENTRIES_PER_INTERRUPT*3)
#endif /*SSH_SAFENET_POLLING*/
#define SAFENET_PE_PLATFORM_SSH_SAFENET_PDR_BURST_COUNT 32


#endif /* SAFENET_PE_405EX_PARAMS_H */