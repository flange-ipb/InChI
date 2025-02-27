/*
 * International Chemical Identifier (InChI)
 * Version 1
 * Software version 1.07
 * 20/11/2023
 *
 * The InChI library and programs are free software developed under the
 * auspices of the International Union of Pure and Applied Chemistry (IUPAC).
 * Originally developed at NIST.
 * Modifications and additions by IUPAC and the InChI Trust.
 * Some portions of code were developed/changed by external contributors
 * (either contractor or volunteer) which are listed in the file
 * 'External-contributors' included in this distribution.
 *
 * IUPAC/InChI-Trust Licence No.1.0 for the
 * International Chemical Identifier (InChI)
 * Copyright (C) IUPAC and InChI Trust
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the IUPAC/InChI Trust InChI Licence No.1.0,
 * or any later version.
 *
 * Please note that this library is distributed WITHOUT ANY WARRANTIES
 * whatsoever, whether expressed or implied.
 * See the IUPAC/InChI-Trust InChI Licence No.1.0 for more details.
 *
 * You should have received a copy of the IUPAC/InChI Trust InChI
 * Licence No. 1.0 with this library; if not, please e-mail:
 *
 * info@inchi-trust.org
 *
 */


#ifndef _E__ICHITIME_H_
#define _E__ICHITIME_H_

#ifdef COMPILE_ANSI_ONLY

#ifdef __FreeBSD__
#include <sys/time.h>
#endif

/* get times() */
#ifdef INCHI_USETIMES
#include <sys/times.h>
#endif

/*#include <sys/timeb.h>*/

#include <time.h>

typedef struct e_tagInchiTime {
    clock_t clockTime;
} e_inchiTime;

#else

/* Win32 _ftime(): */
#include <sys/timeb.h>

typedef struct e_tagInchiTime {
    unsigned long  clockTime; /* Time in seconds since midnight (00:00:00), January 1, 1970;
                                 signed long overflow expected in 2038 */
    long           millitime; /* milliseconds */
} e_inchiTime;

#endif


unsigned long e_ulMyGetTickCount( int bStart );
unsigned long e_ulMyTickCountDiff( unsigned long ulTickEnd, unsigned long ulTickStart );

void e_inchiTimeGet( e_inchiTime *TickEnd );
long e_inchiTimeMsecDiff( e_inchiTime *TickEnd, e_inchiTime *TickStart );
void e_inchiTimeAddMsec( e_inchiTime *TickEnd, unsigned long nNumMsec );
int  bInchiTimeIsOver( e_inchiTime *TickEnd );
long e_inchiTimeElapsed( e_inchiTime *TickStart );


#ifndef COMPILE_ALL_CPP
#ifdef __cplusplus
extern "C" {
#endif
#endif



#ifndef COMPILE_ALL_CPP
#ifdef __cplusplus
}
#endif
#endif



#endif    /* _E__ICHITIME_H_ */
