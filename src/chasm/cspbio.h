
/*
**---------------------------------------------------------------------------
** OpenChasm - Free software reconstruction of Chasm: The Rift game
** Copyright (C) 2013 Alexey Lysiuk
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**---------------------------------------------------------------------------
*/

#ifndef OPENCHASM_CSPBIO_H_INCLUDED
#define OPENCHASM_CSPBIO_H_INCLUDED

extern uint16_t CurVideoMode;

extern bool Internal;
extern bool UserMaps;

extern FILE* F;
extern FILE* Ft;

extern int32_t Ll;

extern char LastFName[256];

extern char AddonPath[41];


bool ExistFile(const char* const filename);

void TOpen(const char* const filename, FILE** externalFile);

void DoHalt(const char* const message);

void* GetMem16(const uint16_t size);

void CspBioInit();

#endif // OPENCHASM_CSPBIO_H_INCLUDED
